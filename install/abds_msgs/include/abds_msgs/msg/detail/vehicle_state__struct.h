// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_msgs:msg/VehicleState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__STRUCT_H_
#define ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'state'
#include "abds_msgs/msg/detail/trajectory_point__struct.h"
// Member 'delta'
#include "geometry_msgs/msg/detail/transform__struct.h"

// Struct defined in msg/VehicleState in the package abds_msgs.
typedef struct abds_msgs__msg__VehicleState
{
  std_msgs__msg__Header header;
  abds_msgs__msg__TrajectoryPoint state;
  geometry_msgs__msg__Transform delta;
} abds_msgs__msg__VehicleState;

// Struct for a sequence of abds_msgs__msg__VehicleState.
typedef struct abds_msgs__msg__VehicleState__Sequence
{
  abds_msgs__msg__VehicleState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_msgs__msg__VehicleState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__STRUCT_H_
