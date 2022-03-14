// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice
#include "ether_follow_interfaces/msg/detail/ether_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ether_follow_interfaces/msg/detail/ether_message__struct.hpp"

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

namespace ether_follow_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ether_follow_interfaces
cdr_serialize(
  const ether_follow_interfaces::msg::EtherMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ip_address
  cdr << ros_message.ip_address;
  // Member: version
  cdr << ros_message.version;
  // Member: steering_cmd
  cdr << ros_message.steering_cmd;
  // Member: brake_cmd
  cdr << ros_message.brake_cmd;
  // Member: accel_cmd
  cdr << ros_message.accel_cmd;
  // Member: gear_cmd
  cdr << ros_message.gear_cmd;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ether_follow_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ether_follow_interfaces::msg::EtherMessage & ros_message)
{
  // Member: ip_address
  cdr >> ros_message.ip_address;

  // Member: version
  cdr >> ros_message.version;

  // Member: steering_cmd
  cdr >> ros_message.steering_cmd;

  // Member: brake_cmd
  cdr >> ros_message.brake_cmd;

  // Member: accel_cmd
  cdr >> ros_message.accel_cmd;

  // Member: gear_cmd
  cdr >> ros_message.gear_cmd;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ether_follow_interfaces
get_serialized_size(
  const ether_follow_interfaces::msg::EtherMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ip_address
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.ip_address.size() + 1);
  // Member: version
  {
    size_t item_size = sizeof(ros_message.version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: steering_cmd
  {
    size_t item_size = sizeof(ros_message.steering_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: brake_cmd
  {
    size_t item_size = sizeof(ros_message.brake_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: accel_cmd
  {
    size_t item_size = sizeof(ros_message.accel_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gear_cmd
  {
    size_t item_size = sizeof(ros_message.gear_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ether_follow_interfaces
max_serialized_size_EtherMessage(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: ip_address
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: version
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: steering_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: brake_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: accel_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gear_cmd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _EtherMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ether_follow_interfaces::msg::EtherMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _EtherMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ether_follow_interfaces::msg::EtherMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _EtherMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ether_follow_interfaces::msg::EtherMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _EtherMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_EtherMessage(full_bounded, 0);
}

static message_type_support_callbacks_t _EtherMessage__callbacks = {
  "ether_follow_interfaces::msg",
  "EtherMessage",
  _EtherMessage__cdr_serialize,
  _EtherMessage__cdr_deserialize,
  _EtherMessage__get_serialized_size,
  _EtherMessage__max_serialized_size
};

static rosidl_message_type_support_t _EtherMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_EtherMessage__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ether_follow_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ether_follow_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ether_follow_interfaces::msg::EtherMessage>()
{
  return &ether_follow_interfaces::msg::typesupport_fastrtps_cpp::_EtherMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ether_follow_interfaces, msg, EtherMessage)() {
  return &ether_follow_interfaces::msg::typesupport_fastrtps_cpp::_EtherMessage__handle;
}

#ifdef __cplusplus
}
#endif
