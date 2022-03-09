// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from abds_core_common:msg/VehicleCommand.idl
// generated code does not contain a copyright notice
#include "abds_core_common/msg/detail/vehicle_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "abds_core_common/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "abds_core_common/msg/detail/vehicle_command__struct.h"
#include "abds_core_common/msg/detail/vehicle_command__functions.h"
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

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_abds_core_common
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_abds_core_common
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_abds_core_common
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();


using _VehicleCommand__ros_msg_type = abds_core_common__msg__VehicleCommand;

static bool _VehicleCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehicleCommand__ros_msg_type * ros_message = static_cast<const _VehicleCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->stamp, cdr))
    {
      return false;
    }
  }

  // Field name: long_accel
  {
    cdr << ros_message->long_accel;
  }

  // Field name: velocity_modifier
  {
    cdr << ros_message->velocity_modifier;
  }

  // Field name: front_wheel_angle
  {
    cdr << ros_message->front_wheel_angle;
  }

  // Field name: rear_wheel_angle
  {
    cdr << ros_message->rear_wheel_angle;
  }

  return true;
}

static bool _VehicleCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehicleCommand__ros_msg_type * ros_message = static_cast<_VehicleCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->stamp))
    {
      return false;
    }
  }

  // Field name: long_accel
  {
    cdr >> ros_message->long_accel;
  }

  // Field name: velocity_modifier
  {
    cdr >> ros_message->velocity_modifier;
  }

  // Field name: front_wheel_angle
  {
    cdr >> ros_message->front_wheel_angle;
  }

  // Field name: rear_wheel_angle
  {
    cdr >> ros_message->rear_wheel_angle;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_core_common
size_t get_serialized_size_abds_core_common__msg__VehicleCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehicleCommand__ros_msg_type * ros_message = static_cast<const _VehicleCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name stamp

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);
  // field.name long_accel
  {
    size_t item_size = sizeof(ros_message->long_accel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name velocity_modifier
  {
    size_t item_size = sizeof(ros_message->velocity_modifier);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name front_wheel_angle
  {
    size_t item_size = sizeof(ros_message->front_wheel_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rear_wheel_angle
  {
    size_t item_size = sizeof(ros_message->rear_wheel_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VehicleCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_abds_core_common__msg__VehicleCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_abds_core_common
size_t max_serialized_size_abds_core_common__msg__VehicleCommand(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: stamp
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_builtin_interfaces__msg__Time(
        full_bounded, current_alignment);
    }
  }
  // member: long_accel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: velocity_modifier
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: front_wheel_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rear_wheel_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _VehicleCommand__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_abds_core_common__msg__VehicleCommand(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehicleCommand = {
  "abds_core_common::msg",
  "VehicleCommand",
  _VehicleCommand__cdr_serialize,
  _VehicleCommand__cdr_deserialize,
  _VehicleCommand__get_serialized_size,
  _VehicleCommand__max_serialized_size
};

static rosidl_message_type_support_t _VehicleCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehicleCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_core_common, msg, VehicleCommand)() {
  return &_VehicleCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
