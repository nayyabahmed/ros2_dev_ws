// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rc_interfaces:msg/TargetCoordinates.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__STRUCT_H_
#define RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in msg/TargetCoordinates in the package rc_interfaces.
typedef struct rc_interfaces__msg__TargetCoordinates
{
  rosidl_runtime_c__String name;
  geometry_msgs__msg__Pose pose;
} rc_interfaces__msg__TargetCoordinates;

// Struct for a sequence of rc_interfaces__msg__TargetCoordinates.
typedef struct rc_interfaces__msg__TargetCoordinates__Sequence
{
  rc_interfaces__msg__TargetCoordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rc_interfaces__msg__TargetCoordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__STRUCT_H_
