// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_core_common:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'centroid'
// Member 'size'
// Member 'corners'
#include "geometry_msgs/msg/detail/point32__struct.h"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

// Struct defined in msg/BoundingBox in the package abds_core_common.
typedef struct abds_core_common__msg__BoundingBox
{
  geometry_msgs__msg__Point32 centroid;
  geometry_msgs__msg__Point32 size;
  geometry_msgs__msg__Quaternion orientation;
  float velocity;
  float heading;
  float heading_rate;
  geometry_msgs__msg__Point32 corners[4];
  float variance;
  uint8_t vehicle_label;
  float class_likelihood;
} abds_core_common__msg__BoundingBox;

// Struct for a sequence of abds_core_common__msg__BoundingBox.
typedef struct abds_core_common__msg__BoundingBox__Sequence
{
  abds_core_common__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_core_common__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
