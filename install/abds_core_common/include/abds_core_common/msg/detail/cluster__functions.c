// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_core_common:msg/Cluster.idl
// generated code does not contain a copyright notice
#include "abds_core_common/msg/detail/cluster__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `points`
#include "geometry_msgs/msg/detail/point32__functions.h"

bool
abds_core_common__msg__Cluster__init(abds_core_common__msg__Cluster * msg)
{
  if (!msg) {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point32__Sequence__init(&msg->points, 0)) {
    abds_core_common__msg__Cluster__fini(msg);
    return false;
  }
  return true;
}

void
abds_core_common__msg__Cluster__fini(abds_core_common__msg__Cluster * msg)
{
  if (!msg) {
    return;
  }
  // points
  geometry_msgs__msg__Point32__Sequence__fini(&msg->points);
}

abds_core_common__msg__Cluster *
abds_core_common__msg__Cluster__create()
{
  abds_core_common__msg__Cluster * msg = (abds_core_common__msg__Cluster *)malloc(sizeof(abds_core_common__msg__Cluster));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_core_common__msg__Cluster));
  bool success = abds_core_common__msg__Cluster__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_core_common__msg__Cluster__destroy(abds_core_common__msg__Cluster * msg)
{
  if (msg) {
    abds_core_common__msg__Cluster__fini(msg);
  }
  free(msg);
}


bool
abds_core_common__msg__Cluster__Sequence__init(abds_core_common__msg__Cluster__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_core_common__msg__Cluster * data = NULL;
  if (size) {
    data = (abds_core_common__msg__Cluster *)calloc(size, sizeof(abds_core_common__msg__Cluster));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_core_common__msg__Cluster__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_core_common__msg__Cluster__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
abds_core_common__msg__Cluster__Sequence__fini(abds_core_common__msg__Cluster__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_core_common__msg__Cluster__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

abds_core_common__msg__Cluster__Sequence *
abds_core_common__msg__Cluster__Sequence__create(size_t size)
{
  abds_core_common__msg__Cluster__Sequence * array = (abds_core_common__msg__Cluster__Sequence *)malloc(sizeof(abds_core_common__msg__Cluster__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_core_common__msg__Cluster__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_core_common__msg__Cluster__Sequence__destroy(abds_core_common__msg__Cluster__Sequence * array)
{
  if (array) {
    abds_core_common__msg__Cluster__Sequence__fini(array);
  }
  free(array);
}
