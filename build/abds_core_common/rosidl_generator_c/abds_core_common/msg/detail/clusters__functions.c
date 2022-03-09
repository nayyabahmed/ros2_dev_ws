// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_core_common:msg/Clusters.idl
// generated code does not contain a copyright notice
#include "abds_core_common/msg/detail/clusters__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `clusters`
#include "abds_core_common/msg/detail/cluster__functions.h"

bool
abds_core_common__msg__Clusters__init(abds_core_common__msg__Clusters * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    abds_core_common__msg__Clusters__fini(msg);
    return false;
  }
  // clusters
  if (!abds_core_common__msg__Cluster__Sequence__init(&msg->clusters, 0)) {
    abds_core_common__msg__Clusters__fini(msg);
    return false;
  }
  return true;
}

void
abds_core_common__msg__Clusters__fini(abds_core_common__msg__Clusters * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // clusters
  abds_core_common__msg__Cluster__Sequence__fini(&msg->clusters);
}

abds_core_common__msg__Clusters *
abds_core_common__msg__Clusters__create()
{
  abds_core_common__msg__Clusters * msg = (abds_core_common__msg__Clusters *)malloc(sizeof(abds_core_common__msg__Clusters));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_core_common__msg__Clusters));
  bool success = abds_core_common__msg__Clusters__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_core_common__msg__Clusters__destroy(abds_core_common__msg__Clusters * msg)
{
  if (msg) {
    abds_core_common__msg__Clusters__fini(msg);
  }
  free(msg);
}


bool
abds_core_common__msg__Clusters__Sequence__init(abds_core_common__msg__Clusters__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_core_common__msg__Clusters * data = NULL;
  if (size) {
    data = (abds_core_common__msg__Clusters *)calloc(size, sizeof(abds_core_common__msg__Clusters));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_core_common__msg__Clusters__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_core_common__msg__Clusters__fini(&data[i - 1]);
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
abds_core_common__msg__Clusters__Sequence__fini(abds_core_common__msg__Clusters__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_core_common__msg__Clusters__fini(&array->data[i]);
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

abds_core_common__msg__Clusters__Sequence *
abds_core_common__msg__Clusters__Sequence__create(size_t size)
{
  abds_core_common__msg__Clusters__Sequence * array = (abds_core_common__msg__Clusters__Sequence *)malloc(sizeof(abds_core_common__msg__Clusters__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_core_common__msg__Clusters__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_core_common__msg__Clusters__Sequence__destroy(abds_core_common__msg__Clusters__Sequence * array)
{
  if (array) {
    abds_core_common__msg__Clusters__Sequence__fini(array);
  }
  free(array);
}
