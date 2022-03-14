# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rc_interfaces:msg/RcStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RcStatus(type):
    """Metaclass of message 'RcStatus'."""

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
            module = import_type_support('rc_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rc_interfaces.msg.RcStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rc_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rc_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rc_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rc_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rc_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RcStatus(metaclass=Metaclass_RcStatus):
    """Message class 'RcStatus'."""

    __slots__ = [
        '_header',
        '_test_index',
        '_test_phase',
        '_mpf_phase',
        '_path_dist',
        '_desire_speed',
        '_pf_test_true',
        '_max_path_err_left',
        '_max_path_err_right',
        '_current_path_exit_index',
        '_dl_status_1',
        '_dl_status_2',
        '_dl_test_procedure_state',
        '_test_in_progress',
        '_ar_control_mode',
        '_mp_status',
        '_g_sr_err_1',
        '_br_ar_err_2',
        '_cr_gr_err_3',
        '_sr_mp_err_4',
        '_syn_temp_err_5',
        '_dl_err_1',
        '_dl_err_2',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'test_index': 'uint16',
        'test_phase': 'int16',
        'mpf_phase': 'int32',
        'path_dist': 'float',
        'desire_speed': 'float',
        'pf_test_true': 'octet',
        'max_path_err_left': 'float',
        'max_path_err_right': 'float',
        'current_path_exit_index': 'int16',
        'dl_status_1': 'octet',
        'dl_status_2': 'octet',
        'dl_test_procedure_state': 'octet',
        'test_in_progress': 'octet',
        'ar_control_mode': 'int32',
        'mp_status': 'int32',
        'g_sr_err_1': 'uint32',
        'br_ar_err_2': 'uint32',
        'cr_gr_err_3': 'uint32',
        'sr_mp_err_4': 'uint32',
        'syn_temp_err_5': 'uint32',
        'dl_err_1': 'uint32',
        'dl_err_2': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('octet'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('octet'),  # noqa: E501
        rosidl_parser.definition.BasicType('octet'),  # noqa: E501
        rosidl_parser.definition.BasicType('octet'),  # noqa: E501
        rosidl_parser.definition.BasicType('octet'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.test_index = kwargs.get('test_index', int())
        self.test_phase = kwargs.get('test_phase', int())
        self.mpf_phase = kwargs.get('mpf_phase', int())
        self.path_dist = kwargs.get('path_dist', float())
        self.desire_speed = kwargs.get('desire_speed', float())
        self.pf_test_true = kwargs.get('pf_test_true', bytes([0]))
        self.max_path_err_left = kwargs.get('max_path_err_left', float())
        self.max_path_err_right = kwargs.get('max_path_err_right', float())
        self.current_path_exit_index = kwargs.get('current_path_exit_index', int())
        self.dl_status_1 = kwargs.get('dl_status_1', bytes([0]))
        self.dl_status_2 = kwargs.get('dl_status_2', bytes([0]))
        self.dl_test_procedure_state = kwargs.get('dl_test_procedure_state', bytes([0]))
        self.test_in_progress = kwargs.get('test_in_progress', bytes([0]))
        self.ar_control_mode = kwargs.get('ar_control_mode', int())
        self.mp_status = kwargs.get('mp_status', int())
        self.g_sr_err_1 = kwargs.get('g_sr_err_1', int())
        self.br_ar_err_2 = kwargs.get('br_ar_err_2', int())
        self.cr_gr_err_3 = kwargs.get('cr_gr_err_3', int())
        self.sr_mp_err_4 = kwargs.get('sr_mp_err_4', int())
        self.syn_temp_err_5 = kwargs.get('syn_temp_err_5', int())
        self.dl_err_1 = kwargs.get('dl_err_1', int())
        self.dl_err_2 = kwargs.get('dl_err_2', int())

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
        if self.header != other.header:
            return False
        if self.test_index != other.test_index:
            return False
        if self.test_phase != other.test_phase:
            return False
        if self.mpf_phase != other.mpf_phase:
            return False
        if self.path_dist != other.path_dist:
            return False
        if self.desire_speed != other.desire_speed:
            return False
        if self.pf_test_true != other.pf_test_true:
            return False
        if self.max_path_err_left != other.max_path_err_left:
            return False
        if self.max_path_err_right != other.max_path_err_right:
            return False
        if self.current_path_exit_index != other.current_path_exit_index:
            return False
        if self.dl_status_1 != other.dl_status_1:
            return False
        if self.dl_status_2 != other.dl_status_2:
            return False
        if self.dl_test_procedure_state != other.dl_test_procedure_state:
            return False
        if self.test_in_progress != other.test_in_progress:
            return False
        if self.ar_control_mode != other.ar_control_mode:
            return False
        if self.mp_status != other.mp_status:
            return False
        if self.g_sr_err_1 != other.g_sr_err_1:
            return False
        if self.br_ar_err_2 != other.br_ar_err_2:
            return False
        if self.cr_gr_err_3 != other.cr_gr_err_3:
            return False
        if self.sr_mp_err_4 != other.sr_mp_err_4:
            return False
        if self.syn_temp_err_5 != other.syn_temp_err_5:
            return False
        if self.dl_err_1 != other.dl_err_1:
            return False
        if self.dl_err_2 != other.dl_err_2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def test_index(self):
        """Message field 'test_index'."""
        return self._test_index

    @test_index.setter
    def test_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'test_index' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'test_index' field must be an unsigned integer in [0, 65535]"
        self._test_index = value

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
            assert value >= -32768 and value < 32768, \
                "The 'test_phase' field must be an integer in [-32768, 32767]"
        self._test_phase = value

    @property
    def mpf_phase(self):
        """Message field 'mpf_phase'."""
        return self._mpf_phase

    @mpf_phase.setter
    def mpf_phase(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mpf_phase' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mpf_phase' field must be an integer in [-2147483648, 2147483647]"
        self._mpf_phase = value

    @property
    def path_dist(self):
        """Message field 'path_dist'."""
        return self._path_dist

    @path_dist.setter
    def path_dist(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'path_dist' field must be of type 'float'"
        self._path_dist = value

    @property
    def desire_speed(self):
        """Message field 'desire_speed'."""
        return self._desire_speed

    @desire_speed.setter
    def desire_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'desire_speed' field must be of type 'float'"
        self._desire_speed = value

    @property
    def pf_test_true(self):
        """Message field 'pf_test_true'."""
        return self._pf_test_true

    @pf_test_true.setter
    def pf_test_true(self, value):
        if __debug__:
            from collections.abc import ByteString
            assert \
                (isinstance(value, (bytes, ByteString)) and
                 len(value) == 1), \
                "The 'pf_test_true' field must be of type 'bytes' or 'ByteString' with length 1"
        self._pf_test_true = value

    @property
    def max_path_err_left(self):
        """Message field 'max_path_err_left'."""
        return self._max_path_err_left

    @max_path_err_left.setter
    def max_path_err_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_path_err_left' field must be of type 'float'"
        self._max_path_err_left = value

    @property
    def max_path_err_right(self):
        """Message field 'max_path_err_right'."""
        return self._max_path_err_right

    @max_path_err_right.setter
    def max_path_err_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_path_err_right' field must be of type 'float'"
        self._max_path_err_right = value

    @property
    def current_path_exit_index(self):
        """Message field 'current_path_exit_index'."""
        return self._current_path_exit_index

    @current_path_exit_index.setter
    def current_path_exit_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_path_exit_index' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'current_path_exit_index' field must be an integer in [-32768, 32767]"
        self._current_path_exit_index = value

    @property
    def dl_status_1(self):
        """Message field 'dl_status_1'."""
        return self._dl_status_1

    @dl_status_1.setter
    def dl_status_1(self, value):
        if __debug__:
            from collections.abc import ByteString
            assert \
                (isinstance(value, (bytes, ByteString)) and
                 len(value) == 1), \
                "The 'dl_status_1' field must be of type 'bytes' or 'ByteString' with length 1"
        self._dl_status_1 = value

    @property
    def dl_status_2(self):
        """Message field 'dl_status_2'."""
        return self._dl_status_2

    @dl_status_2.setter
    def dl_status_2(self, value):
        if __debug__:
            from collections.abc import ByteString
            assert \
                (isinstance(value, (bytes, ByteString)) and
                 len(value) == 1), \
                "The 'dl_status_2' field must be of type 'bytes' or 'ByteString' with length 1"
        self._dl_status_2 = value

    @property
    def dl_test_procedure_state(self):
        """Message field 'dl_test_procedure_state'."""
        return self._dl_test_procedure_state

    @dl_test_procedure_state.setter
    def dl_test_procedure_state(self, value):
        if __debug__:
            from collections.abc import ByteString
            assert \
                (isinstance(value, (bytes, ByteString)) and
                 len(value) == 1), \
                "The 'dl_test_procedure_state' field must be of type 'bytes' or 'ByteString' with length 1"
        self._dl_test_procedure_state = value

    @property
    def test_in_progress(self):
        """Message field 'test_in_progress'."""
        return self._test_in_progress

    @test_in_progress.setter
    def test_in_progress(self, value):
        if __debug__:
            from collections.abc import ByteString
            assert \
                (isinstance(value, (bytes, ByteString)) and
                 len(value) == 1), \
                "The 'test_in_progress' field must be of type 'bytes' or 'ByteString' with length 1"
        self._test_in_progress = value

    @property
    def ar_control_mode(self):
        """Message field 'ar_control_mode'."""
        return self._ar_control_mode

    @ar_control_mode.setter
    def ar_control_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ar_control_mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ar_control_mode' field must be an integer in [-2147483648, 2147483647]"
        self._ar_control_mode = value

    @property
    def mp_status(self):
        """Message field 'mp_status'."""
        return self._mp_status

    @mp_status.setter
    def mp_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mp_status' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mp_status' field must be an integer in [-2147483648, 2147483647]"
        self._mp_status = value

    @property
    def g_sr_err_1(self):
        """Message field 'g_sr_err_1'."""
        return self._g_sr_err_1

    @g_sr_err_1.setter
    def g_sr_err_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'g_sr_err_1' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'g_sr_err_1' field must be an unsigned integer in [0, 4294967295]"
        self._g_sr_err_1 = value

    @property
    def br_ar_err_2(self):
        """Message field 'br_ar_err_2'."""
        return self._br_ar_err_2

    @br_ar_err_2.setter
    def br_ar_err_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'br_ar_err_2' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'br_ar_err_2' field must be an unsigned integer in [0, 4294967295]"
        self._br_ar_err_2 = value

    @property
    def cr_gr_err_3(self):
        """Message field 'cr_gr_err_3'."""
        return self._cr_gr_err_3

    @cr_gr_err_3.setter
    def cr_gr_err_3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cr_gr_err_3' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'cr_gr_err_3' field must be an unsigned integer in [0, 4294967295]"
        self._cr_gr_err_3 = value

    @property
    def sr_mp_err_4(self):
        """Message field 'sr_mp_err_4'."""
        return self._sr_mp_err_4

    @sr_mp_err_4.setter
    def sr_mp_err_4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sr_mp_err_4' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sr_mp_err_4' field must be an unsigned integer in [0, 4294967295]"
        self._sr_mp_err_4 = value

    @property
    def syn_temp_err_5(self):
        """Message field 'syn_temp_err_5'."""
        return self._syn_temp_err_5

    @syn_temp_err_5.setter
    def syn_temp_err_5(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'syn_temp_err_5' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'syn_temp_err_5' field must be an unsigned integer in [0, 4294967295]"
        self._syn_temp_err_5 = value

    @property
    def dl_err_1(self):
        """Message field 'dl_err_1'."""
        return self._dl_err_1

    @dl_err_1.setter
    def dl_err_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dl_err_1' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'dl_err_1' field must be an unsigned integer in [0, 4294967295]"
        self._dl_err_1 = value

    @property
    def dl_err_2(self):
        """Message field 'dl_err_2'."""
        return self._dl_err_2

    @dl_err_2.setter
    def dl_err_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dl_err_2' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'dl_err_2' field must be an unsigned integer in [0, 4294967295]"
        self._dl_err_2 = value
