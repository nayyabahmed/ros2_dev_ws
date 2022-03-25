// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from abds_msgs:msg/TestState.idl
// generated code does not contain a copyright notice
#include "abds_msgs/msg/detail/test_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "abds_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "abds_msgs/msg/detail/test_state__struct.h"
#include "abds_msgs/msg/detail/test_state__functions.h"
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


// forward declare type support functions


using _TestState__ros_msg_type = abds_msgs__msg__TestState;

static bool _TestState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TestState__ros_msg_type * ros_message = static_cast<const _TestState__ros_msg_type *>(untyped_ros_message);
  // Field name: test_id
  {
    cdr << ros_message->test_id;
  }

  // Field name: test_phase
  {
    cdr << ros_message->test_phase;
  }

  // Field name: test_state
  {
    cdr << ros_message->test_state;
  }

  // Field name: path_distance
  {
    cdr << ros_message->path_distance;
  }

  // Field name: deceleration_rate
  {
    cdr << ros_message->deceleration_rate;
  }

  // Field name: abort_deceleration_rate
  {
    cdr << ros_message->abort_deceleration_rate;
  }

  // Field name: desired_speed
  {
    cdr << ros_message->desired_speed;
  }

  return true;
}

static bool _TestState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TestState__ros_msg_type * ros_message = static_cast<_TestState__ros_msg_type *>(untyped_ros_message);
  // Field name: test_id
  {
    cdr >> ros_message->test_id;
  }

  // Field name: test_phase
  {
    cdr >> ros_message->test_phase;
  }

  // Field name: test_state
  {
    cdr >> ros_message->test_state;
  }

  // Field name: path_distance
  {
    cdr >> ros_message->path_distance;
  }

  // Field name: deceleration_rate
  {
    cdr >> ros_message->deceleration_rate;
  }

  // Field name: abort_deceleration_rate
  {
    cdr >> ros_message->abort_deceleration_rate;
  }

  // Field name: desired_speed
  {
    cdr >> ros_message->desired_speed;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_msgs
size_t get_serialized_size_abds_msgs__msg__TestState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TestState__ros_msg_type * ros_message = static_cast<const _TestState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name test_id
  {
    size_t item_size = sizeof(ros_message->test_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name test_phase
  {
    size_t item_size = sizeof(ros_message->test_phase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name test_state
  {
    size_t item_size = sizeof(ros_message->test_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name path_distance
  {
    size_t item_size = sizeof(ros_message->path_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name deceleration_rate
  {
    size_t item_size = sizeof(ros_message->deceleration_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name abort_deceleration_rate
  {
    size_t item_size = sizeof(ros_message->abort_deceleration_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name desired_speed
  {
    size_t item_size = sizeof(ros_message->desired_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TestState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_abds_msgs__msg__TestState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_msgs
size_t max_serialized_size_abds_msgs__msg__TestState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: test_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: test_phase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: test_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: path_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: deceleration_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: abort_deceleration_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: desired_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _TestState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_abds_msgs__msg__TestState(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_TestState = {
  "abds_msgs::msg",
  "TestState",
  _TestState__cdr_serialize,
  _TestState__cdr_deserialize,
  _TestState__get_serialized_size,
  _TestState__max_serialized_size
};

static rosidl_message_type_support_t _TestState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TestState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_msgs, msg, TestState)() {
  return &_TestState__type_support;
}

#if defined(__cplusplus)
}
#endif
