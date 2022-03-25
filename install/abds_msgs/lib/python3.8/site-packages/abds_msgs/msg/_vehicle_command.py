# generated from rosidl_generator_py/resource/_idl.py.em
# with input from abds_msgs:msg/VehicleCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VehicleCommand(type):
    """Metaclass of message 'VehicleCommand'."""

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
            module = import_type_support('abds_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'abds_msgs.msg.VehicleCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle_command

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VehicleCommand(metaclass=Metaclass_VehicleCommand):
    """Message class 'VehicleCommand'."""

    __slots__ = [
        '_stamp',
        '_long_accel',
        '_velocity_modifier',
        '_front_wheel_angle',
        '_rear_wheel_angle',
    ]

    _fields_and_field_types = {
        'stamp': 'builtin_interfaces/Time',
        'long_accel': 'float',
        'velocity_modifier': 'float',
        'front_wheel_angle': 'float',
        'rear_wheel_angle': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())
        self.long_accel = kwargs.get('long_accel', float())
        self.velocity_modifier = kwargs.get('velocity_modifier', float())
        self.front_wheel_angle = kwargs.get('front_wheel_angle', float())
        self.rear_wheel_angle = kwargs.get('rear_wheel_angle', float())

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
        if self.stamp != other.stamp:
            return False
        if self.long_accel != other.long_accel:
            return False
        if self.velocity_modifier != other.velocity_modifier:
            return False
        if self.front_wheel_angle != other.front_wheel_angle:
            return False
        if self.rear_wheel_angle != other.rear_wheel_angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value

    @property
    def long_accel(self):
        """Message field 'long_accel'."""
        return self._long_accel

    @long_accel.setter
    def long_accel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'long_accel' field must be of type 'float'"
        self._long_accel = value

    @property
    def velocity_modifier(self):
        """Message field 'velocity_modifier'."""
        return self._velocity_modifier

    @velocity_modifier.setter
    def velocity_modifier(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'velocity_modifier' field must be of type 'float'"
        self._velocity_modifier = value

    @property
    def front_wheel_angle(self):
        """Message field 'front_wheel_angle'."""
        return self._front_wheel_angle

    @front_wheel_angle.setter
    def front_wheel_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_wheel_angle' field must be of type 'float'"
        self._front_wheel_angle = value

    @property
    def rear_wheel_angle(self):
        """Message field 'rear_wheel_angle'."""
        return self._rear_wheel_angle

    @rear_wheel_angle.setter
    def rear_wheel_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rear_wheel_angle' field must be of type 'float'"
        self._rear_wheel_angle = value
