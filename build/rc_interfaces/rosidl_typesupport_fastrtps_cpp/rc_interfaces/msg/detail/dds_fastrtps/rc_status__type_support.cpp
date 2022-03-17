// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice
#include "rc_interfaces/msg/detail/rc_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rc_interfaces/msg/detail/rc_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace rc_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rc_interfaces
cdr_serialize(
  const rc_interfaces::msg::RcStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: test_index
  cdr << ros_message.test_index;
  // Member: test_phase
  cdr << ros_message.test_phase;
  // Member: mpf_phase
  cdr << ros_message.mpf_phase;
  // Member: path_dist
  cdr << ros_message.path_dist;
  // Member: desire_speed
  cdr << ros_message.desire_speed;
  // Member: pf_test_true
  cdr << ros_message.pf_test_true;
  // Member: max_path_err_left
  cdr << ros_message.max_path_err_left;
  // Member: max_path_err_right
  cdr << ros_message.max_path_err_right;
  // Member: current_path_exit_index
  cdr << ros_message.current_path_exit_index;
  // Member: dl_status_1
  cdr << ros_message.dl_status_1;
  // Member: dl_status_2
  cdr << ros_message.dl_status_2;
  // Member: dl_test_procedure_state
  cdr << ros_message.dl_test_procedure_state;
  // Member: test_in_progress
  cdr << ros_message.test_in_progress;
  // Member: ar_control_mode
  cdr << ros_message.ar_control_mode;
  // Member: mp_status
  cdr << ros_message.mp_status;
  // Member: g_sr_err_1
  cdr << ros_message.g_sr_err_1;
  // Member: br_ar_err_2
  cdr << ros_message.br_ar_err_2;
  // Member: cr_gr_err_3
  cdr << ros_message.cr_gr_err_3;
  // Member: sr_mp_err_4
  cdr << ros_message.sr_mp_err_4;
  // Member: syn_temp_err_5
  cdr << ros_message.syn_temp_err_5;
  // Member: dl_err_1
  cdr << ros_message.dl_err_1;
  // Member: dl_err_2
  cdr << ros_message.dl_err_2;
  // Member: dl_test_data_loaded
  cdr << ros_message.dl_test_data_loaded;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rc_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rc_interfaces::msg::RcStatus & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: test_index
  cdr >> ros_message.test_index;

  // Member: test_phase
  cdr >> ros_message.test_phase;

  // Member: mpf_phase
  cdr >> ros_message.mpf_phase;

  // Member: path_dist
  cdr >> ros_message.path_dist;

  // Member: desire_speed
  cdr >> ros_message.desire_speed;

  // Member: pf_test_true
  cdr >> ros_message.pf_test_true;

  // Member: max_path_err_left
  cdr >> ros_message.max_path_err_left;

  // Member: max_path_err_right
  cdr >> ros_message.max_path_err_right;

  // Member: current_path_exit_index
  cdr >> ros_message.current_path_exit_index;

  // Member: dl_status_1
  cdr >> ros_message.dl_status_1;

  // Member: dl_status_2
  cdr >> ros_message.dl_status_2;

  // Member: dl_test_procedure_state
  cdr >> ros_message.dl_test_procedure_state;

  // Member: test_in_progress
  cdr >> ros_message.test_in_progress;

  // Member: ar_control_mode
  cdr >> ros_message.ar_control_mode;

  // Member: mp_status
  cdr >> ros_message.mp_status;

  // Member: g_sr_err_1
  cdr >> ros_message.g_sr_err_1;

  // Member: br_ar_err_2
  cdr >> ros_message.br_ar_err_2;

  // Member: cr_gr_err_3
  cdr >> ros_message.cr_gr_err_3;

  // Member: sr_mp_err_4
  cdr >> ros_message.sr_mp_err_4;

  // Member: syn_temp_err_5
  cdr >> ros_message.syn_temp_err_5;

  // Member: dl_err_1
  cdr >> ros_message.dl_err_1;

  // Member: dl_err_2
  cdr >> ros_message.dl_err_2;

  // Member: dl_test_data_loaded
  cdr >> ros_message.dl_test_data_loaded;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rc_interfaces
get_serialized_size(
  const rc_interfaces::msg::RcStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: test_index
  {
    size_t item_size = sizeof(ros_message.test_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: test_phase
  {
    size_t item_size = sizeof(ros_message.test_phase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mpf_phase
  {
    size_t item_size = sizeof(ros_message.mpf_phase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: path_dist
  {
    size_t item_size = sizeof(ros_message.path_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: desire_speed
  {
    size_t item_size = sizeof(ros_message.desire_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pf_test_true
  {
    size_t item_size = sizeof(ros_message.pf_test_true);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_path_err_left
  {
    size_t item_size = sizeof(ros_message.max_path_err_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_path_err_right
  {
    size_t item_size = sizeof(ros_message.max_path_err_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_path_exit_index
  {
    size_t item_size = sizeof(ros_message.current_path_exit_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dl_status_1
  {
    size_t item_size = sizeof(ros_message.dl_status_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dl_status_2
  {
    size_t item_size = sizeof(ros_message.dl_status_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dl_test_procedure_state
  {
    size_t item_size = sizeof(ros_message.dl_test_procedure_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: test_in_progress
  {
    size_t item_size = sizeof(ros_message.test_in_progress);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ar_control_mode
  {
    size_t item_size = sizeof(ros_message.ar_control_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mp_status
  {
    size_t item_size = sizeof(ros_message.mp_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: g_sr_err_1
  {
    size_t item_size = sizeof(ros_message.g_sr_err_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: br_ar_err_2
  {
    size_t item_size = sizeof(ros_message.br_ar_err_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cr_gr_err_3
  {
    size_t item_size = sizeof(ros_message.cr_gr_err_3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sr_mp_err_4
  {
    size_t item_size = sizeof(ros_message.sr_mp_err_4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: syn_temp_err_5
  {
    size_t item_size = sizeof(ros_message.syn_temp_err_5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dl_err_1
  {
    size_t item_size = sizeof(ros_message.dl_err_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dl_err_2
  {
    size_t item_size = sizeof(ros_message.dl_err_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dl_test_data_loaded
  {
    size_t item_size = sizeof(ros_message.dl_test_data_loaded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rc_interfaces
max_serialized_size_RcStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: test_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: test_phase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: mpf_phase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: path_dist
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: desire_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pf_test_true
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: max_path_err_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_path_err_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_path_exit_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: dl_status_1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: dl_status_2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: dl_test_procedure_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: test_in_progress
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ar_control_mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: mp_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: g_sr_err_1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: br_ar_err_2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: cr_gr_err_3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sr_mp_err_4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: syn_temp_err_5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: dl_err_1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: dl_err_2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: dl_test_data_loaded
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _RcStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rc_interfaces::msg::RcStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RcStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rc_interfaces::msg::RcStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RcStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rc_interfaces::msg::RcStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RcStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RcStatus(full_bounded, 0);
}

static message_type_support_callbacks_t _RcStatus__callbacks = {
  "rc_interfaces::msg",
  "RcStatus",
  _RcStatus__cdr_serialize,
  _RcStatus__cdr_deserialize,
  _RcStatus__get_serialized_size,
  _RcStatus__max_serialized_size
};

static rosidl_message_type_support_t _RcStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RcStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rc_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rc_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<rc_interfaces::msg::RcStatus>()
{
  return &rc_interfaces::msg::typesupport_fastrtps_cpp::_RcStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rc_interfaces, msg, RcStatus)() {
  return &rc_interfaces::msg::typesupport_fastrtps_cpp::_RcStatus__handle;
}

#ifdef __cplusplus
}
#endif
