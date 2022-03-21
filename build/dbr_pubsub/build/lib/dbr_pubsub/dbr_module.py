
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
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
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
