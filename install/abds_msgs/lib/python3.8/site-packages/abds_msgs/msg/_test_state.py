# generated from rosidl_generator_py/resource/_idl.py.em
# with input from abds_msgs:msg/TestState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TestState(type):
    """Metaclass of message 'TestState'."""

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
                'abds_msgs.msg.TestState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__test_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__test_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__test_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__test_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__test_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TestState(metaclass=Metaclass_TestState):
    """Message class 'TestState'."""

    __slots__ = [
        '_test_id',
        '_test_phase',
        '_test_state',
        '_path_distance',
        '_deceleration_rate',
        '_abort_deceleration_rate',
        '_desired_speed',
    ]

    _fields_and_field_types = {
        'test_id': 'int32',
        'test_phase': 'int32',
        'test_state': 'int32',
        'path_distance': 'float',
        'deceleration_rate': 'float',
        'abort_deceleration_rate': 'float',
        'desired_speed': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.test_id = kwargs.get('test_id', int())
        self.test_phase = kwargs.get('test_phase', int())
        self.test_state = kwargs.get('test_state', int())
        self.path_distance = kwargs.get('path_distance', float())
        self.deceleration_rate = kwargs.get('deceleration_rate', float())
        self.abort_deceleration_rate = kwargs.get('abort_deceleration_rate', float())
        self.desired_speed = kwargs.get('desired_speed', float())

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
        if self.test_id != other.test_id:
            return False
        if self.test_phase != other.test_phase:
            return False
        if self.test_state != other.test_state:
            return False
        if self.path_distance != other.path_distance:
            return False
        if self.deceleration_rate != other.deceleration_rate:
            return False
        if self.abort_deceleration_rate != other.abort_deceleration_rate:
            return False
        if self.desired_speed != other.desired_speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def test_id(self):
        """Message field 'test_id'."""
        return self._test_id

    @test_id.setter
    def test_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'test_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'test_id' field must be an integer in [-2147483648, 2147483647]"
        self._test_id = value

    @property
    def test_phase(self):
        """Message field 'test_phase'."""
        return self._test_phase

    @test_phase.setter
    def test_phase(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'test_phase' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'test_phase' field must be an integer in [-2147483648, 2147483647]"
        self._test_phase = value

    @property
    def test_state(self):
        """Message field 'test_state'."""
        return self._test_state

    @test_state.setter
    def test_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'test_state' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'test_state' field must be an integer in [-2147483648, 2147483647]"
        self._test_state = value

    @property
    def path_distance(self):
        """Message field 'path_distance'."""
        return self._path_distance

    @path_distance.setter
    def path_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'path_distance' field must be of type 'float'"
        self._path_distance = value

    @property
    def deceleration_rate(self):
        """Message field 'deceleration_rate'."""
        return self._deceleration_rate

    @deceleration_rate.setter
    def deceleration_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'deceleration_rate' field must be of type 'float'"
        self._deceleration_rate = value

    @property
    def abort_deceleration_rate(self):
        """Message field 'abort_deceleration_rate'."""
        return self._abort_deceleration_rate

    @abort_deceleration_rate.setter
    def abort_deceleration_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'abort_deceleration_rate' field must be of type 'float'"
        self._abort_deceleration_rate = value

    @property
    def desired_speed(self):
        """Message field 'desired_speed'."""
        return self._desired_speed

    @desired_speed.setter
    def desired_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'desired_speed' field must be of type 'float'"
        self._desired_speed = value
