// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_msgs:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_H_
#define ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'time_from_start'
#include "builtin_interfaces/msg/detail/duration__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in msg/TrajectoryPoint in the package abds_msgs.
typedef struct abds_msgs__msg__TrajectoryPoint
{
  builtin_interfaces__msg__Duration time_from_start;
  float datum_bearing;
  geometry_msgs__msg__Pose pose;
  float dist_along_path;
  float longitudinal_velocity;
  float lateral_velocity;
  float acceleration;
  float heading_rate;
  float instantanious_curvature;
} abds_msgs__msg__TrajectoryPoint;

// Struct for a sequence of abds_msgs__msg__TrajectoryPoint.
typedef struct abds_msgs__msg__TrajectoryPoint__Sequence
{
  abds_msgs__msg__TrajectoryPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_msgs__msg__TrajectoryPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_H_
