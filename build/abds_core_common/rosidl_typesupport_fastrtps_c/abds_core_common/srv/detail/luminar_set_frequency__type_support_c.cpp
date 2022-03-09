// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from abds_core_common:srv/LuminarSetFrequency.idl
// generated code does not contain a copyright notice
#include "abds_core_common/srv/detail/luminar_set_frequency__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "abds_core_common/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "abds_core_common/srv/detail/luminar_set_frequency__struct.h"
#include "abds_core_common/srv/detail/luminar_set_frequency__functions.h"
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


using _LuminarSetFrequency_Request__ros_msg_type = abds_core_common__srv__LuminarSetFrequency_Request;

static bool _LuminarSetFrequency_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LuminarSetFrequency_Request__ros_msg_type * ros_message = static_cast<const _LuminarSetFrequency_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: frequency
  {
    cdr << ros_message->frequency;
  }

  return true;
}

static bool _LuminarSetFrequency_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LuminarSetFrequency_Request__ros_msg_type * ros_message = static_cast<_LuminarSetFrequency_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: frequency
  {
    cdr >> ros_message->frequency;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_core_common
size_t get_serialized_size_abds_core_common__srv__LuminarSetFrequency_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LuminarSetFrequency_Request__ros_msg_type * ros_message = static_cast<const _LuminarSetFrequency_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name frequency
  {
    size_t item_size = sizeof(ros_message->frequency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LuminarSetFrequency_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_abds_core_common__srv__LuminarSetFrequency_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_core_common
size_t max_serialized_size_abds_core_common__srv__LuminarSetFrequency_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: frequency
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LuminarSetFrequency_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_abds_core_common__srv__LuminarSetFrequency_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_LuminarSetFrequency_Request = {
  "abds_core_common::srv",
  "LuminarSetFrequency_Request",
  _LuminarSetFrequency_Request__cdr_serialize,
  _LuminarSetFrequency_Request__cdr_deserialize,
  _LuminarSetFrequency_Request__get_serialized_size,
  _LuminarSetFrequency_Request__max_serialized_size
};

static rosidl_message_type_support_t _LuminarSetFrequency_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LuminarSetFrequency_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_core_common, srv, LuminarSetFrequency_Request)() {
  return &_LuminarSetFrequency_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "abds_core_common/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_set_frequency__struct.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_set_frequency__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


using _LuminarSetFrequency_Response__ros_msg_type = abds_core_common__srv__LuminarSetFrequency_Response;

static bool _LuminarSetFrequency_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LuminarSetFrequency_Response__ros_msg_type * ros_message = static_cast<const _LuminarSetFrequency_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    cdr << ros_message->result;
  }

  return true;
}

static bool _LuminarSetFrequency_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LuminarSetFrequency_Response__ros_msg_type * ros_message = static_cast<_LuminarSetFrequency_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    cdr >> ros_message->result;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_core_common
size_t get_serialized_size_abds_core_common__srv__LuminarSetFrequency_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LuminarSetFrequency_Response__ros_msg_type * ros_message = static_cast<const _LuminarSetFrequency_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name result
  {
    size_t item_size = sizeof(ros_message->result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LuminarSetFrequency_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_abds_core_common__srv__LuminarSetFrequency_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_core_common
size_t max_serialized_size_abds_core_common__srv__LuminarSetFrequency_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: result
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _LuminarSetFrequency_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_abds_core_common__srv__LuminarSetFrequency_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_LuminarSetFrequency_Response = {
  "abds_core_common::srv",
  "LuminarSetFrequency_Response",
  _LuminarSetFrequency_Response__cdr_serialize,
  _LuminarSetFrequency_Response__cdr_deserialize,
  _LuminarSetFrequency_Response__get_serialized_size,
  _LuminarSetFrequency_Response__max_serialized_size
};

static rosidl_message_type_support_t _LuminarSetFrequency_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LuminarSetFrequency_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_core_common, srv, LuminarSetFrequency_Response)() {
  return &_LuminarSetFrequency_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "abds_core_common/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "abds_core_common/srv/luminar_set_frequency.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t LuminarSetFrequency__callbacks = {
  "abds_core_common::srv",
  "LuminarSetFrequency",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_core_common, srv, LuminarSetFrequency_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_core_common, srv, LuminarSetFrequency_Response)(),
};

static rosidl_service_type_support_t LuminarSetFrequency__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &LuminarSetFrequency__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_core_common, srv, LuminarSetFrequency)() {
  return &LuminarSetFrequency__handle;
}

#if defined(__cplusplus)
}
#endif
