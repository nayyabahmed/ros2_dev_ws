# generated from rosidl_generator_py/resource/_idl.py.em
# with input from abds_core_common:srv/LuminarSetDuration.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LuminarSetDuration_Request(type):
    """Metaclass of message 'LuminarSetDuration_Request'."""

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
            module = import_type_support('abds_core_common')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'abds_core_common.srv.LuminarSetDuration_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__luminar_set_duration__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__luminar_set_duration__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__luminar_set_duration__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__luminar_set_duration__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__luminar_set_duration__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LuminarSetDuration_Request(metaclass=Metaclass_LuminarSetDuration_Request):
    """Message class 'LuminarSetDuration_Request'."""

    __slots__ = [
        '_duration',
    ]

    _fields_and_field_types = {
        'duration': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.duration = kwargs.get('duration', int())

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
        if self.duration != other.duration:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def duration(self):
        """Message field 'duration'."""
        return self._duration

    @duration.setter
    def duration(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'duration' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'duration' field must be an integer in [-128, 127]"
        self._duration = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_LuminarSetDuration_Response(type):
    """Metaclass of message 'LuminarSetDuration_Response'."""

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
            module = import_type_support('abds_core_common')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'abds_core_common.srv.LuminarSetDuration_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__luminar_set_duration__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__luminar_set_duration__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__luminar_set_duration__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__luminar_set_duration__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__luminar_set_duration__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LuminarSetDuration_Response(metaclass=Metaclass_LuminarSetDuration_Response):
    """Message class 'LuminarSetDuration_Response'."""

    __slots__ = [
        '_result',
    ]

    _fields_and_field_types = {
        'result': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.result = kwargs.get('result', int())

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
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'result' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'result' field must be an integer in [-128, 127]"
        self._result = value


class Metaclass_LuminarSetDuration(type):
    """Metaclass of service 'LuminarSetDuration'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('abds_core_common')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'abds_core_common.srv.LuminarSetDuration')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__luminar_set_duration

            from abds_core_common.srv import _luminar_set_duration
            if _luminar_set_duration.Metaclass_LuminarSetDuration_Request._TYPE_SUPPORT is None:
                _luminar_set_duration.Metaclass_LuminarSetDuration_Request.__import_type_support__()
            if _luminar_set_duration.Metaclass_LuminarSetDuration_Response._TYPE_SUPPORT is None:
                _luminar_set_duration.Metaclass_LuminarSetDuration_Response.__import_type_support__()


class LuminarSetDuration(metaclass=Metaclass_LuminarSetDuration):
    from abds_core_common.srv._luminar_set_duration import LuminarSetDuration_Request as Request
    from abds_core_common.srv._luminar_set_duration import LuminarSetDuration_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
