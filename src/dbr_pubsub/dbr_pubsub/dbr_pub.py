# Node to publish Data broadcaster channels
# from time import sleep
import time
import rclpy

import math
import numpy as np
#from tf.transformations import quaternion_from_euler
# from geometry_msgs.msg import Pose
# from geometry_msgs.msg import Twist
# from geometry_msgs.msg import Accel

#from tutorial_interfaces.msg import MpStatus

from rc_interfaces.msg import ImuRc
from rc_interfaces.msg import RcStatus

# -*- coding: utf-8 -*-
"""Provides the DataBroadcasterReceiver class.

This allows a python program to setup and stream data from an
AB Dynamics robot system using the data broadcaster.
"""
import socket
import sys
from struct import unpack #This module performs conversions between Python values and C structs represented as Python bytes objects
from struct import pack
decode_data = {0: ('i', 4),  # int32
               1: ('I', 4),  # uint32
               2: ('q', 8),  # int64
               3: ('Q', 8),  # uint64
               4: ('f', 4),  # float
               5: ('d', 8),  # double
               6: ('b', 1),  # int8
               7: ('h', 2),  # int16
               8: ('B', 1),  # uint8
               9: ('H', 2)   # uint16
               }

# DATA_PACKET_HEADER_V5 = 'B>B>B>h>h>h>h>B>h'
DATA_PACKET_HEADER_V5 = '>BBBHHHBH'
TYPE_PACKET_HEADER_V5 = '>BBBxxxxx'
PACKET_VERSION = 2  # Version of the db packet structure
BUFFER_SIZE = 1024  # UDP receive buffer size

class DataBroadcasterReceiver:
    """Access class for data broadcaster system on AB Dynamics robots.

    This class will allow easy access to the robot data broadcaster
    system for AB Dynamics PowerPMAC robots.
    """

    def __init__(self, address, channel_file='', application_no=5,
                 port=2000, return_port=2000, timeout=5.0):
        """Create a data broadcaster stream object.

        Args:
            address (str): The ip address of the robot system
            channel_file (str, optional): A csv file describing the channel
            name with its group and index value. It can be exported from:
            RC Software -> Setup -> Data Capture & Export -> Data Capture ->
            Video Capture -> Export Format File. If none provided then all
            channels need to be added by group ID and channel ID Defaults to ''
            application_no (int, optional): Which application is connecting to
            the robot (should always be 5, unless told otherwise).
            Defaults to 5.
            port (int, optional): Port of data broadcaster system on the robot.
            Defaults to 2000.
            return_port (int, optional): Return data to this port number.
            Defaults to 2000.
            timeout (float, optional): Socket read time out.
            Defaults to 5.0 seconds.

        Raises:
            socket.error: if there is a problem with the socket
            file I/O exceptions: if there is a problem reading the channel
            file.

        Returns:
            RobotDataBroadcaster: object of class
        """
        # Port we will receive data at, we need to send this in a packet
        self.return_port = return_port

        # Address of robot and port of data broadcaster
        # (where we sent packets to)
        self.remote_endpoint = (address, port)

        self.started = False
        self.data_types = []
        self.application = application_no
        self.channel_dict = {}      # Contains all channels
        self.channels = []          # List of channels wanted for streaming
        self.freq = 10
        self.decode_format = ''

        # Create socket and bind to any IP Address (and the return port we
        # specify)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(("0.0.0.0", self.return_port))
        self.sock.settimeout(timeout)

        # Stop any previous data streams (if they were running before - perhaps
        # due to exception from previous session)
        self.stop_stream()

        # If channel file is supplied, then parse data
        if channel_file:
            with open(channel_file, 'r') as file_descriptor:
                self._parse_channel_file(file_descriptor)
    #pylint: enable=too-many-arguments

    def set_timeout(self, timeout):
        """Set the socket timeout in seconds."""
        self.sock.settimeout(timeout)

    def _parse_channel_file(self, file_descriptor):
        """Will parse a channel file (internal use only).

        A channel file can be obtained from RC Software.
        """
        found = False
        for line in file_descriptor:
            if found:
                data = line.split('\t')
                if (int(data[4]) != -1 and int(data[5]) != -1 and
                        data[0] != 'N/C'):
                    self.channel_dict[data[0]] = (data[1],
                                                  int(data[2]),
                                                  int(data[3]),
                                                  int(data[4]),
                                                  int(data[5]))
            if line.startswith("Description"):
                found = True

    def __del__(self):
        """Destructor will stop stream and close socket."""
        self.stop_stream()
        self.sock.shutdown(socket.SHUT_RDWR)
        self.sock.close()

    def get_available_channel_names(self):
        """Return list of channel names."""
        return self.channel_dict.keys()

    def get_channels(self):
        """Return the current list of channels added to this object."""
        return self.channels

    def add_channel(self, *args):
        """Add a channel to the data broadcaster stream.

        You can add using a string name (e.g. add_channel("SR Angle"))
        if you have supplied a channel list.

        or

        You can add a channel by the group ID and channel ID:
        add_channel(3, 2)
        """
        # If a single argument that is is a string is supplied,
        # then look up in dictionary
        if len(args) == 1 and isinstance(args[0], str):
            if not self.channel_dict:
                raise Exception('''Tried to add channel by name - but
                                no dictionary loaded''')
            name = args[0]
            if name not in self.channels:
                self.channels.append(name)
                if self.started:
                    self.start_stream(self.freq)
        elif len(args) == 2:  # else two integers are supplied
            group = args[0]
            channel = args[1]
            if (group, channel) not in self.channels:
                self.channels.append((group, channel))
                if self.started:
                    self.start_stream(self.freq)

    def add_channels(self, channel_list):
        """Add a list of channel names.

        Args:
            channel_list ([str or tuple of len >= 2]): A list of channels to
            add by string name or group ID and channel ID.
        """
        for channel in channel_list:
            if isinstance(channel, tuple):
                if len(channel) >= 2:
                    self.add_channel(*channel)
            elif isinstance(channel, str):
                self.add_channel(channel)

    def delete_channel(self, *args):
        """Delete a channel from your list of streamed variables.

        Raises:
            Exception: when you try to delete a channel that doesn't exist.
        """
        # If a single argument that is is a string is supplied, then look up
        # in dictionary
        if len(args) == 1 and isinstance(args[0], str):
            name = args[0]
            if name in self.channels:
                self.channels.remove(name)
                if self.started:
                    self.start_stream(self.freq)
        elif len(args) == 2:  # else two integers are supplied
            group = args[0]
            channel = args[1]
            if (group, channel) in self.channels:
                self.channels.remove((group, channel))
                if self.started:
                    self.start_stream(self.freq)

    def start_stream(self, freq=10):
        """Start data broadcaster stream.

        Args:
            freq (int, optional): Frequency for the robot to send the data.
            Defaults to 10 Hz.

        Raises:
            Exception: [description]
        """
        if self.started:
            self.stop_stream()
        self.freq = freq
        mutable_bytes = bytearray(b'')
        mutable_bytes.append(3)  # 3 is command to start a stream
        mutable_bytes.append(PACKET_VERSION)
        mutable_bytes.append(self.application)
        mutable_bytes.append(self.freq)
        mutable_bytes.append((len(self.channels)) >> 8 & 0xFF)
        mutable_bytes.append((len(self.channels)) & 0xFF)
        mutable_bytes.append((self.return_port >> 8) & 0xFF)
        mutable_bytes.append(self.return_port & 0xFF)
        for channel in self.channels:
            print(channel)
            if isinstance(channel, str):
                if channel in self.channel_dict.keys():
                    print(self.channel_dict[channel])
                    print("Group ID: ", self.channel_dict[channel][3])
                    print("Channel ID: ", self.channel_dict[channel][4])
                    mutable_bytes.append(self.channel_dict[channel][3])
                    mutable_bytes.append(self.channel_dict[channel][4])
            elif isinstance(channel, tuple):
                mutable_bytes.append(channel[0])
                mutable_bytes.append(channel[1])
        immutable_bytes = bytes(mutable_bytes)
        if self.sock.sendto(immutable_bytes, self.remote_endpoint) == 0:
            raise Exception('Problem sending data to: '
                            + self.remote_endpoint[0]
                            + ' is address correct?')

        # We expect the robot to send a first response back containing
        # value types
        data, _addr = self.sock.recvfrom(BUFFER_SIZE)
        header = data[:8]
        payload = data[8:]
        packet_type, version, app = unpack(TYPE_PACKET_HEADER_V5, header)
        if packet_type == 5:  # Data format packet
            self.decode_format = '>'#
            for i in range(len(payload)):
                data_type = int(payload[i])
                # print(data_type)
                if data_type in decode_data:
                    self.decode_format += decode_data[data_type][0]
                else:
                    raise Exception('Data type not defined: ' +
                                    str(data_type))
            print("Decode format: ", self.decode_format)
            self.started = True

    def stop_stream(self):
        """Stop stream - will work if started from previous session."""
        mutable_bytes = bytearray(b'')
        mutable_bytes.append(4)  # 4 is command to stop
        mutable_bytes.append(1)
        mutable_bytes.append(self.application)
        mutable_bytes.append(0)
        immutable_bytes = bytes(mutable_bytes)
        if self.sock.sendto(immutable_bytes, self.remote_endpoint) == 0:
            raise Exception('Problem sending data to: '
                            + self.remote_endpoint[0] + ' is address correct?')
        self.started = False


    def recv(self):
        """Receive and decode the packet data."""
        if self.started:
            # Get the data from the socket
            data, _addr = self.sock.recvfrom(BUFFER_SIZE)

            # Unpack the first byte to see if its the right packet type
            # print("Data: ", data)
            # print("Data length: ", len(data))
            # print("Format: ", self.decode_format)
            header = data[:12]
            payload = data[12:]
            unpacked_data = unpack(self.decode_format, payload)
            # print("unpacked_data: ", unpacked_data)

            packet_type = header[0]
            if packet_type == 1:
                # Unpack the whole data structure according to the data format
                # specifier
                # print("Decode format: ", self.decode_format)
                # print("Payload :", payload)
                data_output = unpack(self.decode_format, payload)

                # Convert to dict for easier access
                output = {}
                output['packet_type'] = header[0]
                output['version'] = header[1]
                output['app'] = header[2]
                output['vehicle_id'] = header[3]
                output['test_id'] = header[4]
                output['run_id'] = header[5]
                output['watermark'] = header[6]
                output['header_spare'] = header[7]

                if len(data_output)-8 != len(self.channels):
                    Exception('''The received channel data does not match the
                              length of our original request.''')

                # Now process the body
                for idx in range(len(unpacked_data)):
                    key = self.channels[idx]
                    value = data_output[idx]
                    units = ''
                    if isinstance(key, str):
                        units = self.channel_dict[key][1]
                    output[key] = (value, units)
                return output
        return {}

    def recv_print(self):
        """Receive and print output to terminal."""
        data = self.recv()
        for key in data:
            if isinstance(data[key], tuple) and len(data[key]) == 2:
                print(key + ' = ' + str(data[key][0]) + ' '
                      + data[key][1].decode("mbcs"))
            else:
                print(key + ' = ' + str(data[key]))
        return data


# def data_broadcaster_example(ip_address):
#     """Run an example showing how to use the data broadcaster."""
#     """Add a channel to the data broadcaster stream.
#     You can add using a string name (e.g. add_channel("SR Angle"))
#     if you have supplied a channel list.
#     or
#     You can add a channel by the group ID and channel ID:
#     add_channel(3, 2)
#     """
#     dbr = DataBroadcasterReceiver(ip_address, "channels.txt")
#     dbr.add_channel("SR Angle")
#     dbr.add_channel(2, 1)
#     dbr.start_stream(1)
#     count = 0
#     while True:
#         data_output = dbr.recv()
#         print(data_output)
#         count = count + 1
#         if count == 15:
#             dbr.delete_channel(1, 0)  # remove SR Angle by number
#         if count == 20:
#             dbr.add_channel(3, 4)
#         if count == 30:
#             return



def setupDataBroadcaster(robot_ip, frequency, dabc_app, dabc_port,channels):
   dbr = DataBroadcasterReceiver(robot_ip, application_no=dabc_app, port=dabc_port)
   for val in channels:
      dbr.add_channel(int(val[0]), int(val[1]))  # Triggers
   dbr.start_stream(frequency)
   num_triggers = len(channels)
   return dbr, channels, num_triggers


def getRobotData(dbr, channels):
   dataOutput = dbr.recv()
   triggerValues = []
   for channel in channels:
      triggerValues.append(dataOutput[channel])
   return triggerValues


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
    freq = 10

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



    dic_chan_status = { 'path_dist':(7,6) , 'test_index':(7,36), 'test_phase':(7,106), 'desire_speed':(6,102), 'pf_test_true':(7,102),'max_path_err_left':(7,114),'max_path_err_right':(7,115),
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
        rc_imu.name= "RC Robot"
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

        # print(data[dic_chan['pf_test_true']][0])
        # print(type(data[dic_chan['pf_test_true']][0]))
        # print(pack("B", data[dic_chan_status['pf_test_true']][0] ))
        # rc_imu.test_index    = data[dic_chan['test_index']][0]
        # rc_imu.test_phase    =data[dic_chan['test_phase']][0]
        # rc_imu.path_dist     =data[dic_chan['path_dist']][0]
        # rc_imu.desire_speed  =data[dic_chan['desire_speed']][0]
        # rc_imu.pf_test_true  =data[dic_chan['pf_test_true']][0]

        rc_status.test_index    =data[dic_chan_status['test_index']][0]
        rc_status.test_phase    =data[dic_chan_status['test_phase']][0]
        rc_status.path_dist     =data[dic_chan_status['path_dist']][0]
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
        rc_status.sr_mp_err_4   =data[dic_chan_status['test_phase']][0]
        rc_status.syn_temp_err_5 =data[dic_chan_status['syn_temp_err_5']][0]
        rc_status.dl_err_1       =data[dic_chan_status['dl_err_1']][0]
        rc_status.dl_err_2       =data[dic_chan_status['dl_err_2']][0]

        # pub_pose.publish(rc_pose)
        # pub_twist.publish(rc_twist)
        # pub_accel.publish(rc_accel)
        # pub_mp.publish(mp_status)
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
