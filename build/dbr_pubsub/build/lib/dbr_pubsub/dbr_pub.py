# Node to publish Data broadcaster channels
# from time import sleep
import time
import rclpy

import math
import numpy as np

from rc_interfaces.msg import ImuRc
from rc_interfaces.msg import RcStatus
from dbr_pubsub.dbr_module import *


def quaternion_from_euler(roll, pitch, yaw):
  """
  Convert an Euler angle to a quaternion.

  Input
    :param roll: The roll (rotation around x-axis) angle in radians.
    :param pitch: The pitch (rotation around y-axis) angle in radians.
    :param yaw: The yaw (rotation around z-axis) angle in radians.

  Output
    :return qx, qy, qz, qw: The orientation in quaternion [x,y,z,w] format
  """
  qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
  qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
  qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
  qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)

  return (qx, qy, qz, qw)




def main(args=None):
    rclpy.init(args=args)

    node = rclpy.create_node('IMU_publisher')
    #publisher = node.create_publisher(Num, 'topic', 10)

    # pub_pose = node.create_publisher(Pose,'rc_pose', 10)
    # pub_twist = node.create_publisher(Twist,'rc_twist', 10)
    # pub_accel = node.create_publisher( Accel,'rc_accel',  10)
    # pub_mp = node.create_publisher(MpStatus,'mp_status',10)
    pub_imu =node.create_publisher(ImuRc,'rc_imu',10)
    pub_status =node.create_publisher(RcStatus,'rc_status',10)

    # rc_pose = Pose()
    # rc_twist = Twist()
    # rc_accel = Accel()
    # mp_status = MpStatus()
    rc_imu =ImuRc()
    rc_status = RcStatus()

    count=1 #loop counter

    ip_addr='195.0.1.1'
    app=5
    port=2000
    freq = 100

    roll_angle=0
    pitch_angle=0
    yaw_angle=0

    dic_chan={'x_pos':(5,0),'y_pos':(5,1),'z_pos':(5,2),'roll':(5,9),'pitch':(5,10),'yaw':(5,11),'x_vel':(5,3),
                'y_vel':(5,4),'z_vel':(5,5),'roll_vel':(5,12),'pitch_vel':(5,13),'yaw_vel':(5,14),'x_accel':(5,6),
                'y_accel':(5,7),'z_accel':(5,8),'yaw_accel':(5,17),'mp_time':(5,18),'mp_lat':(5,31),'mp_longt':(5,32),'mp_bearing':(5,33),
                'path_dist':(7,6) , 'test_index':(7,36), 'test_phase':(7,106), 'desire_speed':(6,102),'pf_test_true':(7,102)
             }
    channels = set()  # create a set for channels
    for x in dic_chan.values():
        channels.add(x)


    dic_chan_status = {  'mpf_phase':(7,13) ,'path_dist':(7,6) , 'test_index':(7,36), 'test_phase':(7,106), 'desire_speed':(6,102), 'pf_test_true':(7,102),'max_path_err_left':(7,114),'max_path_err_right':(7,115),
            "current_path_exit_index":(7,107),'dl_status_1':(99,0),'dl_status_2':(99,1),'dl_test_procedure_state':(99,2),'test_in_progress':(98,2),"ar_control_mode":(6,8),
            "mp_status":(5,28),"g_sr_err_1":(98,11),"br_ar_err_2":(98,12),"cr_gr_err_3":(98,13),"sr_mp_err_4":(98,14),"syn_temp_err_5":(98,15),
            "dl_err_1":(98,23),"dl_err_2":(98,24) }

    for x in dic_chan_status.values():
        channels.add(x)
    ##Set the IP address and Frequency at which the data needs to be transmitted
    dbr, channels, num_triggers= setupDataBroadcaster(ip_addr, freq, app, port,channels)

    print("The transmiting messages at: {}hz".format(freq))
    #rate = rospy.Rate(30) #set the max rate at which the while loop needs to publish data

    while rclpy.ok():
        #data= getRobotData(dbr, channels)
        data= dbr.recv()

        roll_angle  =data[dic_chan['roll']][0]
        pitch_angle =data[dic_chan['pitch']][0]
        yaw_angle   =data[dic_chan['yaw']][0]

        qx, qy, qz, qw= quaternion_from_euler( math.radians(roll_angle), math.radians(pitch_angle), math.radians(yaw_angle) )

        #print(data)
        rc_imu.header.frame_id= "mp_frame"
        rc_imu.header.stamp = node.get_clock().now().to_msg()
        rc_imu.msg_count = count
        #print(data[dic_chan['mp_time']][0])
        rc_imu.mp_time =data[dic_chan['mp_time']][0]
        rc_imu.mp_lat  =data[dic_chan['mp_lat']][0]
        rc_imu.mp_longt=data[dic_chan['mp_longt']][0]
        rc_imu.mp_bearing =data[dic_chan['mp_bearing']][0]
        rc_imu.yaw_angle =data[dic_chan['yaw']][0]

        rc_imu.pose.position.x = data[dic_chan['x_pos']][0]
        rc_imu.pose.position.y = data[dic_chan['y_pos']][0]
        rc_imu.pose.position.z = data[dic_chan['z_pos']][0]
        rc_imu.pose.orientation.x = qx
        rc_imu.pose.orientation.y = qy
        rc_imu.pose.orientation.z = qz
        rc_imu.pose.orientation.w = qw

        rc_imu.twist.linear.x = data[dic_chan['x_vel']][0]
        rc_imu.twist.linear.y =data[dic_chan['y_vel']][0]
        rc_imu.twist.linear.z =data[dic_chan['z_vel']][0]

        rc_imu.twist.angular.x =data[dic_chan['roll_vel']][0]
        rc_imu.twist.angular.y =data[dic_chan['pitch_vel']][0]
        rc_imu.twist.angular.z =data[dic_chan['yaw_vel']][0]

        rc_imu.accel.linear.x =data[dic_chan['x_accel']][0]
        rc_imu.accel.linear.y =data[dic_chan['y_accel']][0]
        rc_imu.accel.linear.z =data[dic_chan['z_accel']][0]

        rc_imu.accel.angular.z =data[dic_chan['yaw_accel']][0]


        rc_status.header.frame_id= "mp_frame"
        rc_status.header.stamp = node.get_clock().now().to_msg()
        rc_status.test_index    =data[dic_chan_status['test_index']][0]
        rc_status.test_phase    =data[dic_chan_status['test_phase']][0]
        rc_status.path_dist     =data[dic_chan_status['path_dist']][0]
        rc_status.mpf_phase     =data[dic_chan_status['mpf_phase']][0]
        rc_status.desire_speed  =data[dic_chan_status['desire_speed']][0]
        rc_status.pf_test_true  =pack("B", data[dic_chan_status['pf_test_true']][0] )
        rc_status.max_path_err_left =data[dic_chan_status['max_path_err_left']][0]
        rc_status.max_path_err_right=data[dic_chan_status['max_path_err_right']][0]
        rc_status.current_path_exit_index=data[dic_chan_status['current_path_exit_index']][0]
        rc_status.dl_status_1       =pack("B", data[dic_chan_status['dl_status_1']][0] )
        rc_status.dl_status_2       =pack("B", data[dic_chan_status['dl_status_2']][0] )
        rc_status.dl_test_procedure_state=pack("B", data[dic_chan_status['dl_test_procedure_state']][0])
        rc_status.test_in_progress  =pack("B", data[dic_chan_status['test_in_progress']][0])
        rc_status.ar_control_mode   =data[dic_chan_status['ar_control_mode']][0]
        rc_status.mp_status     =data[dic_chan_status['mp_status']][0]
        rc_status.g_sr_err_1    =data[dic_chan_status['g_sr_err_1']][0]
        rc_status.br_ar_err_2   =data[dic_chan_status['br_ar_err_2']][0]
        rc_status.cr_gr_err_3   =data[dic_chan_status['cr_gr_err_3']][0]
        rc_status.sr_mp_err_4   =data[dic_chan_status['sr_mp_err_4']][0]
        rc_status.syn_temp_err_5 =data[dic_chan_status['syn_temp_err_5']][0]
        rc_status.dl_err_1       =data[dic_chan_status['dl_err_1']][0]
        rc_status.dl_err_2       =data[dic_chan_status['dl_err_2']][0]


        pub_imu.publish(rc_imu)

        pub_status.publish(rc_status)

        print("publishing message number:",count)
        count+=1

        # rate.sleep()

        # node.get_logger().info('Publishing: "%d"' % )
        #sleep(0.5)  # seconds

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
