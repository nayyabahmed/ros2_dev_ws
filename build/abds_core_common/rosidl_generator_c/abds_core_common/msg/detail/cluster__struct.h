// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_core_common:msg/Cluster.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__STRUCT_H_
#define ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point32__struct.h"

// Struct defined in msg/Cluster in the package abds_core_common.
typedef struct abds_core_common__msg__Cluster
{
  geometry_msgs__msg__Point32__Sequence points;
} abds_core_common__msg__Cluster;

// Struct for a sequence of abds_core_common__msg__Cluster.
typedef struct abds_core_common__msg__Cluster__Sequence
{
  abds_core_common__msg__Cluster * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_core_common__msg__Cluster__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__STRUCT_H_
