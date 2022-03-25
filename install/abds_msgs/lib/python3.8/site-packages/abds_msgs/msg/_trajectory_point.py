# generated from rosidl_generator_py/resource/_idl.py.em
# with input from abds_msgs:msg/TrajectoryPoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TrajectoryPoint(type):
    """Metaclass of message 'TrajectoryPoint'."""

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
                'abds_msgs.msg.TrajectoryPoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__trajectory_point
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__trajectory_point
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__trajectory_point
            cls._TYPE_SUPPORT = module.type_support_msg__msg__trajectory_point
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__trajectory_point

            from builtin_interfaces.msg import Duration
            if Duration.__class__._TYPE_SUPPORT is None:
                Duration.__class__.__import_type_support__()

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryPoint(metaclass=Metaclass_TrajectoryPoint):
    """Message class 'TrajectoryPoint'."""

    __slots__ = [
        '_time_from_start',
        '_datum_bearing',
        '_pose',
        '_dist_along_path',
        '_longitudinal_velocity',
        '_lateral_velocity',
        '_acceleration',
        '_heading_rate',
        '_instantanious_curvature',
    ]

    _fields_and_field_types = {
        'time_from_start': 'builtin_interfaces/Duration',
        'datum_bearing': 'float',
        'pose': 'geometry_msgs/Pose',
        'dist_along_path': 'float',
        'longitudinal_velocity': 'float',
        'lateral_velocity': 'float',
        'acceleration': 'float',
        'heading_rate': 'float',
        'instantanious_curvature': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Duration'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Duration
        self.time_from_start = kwargs.get('time_from_start', Duration())
        self.datum_bearing = kwargs.get('datum_bearing', float())
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        self.dist_along_path = kwargs.get('dist_along_path', float())
        self.longitudinal_velocity = kwargs.get('longitudinal_velocity', float())
        self.lateral_velocity = kwargs.get('lateral_velocity', float())
        self.acceleration = kwargs.get('acceleration', float())
        self.heading_rate = kwargs.get('heading_rate', float())
        self.instantanious_curvature = kwargs.get('instantanious_curvature', float())

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
        if self.time_from_start != other.time_from_start:
            return False
        if self.datum_bearing != other.datum_bearing:
            return False
        if self.pose != other.pose:
            return False
        if self.dist_along_path != other.dist_along_path:
            return False
        if self.longitudinal_velocity != other.longitudinal_velocity:
            return False
        if self.lateral_velocity != other.lateral_velocity:
            return False
        if self.acceleration != other.acceleration:
            return False
        if self.heading_rate != other.heading_rate:
            return False
        if self.instantanious_curvature != other.instantanious_curvature:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def time_from_start(self):
        """Message field 'time_from_start'."""
        return self._time_from_start

    @time_from_start.setter
    def time_from_start(self, value):
        if __debug__:
            from builtin_interfaces.msg import Duration
            assert \
                isinstance(value, Duration), \
                "The 'time_from_start' field must be a sub message of type 'Duration'"
        self._time_from_start = value

    @property
    def datum_bearing(self):
        """Message field 'datum_bearing'."""
        return self._datum_bearing

    @datum_bearing.setter
    def datum_bearing(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'datum_bearing' field must be of type 'float'"
        self._datum_bearing = value

    @property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @property
    def dist_along_path(self):
        """Message field 'dist_along_path'."""
        return self._dist_along_path

    @dist_along_path.setter
    def dist_along_path(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dist_along_path' field must be of type 'float'"
        self._dist_along_path = value

    @property
    def longitudinal_velocity(self):
        """Message field 'longitudinal_velocity'."""
        return self._longitudinal_velocity

    @longitudinal_velocity.setter
    def longitudinal_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitudinal_velocity' field must be of type 'float'"
        self._longitudinal_velocity = value

    @property
    def lateral_velocity(self):
        """Message field 'lateral_velocity'."""
        return self._lateral_velocity

    @lateral_velocity.setter
    def lateral_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lateral_velocity' field must be of type 'float'"
        self._lateral_velocity = value

    @property
    def acceleration(self):
        """Message field 'acceleration'."""
        return self._acceleration

    @acceleration.setter
    def acceleration(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acceleration' field must be of type 'float'"
        self._acceleration = value

    @property
    def heading_rate(self):
        """Message field 'heading_rate'."""
        return self._heading_rate

    @heading_rate.setter
    def heading_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading_rate' field must be of type 'float'"
        self._heading_rate = value

    @property
    def instantanious_curvature(self):
        """Message field 'instantanious_curvature'."""
        return self._instantanious_curvature

    @instantanious_curvature.setter
    def instantanious_curvature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'instantanious_curvature' field must be of type 'float'"
        self._instantanious_curvature = value
