// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_core_common:msg/Clusters.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__CLUSTERS__STRUCT_H_
#define ABDS_CORE_COMMON__MSG__DETAIL__CLUSTERS__STRUCT_H_

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
// Member 'clusters'
#include "abds_core_common/msg/detail/cluster__struct.h"

// Struct defined in msg/Clusters in the package abds_core_common.
typedef struct abds_core_common__msg__Clusters
{
  std_msgs__msg__Header header;
  abds_core_common__msg__Cluster__Sequence clusters;
} abds_core_common__msg__Clusters;

// Struct for a sequence of abds_core_common__msg__Clusters.
typedef struct abds_core_common__msg__Clusters__Sequence
{
  abds_core_common__msg__Clusters * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_core_common__msg__Clusters__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__CLUSTERS__STRUCT_H_
