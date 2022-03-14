// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice
#include "ether_follow_interfaces/msg/detail/ether_message__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ether_follow_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ether_follow_interfaces/msg/detail/ether_message__struct.h"
#include "ether_follow_interfaces/msg/detail/ether_message__functions.h"
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

#include "rosidl_runtime_c/string.h"  // ip_address
#include "rosidl_runtime_c/string_functions.h"  // ip_address

// forward declare type support functions


using _EtherMessage__ros_msg_type = ether_follow_interfaces__msg__EtherMessage;

static bool _EtherMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _EtherMessage__ros_msg_type * ros_message = static_cast<const _EtherMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: ip_address
  {
    const rosidl_runtime_c__String * str = &ros_message->ip_address;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: steering_cmd
  {
    cdr << ros_message->steering_cmd;
  }

  // Field name: brake_cmd
  {
    cdr << ros_message->brake_cmd;
  }

  // Field name: accel_cmd
  {
    cdr << ros_message->accel_cmd;
  }

  // Field name: gear_cmd
  {
    cdr << ros_message->gear_cmd;
  }

  return true;
}

static bool _EtherMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _EtherMessage__ros_msg_type * ros_message = static_cast<_EtherMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: ip_address
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ip_address.data) {
      rosidl_runtime_c__String__init(&ros_message->ip_address);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ip_address,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ip_address'\n");
      return false;
    }
  }

  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: steering_cmd
  {
    cdr >> ros_message->steering_cmd;
  }

  // Field name: brake_cmd
  {
    cdr >> ros_message->brake_cmd;
  }

  // Field name: accel_cmd
  {
    cdr >> ros_message->accel_cmd;
  }

  // Field name: gear_cmd
  {
    cdr >> ros_message->gear_cmd;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ether_follow_interfaces
size_t get_serialized_size_ether_follow_interfaces__msg__EtherMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EtherMessage__ros_msg_type * ros_message = static_cast<const _EtherMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ip_address
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ip_address.size + 1);
  // field.name version
  {
    size_t item_size = sizeof(ros_message->version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name steering_cmd
  {
    size_t item_size = sizeof(ros_message->steering_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name brake_cmd
  {
    size_t item_size = sizeof(ros_message->brake_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name accel_cmd
  {
    size_t item_size = sizeof(ros_message->accel_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gear_cmd
  {
    size_t item_size = sizeof(ros_message->gear_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _EtherMessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ether_follow_interfaces__msg__EtherMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ether_follow_interfaces
size_t max_serialized_size_ether_follow_interfaces__msg__EtherMessage(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: ip_address
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: version
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: steering_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: brake_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: accel_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gear_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _EtherMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ether_follow_interfaces__msg__EtherMessage(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_EtherMessage = {
  "ether_follow_interfaces::msg",
  "EtherMessage",
  _EtherMessage__cdr_serialize,
  _EtherMessage__cdr_deserialize,
  _EtherMessage__get_serialized_size,
  _EtherMessage__max_serialized_size
};

static rosidl_message_type_support_t _EtherMessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EtherMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ether_follow_interfaces, msg, EtherMessage)() {
  return &_EtherMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
