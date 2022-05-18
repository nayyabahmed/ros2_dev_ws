#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <memory>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <visualization_msgs/msg/marker.hpp>

#include "abds_msgs/msg/trajectory.hpp"
#include "rc_interfaces/msg/imu_rc.hpp"
#include "rc_interfaces/msg/rc_status.hpp"

using trajectory_msg = abds_msgs::msg::Trajectory;
using trajectory_point = abds_msgs::msg::TrajectoryPoint;
using visualization_msgs::msg::Marker;

#include "traj_defines.h"
#include "vehicle_dimensions.h"
#include "pf_structures.h"
#include "driverless_values_struct.h"
#include "comms.h"
#include "network_utils.h"
#include "numeric_analysis.h"
#include "pf_segment_functions.h"
#include "pf_phase_enum.h"
#include "test_state_enum.h"

#define DEG2RAD (M_PI / 180.0)

#define DEBUG

// ================================== Structs ===============================================

typedef struct
{
	unsigned char isTestOrTrans; // 1 for test, 2 for trans
	unsigned char branchLevel; // 0 primary, 1 first trigger on, 2 first trigger off, second trigger on, 3 first trigger on, second trigger on, etc.
	int16_t testOrTransId;
	float startDist;
	float endDist;
	float cumDist;
}_CHIPOLATA_DATA;


typedef struct {
	float path_distance;
	int32_t mPfPhase;
	uint16_t test_index;
	int16_t test_phase;
	float desired_speed;
	uint16_t test_data_loaded;
	unsigned char pf_test_true;
	int16_t current_path_exit_index;
	unsigned char autonomous_status_1;
	unsigned char autonomous_status_2;
	unsigned char autonomous_test_state;
	unsigned char test_in_progress;
} _TEST_STATUS;

// ================================== Functions declarations ===============================================

unsigned char validPFphaseForPathCollisionChecking( int32_t pfPhase );


// ================================== Functions defintions ===============================================


unsigned char validPFphaseForPathCollisionChecking( int32_t pfPhase )
{
	if ( pfPhase > 0 ) // 1st lap, 2nd lap, etc..
	{
		return 1;
	}

	switch ( pfPhase )
	{
		case 0: // Lead-in or restart to path
			return 1;
		case -1: // Transition between paths
			return 1;
		case -4: // On entry lap
			return 1;
		case -5: // Sync tracker mode enabled fully
			return 1;
		case -6: // Synchro finished
			return 1;
		case -8: // In critical section
			return 1;
		case -9: // In VGR
			return 0;
		case -14: // On exit lap
			return 1;
		case -17: // Normal stopping
			return 1;
		case -18: // Held at stop point, not valid, should use stopzone
			return 0;
		case -24: // Sync tracker mode enabled lateral only
			return 1;
		case -25: // Sync tracker mode enabled longitudinal only
			return 1;
		case -26: // Sync tracker mode enabled start/e-stop only
			return 1;
		default:
			return 0;
	}

	return 0;
}

// ================================== Classes ===============================================

class LowPassButterworth {
	public:
		LowPassButterworth() {
			b_0 = 1.0;
			b_1 = 0.0;
			b_2 = 0.0;
			a_1 = 0.0;
			a_2 = 0.0;
			x_n_1 = NAN;
			x_n_2 = NAN;
			y_n_1 = NAN;
			y_n_2 = NAN;
		}
		int calculateCoefficients( double sample_f, double cutoff_f ) {
			if ( sample_f < cutoff_f)
			{
				return -1;
			}
			double f_ratio = cutoff_f / sample_f;
			double inv_tan = 1.0 / std::tan( M_PI * f_ratio );
			b_0 = 1.0 / (1.0 + M_SQRT2*inv_tan + inv_tan*inv_tan);
			b_1 = 2 * b_0;
			b_2 = b_0;
			a_1 = 2.0 * b_0 * ( inv_tan*inv_tan - 1.0 );
			a_2 = -b_0 * (1.0 - M_SQRT2*inv_tan + inv_tan*inv_tan );
			cutoff_freq = cutoff_f;
			sample_freq = sample_f;

			return 1;
		}
		double update( double x_n ) {

			// start of the filter
			if ( std::isnan(x_n_1) )
				x_n_1 = x_n;

			if ( std::isnan(x_n_2) )
				x_n_2 = x_n_1;

			if ( std::isnan(y_n_1) )
				y_n_1 = x_n;

			if ( std::isnan(y_n_2) )
				y_n_2 = y_n_1;

			// caluclate output
			double y_n = b_0*x_n + b_1*x_n_1 + b_2*x_n_2 + a_1*y_n_1 + a_2*y_n_2;

			// update stored values
			x_n_2 = x_n_1;
			x_n_1 = x_n;
			y_n_2 = y_n_1;
			y_n_1 = y_n;

			return y_n;
		}

	private:
		double b_0;
		double b_1;
		double b_2;
		double a_1;
		double a_2;
		double cutoff_freq;
		double sample_freq;
		double x_n_1;
		double x_n_2;
		double y_n_1;
		double y_n_2;
};


class TrajectoryPoint {
	public:
		float x_pos; //x position in the robot coordinate system
		float y_pos; //y position in the robot coordinate system
		float z_pos;
		float yaw;
		float pitch;
		float roll;
		double latitude;
		double longitude;
		float bearing;
		float distance;
		float time;
		float longitudinal_velocity;
		float lateral_velocity;
		float longitudinal_acceleration;
		float yaw_velocity;
		float curvature;

		TrajectoryPoint() {
			x_pos = 0.0f;
			y_pos = 0.0f;
			z_pos = 0.0f;
			yaw = 0.0f;
			pitch = 0.0f;
			roll = 0.0f;
			latitude = 0.0f;
			longitude = 0.0f;
			bearing = 0.0f;
			distance = 0.0f;
			time = 0.0f;
			longitudinal_velocity = 0.0f;
			lateral_velocity = 0.0f;
			longitudinal_acceleration = 0.0f;
			yaw_velocity = 0.0f;
			curvature = 0.0f;
		}
};

class Trajectory : public rclcpp::Node
{
	public:
		int32_t num_points;
		std::vector<TrajectoryPoint> points;
		Trajectory()
		: Node("trajectory"),
		  m_marker_pub_ptr(create_publisher<Marker>(
		  "trajectory_viz", rclcpp::QoS{10}))
		{
			num_points = 0;
			points.reserve(MAX_NUM_PATH_POINTS);
			hasValidPath = 0;
			pathDataContainsRelativePaths = 0;
			last_trigger_download_path_data = 0;
			num_chipolata = 0;
			points.clear();
			subscription_ = this->create_subscription<rc_interfaces::msg::ImuRc>("rc_imu", 10, std::bind(&Trajectory::topic_callback_IMU, this, std::placeholders::_1));
			subscription_2 = this->create_subscription<rc_interfaces::msg::RcStatus>("rc_status", 10, std::bind(&Trajectory::topic_callback_TestState, this, std::placeholders::_1));

      		publisher_ = this->create_publisher<trajectory_msg>("trajectory", 10);

			raw_path_data = malloc( MAX_PATH_DATA_SIZE );
			raw_path_data_size = 0;
			if ( raw_path_data == NULL )
			{
				std::cout << "Couldn't allocate memory for path data. exit()\n";
				std::exit(EXIT_FAILURE);
			}

			filt.calculateCoefficients( SAMPLE_FREQ, CUTOFF_FREQ);
		}
		~Trajectory()
		{
			std::cout << "Destroy Trajectory()\n";
			if (raw_path_data != NULL)
			{
				free(raw_path_data);
			}
		}
		int32_t generate_trajectory_points_straight( float horizon_time, float horizon_distance, float point_separation, float min_dist, float longitudinal_velocity, float robot_x_pos, float robot_y_pos, float robot_z_pos, float robot_yaw );
		int32_t generate_trajectory_points_arc( float horizon_time, float horizon_distance, float point_separation, float min_dist, float longitudinal_velocity, float robot_x_pos, float robot_y_pos, float robot_z_pos, float robot_yaw, float robot_yaw_rate );
		int32_t generate_trajectory_points_path( float horizon_time, float horizon_distance, float min_dist, float robot_z_pos, float point_separation );
		uint32_t downloadPathData( void );
		uint32_t pathDownloaderFun_4( void *raw_path_data, int sock, unsigned char *server_reply );
		uint32_t downloadLeadInData( void );
		int leadinDownloaderFun_2( int sock, unsigned char *server_reply );
		int32_t getSausage( float sausageLength );
		int32_t getPathPoints( int numChipolata, float horizon_time, float horizon_distance, float min_dist, float robot_z_pos, float point_separation );

	private:
		const std::shared_ptr<rclcpp::Publisher<Marker>> m_marker_pub_ptr;

		void topic_callback_IMU(const rc_interfaces::msg::ImuRc::SharedPtr msg)
		{
			RCLCPP_INFO(this->get_logger(), "IMU: I heard: '%f'", msg->mp_time);

			// Filter IMU data as appropriate
			filt_yaw_rate = filt.update( msg->twist.angular.z * DEG2RAD );

			// Switch whether to use arc method or path method
			int path_condition = 0;
			if ((testStat.autonomous_status_1 % 2) == 0) { // not driverless
				path_condition = ( testStat.mPfPhase >= ON_EXIT_LAP );
			}
			else { // driverless
				path_condition = ((testStat.autonomous_test_state == TEST_RUNNING) || (testStat.autonomous_test_state == SR_BR_TEST_COMPLETE)); // running test or normal stopping
			}

			if ( ( hasValidPath > 0 ) && (path_condition) )
			{
				RCLCPP_INFO(this->get_logger(), "use Path method");
				int32_t retVal = generate_trajectory_points_path( TIME_HORIZON_S, DISTANCE_HORIZON_M, DISTANCE_MINIMUM_M, msg->pose.position.z, POINT_SEPARATION_M );
				if ( retVal <= 0 ) // fallback option
				{
					RCLCPP_INFO(this->get_logger(), "fallback to IMU method");
					generate_trajectory_points_arc( IMU_TIME_HORIZON_S, IMU_DISTANCE_HORIZON_M, POINT_SEPARATION_M, DISTANCE_MINIMUM_M, msg->twist.linear.x, msg->pose.position.x, msg->pose.position.y, msg->pose.position.z, msg->yaw_angle * DEG2RAD, filt_yaw_rate );
				}
			}
			else
			{
				RCLCPP_INFO(this->get_logger(), "use IMU method %d, %d", hasValidPath, path_condition);
				generate_trajectory_points_arc( IMU_TIME_HORIZON_S, IMU_DISTANCE_HORIZON_M, POINT_SEPARATION_M, DISTANCE_MINIMUM_M, msg->twist.linear.x, msg->pose.position.x, msg->pose.position.y, msg->pose.position.z, msg->yaw_angle * DEG2RAD, filt_yaw_rate );
			}

			// echo x,y points to file
			//FILE *fd = fopen( "/home/louis/Downloads/data.csv", "w" );
			//fprintf( fd, "x, y\n" );
			/*
			for ( uint32_t i = 0; i < points.size(); ++i ) // print out the spoofed data
			{

				//fprintf( fd, "%f, %f\n", points[i].x_pos, points[i].y_pos );
				std::cout << "(" << points[i].x_pos << "," << points[i].y_pos << "," << points[i].distance << "," << points[i].time << "," <<")\n";
			}
			*/
			//fclose(fd);


			// todo use path data if exists
			Marker m;
			m.ns = "traj";
			m.id = 0;
			m.type = Marker::LINE_STRIP;
			m.action = Marker::ADD;
			m.color.r = 0.5;
			m.color.g = 0.5;
			m.color.b = 0.8;
			m.color.a = 0.75;
			m.lifetime.sec = 0;
			m.lifetime.nanosec = 500000000;
			m.scale.x = 3.0; //TODO: get from param

			m.header.stamp = msg->header.stamp;
			m.header.frame_id = "base_link"; // TODO: get from param file

			t.header.stamp = msg->header.stamp;
			t.header.frame_id = "trajectory_calculator";
			t.points.clear();
			for ( uint32_t i = 0; i < points.size(); ++i )
			{
				geometry_msgs::msg::Point p {};
				p.x = points[i].x_pos;
				p.y = points[i].y_pos;
				p.z = points[i].z_pos;
    			m.points.push_back(p);
				trajectory_point tp {};
				tp.pose.position.x = points[i].x_pos;
				tp.pose.position.y = points[i].y_pos;
				tp.pose.position.z = points[i].z_pos;

				rclcpp::Duration time_along_traj = rclcpp::Duration::from_seconds(points[i].time);
				tp.time_from_start = time_along_traj;
				tp.dist_along_path = points[i].distance;
				t.points.push_back( tp );
			}
			publisher_->publish(t);
 			m_marker_pub_ptr->publish(m);
		}
		void topic_callback_TestState(const rc_interfaces::msg::RcStatus::SharedPtr msg)
		{
			RCLCPP_INFO(this->get_logger(), "Test: I heard: '%f'", msg->path_dist);

			//----------------------------------------
			// Save the test data for use elsewhere
			testStat.path_distance 				= msg->path_dist;
			testStat.mPfPhase					= msg->mpf_phase;
			testStat.test_index 				= msg->test_index;
			testStat.test_phase 				= msg->test_phase;
			testStat.desired_speed 				= msg->desire_speed;
			testStat.pf_test_true 				= msg->pf_test_true;
			testStat.current_path_exit_index	= msg->current_path_exit_index;
			testStat.autonomous_status_1		= msg->dl_status_1;
			testStat.autonomous_status_2		= msg->dl_status_2;
			testStat.autonomous_test_state		= msg->dl_test_procedure_state;
			testStat.test_in_progress			= msg->test_in_progress;
			testStat.test_data_loaded			= msg->dl_test_data_loaded;

			//----------------------------------------
			// check for whether to trigger the path update
			int trigger_download_path_data = 0;
			int trigger_download_lead_in   = 0;
			if ( (testStat.autonomous_status_1 % 2) == 1 ) // driverless
			{
				trigger_download_path_data = ( testStat.autonomous_test_state == WAIT_FOR_START ); // TODO redownload transition 0 when it updates
				trigger_download_lead_in   = (( testStat.autonomous_status_1 & 0x08 ) > 0 ); // startPosition ok
			}
			else // non-driverless
			{
				trigger_download_path_data = ((testStat.test_in_progress > 0) || ( testStat.mPfPhase >= ON_LEAD_IN )); // TODO change to inactive data loaded when we redownload the start spline
				RCLCPP_INFO(this->get_logger(), "testInProgress %d, mpfphase %d", testStat.test_in_progress, testStat.pf_test_true, testStat.mPfPhase );
			}

			if ( (trigger_download_path_data > 0) && ( last_trigger_download_path_data == 0 ) )
			{
				raw_path_data_size = downloadPathData();
			}

			if ( (trigger_download_lead_in > 0) && ( last_trigger_download_lead_in == 0 ) )
			{
				downloadLeadInData();
			}

			last_trigger_download_path_data = trigger_download_path_data;
			last_trigger_download_lead_in   = trigger_download_lead_in;
		}

		const float min_velocity = MIN_VELOCITY_M_S;
		double filt_yaw_rate;
		int hasValidPath;
		int pathDataContainsRelativePaths;
		trajectory_msg t;
		rclcpp::Subscription<rc_interfaces::msg::ImuRc>::SharedPtr subscription_;
		rclcpp::Subscription<rc_interfaces::msg::RcStatus>::SharedPtr subscription_2;
		rclcpp::Publisher<trajectory_msg>::SharedPtr publisher_;
		LowPassButterworth filt;
		void *raw_path_data;
		uint32_t raw_path_data_size;
		int robot_client_endianness;
		int last_trigger_download_path_data;
		int last_trigger_download_lead_in;
		int num_chipolata;
		_CHIPOLATA_DATA chipolata[MAX_CHIPOLATA]; // could use std::vector to dynamically size these if preferable
		_TEST_STATUS testStat;
		_VEHICLEDATA vehicle_data;
		_DATUMDATA datum;
		_DRIVERLESSVALUES driverless_values;
		_GROUPDATA_4 groupData;
		_SUBGROUPDATA_2 *subgroupData; // pointers in the raw path data to pf struct arrays
		_TESTDATA_2 *testData; // could use std::vector to dynamically size these if preferable
		_TRANSITIONDATA_2 *transData;
		_SEGMENTDATA_2 *segmentData;
		_SPLINEDATA_0 *splineData;
};

int32_t Trajectory::generate_trajectory_points_straight( float horizon_time, float horizon_distance, float point_separation, float min_dist, float longitudinal_velocity, float robot_x_pos, float robot_y_pos, float robot_z_pos, float robot_yaw )
{
	float distance = 0.0f;
	float time = 0.0f;
	int32_t point_counter = 0;
	points.clear();

	float x_inc = std::cos(robot_yaw);
	float y_inc = std::sin(robot_yaw);

	while (((distance < horizon_distance) && (time < horizon_time)) || (distance < min_dist))
	{
		TrajectoryPoint p;
		p.x_pos = robot_x_pos + x_inc * distance;
		p.y_pos = robot_y_pos + y_inc * distance;
		p.z_pos = robot_z_pos;
		p.yaw = robot_yaw;
		p.distance = distance;
		p.curvature = 0;
		p.longitudinal_velocity = longitudinal_velocity;

		time = distance / longitudinal_velocity;
		p.time = time;

		point_counter += 1;

		distance += point_separation;

		points.push_back( p );
	}

	return point_counter;
}

int32_t Trajectory::generate_trajectory_points_arc( float horizon_time, float horizon_distance, float point_separation, float min_dist, float longitudinal_velocity, float robot_x_pos, float robot_y_pos, float robot_z_pos, float robot_yaw, float robot_yaw_rate )
{
	float distance = 0.0f;
	float time = 0.0f;
	int32_t point_counter = 0;
	points.clear();

	if (longitudinal_velocity > min_velocity)  // velocity is in valid regime
	{
		float curvature = robot_yaw_rate / longitudinal_velocity;

		if ( std::abs(curvature) > 1e-3 )
		{
			float radius = 1.0f / curvature;

			while (((distance < horizon_distance) && (time < horizon_time)) || (distance < min_dist))
			{
				TrajectoryPoint p;
				float theta = distance * curvature;
				float temp_x = radius * std::sin(theta);
				float temp_y = radius * (1.0f - std::cos(theta));
				float initial_cos = std::cos(robot_yaw);
				float initial_sin = std::sin(robot_yaw);

				p.x_pos = robot_x_pos + (temp_x * initial_cos) - (temp_y * initial_sin);
				p.y_pos = robot_y_pos + (temp_x * initial_sin) + (temp_y * initial_cos);
				p.z_pos = robot_z_pos;
				p.yaw = robot_yaw + theta;
				p.distance = distance;
				p.curvature = curvature;
				p.longitudinal_velocity = longitudinal_velocity;

				time = distance / longitudinal_velocity;
				p.time = time;

				points.push_back( p );
				point_counter += 1;

				distance += point_separation;
			}
		}
		else  // degenerate to straight line case
		{
				point_counter = generate_trajectory_points_straight(horizon_time, horizon_distance,
																	point_separation, min_dist, longitudinal_velocity,
																	robot_x_pos, robot_y_pos, robot_z_pos, robot_yaw);
		}

	}
	else
	{
		point_counter = generate_trajectory_points_straight(horizon_time, horizon_distance,
															point_separation, min_dist, longitudinal_velocity,
															robot_x_pos, robot_y_pos, robot_z_pos, robot_yaw);
	}

	return point_counter;
}

int32_t Trajectory::generate_trajectory_points_path( float horizon_time, float horizon_distance, float min_dist, float robot_z_pos, float point_separation )
{
	RCLCPP_INFO( this->get_logger(), "Using path method");
	int numPoints = 0;

	num_chipolata = getSausage( horizon_distance * 1.1 );
	if ( num_chipolata > 0 )
	{
		numPoints = getPathPoints( num_chipolata, horizon_time, horizon_distance, min_dist, robot_z_pos, point_separation );
	}

	return numPoints;
}

int32_t Trajectory::getSausage( float sausageLength )
{
	if ( validPFphaseForPathCollisionChecking( testStat.mPfPhase ) == 0 )
	{
		return -1;
	}

	float distNow, maxDist;

	//-------------------------------------------------------------------------
	// Arrays for start of different branches

	int16_t idxArray[MAX_BRANCHES + 1] = { 0 };
	int onTestArray[MAX_BRANCHES + 1] = { 0 };
	float distNowArray[MAX_BRANCHES + 1] = { 0 };
	float cumDistArray[MAX_BRANCHES + 1] = { 0 };
	//float trigExitDistArray[MAX_BRANCHES + 1] = { 0 };

	//-------------------------------------------------------------------------
	// Get the nearest previous idx of the car
	int32_t lTestPhase = testStat.test_phase;
	int16_t testIdx = 0, transIdx = 0;
	float mPathDist = testStat.path_distance;
	int16_t currentPathExitIndex = testStat.current_path_exit_index;

	if (lTestPhase > 0)
	{
		onTestArray[0] = 1; // on test
		idxArray[0] = testStat.test_index; // Current idx of the test we're on
		testIdx = idxArray[0];
		maxDist = testData[testIdx].Length;
		distNowArray[0] = (mPathDist > maxDist) ? maxDist : mPathDist; // Current distance along this test
	}
	else if (lTestPhase == 0)
	{
		onTestArray[0] = 2; // on transition
		idxArray[0] = 0; // Current idx of the transition we're on
		transIdx = idxArray[0];
		maxDist = transData[transIdx].Length;
		distNowArray[0] = (transData[transIdx].Length + mPathDist - transData[transIdx].EntryPointDistance > maxDist) ? maxDist : transData[transIdx].Length + mPathDist - transData[transIdx].EntryPointDistance; // Current distance along this transition
		RCLCPP_INFO( this->get_logger(), "On lead in: distnow %f, transition length %f", distNowArray[0], transData[transIdx].Length );

		if ( distNowArray[0] < 0.0 )
			distNowArray[0] = 0.0;
	}
	else
	{
		onTestArray[0] = 2; // on transition
		idxArray[0] = -lTestPhase; // Current idx of the transition we're on
		transIdx = idxArray[0];
		maxDist = transData[transIdx].Length;
		distNowArray[0] = (transData[transIdx].Length + mPathDist - transData[transIdx].EntryPointDistance > maxDist) ? maxDist : transData[transIdx].Length + mPathDist - transData[transIdx].EntryPointDistance; // Current distance along this transition
	}
	cumDistArray[0] = 0.0f;

	int chipolata_cnt = 0;
	int triggeredBranchNumber = 0;
	int branchLevel;
	for (branchLevel = 0; branchLevel <= MAX_BRANCHES; ++branchLevel)
	{
		// Set up for this branch
		unsigned char onTest = onTestArray[branchLevel];
		if (onTest == 1) // test
		{
			testIdx = idxArray[branchLevel];
		}
		else if (onTest == 2) // transition
		{
			transIdx = idxArray[branchLevel];
		}
		else // not set
		{
			break;
		}

		float cumDist = cumDistArray[branchLevel];
		float maxDistRemaining;
		distNow = distNowArray[branchLevel];

		while (chipolata_cnt < MAX_CHIPOLATA)
		{
			if (onTest == 1) // Test phase is in the fast packet of the data broadcaster
			{ // Car is on a test path
				transIdx = testData[testIdx].NormalExitIndex;
				maxDist = testData[testIdx].Length;
				maxDistRemaining = testData[testIdx].Length - distNow;

				// Check whether we are before any triggered transitions
				int i;
				for (i = 0; i < testData[testIdx].nTriggeredExits; ++i) // for each triggered exit
				{
					if ((transData[testData[testIdx].FirstTriggeredExitIndex + i].ExitLocation > distNow) && // the triggered exit could occur in the future
						(transData[testData[testIdx].FirstTriggeredExitIndex + i].ExitLocation + cumDist - distNow) < sausageLength
					)
					{
						if (currentPathExitIndex != testData[testIdx].FirstTriggeredExitIndex + i) // If the currentTrigExitIdx is not set to this triggered exit then it will be a possible branch
						{
							triggeredBranchNumber += 1;
							if (triggeredBranchNumber <= MAX_BRANCHES)
							{
								onTestArray[triggeredBranchNumber] = 2; // transition
								distNowArray[triggeredBranchNumber] = 0;
								idxArray[triggeredBranchNumber] = testData[testIdx].FirstTriggeredExitIndex + i;
								cumDistArray[triggeredBranchNumber] = cumDist + (transData[testData[testIdx].FirstTriggeredExitIndex + i].ExitLocation - distNow);
							}
						}
						else
						{
							// Primary exit is now the triggered exit
							maxDist = transData[testData[testIdx].FirstTriggeredExitIndex + i].ExitLocation;
							maxDistRemaining = maxDist - distNow;
							transIdx = currentPathExitIndex;
						}
					}
				}

				if ( sausageLength > cumDist + maxDistRemaining) // sausage exceeds the end of this test
				{
					// Fill in the first chipolata data
					chipolata[chipolata_cnt].isTestOrTrans = 1; // is a test
					chipolata[chipolata_cnt].testOrTransId = testIdx;
					chipolata[chipolata_cnt].startDist = distNow;
					chipolata[chipolata_cnt].endDist = maxDist;
					chipolata[chipolata_cnt].branchLevel = branchLevel;
					chipolata[chipolata_cnt].cumDist = cumDist;
					++chipolata_cnt;

					// Get the next normal transition
					if (transIdx < 0) // end of test
					{
						break;
					}

					cumDist += maxDistRemaining;
					onTest = 2;
					distNow = 0;
				}
				else // Remainder of sausage is on this test
				{
					// Fill in the first chipolata data
					chipolata[chipolata_cnt].isTestOrTrans = 1; // is a test
					chipolata[chipolata_cnt].testOrTransId = testIdx;
					chipolata[chipolata_cnt].startDist = distNow;
					chipolata[chipolata_cnt].endDist = distNow + sausageLength - cumDist;
					chipolata[chipolata_cnt].branchLevel = branchLevel; // primary branch
					chipolata[chipolata_cnt].cumDist = cumDist;

					++chipolata_cnt;

					break;
				}
			}
			else if (onTest == 2)
			{ // Car is on a transition
				maxDist = transData[transIdx].Length;
				maxDistRemaining = maxDist - distNow;

				if (sausageLength > cumDist + maxDistRemaining)
				{
					// Fill in the first chipolata data
					chipolata[chipolata_cnt].isTestOrTrans = 2; // is a trans
					chipolata[chipolata_cnt].testOrTransId = transIdx;
					chipolata[chipolata_cnt].startDist = distNow;
					chipolata[chipolata_cnt].endDist = maxDist;
					chipolata[chipolata_cnt].branchLevel = branchLevel;
					chipolata[chipolata_cnt].cumDist = cumDist;

					++chipolata_cnt;

					// Get the next test
					cumDist += maxDistRemaining;

					onTest = 1;
					testIdx = transData[transIdx].DestinationTestIndex;
					distNow = transData[transIdx].EntryPointDistance;
				}
				else // Remainder of sausage is on this transition
				{
					// Fill in the first chipolata data
					chipolata[chipolata_cnt].isTestOrTrans = 2; // is a trans
					chipolata[chipolata_cnt].testOrTransId = transIdx;
					chipolata[chipolata_cnt].startDist = distNow;
					chipolata[chipolata_cnt].endDist = distNow + sausageLength - cumDist;
					chipolata[chipolata_cnt].branchLevel = branchLevel;
					chipolata[chipolata_cnt].cumDist = cumDist;

					++chipolata_cnt;

					break;
				}
			}
			else
			{
				RCLCPP_INFO( this->get_logger(), "Error! Unrecognised type.\n");
				break; // Unrecognised testOrTrans type
			}
		}
	}
	int numChipolata = chipolata_cnt;

	#ifdef DEBUG
	// Debug logging
	RCLCPP_INFO( this->get_logger(), "testPhase_lead_axle %d, testIdx_lead_axle %d, Num chipolata %d:, Length %f, Seg %d", testStat.test_phase, testStat.test_index, numChipolata, testData[0].Length, testData[0].nSegments );
	RCLCPP_INFO( this->get_logger(),  "Sausage data:" );
	for ( chipolata_cnt = 0; chipolata_cnt < numChipolata; ++chipolata_cnt )
	{
		RCLCPP_INFO( this->get_logger(),  "\t Chipolata %d: TestOrTrans %d, Id %d, StartDist %f, EndDist %f, CumDist %f, BranchLevel %d", chipolata_cnt, chipolata[chipolata_cnt].isTestOrTrans, chipolata[chipolata_cnt].testOrTransId, chipolata[chipolata_cnt].startDist, chipolata[chipolata_cnt].endDist, chipolata[chipolata_cnt].cumDist, chipolata[chipolata_cnt].branchLevel );
	}
	#endif

	return numChipolata;
}

int Trajectory::getPathPoints( int numChipolata, float timeHorizon, float distHorizon, float min_dist, float robot_z_pos, float dd )
{
	int chipolata_cnt;
	TrajectoryPoint p;
	points.clear();

	_COORDS here = {};

	float cumTime = 0; // cumulative time along this branch
	float cumDist = 0; // cumulative dist along this branch
	float distNow = 0; // distance on this chipolata
	float lastTimeOnPath = 0, dt;

	int numPoints = 0;

	int16_t path_point_error;
	float excess_distance = 0.0f;

	for ( chipolata_cnt = 0; chipolata_cnt < numChipolata; ++chipolata_cnt )
	{
		distNow = chipolata[chipolata_cnt].startDist + excess_distance;
		cumDist = chipolata[chipolata_cnt].cumDist + excess_distance;

		if ((cumDist > distHorizon) || (cumTime > timeHorizon))
		{
			break;
		}

		if ( chipolata[chipolata_cnt].branchLevel == 0 ) // primary branch
		{
			if ( chipolata[chipolata_cnt].isTestOrTrans == 1 ) // is test
			{
				path_point_error = testPoint_4( distNow, testData[chipolata[chipolata_cnt].testOrTransId], segmentData, splineData, &here );
				if (path_point_error < 0)
				{
					RCLCPP_INFO( this->get_logger(), "Path point error1: %f, %d!\n", distNow, path_point_error);
					return -1;
				}

				while (( distNow < chipolata[chipolata_cnt].endDist ) && ( cumDist < distHorizon ) && ( cumTime < timeHorizon ))
				{
					lastTimeOnPath = here.timeOnPath;
					path_point_error = testPoint_4( distNow, testData[chipolata[chipolata_cnt].testOrTransId], segmentData, splineData, &here );


					if (path_point_error < 0)
					{
						RCLCPP_INFO( this->get_logger(), "Path point error2: %d!\n", path_point_error);
						break;
					}

					p.x_pos = here.xPos;
					p.y_pos = here.yPos;
					p.z_pos = robot_z_pos;
					//p.longitudinal_velocity = distNow; // debug
					//p.longitude = here.longitude; // debug
					//p.latitude = here.latitude; //debug
					p.distance = cumDist;
					p.time = cumTime;

					distNow += dd;
					cumDist += dd;

					points.push_back( p );

					cumTime += here.timeOnPath - lastTimeOnPath;
				}

				excess_distance = (distNow - chipolata[chipolata_cnt].endDist);
				if (excess_distance < 0)
					excess_distance = 0;

			}
			else if ( chipolata[chipolata_cnt].isTestOrTrans == 2 ) // is trans
			{
				here = cubTransition_2( distNow, transData[chipolata[chipolata_cnt].testOrTransId], transData[chipolata[chipolata_cnt].testOrTransId].FirstValidX );
				lastTimeOnPath = here.timeOnPath;

				while (( distNow < chipolata[chipolata_cnt].endDist ) && ( cumDist < distHorizon ) && ( cumTime < timeHorizon ) )
				{
					here = cubTransition_2( distNow, transData[chipolata[chipolata_cnt].testOrTransId], transData[chipolata[chipolata_cnt].testOrTransId].FirstValidX );

					p.x_pos = here.xPos;
					p.y_pos = here.yPos;
					p.z_pos = robot_z_pos;
					//p.longitudinal_velocity = distNow; // debug
					//p.longitude = -99; // debug
					//p.latitude = here.timeOnPath; // debug
					p.distance = cumDist;
					p.time = cumTime;

					dt = here.timeOnPath - lastTimeOnPath;
					lastTimeOnPath = here.timeOnPath;

					distNow += dd;
					cumDist += dd;
					cumTime += dt;

					points.push_back( p );

				}

				excess_distance = (distNow - chipolata[chipolata_cnt].endDist);
				if (excess_distance < 0)
					excess_distance = 0;
			}
			else
			{
				RCLCPP_INFO( this->get_logger(), "Error! Unrecognised type." );
				break; // Unrecognised testOrTrans type
			}
		}
	}

	// Extrapolate over the end of the path
	if (cumDist < min_dist )
	{
		if (points.size() < 2)
		{
			numPoints = 0;
		}
		else // linear extrapolation of the last two points
		{
			float dx = points.rbegin()[0].x_pos - points.rbegin()[1].x_pos;
			float dy = points.rbegin()[0].y_pos - points.rbegin()[1].y_pos;
			float dt = points.rbegin()[0].time - points.rbegin()[1].time;
			do {
				p.x_pos += dx;
				p.y_pos += dy;
				p.z_pos = robot_z_pos;
				p.time += dt;

				cumDist += dd;

				p.distance = cumDist;

				points.push_back( p );

			} while (cumDist < min_dist);
		}
		numPoints = points.size();
	}
	else
	{
		numPoints = points.size();
	}

	return numPoints;
}


uint32_t Trajectory::downloadPathData( void )
{
	hasValidPath = 0;

	RCLCPP_INFO( this->get_logger(), "Downloading path data from Robot '%s'", ROBOT_IP);

	// Create socket
	int sTCP;
	if (( sTCP = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP ) ) < 0 )
	{
		RCLCPP_INFO( this->get_logger(), "Unable to create socket with reason: '%s'", strerror(errno) );
		return 0;
	}

	// dprem address
	struct sockaddr_in dprem_addr;
	int addrlen = sizeof(dprem_addr);
	dprem_addr.sin_family = AF_INET;
	dprem_addr.sin_port = htons(DPREM_PORT);
	inet_pton( AF_INET, ROBOT_IP, &dprem_addr.sin_addr.s_addr);

	// connect
	if ( connect( sTCP, (struct sockaddr *) &dprem_addr, addrlen) < 0 )
	{
		close(sTCP);
		RCLCPP_INFO( this->get_logger(), "Unable to connect socket with reason: '%s'", strerror(errno) );
		return 0;
	}

	// Get client endianness
	robot_client_endianness = checkPMAC_endianness( sTCP );
	if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__ )
	{
		RCLCPP_INFO( this->get_logger(), "Connected to little endian machine." );
	}
	else if ( robot_client_endianness == __ORDER_BIG_ENDIAN__ )
	{
		RCLCPP_INFO( this->get_logger(), "Connected to big endian machine." );
	}
	else
	{
		RCLCPP_INFO( this->get_logger(), "Unknown target endianness: return code %d", robot_client_endianness );
		return 0;
	}

	//--------------------------------------------------------------------------------------------------------------
	// Get the vehicle dimension data
	unsigned char server_reply[BUFFLEN];
	int recv_size;
	_VEHICLEDATA tempVehData;

	recv_size = requestDataFromPowerPMAC( sTCP, VEHICLE_DIMENSIONS_LOCATION, sizeof(_VEHICLEDATA), server_reply);
	if (recv_size != sizeof(_VEHICLEDATA))
	{
		RCLCPP_INFO( this->get_logger(), "Unexpected message length received." );
		close(sTCP);
		return 0;
	}
	else
	{
		memcpy( (void *)&tempVehData, &server_reply, recv_size);

		if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
		{
			vehicle_data = betoh_VehicleData( tempVehData );
		}
		else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
		{
			vehicle_data = letoh_VehicleData( tempVehData );
		}
		else // unknown endianness of the robot
		{
			RCLCPP_INFO( this->get_logger(), "Unknown target endianess." );
			close(sTCP);
			return 0;
		}
		vehicle_data.vehicle_dimension_type = VEH_DIM_ROBOT;
	}

	RCLCPP_INFO( this->get_logger(), "Length %f, Width %f", vehicle_data.pmVehicleLength, vehicle_data.pmVehicleWidth );

	//--------------------------------------------------------------------------------------------------------------
	// Get the datum data
	_DATUMDATA tempDatumData;
	recv_size = requestDataFromPowerPMAC( sTCP, DATUM_LOCATION, sizeof(_DATUMDATA), server_reply);
	if (recv_size != sizeof(_DATUMDATA))
	{
		RCLCPP_INFO( this->get_logger(), "Unexpected message length received." );
		close(sTCP);
		return 0;
	}
	else
	{
		memcpy( (void *)&tempDatumData, &server_reply, recv_size);

		if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
		{
			datum = betoh_DatumData( tempDatumData );
		}
		else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
		{
			datum = letoh_DatumData( tempDatumData );
		}
	}

	RCLCPP_INFO( this->get_logger(), "Datum data: latitude %f, longitude %f, bearing %f, ref height %f", (datum.pmLatitudeInt * 0.001) + datum.pmLatitudeFract, (datum.pmLongitudeInt * 0.001) + datum.pmLongitudeFract, datum.pmXaxisDatumBearing, datum.pmRefHeight );

	//--------------------------------------------------------------------------------------------------------------
	// Get the driverless values
	_DRIVERLESSVALUES tempDriverlessValues;
	recv_size = requestDataFromPowerPMAC( sTCP, DRIVERLESSVALUES_LOCATION, sizeof( _DRIVERLESSVALUES ), server_reply );
	if (recv_size != sizeof( _DRIVERLESSVALUES ))
	{
		RCLCPP_INFO( this->get_logger(), "Unexpected message length received." );
		close(sTCP);
		return 0;
	}
	else
	{
		memcpy( (void *)&tempDriverlessValues, &server_reply, recv_size );

		if (robot_client_endianness == __ORDER_BIG_ENDIAN__)
		{
			driverless_values = betoh_DriverlessValues( tempDriverlessValues );
		}
		else if (robot_client_endianness == __ORDER_LITTLE_ENDIAN__)
		{
			driverless_values = letoh_DriverlessValues( tempDriverlessValues );
		}
	}

	RCLCPP_INFO( this->get_logger(), "Driverless data: pmBrEmergencyDisp: %f, pmBrHoldForce: %f, pmBrEmergencyForce: %f, pmBrNormalDecel: %f, pmBrEmergencyDecel: %f, pmBaseStationTimeout: %u\n", driverless_values.pmBrEmergencyDisp, driverless_values.pmBrHoldForce, driverless_values.pmBrEmergencyForce, driverless_values.pmBrNormalDecel, driverless_values.pmBrEmergencyDecel, driverless_values.pmBaseStationTimeout );

	// If the test will involve path following, download the path data
	raw_path_data_size = 0;
	if ( testStat.pf_test_true )
	{
		//--------------------------------------------------------------------------------------------------------------
		// Start the correct path downloader for the right version
		int structureVersion = TARGET_PF_STRUCT_VERSION; // TODO get real pf structure version number from robot
		switch ( structureVersion )
		{
			case 0: // version 0 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			case 1: // version 1 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			case 2: // version 2 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			case 4: // version 4 paths
				raw_path_data_size = pathDownloaderFun_4( raw_path_data, sTCP, server_reply );
				break;

			case 5: // version 5 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			default:
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

		}
	}
	else
	{
		hasValidPath = 0;
	}

	close(sTCP);

	return 1;
}

uint32_t Trajectory::pathDownloaderFun_4( void * const path_data, int sock, unsigned char *server_reply )
{
	//--------------------------------------------------------------------------------------------------------------
	// Download the group data using the dprem
	_GROUPDATA_4 tempGroupData;
	uint32_t pathAddr = PATH_LOCATION;
	uint32_t num_bytes = 0;
	int recv_size = requestDataFromPowerPMAC( sock, pathAddr, sizeof( _GROUPDATA_4 ), server_reply);
	if (recv_size != sizeof( _GROUPDATA_4 ))
	{
		RCLCPP_INFO( this->get_logger(), "Unexpected message length received." );
		return 0;
	}
	else
	{
		pathAddr += sizeof( _GROUPDATA_4 );
		memcpy( (void *)&tempGroupData, server_reply, recv_size );

		if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
		{
			groupData = betoh_GroupData_4( tempGroupData );
		}
		else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
		{
			groupData = letoh_GroupData_4( tempGroupData );
		}

		num_bytes += sizeof( _GROUPDATA_4 );
	}

	RCLCPP_INFO( this->get_logger(), "Group data: nSubgroups %d, nTests %d, nTrans %d", groupData.nSubGroups, groupData.nTests, groupData.nTransitions );

	// guards on strange data
	if ( ( groupData.nSubGroups > 1024 ) || ( groupData.nTests > 1024 ) || ( groupData.nTransitions > 1024 ) || ( groupData.nTransitions < 0 ) )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------------------------------------
	// Download the subgroup data and copy into the shared memory segment
	int i;
	unsigned int shm_offset = 0;

	subgroupData = (_SUBGROUPDATA_2 *)((unsigned char *)path_data + shm_offset);
	_SUBGROUPDATA_2 tempSubGroupData;

	if ( ( shm_offset + ( (groupData.nSubGroups) * (sizeof(_SUBGROUPDATA_2)) ) ) > MAX_PATH_DATA_SIZE ) {
		RCLCPP_INFO( this->get_logger(), "Out of path memory." );
		return 0;
	}

	for ( i = 0; i < groupData.nSubGroups; ++i )
	{
		recv_size = requestDataFromPowerPMAC( sock, pathAddr, sizeof(_SUBGROUPDATA_2), server_reply);
		if (recv_size != sizeof(_SUBGROUPDATA_2))
		{
			RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Subgroup[%d]", i );
			return 0;
		}
		else
		{
			memcpy( (void *)&tempSubGroupData, server_reply, recv_size);

			if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
			{
				subgroupData[i] = betoh_SubGroupData_2( tempSubGroupData );
			}
			else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
			{
				subgroupData[i] = letoh_SubGroupData_2( tempSubGroupData );
			}
			pathAddr += sizeof(_SUBGROUPDATA_2);
			shm_offset += sizeof(_SUBGROUPDATA_2);
		}

		RCLCPP_INFO( this->get_logger(), "Subgroup data [%d]: nTests %d, relative_offset (%lf,%lf)", i, subgroupData[i].nTests, subgroupData[i].pathRelativeOffsetX, subgroupData[i].pathRelativeOffsetY );

	}

	//--------------------------------------------------------------------------------------------------------------
	// Next up is the test data

	pathDataContainsRelativePaths = 0;

	testData = (_TESTDATA_2 *)((unsigned char *)path_data + shm_offset);
	pathAddr = groupData.FirstTestOffset;
	_TESTDATA_2 temtestData;

	if ( ( shm_offset + ( (groupData.nTests + groupData.nReturnPaths) * (sizeof(_TESTDATA_2)) ) ) > MAX_PATH_DATA_SIZE ) {
		RCLCPP_INFO( this->get_logger(), "Out of path memory." );
		return 0;
	}

	for ( i = 0; i < groupData.nTests + groupData.nReturnPaths; ++i )
	{
		recv_size = requestDataFromPowerPMAC( sock, pathAddr, sizeof(_TESTDATA_2), server_reply);
		if (recv_size != sizeof(_TESTDATA_2))
		{
			RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Test[%d]", i );
			return 0;
		}
		else
		{
			memcpy( (void *)&temtestData, server_reply, recv_size);

			if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
			{
				testData[i] = betoh_TestData_2( temtestData );
			}
			else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
			{
				testData[i] = letoh_TestData_2( temtestData );
			}

			pathAddr += sizeof(_TESTDATA_2);
			shm_offset += sizeof(_TESTDATA_2);

			// Check if the test is a relative path
			if ( testData[i].Type == TEST_TYPE_RELATIVE )
			{
				pathDataContainsRelativePaths = 1;
			}
		}
		RCLCPP_INFO( this->get_logger(), "Test data [%d]: Length %lf, Transit %lf, nSegments %d", i, testData[i].Length, testData[i].TransitTime, testData[i].nSegments );
	}

	//--------------------------------------------------------------------------------------------------------------
	// Next comes the transition data
	transData = (_TRANSITIONDATA_2 *)((unsigned char *)path_data + shm_offset);
	pathAddr = groupData.FirstTransitionOffset;
	_TRANSITIONDATA_2 tempTransData;

	if ( ( shm_offset + ( (groupData.nTransitions) * (sizeof(_TRANSITIONDATA_2)) ) ) > MAX_PATH_DATA_SIZE ) {
		RCLCPP_INFO( this->get_logger(), "Out of path memory." );
		return 0;
	}

	for ( i = 0; i < groupData.nTransitions; ++i )
	{
		recv_size = requestDataFromPowerPMAC( sock, pathAddr, sizeof( _TRANSITIONDATA_2 ), server_reply);
		if (recv_size != sizeof( _TRANSITIONDATA_2 ))
		{
			RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Transition[%d]", i );
			return 0;
		}
		else
		{
			memcpy( (void *)&tempTransData, server_reply, recv_size);

			if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
			{
				transData[i] = betoh_TransitionData_2( tempTransData );
			}
			else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
			{
				transData[i] = letoh_TransitionData_2( tempTransData );
			}
			pathAddr += sizeof( _TRANSITIONDATA_2 );
			shm_offset += sizeof( _TRANSITIONDATA_2 );
		}

		RCLCPP_INFO( this->get_logger(), "Transition data [%d]: Length %f, Transit %f", i, transData[i].Length, transData[i].TransitTime );
	}

	//--------------------------------------------------------------------------------------------------------------
	// Now the segment data
	segmentData = ( _SEGMENTDATA_2 *)((unsigned char *)path_data + shm_offset);
	pathAddr = groupData.FirstSegmentOffset;

	int totalData = sizeof( _SEGMENTDATA_2 )*groupData.nSegments;
	int chunk = 1400; // Faster to keep it below the MTU?

	if ( ( shm_offset + totalData ) > MAX_PATH_DATA_SIZE ) {
		RCLCPP_INFO( this->get_logger(), "Out of path memory." );
		return 0;
	}

	while(totalData > chunk)
	{
		recv_size = requestDataFromPowerPMAC( sock, pathAddr, chunk, server_reply);
		if (recv_size < chunk)
		{
			RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Segments" );
			return 0;
		}
		else
		{
			memcpy( ((unsigned char *)path_data + shm_offset), server_reply, recv_size);
			shm_offset += chunk;
			pathAddr += chunk;
			totalData -= chunk;
		}
	}

	if (totalData > 0)
	{
		chunk = totalData;
		recv_size = requestDataFromPowerPMAC( sock, pathAddr, chunk, server_reply);
		if (recv_size < chunk)
		{
			RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Segments" );
			return 0;
		}
		else
		{
			memcpy( ((unsigned char *)path_data + shm_offset), server_reply, recv_size);
			shm_offset += chunk;
		}
	}

	if ( robot_client_endianness == __ORDER_BIG_ENDIAN__ )
	{
		for (i = 0; i < groupData.nSegments; ++i)
		{
			segmentData[i] = betoh_SegmentData_2(segmentData[i]);
			RCLCPP_INFO( this->get_logger(), "Segment data [%d]: Type %d, Length %f", i, segmentData[i].Type, segmentData[i].Length );
		}
	}
	else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__ )
	{
		for (i = 0; i < groupData.nSegments; ++i)
		{
			segmentData[i] = letoh_SegmentData_2(segmentData[i]);
			RCLCPP_INFO( this->get_logger(), "Segment data [%d]: Type %d, Length %f", i, segmentData[i].Type, segmentData[i].Length );
		}
	}
	// Note shuffling bytes in place, so don't access raw segment data if hasValidPath = 0

	//--------------------------------------------------------------------------------------------------------------
	// And the spline point data
	splineData = (_SPLINEDATA_0 *)((unsigned char *)path_data + shm_offset);
	pathAddr = groupData.FirstBSplineOffset;

	totalData = sizeof(_SPLINEDATA_0)*groupData.nBSpoints;
	chunk = 1400;

	if ( ( shm_offset + totalData ) > MAX_PATH_DATA_SIZE ) {
		RCLCPP_INFO( this->get_logger(), "Out of path memory." );
		return 0;
	}

	while(totalData > chunk)
	{
		recv_size = requestDataFromPowerPMAC( sock, pathAddr, chunk, server_reply);
		if (recv_size < chunk)
		{
			RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Segments" );
			return 0;
		}
		else
		{
			memcpy( ((unsigned char *)path_data + shm_offset), server_reply, recv_size);
			shm_offset += chunk;
			pathAddr += chunk;
			totalData -= chunk;
		}
	}

	if (totalData > 0)
	{
		chunk = totalData;
		recv_size = requestDataFromPowerPMAC( sock, pathAddr, chunk, server_reply);
		if (recv_size < chunk)
		{
			RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Segments" );
			return 0;
		}
		else
		{
			memcpy( ((unsigned char *)path_data + shm_offset), server_reply, recv_size);
			shm_offset += chunk;
		}
	}

	if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
	{
		for (i = 0; i < groupData.nBSpoints; ++i)
		{
			splineData[i] = betoh_SplineData_0(splineData[i]);
		}
	}
	else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
	{
		for (i = 0; i < groupData.nBSpoints; ++i)
		{
			splineData[i] = letoh_SplineData_0(splineData[i]);
		}
	}

	RCLCPP_INFO( this->get_logger(), "Spline points: Number %d", groupData.nBSpoints );
	// Note shuffling bytes in place, so don't access raw segment data if hasValidPath = 0

	//--------------------------------------------------------------------------------------------------------------
	// Set the flag to indicate path data has been downloaded successfully

	if (( groupData.nTests > 0 ) && (testData[0].Length > 0.1))
	{
		hasValidPath = 1;
	}

	num_bytes = shm_offset;
	RCLCPP_INFO( this->get_logger(), "Downloaded %d bytes of path data\n", num_bytes );

	return num_bytes;
}


uint32_t Trajectory::downloadLeadInData( void )
{
	RCLCPP_INFO( this->get_logger(), "Downloading leadin data from Robot '%s'", ROBOT_IP);
	if ( hasValidPath == 0 )
	{
		return 0;
	}

	// Create socket
	int sTCP;
	if (( sTCP = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP ) ) < 0 )
	{
		RCLCPP_INFO( this->get_logger(), "Unable to create socket with reason: '%s'", strerror(errno) );
		return 0;
	}

	// dprem address
	struct sockaddr_in dprem_addr;
	int addrlen = sizeof(dprem_addr);
	dprem_addr.sin_family = AF_INET;
	dprem_addr.sin_port = htons(DPREM_PORT);
	inet_pton( AF_INET, ROBOT_IP, &dprem_addr.sin_addr.s_addr);

	// connect
	if ( connect( sTCP, (struct sockaddr *) &dprem_addr, addrlen) < 0 )
	{
		close(sTCP);
		RCLCPP_INFO( this->get_logger(), "Unable to connect socket with reason: '%s'", strerror(errno) );
		return 0;
	}

	// Get client endianness
	robot_client_endianness = checkPMAC_endianness( sTCP );
	if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__ )
	{
		RCLCPP_INFO( this->get_logger(), "Connected to little endian machine." );
	}
	else if ( robot_client_endianness == __ORDER_BIG_ENDIAN__ )
	{
		RCLCPP_INFO( this->get_logger(), "Connected to big endian machine." );
	}
	else
	{
		RCLCPP_INFO( this->get_logger(), "Unknown target endianness: return code %d", robot_client_endianness );
		return 0;
	}

	unsigned char server_reply[BUFFLEN];

	if ( testStat.pf_test_true )
	{
		//--------------------------------------------------------------------------------------------------------------
		// Start the correct downloader for the version
		int structureVersion = TARGET_PF_STRUCT_VERSION; // TODO get real pf structure version number from robot
		switch ( structureVersion )
		{
			case 0: // version 0 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			case 1: // version 1 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			case 2: // version 2 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			case 4: // version 4 paths
				leadinDownloaderFun_2( sTCP, server_reply );
				break;

			case 5: // version 5 paths
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

			default:
				RCLCPP_INFO( this->get_logger(), "Unsupported pf structure version" );
				break;

		}
	}

	close(sTCP);

	return 1;
}


int Trajectory::leadinDownloaderFun_2( int sock, unsigned char *server_reply )
{
	//--------------------------------------------------------------------------------------------------------------
	// Download transition 0

	int pathAddr = groupData.FirstTransitionOffset;
	if ( pathAddr == 0 )
		return -1;


	_TRANSITIONDATA_2 tempTransData;

	int recv_size = requestDataFromPowerPMAC( sock, pathAddr, sizeof( _TRANSITIONDATA_2 ), server_reply);
	if (recv_size != sizeof( _TRANSITIONDATA_2 ))
	{
		RCLCPP_INFO( this->get_logger(), "Unexpected message length received. Lead in" );
		return -1;
	}
	else
	{
		memcpy( (void *)&tempTransData, server_reply, recv_size);

		if ( robot_client_endianness == __ORDER_BIG_ENDIAN__  )
		{
			transData[0] = betoh_TransitionData_2( tempTransData );
		}
		else if ( robot_client_endianness == __ORDER_LITTLE_ENDIAN__  )
		{
			transData[0] = letoh_TransitionData_2( tempTransData );
		}

		RCLCPP_INFO( this->get_logger(), "Lead in data: Length %f, Transit %f", transData[0].Length, transData[0].TransitTime );
	}

	return 1;
}

int main(int argc, char ** argv)
{

	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<Trajectory>());
	rclcpp::shutdown();

	return 0;
}
