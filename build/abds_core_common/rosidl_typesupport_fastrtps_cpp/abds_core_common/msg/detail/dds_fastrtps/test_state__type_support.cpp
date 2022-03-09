// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from abds_core_common:msg/TestState.idl
// generated code does not contain a copyright notice
#include "abds_core_common/msg/detail/test_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "abds_core_common/msg/detail/test_state__struct.hpp"

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

namespace abds_core_common
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_serialize(
  const abds_core_common::msg::TestState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: test_id
  cdr << ros_message.test_id;
  // Member: test_phase
  cdr << ros_message.test_phase;
  // Member: test_state
  cdr << ros_message.test_state;
  // Member: path_distance
  cdr << ros_message.path_distance;
  // Member: deceleration_rate
  cdr << ros_message.deceleration_rate;
  // Member: abort_deceleration_rate
  cdr << ros_message.abort_deceleration_rate;
  // Member: desired_speed
  cdr << ros_message.desired_speed;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  abds_core_common::msg::TestState & ros_message)
{
  // Member: test_id
  cdr >> ros_message.test_id;

  // Member: test_phase
  cdr >> ros_message.test_phase;

  // Member: test_state
  cdr >> ros_message.test_state;

  // Member: path_distance
  cdr >> ros_message.path_distance;

  // Member: deceleration_rate
  cdr >> ros_message.deceleration_rate;

  // Member: abort_deceleration_rate
  cdr >> ros_message.abort_deceleration_rate;

  // Member: desired_speed
  cdr >> ros_message.desired_speed;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
get_serialized_size(
  const abds_core_common::msg::TestState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: test_id
  {
    size_t item_size = sizeof(ros_message.test_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: test_phase
  {
    size_t item_size = sizeof(ros_message.test_phase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: test_state
  {
    size_t item_size = sizeof(ros_message.test_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: path_distance
  {
    size_t item_size = sizeof(ros_message.path_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: deceleration_rate
  {
    size_t item_size = sizeof(ros_message.deceleration_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: abort_deceleration_rate
  {
    size_t item_size = sizeof(ros_message.abort_deceleration_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: desired_speed
  {
    size_t item_size = sizeof(ros_message.desired_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
max_serialized_size_TestState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: test_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: test_phase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: test_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: path_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: deceleration_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: abort_deceleration_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: desired_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TestState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const abds_core_common::msg::TestState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TestState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<abds_core_common::msg::TestState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TestState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const abds_core_common::msg::TestState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TestState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_TestState(full_bounded, 0);
}

static message_type_support_callbacks_t _TestState__callbacks = {
  "abds_core_common::msg",
  "TestState",
  _TestState__cdr_serialize,
  _TestState__cdr_deserialize,
  _TestState__get_serialized_size,
  _TestState__max_serialized_size
};

static rosidl_message_type_support_t _TestState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TestState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace abds_core_common

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_abds_core_common
const rosidl_message_type_support_t *
get_message_type_support_handle<abds_core_common::msg::TestState>()
{
  return &abds_core_common::msg::typesupport_fastrtps_cpp::_TestState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, msg, TestState)() {
  return &abds_core_common::msg::typesupport_fastrtps_cpp::_TestState__handle;
}

#ifdef __cplusplus
}
#endif
