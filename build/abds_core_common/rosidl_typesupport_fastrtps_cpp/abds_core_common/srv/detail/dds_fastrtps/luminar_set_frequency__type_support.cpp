// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from abds_core_common:srv/LuminarSetFrequency.idl
// generated code does not contain a copyright notice
#include "abds_core_common/srv/detail/luminar_set_frequency__rosidl_typesupport_fastrtps_cpp.hpp"
#include "abds_core_common/srv/detail/luminar_set_frequency__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_serialize(
  const abds_core_common::srv::LuminarSetFrequency_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: frequency
  cdr << ros_message.frequency;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  abds_core_common::srv::LuminarSetFrequency_Request & ros_message)
{
  // Member: frequency
  cdr >> ros_message.frequency;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
get_serialized_size(
  const abds_core_common::srv::LuminarSetFrequency_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: frequency
  {
    size_t item_size = sizeof(ros_message.frequency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
max_serialized_size_LuminarSetFrequency_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: frequency
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LuminarSetFrequency_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarSetFrequency_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LuminarSetFrequency_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<abds_core_common::srv::LuminarSetFrequency_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LuminarSetFrequency_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarSetFrequency_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LuminarSetFrequency_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LuminarSetFrequency_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _LuminarSetFrequency_Request__callbacks = {
  "abds_core_common::srv",
  "LuminarSetFrequency_Request",
  _LuminarSetFrequency_Request__cdr_serialize,
  _LuminarSetFrequency_Request__cdr_deserialize,
  _LuminarSetFrequency_Request__get_serialized_size,
  _LuminarSetFrequency_Request__max_serialized_size
};

static rosidl_message_type_support_t _LuminarSetFrequency_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LuminarSetFrequency_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace abds_core_common

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_abds_core_common
const rosidl_message_type_support_t *
get_message_type_support_handle<abds_core_common::srv::LuminarSetFrequency_Request>()
{
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarSetFrequency_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarSetFrequency_Request)() {
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarSetFrequency_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace abds_core_common
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_serialize(
  const abds_core_common::srv::LuminarSetFrequency_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: result
  cdr << ros_message.result;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  abds_core_common::srv::LuminarSetFrequency_Response & ros_message)
{
  // Member: result
  cdr >> ros_message.result;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
get_serialized_size(
  const abds_core_common::srv::LuminarSetFrequency_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: result
  {
    size_t item_size = sizeof(ros_message.result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
max_serialized_size_LuminarSetFrequency_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: result
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _LuminarSetFrequency_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarSetFrequency_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LuminarSetFrequency_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<abds_core_common::srv::LuminarSetFrequency_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LuminarSetFrequency_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarSetFrequency_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LuminarSetFrequency_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LuminarSetFrequency_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _LuminarSetFrequency_Response__callbacks = {
  "abds_core_common::srv",
  "LuminarSetFrequency_Response",
  _LuminarSetFrequency_Response__cdr_serialize,
  _LuminarSetFrequency_Response__cdr_deserialize,
  _LuminarSetFrequency_Response__get_serialized_size,
  _LuminarSetFrequency_Response__max_serialized_size
};

static rosidl_message_type_support_t _LuminarSetFrequency_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LuminarSetFrequency_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace abds_core_common

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_abds_core_common
const rosidl_message_type_support_t *
get_message_type_support_handle<abds_core_common::srv::LuminarSetFrequency_Response>()
{
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarSetFrequency_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarSetFrequency_Response)() {
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarSetFrequency_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace abds_core_common
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _LuminarSetFrequency__callbacks = {
  "abds_core_common::srv",
  "LuminarSetFrequency",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarSetFrequency_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarSetFrequency_Response)(),
};

static rosidl_service_type_support_t _LuminarSetFrequency__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LuminarSetFrequency__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace abds_core_common

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_abds_core_common
const rosidl_service_type_support_t *
get_service_type_support_handle<abds_core_common::srv::LuminarSetFrequency>()
{
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarSetFrequency__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarSetFrequency)() {
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarSetFrequency__handle;
}

#ifdef __cplusplus
}
#endif
