// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from abds_core_common:srv/LuminarDiscoverSensors.idl
// generated code does not contain a copyright notice
#include "abds_core_common/srv/detail/luminar_discover_sensors__rosidl_typesupport_fastrtps_cpp.hpp"
#include "abds_core_common/srv/detail/luminar_discover_sensors__struct.hpp"

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
  const abds_core_common::srv::LuminarDiscoverSensors_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  abds_core_common::srv::LuminarDiscoverSensors_Request & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
get_serialized_size(
  const abds_core_common::srv::LuminarDiscoverSensors_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
max_serialized_size_LuminarDiscoverSensors_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _LuminarDiscoverSensors_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarDiscoverSensors_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LuminarDiscoverSensors_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<abds_core_common::srv::LuminarDiscoverSensors_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LuminarDiscoverSensors_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarDiscoverSensors_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LuminarDiscoverSensors_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LuminarDiscoverSensors_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _LuminarDiscoverSensors_Request__callbacks = {
  "abds_core_common::srv",
  "LuminarDiscoverSensors_Request",
  _LuminarDiscoverSensors_Request__cdr_serialize,
  _LuminarDiscoverSensors_Request__cdr_deserialize,
  _LuminarDiscoverSensors_Request__get_serialized_size,
  _LuminarDiscoverSensors_Request__max_serialized_size
};

static rosidl_message_type_support_t _LuminarDiscoverSensors_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LuminarDiscoverSensors_Request__callbacks,
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
get_message_type_support_handle<abds_core_common::srv::LuminarDiscoverSensors_Request>()
{
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarDiscoverSensors_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarDiscoverSensors_Request)() {
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarDiscoverSensors_Request__handle;
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
  const abds_core_common::srv::LuminarDiscoverSensors_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sensors_found
  cdr << ros_message.sensors_found;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  abds_core_common::srv::LuminarDiscoverSensors_Response & ros_message)
{
  // Member: sensors_found
  cdr >> ros_message.sensors_found;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
get_serialized_size(
  const abds_core_common::srv::LuminarDiscoverSensors_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sensors_found
  {
    size_t item_size = sizeof(ros_message.sensors_found);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_abds_core_common
max_serialized_size_LuminarDiscoverSensors_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: sensors_found
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _LuminarDiscoverSensors_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarDiscoverSensors_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LuminarDiscoverSensors_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<abds_core_common::srv::LuminarDiscoverSensors_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LuminarDiscoverSensors_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const abds_core_common::srv::LuminarDiscoverSensors_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LuminarDiscoverSensors_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LuminarDiscoverSensors_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _LuminarDiscoverSensors_Response__callbacks = {
  "abds_core_common::srv",
  "LuminarDiscoverSensors_Response",
  _LuminarDiscoverSensors_Response__cdr_serialize,
  _LuminarDiscoverSensors_Response__cdr_deserialize,
  _LuminarDiscoverSensors_Response__get_serialized_size,
  _LuminarDiscoverSensors_Response__max_serialized_size
};

static rosidl_message_type_support_t _LuminarDiscoverSensors_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LuminarDiscoverSensors_Response__callbacks,
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
get_message_type_support_handle<abds_core_common::srv::LuminarDiscoverSensors_Response>()
{
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarDiscoverSensors_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarDiscoverSensors_Response)() {
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarDiscoverSensors_Response__handle;
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

static service_type_support_callbacks_t _LuminarDiscoverSensors__callbacks = {
  "abds_core_common::srv",
  "LuminarDiscoverSensors",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarDiscoverSensors_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarDiscoverSensors_Response)(),
};

static rosidl_service_type_support_t _LuminarDiscoverSensors__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LuminarDiscoverSensors__callbacks,
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
get_service_type_support_handle<abds_core_common::srv::LuminarDiscoverSensors>()
{
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarDiscoverSensors__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, abds_core_common, srv, LuminarDiscoverSensors)() {
  return &abds_core_common::srv::typesupport_fastrtps_cpp::_LuminarDiscoverSensors__handle;
}

#ifdef __cplusplus
}
#endif
