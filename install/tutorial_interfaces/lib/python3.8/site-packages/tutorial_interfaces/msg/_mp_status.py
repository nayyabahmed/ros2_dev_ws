# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tutorial_interfaces:msg/MpStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MpStatus(type):
    """Metaclass of message 'MpStatus'."""

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
            module = import_type_support('tutorial_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tutorial_interfaces.msg.MpStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mp_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mp_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mp_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mp_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mp_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MpStatus(metaclass=Metaclass_MpStatus):
    """Message class 'MpStatus'."""

    __slots__ = [
        '_mp_time',
        '_mp_lat',
        '_mp_longt',
        '_mp_bearing',
        '_yaw_angle',
    ]

    _fields_and_field_types = {
        'mp_time': 'double',
        'mp_lat': 'float',
        'mp_longt': 'float',
        'mp_bearing': 'float',
        'yaw_angle': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mp_time = kwargs.get('mp_time', float())
        self.mp_lat = kwargs.get('mp_lat', float())
        self.mp_longt = kwargs.get('mp_longt', float())
        self.mp_bearing = kwargs.get('mp_bearing', float())
        self.yaw_angle = kwargs.get('yaw_angle', float())

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
        if self.mp_time != other.mp_time:
            return False
        if self.mp_lat != other.mp_lat:
            return False
        if self.mp_longt != other.mp_longt:
            return False
        if self.mp_bearing != other.mp_bearing:
            return False
        if self.yaw_angle != other.yaw_angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def mp_time(self):
        """Message field 'mp_time'."""
        return self._mp_time

    @mp_time.setter
    def mp_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mp_time' field must be of type 'float'"
        self._mp_time = value

    @property
    def mp_lat(self):
        """Message field 'mp_lat'."""
        return self._mp_lat

    @mp_lat.setter
    def mp_lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mp_lat' field must be of type 'float'"
        self._mp_lat = value

    @property
    def mp_longt(self):
        """Message field 'mp_longt'."""
        return self._mp_longt

    @mp_longt.setter
    def mp_longt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mp_longt' field must be of type 'float'"
        self._mp_longt = value

    @property
    def mp_bearing(self):
        """Message field 'mp_bearing'."""
        return self._mp_bearing

    @mp_bearing.setter
    def mp_bearing(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mp_bearing' field must be of type 'float'"
        self._mp_bearing = value

    @property
    def yaw_angle(self):
        """Message field 'yaw_angle'."""
        return self._yaw_angle

    @yaw_angle.setter
    def yaw_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_angle' field must be of type 'float'"
        self._yaw_angle = value
