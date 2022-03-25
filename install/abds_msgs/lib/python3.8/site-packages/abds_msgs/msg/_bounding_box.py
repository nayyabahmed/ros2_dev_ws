# generated from rosidl_generator_py/resource/_idl.py.em
# with input from abds_msgs:msg/BoundingBox.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BoundingBox(type):
    """Metaclass of message 'BoundingBox'."""

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
                'abds_msgs.msg.BoundingBox')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__bounding_box
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__bounding_box
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__bounding_box
            cls._TYPE_SUPPORT = module.type_support_msg__msg__bounding_box
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__bounding_box

            from geometry_msgs.msg import Point32
            if Point32.__class__._TYPE_SUPPORT is None:
                Point32.__class__.__import_type_support__()

            from geometry_msgs.msg import Quaternion
            if Quaternion.__class__._TYPE_SUPPORT is None:
                Quaternion.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BoundingBox(metaclass=Metaclass_BoundingBox):
    """Message class 'BoundingBox'."""

    __slots__ = [
        '_centroid',
        '_size',
        '_orientation',
        '_velocity',
        '_heading',
        '_heading_rate',
        '_corners',
        '_variance',
        '_vehicle_label',
        '_class_likelihood',
    ]

    _fields_and_field_types = {
        'centroid': 'geometry_msgs/Point32',
        'size': 'geometry_msgs/Point32',
        'orientation': 'geometry_msgs/Quaternion',
        'velocity': 'float',
        'heading': 'float',
        'heading_rate': 'float',
        'corners': 'geometry_msgs/Point32[4]',
        'variance': 'float',
        'vehicle_label': 'uint8',
        'class_likelihood': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Quaternion'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point32
        self.centroid = kwargs.get('centroid', Point32())
        from geometry_msgs.msg import Point32
        self.size = kwargs.get('size', Point32())
        from geometry_msgs.msg import Quaternion
        self.orientation = kwargs.get('orientation', Quaternion())
        self.velocity = kwargs.get('velocity', float())
        self.heading = kwargs.get('heading', float())
        self.heading_rate = kwargs.get('heading_rate', float())
        from geometry_msgs.msg import Point32
        self.corners = kwargs.get(
            'corners',
            [Point32() for x in range(4)]
        )
        self.variance = kwargs.get('variance', float())
        self.vehicle_label = kwargs.get('vehicle_label', int())
        self.class_likelihood = kwargs.get('class_likelihood', float())

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
        if self.centroid != other.centroid:
            return False
        if self.size != other.size:
            return False
        if self.orientation != other.orientation:
            return False
        if self.velocity != other.velocity:
            return False
        if self.heading != other.heading:
            return False
        if self.heading_rate != other.heading_rate:
            return False
        if self.corners != other.corners:
            return False
        if self.variance != other.variance:
            return False
        if self.vehicle_label != other.vehicle_label:
            return False
        if self.class_likelihood != other.class_likelihood:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def centroid(self):
        """Message field 'centroid'."""
        return self._centroid

    @centroid.setter
    def centroid(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'centroid' field must be a sub message of type 'Point32'"
        self._centroid = value

    @property
    def size(self):
        """Message field 'size'."""
        return self._size

    @size.setter
    def size(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'size' field must be a sub message of type 'Point32'"
        self._size = value

    @property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if __debug__:
            from geometry_msgs.msg import Quaternion
            assert \
                isinstance(value, Quaternion), \
                "The 'orientation' field must be a sub message of type 'Quaternion'"
        self._orientation = value

    @property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'velocity' field must be of type 'float'"
        self._velocity = value

    @property
    def heading(self):
        """Message field 'heading'."""
        return self._heading

    @heading.setter
    def heading(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading' field must be of type 'float'"
        self._heading = value

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
    def corners(self):
        """Message field 'corners'."""
        return self._corners

    @corners.setter
    def corners(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, Point32) for v in value) and
                 True), \
                "The 'corners' field must be a set or sequence with length 4 and each value of type 'Point32'"
        self._corners = value

    @property
    def variance(self):
        """Message field 'variance'."""
        return self._variance

    @variance.setter
    def variance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'variance' field must be of type 'float'"
        self._variance = value

    @property
    def vehicle_label(self):
        """Message field 'vehicle_label'."""
        return self._vehicle_label

    @vehicle_label.setter
    def vehicle_label(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vehicle_label' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vehicle_label' field must be an unsigned integer in [0, 255]"
        self._vehicle_label = value

    @property
    def class_likelihood(self):
        """Message field 'class_likelihood'."""
        return self._class_likelihood

    @class_likelihood.setter
    def class_likelihood(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'class_likelihood' field must be of type 'float'"
        self._class_likelihood = value
