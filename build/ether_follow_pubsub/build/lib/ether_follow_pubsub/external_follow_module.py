# -*- coding: utf-8 -*-
"""Provides a class for robot external following via Ethernet.

This allows a python program to send actuator commands for steering, brake,
 accelerator and gears. These will be acted upon if the robot is configured for
 External Following via Ethernet.
"""
# For class
import ctypes
import socket

# For test
from threading import Event
from math import sin, pi
import sys

ETHFOLLOW_PACKET_VERSION = 2
ETHFOLLOW_PACKET_SIZE = 48

# Disable these messages for pylint due to ctypes
# pylint: disable=too-few-public-methods
# pylint: disable=too-many-instance-attributes

class ExtFollowingPacket(ctypes.LittleEndianStructure):
    """The accepted C structure for ethernet external following.

    C Equivalent:
        typedef struct EthCommandData
        {
            unsigned char Version;
            unsigned char Spare1;
            unsigned short Spare2;
            unsigned int MessageNo;
            double SteeringCommand;
            double BrakeCommand;
            double AccelCommand;
            unsigned short ExternalComms;
            unsigned short Triggering;
            unsigned int Spare3;
            unsigned char Watchdog;
            signed char GearCommand;
            unsigned short Spare5;
            unsigned int Spare6;
        }
    """

    _pack_ = 4
    _fields_ = [('version', ctypes.c_ubyte),
                ('spare1', ctypes.c_ubyte),
                ('spare2', ctypes.c_ushort),
                ('message_no', ctypes.c_uint),
                ('steer_command', ctypes.c_double),
                ('brake_command', ctypes.c_double),
                ('accel_command', ctypes.c_double),
                ('external_comms', ctypes.c_ushort),
                ('triggers', ctypes.c_ushort),
                ('spare3', ctypes.c_uint),
                ('watchdog', ctypes.c_ubyte),
                ('gear_command', ctypes.c_byte),
                ('spare5', ctypes.c_ushort),
                ('spare6', ctypes.c_uint)]

# pylint: enable=too-few-public-methods
# pylint: enable=too-many-instance-attributes

class EfException(Exception):
    """Exception for the ExternalFollowing class."""

# Gear numbers constants
TEST_DEFAULT = -1
AUTO_SELECT = 0
M1 = 1
M2 = 2
M3 = 3
M4 = 4
M5 = 5
M6 = 6
M7 = 7
M8 = 8
PARK = 9
REVERSE = 12
NEUTRAL = 14
DRIVE = 16
SPORT = 18
SEQUENTIAL_AUTO_SELECT = 20

class ExternalFollowing:
    """Class to send ethernet following commands to an AB Dynamics robot."""

    def __init__(self, ip_address, port=8000, timeout=10.0, message_no=0):
        """Initialise object and create socket for robot communication.

        Args:
            ip_address (string): IP address of robot
            port (int, optional): The port for communication. Defaults to 8000.
            timeout (float, optional): A timeout for sending. Defaults to 1.0.
            message_no (int, optional): The message count number - if the app
                has previously been operating then this should be set to the
                last used value. Defaults to 0.

        Raises:
            REFexception: if the packed structure size does not match a fixed
                        known size that is expected at the robot.
            socket.error: on socket exception
        """
        # Check packet structure size is correct
        if ctypes.sizeof(ExtFollowingPacket) != ETHFOLLOW_PACKET_SIZE:
            msg = 'Packed structure size is wrong, needed {} but got{} bytes'.format(
                ETHFOLLOW_PACKET_SIZE, ctypes.sizeof(ExtFollowingPacket))
            raise EfException(msg)

        # Create a UDP socket
        self._sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self._sock.settimeout(timeout)

        # Set object members
        self.remote_endpoint = (ip_address, port)
        self.message_no = message_no

    def __del__(self):
        """Destructor will close socket properly."""
        self._sock.close()

    # pylint: disable=too-many-arguments
    def send(self, steer=0.0, brake=0.0, throttle=0.0, gear=AUTO_SELECT,
             start_test=False, triggers=None):
        """Send an ethernet following command into the robot.

        Args:
            steer (float): steer command - units of [deg] or [Nm]
            brake (float): brake command - units of [mm], [m/s^2], [N], [EU]
            throttle (float): throttle command - units of [%], [m/s]
            gear (int):
                    Manual or Sequential Gearbox
                     -1 = Test default
                      0 = Change gear automatically based on speed.
                    1-X = Manual Gear - 1st to Top Gear
                     12 = Reverse
                     14 = Neutral
                    Automatic Gearbox:
                     -1 = Test default
                      0 = Change gear automatically based on speed.
                    1-8 = Sequential Manual Gear 1-8 
                      9 = Park
                     12 = Reverse
                     14 = Neutral
                     16 = Drive
                     18 = Sport
                     20 = Sequential Manual - Change gear automatically
                        based on speed.
            start_test (bool): if true will trigger the test to start
            triggers (list): list of trigger indices to be set to true (e.g.)
        """
        self.message_no += 1

        # Create and populate c structure
        efp = ExtFollowingPacket()

        # pylint: disable=attribute-defined-outside-init
        efp.version = ETHFOLLOW_PACKET_VERSION
        efp.spare1 = 0           # Not used
        efp.spare2 = 0           # Not used
        efp.message_no = self.message_no
        efp.steer_command = steer
        efp.brake_command = brake
        efp.accel_command = throttle
        efp.external_comms = 0   # Not used
        efp.triggers = 0
        if start_test:
            efp.triggers = 1
        if triggers:
            for val in triggers:
                if 0 < val < 16:
                    efp.triggers |= (1 << val)

        efp.spare3 = 0           # Not used
        efp.watchdog = 127       # Can be anything other than 255
        efp.gear_command = gear
        efp.spare5 = 0           # Not used
        efp.spare6 = 0           # Not used
        # pylint: enable=attribute-defined-outside-init

        # Send packet to the robot
        self._sock.sendto(bytes(efp), self.remote_endpoint)
        print("message number:{} sent to:{}, of length:{}".format(self.message_no,self.remote_endpoint, len(bytes(efp)) ) )
        # pylint: enable=too-many-arguments

def test_robot_external_following(ip_address):
    """Simple test function."""
    ref = ExternalFollowing(ip_address)

    i = 0
    wait_for = 0.01 # seconds

    ticker = Event()
    triggers = [3, 5, 6, 14, 15]
    while not ticker.wait(wait_for):
        i += 1
        steer = sin(i/(pi))*180.0
        throttle = (i % 100)/10
        brake = (i % 100)/10
        start = False

        ref.send(steer=steer,
                 throttle=throttle,
                 brake=brake,
                 gear=DRIVE,
                 start_test=start,
                 triggers=triggers)
