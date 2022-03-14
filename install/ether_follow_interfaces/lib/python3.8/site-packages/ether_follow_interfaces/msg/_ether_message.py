# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ether_follow_interfaces:msg/EtherMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EtherMessage(type):
    """Metaclass of message 'EtherMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ether_follow_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ether_follow_interfaces.msg.EtherMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ether_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ether_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ether_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ether_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ether_message

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EtherMessage(metaclass=Metaclass_EtherMessage):
    """Message class 'EtherMessage'."""

    __slots__ = [
        '_ip_address',
        '_version',
        '_steering_cmd',
        '_brake_cmd',
        '_accel_cmd',
        '_gear_cmd',
    ]

    _fields_and_field_types = {
        'ip_address': 'string',
        'version': 'uint8',
        'steering_cmd': 'double',
        'brake_cmd': 'double',
        'accel_cmd': 'double',
        'gear_cmd': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ip_address = kwargs.get('ip_address', str())
        self.version = kwargs.get('version', int())
        self.steering_cmd = kwargs.get('steering_cmd', float())
        self.brake_cmd = kwargs.get('brake_cmd', float())
        self.accel_cmd = kwargs.get('accel_cmd', float())
        self.gear_cmd = kwargs.get('gear_cmd', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.ip_address != other.ip_address:
            return False
        if self.version != other.version:
            return False
        if self.steering_cmd != other.steering_cmd:
            return False
        if self.brake_cmd != other.brake_cmd:
            return False
        if self.accel_cmd != other.accel_cmd:
            return False
        if self.gear_cmd != other.gear_cmd:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def ip_address(self):
        """Message field 'ip_address'."""
        return self._ip_address

    @ip_address.setter
    def ip_address(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'ip_address' field must be of type 'str'"
        self._ip_address = value

    @property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'version' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'version' field must be an unsigned integer in [0, 255]"
        self._version = value

    @property
    def steering_cmd(self):
        """Message field 'steering_cmd'."""
        return self._steering_cmd

    @steering_cmd.setter
    def steering_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steering_cmd' field must be of type 'float'"
        self._steering_cmd = value

    @property
    def brake_cmd(self):
        """Message field 'brake_cmd'."""
        return self._brake_cmd

    @brake_cmd.setter
    def brake_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'brake_cmd' field must be of type 'float'"
        self._brake_cmd = value

    @property
    def accel_cmd(self):
        """Message field 'accel_cmd'."""
        return self._accel_cmd

    @accel_cmd.setter
    def accel_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'accel_cmd' field must be of type 'float'"
        self._accel_cmd = value

    @property
    def gear_cmd(self):
        """Message field 'gear_cmd'."""
        return self._gear_cmd

    @gear_cmd.setter
    def gear_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gear_cmd' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'gear_cmd' field must be an integer in [-128, 127]"
        self._gear_cmd = value
