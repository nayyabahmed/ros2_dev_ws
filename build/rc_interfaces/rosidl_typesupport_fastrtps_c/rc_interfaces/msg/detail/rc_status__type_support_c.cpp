// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice
#include "rc_interfaces/msg/detail/rc_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rc_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rc_interfaces/msg/detail/rc_status__struct.h"
#include "rc_interfaces/msg/detail/rc_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_rc_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_rc_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_rc_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _RcStatus__ros_msg_type = rc_interfaces__msg__RcStatus;

static bool _RcStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RcStatus__ros_msg_type * ros_message = static_cast<const _RcStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: test_index
  {
    cdr << ros_message->test_index;
  }

  // Field name: test_phase
  {
    cdr << ros_message->test_phase;
  }

  // Field name: mpf_phase
  {
    cdr << ros_message->mpf_phase;
  }

  // Field name: path_dist
  {
    cdr << ros_message->path_dist;
  }

  // Field name: desire_speed
  {
    cdr << ros_message->desire_speed;
  }

  // Field name: pf_test_true
  {
    cdr << ros_message->pf_test_true;
  }

  // Field name: max_path_err_left
  {
    cdr << ros_message->max_path_err_left;
  }

  // Field name: max_path_err_right
  {
    cdr << ros_message->max_path_err_right;
  }

  // Field name: current_path_exit_index
  {
    cdr << ros_message->current_path_exit_index;
  }

  // Field name: dl_status_1
  {
    cdr << ros_message->dl_status_1;
  }

  // Field name: dl_status_2
  {
    cdr << ros_message->dl_status_2;
  }

  // Field name: dl_test_procedure_state
  {
    cdr << ros_message->dl_test_procedure_state;
  }

  // Field name: test_in_progress
  {
    cdr << ros_message->test_in_progress;
  }

  // Field name: ar_control_mode
  {
    cdr << ros_message->ar_control_mode;
  }

  // Field name: mp_status
  {
    cdr << ros_message->mp_status;
  }

  // Field name: g_sr_err_1
  {
    cdr << ros_message->g_sr_err_1;
  }

  // Field name: br_ar_err_2
  {
    cdr << ros_message->br_ar_err_2;
  }

  // Field name: cr_gr_err_3
  {
    cdr << ros_message->cr_gr_err_3;
  }

  // Field name: sr_mp_err_4
  {
    cdr << ros_message->sr_mp_err_4;
  }

  // Field name: syn_temp_err_5
  {
    cdr << ros_message->syn_temp_err_5;
  }

  // Field name: dl_err_1
  {
    cdr << ros_message->dl_err_1;
  }

  // Field name: dl_err_2
  {
    cdr << ros_message->dl_err_2;
  }

  return true;
}

static bool _RcStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RcStatus__ros_msg_type * ros_message = static_cast<_RcStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: test_index
  {
    cdr >> ros_message->test_index;
  }

  // Field name: test_phase
  {
    cdr >> ros_message->test_phase;
  }

  // Field name: mpf_phase
  {
    cdr >> ros_message->mpf_phase;
  }

  // Field name: path_dist
  {
    cdr >> ros_message->path_dist;
  }

  // Field name: desire_speed
  {
    cdr >> ros_message->desire_speed;
  }

  // Field name: pf_test_true
  {
    cdr >> ros_message->pf_test_true;
  }

  // Field name: max_path_err_left
  {
    cdr >> ros_message->max_path_err_left;
  }

  // Field name: max_path_err_right
  {
    cdr >> ros_message->max_path_err_right;
  }

  // Field name: current_path_exit_index
  {
    cdr >> ros_message->current_path_exit_index;
  }

  // Field name: dl_status_1
  {
    cdr >> ros_message->dl_status_1;
  }

  // Field name: dl_status_2
  {
    cdr >> ros_message->dl_status_2;
  }

  // Field name: dl_test_procedure_state
  {
    cdr >> ros_message->dl_test_procedure_state;
  }

  // Field name: test_in_progress
  {
    cdr >> ros_message->test_in_progress;
  }

  // Field name: ar_control_mode
  {
    cdr >> ros_message->ar_control_mode;
  }

  // Field name: mp_status
  {
    cdr >> ros_message->mp_status;
  }

  // Field name: g_sr_err_1
  {
    cdr >> ros_message->g_sr_err_1;
  }

  // Field name: br_ar_err_2
  {
    cdr >> ros_message->br_ar_err_2;
  }

  // Field name: cr_gr_err_3
  {
    cdr >> ros_message->cr_gr_err_3;
  }

  // Field name: sr_mp_err_4
  {
    cdr >> ros_message->sr_mp_err_4;
  }

  // Field name: syn_temp_err_5
  {
    cdr >> ros_message->syn_temp_err_5;
  }

  // Field name: dl_err_1
  {
    cdr >> ros_message->dl_err_1;
  }

  // Field name: dl_err_2
  {
    cdr >> ros_message->dl_err_2;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rc_interfaces
size_t get_serialized_size_rc_interfaces__msg__RcStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RcStatus__ros_msg_type * ros_message = static_cast<const _RcStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name test_index
  {
    size_t item_size = sizeof(ros_message->test_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name test_phase
  {
    size_t item_size = sizeof(ros_message->test_phase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mpf_phase
  {
    size_t item_size = sizeof(ros_message->mpf_phase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name path_dist
  {
    size_t item_size = sizeof(ros_message->path_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name desire_speed
  {
    size_t item_size = sizeof(ros_message->desire_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pf_test_true
  {
    size_t item_size = sizeof(ros_message->pf_test_true);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_path_err_left
  {
    size_t item_size = sizeof(ros_message->max_path_err_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_path_err_right
  {
    size_t item_size = sizeof(ros_message->max_path_err_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_path_exit_index
  {
    size_t item_size = sizeof(ros_message->current_path_exit_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dl_status_1
  {
    size_t item_size = sizeof(ros_message->dl_status_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dl_status_2
  {
    size_t item_size = sizeof(ros_message->dl_status_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dl_test_procedure_state
  {
    size_t item_size = sizeof(ros_message->dl_test_procedure_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name test_in_progress
  {
    size_t item_size = sizeof(ros_message->test_in_progress);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ar_control_mode
  {
    size_t item_size = sizeof(ros_message->ar_control_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mp_status
  {
    size_t item_size = sizeof(ros_message->mp_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name g_sr_err_1
  {
    size_t item_size = sizeof(ros_message->g_sr_err_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name br_ar_err_2
  {
    size_t item_size = sizeof(ros_message->br_ar_err_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cr_gr_err_3
  {
    size_t item_size = sizeof(ros_message->cr_gr_err_3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sr_mp_err_4
  {
    size_t item_size = sizeof(ros_message->sr_mp_err_4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name syn_temp_err_5
  {
    size_t item_size = sizeof(ros_message->syn_temp_err_5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dl_err_1
  {
    size_t item_size = sizeof(ros_message->dl_err_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dl_err_2
  {
    size_t item_size = sizeof(ros_message->dl_err_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RcStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rc_interfaces__msg__RcStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rc_interfaces
size_t max_serialized_size_rc_interfaces__msg__RcStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: test_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: test_phase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: mpf_phase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: path_dist
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: desire_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pf_test_true
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: max_path_err_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: max_path_err_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_path_exit_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: dl_status_1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: dl_status_2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: dl_test_procedure_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: test_in_progress
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ar_control_mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: mp_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: g_sr_err_1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: br_ar_err_2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: cr_gr_err_3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: sr_mp_err_4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: syn_temp_err_5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: dl_err_1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: dl_err_2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _RcStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rc_interfaces__msg__RcStatus(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RcStatus = {
  "rc_interfaces::msg",
  "RcStatus",
  _RcStatus__cdr_serialize,
  _RcStatus__cdr_deserialize,
  _RcStatus__get_serialized_size,
  _RcStatus__max_serialized_size
};

static rosidl_message_type_support_t _RcStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RcStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rc_interfaces, msg, RcStatus)() {
  return &_RcStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
