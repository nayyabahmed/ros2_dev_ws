#ifndef __TRAJ_DEFINES_H__
#define __TRAJ_DEFINES_H__


#define IMU_TIME_HORIZON_S 5.0
#define IMU_DISTANCE_HORIZON_M 100.0

#define TIME_HORIZON_S 10.0
#define DISTANCE_HORIZON_M 200.0
#define DISTANCE_MINIMUM_M 20.0
#define POINT_SEPARATION_M 0.5
#define MIN_VELOCITY_M_S 0.1

#define MAX_PATH_DATA_SIZE 1024*1024*4 // 4MB max path data

#define ROBOT_IP "10.0.28.1"
#define DPREM_PORT 12264
#define TARGET_PF_STRUCT_VERSION 4 // pf structure version number of the target machine

#define BUFFLEN 8192

#define MAX_NUM_PATH_POINTS 200 // maximum number of path points in the trajectory
#define MAX_BRANCHES 2 // maximum number of branching paths to interrogate
#define MAX_CHIPOLATA 24 // maximum number of chipolatas in the sausage string

#define SAMPLE_FREQ 10.0 // Frequency we get IMU data at (Hz)
#define CUTOFF_FREQ 0.5 // Cutoff frequency for low pass filter (Hz)


#endif
