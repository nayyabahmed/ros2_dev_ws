// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_
#define ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in msg/VehicleCommand in the package abds_msgs.
typedef struct abds_msgs__msg__VehicleCommand
{
  builtin_interfaces__msg__Time stamp;
  float long_accel;
  float velocity_modifier;
  float front_wheel_angle;
  float rear_wheel_angle;
} abds_msgs__msg__VehicleCommand;

// Struct for a sequence of abds_msgs__msg__VehicleCommand.
typedef struct abds_msgs__msg__VehicleCommand__Sequence
{
  abds_msgs__msg__VehicleCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_msgs__msg__VehicleCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_
