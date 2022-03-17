# Node to publish Data broadcaster channels
# from time import sleep
import time
import rclpy
from rclpy.node import Node

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




class ImuPub(Node):
    def __init__(self):
        super().__init__('IMU_publisher')

        self.pub_imu_ = self.create_publisher(ImuRc,'rc_imu',10)
        self.pub_status_ =self.create_publisher(RcStatus,'rc_status',10)

        self.declare_parameter('ip_address')
        self.declare_parameter('frequency')
        self.declare_parameter('port')

        self.count = 1
        self.ip_addr= self.get_parameter('ip_address').get_parameter_value().string_value
        self.app=5
        self.port= self.get_parameter('port').value
        self.freq = self.get_parameter('frequency').value

        timer_period =int(1/self.freq)
        self.timer =self.create_timer(timer_period, self.timer_call)

        self.roll_angle=0
        self.pitch_angle=0
        self.yaw_angle=0

        self.dbr =0
        self.rc_imu =ImuRc()
        self.rc_status = RcStatus()
        self.dic_chan={}
        self.dic_chan_status={}

    def dbr_gen(self):
        self.dic_chan={'x_pos':(5,0),'y_pos':(5,1),'z_pos':(5,2),'roll':(5,9),'pitch':(5,10),'yaw':(5,11),'x_vel':(5,3),
                    'y_vel':(5,4),'z_vel':(5,5),'roll_vel':(5,12),'pitch_vel':(5,13),'yaw_vel':(5,14),'x_accel':(5,6),
                    'y_accel':(5,7),'z_accel':(5,8),'yaw_accel':(5,17),'mp_time':(5,18),'mp_lat':(5,31),'mp_longt':(5,32),'mp_bearing':(5,33),
                    'path_dist':(7,6) , 'test_index':(7,36), 'test_phase':(7,106), 'desire_speed':(6,102),'pf_test_true':(7,102)
                 }
        channels = set()  # create a set for channels
        for x in self.dic_chan.values():
            channels.add(x)


        self.dic_chan_status = {  'mpf_phase':(7,13) ,'path_dist':(7,6) , 'test_index':(7,36), 'test_phase':(7,106), 'desire_speed':(6,102), 'pf_test_true':(7,102),'max_path_err_left':(7,114),'max_path_err_right':(7,115),
                "current_path_exit_index":(7,107),'dl_test_data_loaded':(99,9),'dl_status_1':(99,0),'dl_status_2':(99,1),'dl_test_procedure_state':(99,2),'test_in_progress':(98,2),"ar_control_mode":(6,8),
                "mp_status":(5,28),"g_sr_err_1":(98,11),"br_ar_err_2":(98,12),"cr_gr_err_3":(98,13),"sr_mp_err_4":(98,14),"syn_temp_err_5":(98,15),
                "dl_err_1":(98,23),"dl_err_2":(98,24) }

        for x in self.dic_chan_status.values():
            channels.add(x)

        self.dbr, channels, num_triggers= setupDataBroadcaster(self.ip_addr,self.freq, self.app, self.port,channels)
        print("Transmitting at frequency:{} from IP address:{}".format(self.freq, self.ip_addr))

    def data_update(self):
        data= self.dbr.recv()

        self.roll_angle  =data[self.dic_chan['roll']][0]
        self.pitch_angle =data[self.dic_chan['pitch']][0]
        self.yaw_angle   =data[self.dic_chan['yaw']][0]

        qx, qy, qz, qw= quaternion_from_euler( math.radians(self.roll_angle), math.radians(self.pitch_angle), math.radians(self.yaw_angle) )

        #print(data)
        self.rc_imu.header.frame_id= "mp_frame"
        self.rc_imu.header.stamp = self.get_clock().now().to_msg()
        self.rc_imu.msg_count = self.count
        #print(data[dic_chan['mp_time']][0])
        self.rc_imu.mp_time =data[self.dic_chan['mp_time']][0]
        self.rc_imu.mp_lat  =data[self.dic_chan['mp_lat']][0]
        self.rc_imu.mp_longt=data[self.dic_chan['mp_longt']][0]
        self.rc_imu.mp_bearing =data[self.dic_chan['mp_bearing']][0]
        self.rc_imu.yaw_angle =data[self.dic_chan['yaw']][0]

        self.rc_imu.pose.position.x = data[self.dic_chan['x_pos']][0]
        self.rc_imu.pose.position.y = data[self.dic_chan['y_pos']][0]
        self.rc_imu.pose.position.z = data[self.dic_chan['z_pos']][0]
        self.rc_imu.pose.orientation.x = qx
        self.rc_imu.pose.orientation.y = qy
        self.rc_imu.pose.orientation.z = qz
        self.rc_imu.pose.orientation.w = qw

        self.rc_imu.twist.linear.x = data[self.dic_chan['x_vel']][0]
        self.rc_imu.twist.linear.y =data[self.dic_chan['y_vel']][0]
        self.rc_imu.twist.linear.z =data[self.dic_chan['z_vel']][0]

        self.rc_imu.twist.angular.x =data[self.dic_chan['roll_vel']][0]
        self.rc_imu.twist.angular.y =data[self.dic_chan['pitch_vel']][0]
        self.rc_imu.twist.angular.z =data[self.dic_chan['yaw_vel']][0]

        self.rc_imu.accel.linear.x =data[self.dic_chan['x_accel']][0]
        self.rc_imu.accel.linear.y =data[self.dic_chan['y_accel']][0]
        self.rc_imu.accel.linear.z =data[self.dic_chan['z_accel']][0]

        self.rc_imu.accel.angular.z =data[self.dic_chan['yaw_accel']][0]


        self.rc_status.header.frame_id= "mp_frame"
        self.rc_status.header.stamp = self.get_clock().now().to_msg()
        self.rc_status.test_index    =data[self.dic_chan_status['test_index']][0]
        self.rc_status.test_phase    =data[self.dic_chan_status['test_phase']][0]
        self.rc_status.path_dist     =data[self.dic_chan_status['path_dist']][0]
        self.rc_status.mpf_phase     =data[self.dic_chan_status['mpf_phase']][0]
        self.rc_status.desire_speed  =data[self.dic_chan_status['desire_speed']][0]
        self.rc_status.pf_test_true  =pack("B", data[self.dic_chan_status['pf_test_true']][0] )
        self.rc_status.max_path_err_left =data[self.dic_chan_status['max_path_err_left']][0]
        self.rc_status.max_path_err_right=data[self.dic_chan_status['max_path_err_right']][0]
        self.rc_status.current_path_exit_index=data[self.dic_chan_status['current_path_exit_index']][0]
        self.rc_status.dl_status_1       =pack("B", data[self.dic_chan_status['dl_status_1']][0] )
        self.rc_status.dl_status_2       =pack("B", data[self.dic_chan_status['dl_status_2']][0] )
        self.rc_status.dl_test_procedure_state=pack("B", data[self.dic_chan_status['dl_test_procedure_state']][0])
        self.rc_status.test_in_progress  =pack("B", data[self.dic_chan_status['test_in_progress']][0])
        self.rc_status.ar_control_mode   =data[self.dic_chan_status['ar_control_mode']][0]
        self.rc_status.mp_status     =data[self.dic_chan_status['mp_status']][0]
        self.rc_status.g_sr_err_1    =data[self.dic_chan_status['g_sr_err_1']][0]
        self.rc_status.br_ar_err_2   =data[self.dic_chan_status['br_ar_err_2']][0]
        self.rc_status.cr_gr_err_3   =data[self.dic_chan_status['cr_gr_err_3']][0]
        self.rc_status.sr_mp_err_4   =data[self.dic_chan_status['sr_mp_err_4']][0]
        self.rc_status.syn_temp_err_5 =data[self.dic_chan_status['syn_temp_err_5']][0]
        self.rc_status.dl_err_1       =data[self.dic_chan_status['dl_err_1']][0]
        self.rc_status.dl_err_2       =data[self.dic_chan_status['dl_err_2']][0]
        self.dl_test_data_loaded       =data[self.dic_chan_status['dl_test_data_loaded']][0]

    def timer_call(self):
        self.data_update()

        self.pub_imu_.publish(self.rc_imu)
        self.pub_status_.publish(self.rc_status)
        self.get_logger().info("Publishing at frequency:%d message number: %d " %(self.freq, self.count) )
        #print("Publishing message number:",self.count)
        self.count+=1


def main(args=None):
    rclpy.init(args=args)
    node = ImuPub()
    node.dbr_gen()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
