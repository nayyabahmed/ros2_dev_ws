# -*- coding: utf-8 -*-

import rclpy
from std_msgs.msg import String
from std_msgs.msg import Float32
#from abds_core_common.msg import VehicleCommand
g_node = None
# -*- coding: utf-8 -*-
"""Provides a class for communicating with the robot using the dpremulator background app."""
import ctypes
import socket
import struct
import sys
import re
from collections import OrderedDict

try:
    import socketserver
except:
    # For Python 2
    import SocketServer as socketserver


#TODO: Test with arm based CPUs with little endiannes
#TODO: Handle interlaced array (ie array with length < 32 bits)

# pylint: disable=attribute-defined-outside-init

DPR_PORT = 12264

DPR_UPLOAD = 0xC0
DPR_GET_MEM = 0xB4
DPR_SET_MEM = 0xB5
DPR_GET_VAR = 0xBE
DPR_SET_VAR = 0xBD
DPR_GET_REPONSE = 0xBF

class DPRheader(ctypes.BigEndianStructure):
    """Header structure for Robot DPR."""

    _pack_ = 1
    _fields_ = [('request_type', ctypes.c_ubyte),
                ('request', ctypes.c_ubyte),
                ('value', ctypes.c_uint),
                ('index', ctypes.c_ushort),
                ('length', ctypes.c_uint)]

class DPRserverHandlerBase(socketserver.BaseRequestHandler):
    """Base request handler for DPR Socket Server.

    Inherit from this class and overload get/set functions.
    """

    def handle(self):
        """Will handle incomming requests and dispatch to required function."""
        header = self.request.recv(ctypes.sizeof(DPRheader))
        header = DPRheader.from_buffer_copy(header)
        payload = self.request.recv(header.length)
        print(header.request_type)
        print(header.request)
        print(header.value)
        print(header.length)
        if header.request_type == DPR_UPLOAD:
            if header.request == DPR_GET_MEM:
                print('here')
                value = self.get_mem(header.value, header.length)
                self.request.sendall(value)
            elif header.request == DPR_SET_MEM:
                if self.set_mem(header.value, payload):
                    # Success
                    return_data = struct.pack('B', 0x06)
                    print(return_data)
                    print(len(return_data))
                    self.request.sendall(return_data)
                else:
                    # Failure
                    self.request.sendall(struct.pack('B', 0x00))
            elif header.request == DPR_GET_VAR:
                name = struct.unpack('s', payload)
                value = self.get_var(name)
                if value is not None:
                    # Success
                    self.request.sendall(struct.pack('d', value))
                else:
                    # Failure
                    self.request.sendall(struct.pack('B', 0))
            elif header.request == DPR_SET_VAR:
                value, name = struct.unpack('ds', payload)
                if self.set_var(name, value):
                    # Success
                    self.request.sendall(struct.pack('B', 0x06))
                else:
                    # Failure
                    self.request.sendall(struct.pack('B', 0x00))
            elif header.request == DPR_GET_REPONSE:
                command = struct.unpack('s', payload)
                response = self.get_response(command)
                self.request.sendall(struct.pack('s', response))

    def set_mem(self, address, payload):
        """Set mem request stub, override this function.

        Args:
            address (int): memory address offset
            payload (bytes): the payload of bytes
        Returns:
            bool: True if success, False if failure
        """
        print(self.client_address[0] +  " set mem: " + str(address) + ' ' + str(len(payload)))
        return True

    def get_mem(self, address, length):
        """Get mem request stub, override this function.

        Args:
            address (int): memory address offset
            length (int): length in bytes

        Returns:
            bytes: bytes object of memory of length
        """
        print(self.client_address[0] +  " get mem: " + str(address) + ' ' + str(length))
        return b'\0' * length

    def get_var(self, name):
        """Get a variable by string name and return as float.

        Args:
            name (str): name

        Returns:
            float: variable value as float
        """
        print(self.client_address[0] +  " get var: " + name)
        return 0.0

    def set_var(self, name, value):
        """Set a variable by string name and float.

        Args:
            name (str): Name of variable
            value (float): Value of variable

        Returns:
            bool: True if success, False if failure
        """
        print(self.client_address[0] +  " set var: " + name + '=' + str(value))
        return True

    def get_response(self, command):
        """Send a command and get a response.

        Args:
            command (str): The command string

        Returns:
            str: The response of the command as a string
        """
        print(self.client_address[0] +  " get response: " + command)
        return 'A response'


class DPRserver(socketserver.TCPServer):
    """A DPR emulator TCP socket server.

    e.g.:
    dprs = DPRServer(handler=DRPserverHandler)
    dprs.serve_forever()
    """

    def __init__(self, address='0.0.0.0', port=DPR_PORT, handler=DPRserverHandlerBase):
        super(DPRserver, self).__init__((address, port), handler)


class DPRexception(Exception):
    """Exception class for DPRclient class."""

class DPRclient:
    """Class to send DPR TCP packets to robots to get and set memory."""

    def __init__(self, ip_address, ushmfile='', port=DPR_PORT, endianness='auto', timeout=None):
        """Initialise object and create socket for robot communication.

        Args:
            ip_address (string): IP address of robot
            port (int, optional): The port for communication. Defaults to 12264.
            endianness (str): 'auto', 'big', 'little'. Defaults to 'auto'
            timeout (float, optional): A timeout for sending. Defaults to None

        Raises:
            socket.error: on socket exception
        """
        # Set object members
        self.endianness = endianness
        self.remote_endpoint = (ip_address, port)

        # Create a TCP socket and connect
        self._sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._sock.connect(self.remote_endpoint)
        if timeout:
            self._sock.settimeout(timeout)

        # If auto endianness is provided, try to guess by
        # Setting and getting memory
        if self.endianness == 'auto':
            self.endianness = self.determine_endianness()

        self.var_list = OrderedDict()
        if ushmfile:
            self._read_ushm_file(ushmfile)

    def determine_endianness(self):
        """Automatically determine the endianness of a robot system."""
        # Determine endianness by setting a value and getting it back
        magic_number = struct.pack('>I', 0x01020304)

        self.set_raw(8, magic_number)  # the address of reservedReadAddress is 8
        value = self.get_var("reservedReadAddress")

        if value == struct.unpack('>I', magic_number)[0]:
            endianness = 'big'
        elif value == struct.unpack('<I', magic_number)[0]:
            endianness = 'little'
        else:
            print("Unable to resolve endianness of target machine")
            endianness = 'unknown'

        return endianness

    def unpack_format(self, length, var_type):
        """Determine unpack format based on parameters."""
        if self.endianness == 'big':
            formatstr = '>'
        elif self.endianness == 'little':
            formatstr = '<'
        if var_type == 'f':
            formatstr += 'f'
        elif var_type == 'd':
            formatstr += 'd'
        elif var_type == 'i':
            if length == 1:
                formatstr += 'B'
            elif length == 8:
                formatstr += 'b'
            elif length == 16:
                formatstr += 'h'
            elif length == 32:
                formatstr += 'i'
        elif var_type == 'u':
            if length == 1:
                formatstr += 'B'
            elif length == 8:
                formatstr += 'B'
            elif length == 16:
                formatstr += 'H'
            elif length == 32:
                formatstr += 'I'
        return formatstr

    def _read_ushm_file(self, filename):
        """Open a ushmdefinitions.pmh file and parse for memory structure."""
        with open(filename) as ushm_file:
            for line in ushm_file:
                if line.lstrip().startswith('ptr'):
                    pattern = r'ptr\s*([^\(\)]*?)->(.)\.(.*?):(\d+)(\.(\d+)\.(\d+))?'
                    match = re.match(pattern, line)
                    if match:
                        name = match.group(1)
                        self.var_list[name] = {}
                        self.var_list[name]['type'] = match.group(2)
                        self.var_list[name]['address'] = int(match.group(4))
                        self.var_list[name]['arraylen'] = 0
                        if match.group(6) is not None and match.group(7) is not None:
                            self.var_list[name]['bit_offset'] = int(match.group(6))
                            self.var_list[name]['length'] = int(match.group(7))
                        else:
                            self.var_list[name]['bit_offset'] = 0
                            if self.var_list[name]['type'] == 'd':
                                self.var_list[name]['length'] = 64
                            else:
                                self.var_list[name]['length'] = 32
                        format_str = self.unpack_format(self.var_list[name]['length'],
                                                        self.var_list[name]['type'])
                        byte_offset = self.var_list[name]['bit_offset'] // 8
                        address = self.var_list[name]['address']
                        length = self.var_list[name]['length'] // 8
                        bit_offset_byte = None
                        if length == 0:
                            length = 1
                            bit_offset_byte = self.var_list[name]['bit_offset'] % 8
                        if self.endianness == 'little':
                            address = self.var_list[name]['address'] + byte_offset
                        elif self.endianness == 'big':
                            address = self.var_list[name]['address'] + 4 - byte_offset - length
                        self.var_list[name]['unpack'] = format_str
                        self.var_list[name]['length_bytes'] = length
                        self.var_list[name]['address_offset'] = address
                        self.var_list[name]['bit_offset_byte'] = bit_offset_byte
                    else:
                        pattern = r'ptr\s*(.*?)\(?(\d+)\)?->(.)\.(.*?):(\d+)(\.(\d+)\.(\d+)(\+))?'
                        match = re.match(pattern, line)
                        if match:
                            name = match.group(1)
                            self.var_list[name] = {}
                            self.var_list[name]['arraylen'] = int(match.group(2))
                            self.var_list[name]['type'] = match.group(3)
                            self.var_list[name]['address'] = int(match.group(5))
                            if match.group(7) is not None and match.group(8) is not None:
                                self.var_list[name]['bit_offset'] = int(match.group(7))
                                self.var_list[name]['length'] = int(match.group(8))
                            else:
                                self.var_list[name]['bit_offset'] = 0
                                if self.var_list[name]['type'] == 'd':
                                    self.var_list[name]['length'] = 64
                                else:
                                    self.var_list[name]['length'] = 32
                            format_str = self.unpack_format(self.var_list[name]['length'],
                                                            self.var_list[name]['type'])
                            byte_offset = self.var_list[name]['bit_offset'] // 8
                            address = self.var_list[name]['address']
                            length = self.var_list[name]['length'] // 8
                            bit_offset_byte = None
                            if length == 0:
                                length = 1
                                bit_offset_byte = self.var_list[name]['bit_offset'] % 8
                            if self.endianness == 'little':
                                address = self.var_list[name]['address'] + byte_offset
                            elif self.endianness == 'big':
                                address = self.var_list[name]['address'] + 4 - byte_offset - length
                            self.var_list[name]['unpack'] = format_str
                            self.var_list[name]['length_bytes'] = length
                            self.var_list[name]['address_offset'] = address
                            self.var_list[name]['bit_offset_byte'] = bit_offset_byte

    def __del__(self):
        """Destructor will close socket properly."""
        self._sock.shutdown(socket.SHUT_RDWR)
        self._sock.close()

    def get_ushm_range(self, name_start, name_end, actual_address=None):
        """Get a range of consecutive values within the range of name_start to name_end.

        This is more efficient than getting individual ones as it gets memory in one block.

        Args:
            name_start (str): Name of first variable in the block
            name_end (str): Name of second variable in the block
            actual_address (int, optional): A different address offset, than the default

        Returns:
            dict: A dictionary with the name as the key
        """
        address_start = self.var_list[name_start]['address_offset']
        address_end = self.var_list[name_end]['address_offset']
        length_end = self.var_list[name_end]['length_bytes']
        data_length = address_end + length_end - address_start
        if actual_address is None:
            actual_address = address_start
        data = self.get_raw(address_start, data_length)
        next_var = name_start
        data_out = {}
        while True:

            length = self.var_list[next_var]['length_bytes']
            address = self.var_list[next_var]['address_offset']
            format_str = self.var_list[next_var]['unpack']
            arraylen = self.var_list[next_var]['arraylen']
            bit_offset_byte = self.var_list[next_var]['bit_offset_byte']

            length *= arraylen

            byte_offset = address - address_start
            data = []

            if next_var == name_end:
                break

            if arraylen > 0:
                format_str = format_str[0] + str(arraylen) + format_str[1]
                data = struct.unpack_from(format_str, data, byte_offset)
            else:
                if bit_offset_byte is None:
                    # Extract data value
                    data = struct.unpack_from(format_str, data, byte_offset)[0]
                else:
                    # Apply bit shift to byte value and extract as bool
                    data = struct.unpack_from(format_str, data, byte_offset)[0]
                    data = bool((data >> bit_offset_byte) & 0x1)
            data_out[next_var] = data

            next_index = self.var_list.keys().index(next_var) + 1
            next_var = self.var_list.items()[next_index]
        return data_out

    def get_ushm(self, name):
        """Get user shared memory variable from the robot by name.

        Get user shared memory variable from the robot by name if ushm definitions.pmh file
        has been loaded into the object.

        Args:
            name (str): A string containing the variable name, with (n) for array index if required
        """
        # Get array index if provided and extract name
        arrayindex = 0
        if '(' in name:
            match = re.match(r'(.*?)\(?(\d+)\)?', name)
            if match:
                name = match.group(1)
                arrayindex = int(match.group(2))

        # Extract necessary info
        length = self.var_list[name]['length_bytes']
        address = self.var_list[name]['address_offset']
        format_str = self.var_list[name]['unpack']
        arraylen = self.var_list[name]['arraylen']
        bit_offset_byte = self.var_list[name]['bit_offset_byte']

        if arrayindex > 0:
            # Apply array offset to address
            address += arrayindex * length
            arraylen = 0
        elif arraylen > 0:
            # If variable is an array, get all items in elements
            length *= arraylen

        # Now we know the address and length, fetch the value
        data = self.get_raw(address, length)

        # Process raw bytes into python variable
        if arraylen > 0:
            format_str = format_str[0] + str(arraylen) + format_str[1]
            data = struct.unpack(format_str, data)
        else:
            if bit_offset_byte is None:
                # Extract data value
                data = struct.unpack(format_str, data)[0]
            else:
                # Apply bit shift to byte value and extract as bool
                data = struct.unpack(format_str, data)[0]
                data = bool((data >> bit_offset_byte) & 0x1)
        return data

    def get_raw(self, address, length):
        """Get raw bytes from robot user shared memory.

        Args:
            address (int): The memory address offset
            length (int): The number of bytes to get from the address
        """
        header = DPRheader()
        header.request_type = DPR_UPLOAD       # Upload
        header.request = DPR_GET_MEM           # Get mem
        header.index = 0
        header.value = address # DRP Address
        header.length = length
        # Send packet to the robot
        self._sock.sendall(bytes(header))
        data = self._sock.recv(length)
        return data

    def get_var(self, name):
        """Request PMAC variable by string name.

        Args:
            name (string): Name of PMAC variable (P or M)

        Returns:
            int or float: The value of the string, None if not defined
        """
        payload_bytes = name.encode('utf-8')

        header = DPRheader()
        header.request_type = DPR_UPLOAD       # Upload
        header.request = DPR_GET_VAR            # Get var
        header.index = 0
        header.value = 0 # DRP Address
        header.length = len(payload_bytes)

        # Send packet to the robot
        self._sock.sendall(bytes(header) + payload_bytes)
        data = self._sock.recv(50)
        if data[0] != '0':
            data = float(data.decode('utf-8'))
            if data.is_integer():
                data = int(data)
        else:
            data = None
        return data

    def __getitem__(self, name):
        """Get a global shared memory variable."""
        if name in self.var_list:
            # Get by ushm address if it is known
            return self.get_ushm(name)
        # Else get by ascii string
        return self.get_var(name)

    def set_var(self, name, value):
        """Set the PMAC variable by string name.

        Args:
            name (string): Name of PMAC variable
            value (float): Value of variable as a float

        Exceptions:
            DPRexception: If string name is not accepted
        """
        if self.endianness == "big":
            payload_bytes = struct.pack('<d', value) + name.encode('utf-8')
        else:
            payload_bytes = struct.pack('>d', value) + name.encode('utf-8')

        header = DPRheader()
        header.request_type = DPR_UPLOAD       # Upload
        header.request = DPR_SET_VAR           # Set var
        header.index = 0
        header.value = 0 # DRP Address
        header.length = len(payload_bytes)

        # Send packet to the robot
        self._sock.sendall(bytes(header) + payload_bytes)
        data = self._sock.recv(1)
        if len(data) == 1:
            if data[0] != 0x06:
                raise DPRexception('Bad return value, expected 0x06, but got ' + str(data[0]))
        else:
            raise DPRexception('Bad return length, expected 1 byte, but got ' + len(data))

    def set_raw(self, address, data):
        """Set a driverless structure into the robot.

        Args:
            address (int): Shared memory address offset
            data (bytes): Raw data bytes
        """
        header = DPRheader()
        header.request_type = DPR_UPLOAD       # Upload
        header.request = DPR_SET_MEM           # Set mem
        header.index = 0                 # Not used
        header.value = address           # DRP Address
        header.length = len(data)        # Length of payload

        # Send packet to the robot
        self._sock.send(bytes(header) + data)
        data = self._sock.recv(1)
        if len(data) == 1:
            if data[0] != 0x06:
                raise DPRexception('Bad return value, expected 0x06, but got ' + str(data[0]))
        else:
            raise DPRexception('Bad return length, expected 1 byte, but got ' + len(data))

    def set_ushm(self, name, value):
        """Set a ushm variable by name if ushm definitions.pmh file is provided.

        Args:
            name (str): The name of the variable as a string
            value (int or float): The value as a int or float
        """
        # Get array index if provided offset the address further
        arrayindex = 0
        if '(' in name:
            match = re.match(r'(.*?)\(?(\d+)\)?', name)
            if match:
                name = match.group(1)
                arrayindex = int(match.group(2))
        length = self.var_list[name]['length_bytes']
        address = self.var_list[name]['address_offset']
        format_str = self.var_list[name]['unpack']
        arraylen = self.var_list[name]['arraylen']
        bit_offset_byte = self.var_list[name]['bit_offset_byte']

        if arrayindex > 0:
            # Apply array offset to address
            address += arrayindex * length
            arraylen = 0
        elif arraylen > 0:
            # Get if an array, get all items in array
            length *= arraylen

        if arraylen == 0:
            if bit_offset_byte is None:
                data = struct.pack(format_str, value)
            else:
                # If a bool, we have to fetch the whole byte first, then set the byte back
                # with the correct bit set
                data = self.get_raw(address, length)
                byte = struct.unpack(format_str, data)[0]
                if value:
                    byte |= (1 << bit_offset_byte)
                else:
                    byte &= ~(1 << bit_offset_byte)
                data = struct.pack(format_str, byte)
        else:
            format_str = format_str[0] + len(value) + format_str[1]
            data = struct.pack(format_str, *value)
        self.set_raw(address, data)

    def __setitem__(self, name, value):
        """Set a global shared memory variable."""
        if name in self.var_list:
            # Get by ushm address if its known to us
            return self.set_ushm(name, value)
        # Else get by ascii string
        return self.set_var(name, value)

    def save(self):
        """Send save command to PMAC card."""
        return self.terminal('save')

    def reset(self):
        """Send reset command ($$$) to PMAC card."""
        return self.terminal('$$$')

    def restore(self):
        """Send restore command ($$$***) to PMAC card."""
        return self.terminal('$$$***')

    def reboot(self):
        """Send reboot command (reboot) to PMAC card."""
        return self.terminal('reboot')

    def system(self, command):
        """Send system command (i.e. bash command) to PMAC card."""
        return self.terminal('system ' + command)

    def terminal(self, request):
        """Send terminal command and get response as string.

        Args:
            request (string): The terminal command

        Returns:
            int or float: The value of the string, None if not defined
        """
        payload_bytes = request.encode('utf-8')

        header = DPRheader()
        header.request_type = DPR_UPLOAD       # Upload
        header.request = DPR_GET_REPONSE       # Get var
        header.index = 0
        header.value = 0 # DRP Address
        header.length = len(payload_bytes)

        # Send packet to the robot
        self._sock.sendall(bytes(header) + payload_bytes)
        data = self._sock.recv(4096)
        if data != b'\x00':
            data = data.decode('utf-8').strip()
        else:
            data = ''
        return data

# pylint: enable=attribute-defined-outside-init

def test_dpr():
    """Test function for DPRclient class."""
    ip_address='195.0.1.1'
    ushmfile = r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'
    dpr = DPRclient(ip_address, ushmfile)
    print(dpr.endianness)
    print(dpr['iDigTrigCAN15'])
    dpr['iDigTrigCAN15'] = True
    print(dpr['iDigTrigCAN15'])

    print(dpr.system('ls -l'))
    dpr.get_var('pmC_SerialNo')
    dpr.set_var('pmC_SerialNo', 1245)
    dpr.get_var('pmC_SerialNo')

    print('pmPMACbuildVersion = ' + str(dpr['pmPMACbuildVersion']))
    print('pmPMACisDevVersion = ' + str(dpr['pmPMACisDevVersion']))
    print('pmC_SerialNo = ' + str(dpr['pmC_SerialNo']))
    print('pmC_ADC8Sensitivity = ' + str(dpr['pmC_ADC8Sensitivity']))
    print('pmC_DAC1Offset = ' + str(dpr['pmC_DAC1Offset']))
    print('pmXnode = ' + str(dpr['pmXnode']))
    print('pmXnode = ' + str(dpr['pmXnode(1)']))
    dpr['pmXnode(1)'] = 123.456
    print('pmXnode = ' + str(dpr['pmXnode']))

    pmLatitudeInt = dpr.get_var('pmLatitudeInt')
    pmLatitudeFract = dpr.get_var('pmLatitudeFract')
    pmLongitudeInt = dpr.get_var('pmLongitudeInt')
    pmLongitudeFract = dpr.get_var('pmLongitudeFract')
    pmXaxisDatumBearing = dpr.get_var('pmXaxisDatumBearing')
    pmSetOverrideSpeed = dpr.get_var('pmSetOverrideSpeed')
    pmDesiredOverrideSpeed= dpr.get_var('pmDesiredOverrideSpeed')

    datumLat = pmLatitudeInt * 0.001 + pmLatitudeFract * 0.001
    datumLong = pmLongitudeInt * 0.001 + pmLongitudeFract * 0.001
    print('Datum at: ' + str(datumLat) + ':' + str(datumLong) + ' Aligned: ' + str(pmXaxisDatumBearing))


    print("The overide speed var was set to:",pmSetOverrideSpeed)
    dpr.set_var('pmSetOverrideSpeed', 1)
    pmSetOverrideSpeed = dpr.get_var('pmSetOverrideSpeed')
    print("The overide speed var is now set to:", pmSetOverrideSpeed)

    print(pmDesiredOverrideSpeed)
    dpr.set_var('pmDesiredOverrideSpeed', 50)
    pmDesiredOverrideSpeed = dpr.get_var('pmDesiredOverrideSpeed')
    print(pmDesiredOverrideSpeed)

    while True:
        serial_no = dpr['pmC_SerialNo']
        print('pmC_SerialNo = ' + str(serial_no))
        dpr['pmC_SerialNo'] = serial_no - 1
        break



def vcmd_callback(msg):
    global g_node
    g_node.get_logger().info(
        'I heard: "%d"' % msg.data)


def main(args=None):
    """Test function for DPRclient class."""
    ip_address='195.0.1.1'

    global g_node
    rclpy.init(args=args)
    g_node = rclpy.create_node('vcmd_subscriber')

    subscription = g_node.create_subscription(Float32, 'vcmd', vcmd_callback, 10)
    subscription  # prevent unused variable warning

    test_dpr()

    while rclpy.ok():
        rclpy.spin_once(g_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    g_node.destroy_node()
    rclpy.shutdown()




if __name__ == "__main__":
    main()
    # test_dpr(sys.argv[1], sys.argv[2])
