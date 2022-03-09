// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rc_interfaces:msg/TargetCoordinates.idl
// generated code does not contain a copyright notice
#include "rc_interfaces/msg/detail/target_coordinates__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
rc_interfaces__msg__TargetCoordinates__init(rc_interfaces__msg__TargetCoordinates * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    rc_interfaces__msg__TargetCoordinates__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    rc_interfaces__msg__TargetCoordinates__fini(msg);
    return false;
  }
  return true;
}

void
rc_interfaces__msg__TargetCoordinates__fini(rc_interfaces__msg__TargetCoordinates * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

rc_interfaces__msg__TargetCoordinates *
rc_interfaces__msg__TargetCoordinates__create()
{
  rc_interfaces__msg__TargetCoordinates * msg = (rc_interfaces__msg__TargetCoordinates *)malloc(sizeof(rc_interfaces__msg__TargetCoordinates));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rc_interfaces__msg__TargetCoordinates));
  bool success = rc_interfaces__msg__TargetCoordinates__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rc_interfaces__msg__TargetCoordinates__destroy(rc_interfaces__msg__TargetCoordinates * msg)
{
  if (msg) {
    rc_interfaces__msg__TargetCoordinates__fini(msg);
  }
  free(msg);
}


bool
rc_interfaces__msg__TargetCoordinates__Sequence__init(rc_interfaces__msg__TargetCoordinates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rc_interfaces__msg__TargetCoordinates * data = NULL;
  if (size) {
    data = (rc_interfaces__msg__TargetCoordinates *)calloc(size, sizeof(rc_interfaces__msg__TargetCoordinates));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rc_interfaces__msg__TargetCoordinates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rc_interfaces__msg__TargetCoordinates__fini(&data[i - 1]);
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
rc_interfaces__msg__TargetCoordinates__Sequence__fini(rc_interfaces__msg__TargetCoordinates__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rc_interfaces__msg__TargetCoordinates__fini(&array->data[i]);
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

rc_interfaces__msg__TargetCoordinates__Sequence *
rc_interfaces__msg__TargetCoordinates__Sequence__create(size_t size)
{
  rc_interfaces__msg__TargetCoordinates__Sequence * array = (rc_interfaces__msg__TargetCoordinates__Sequence *)malloc(sizeof(rc_interfaces__msg__TargetCoordinates__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rc_interfaces__msg__TargetCoordinates__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rc_interfaces__msg__TargetCoordinates__Sequence__destroy(rc_interfaces__msg__TargetCoordinates__Sequence * array)
{
  if (array) {
    rc_interfaces__msg__TargetCoordinates__Sequence__fini(array);
  }
  free(array);
}
