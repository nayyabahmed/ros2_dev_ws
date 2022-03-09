// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:msg/MpStatus.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/mp_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
tutorial_interfaces__msg__MpStatus__init(tutorial_interfaces__msg__MpStatus * msg)
{
  if (!msg) {
    return false;
  }
  // mp_time
  // mp_lat
  // mp_longt
  // mp_bearing
  // yaw_angle
  return true;
}

void
tutorial_interfaces__msg__MpStatus__fini(tutorial_interfaces__msg__MpStatus * msg)
{
  if (!msg) {
    return;
  }
  // mp_time
  // mp_lat
  // mp_longt
  // mp_bearing
  // yaw_angle
}

tutorial_interfaces__msg__MpStatus *
tutorial_interfaces__msg__MpStatus__create()
{
  tutorial_interfaces__msg__MpStatus * msg = (tutorial_interfaces__msg__MpStatus *)malloc(sizeof(tutorial_interfaces__msg__MpStatus));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__msg__MpStatus));
  bool success = tutorial_interfaces__msg__MpStatus__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__msg__MpStatus__destroy(tutorial_interfaces__msg__MpStatus * msg)
{
  if (msg) {
    tutorial_interfaces__msg__MpStatus__fini(msg);
  }
  free(msg);
}


bool
tutorial_interfaces__msg__MpStatus__Sequence__init(tutorial_interfaces__msg__MpStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tutorial_interfaces__msg__MpStatus * data = NULL;
  if (size) {
    data = (tutorial_interfaces__msg__MpStatus *)calloc(size, sizeof(tutorial_interfaces__msg__MpStatus));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__msg__MpStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__msg__MpStatus__fini(&data[i - 1]);
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
tutorial_interfaces__msg__MpStatus__Sequence__fini(tutorial_interfaces__msg__MpStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__msg__MpStatus__fini(&array->data[i]);
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

tutorial_interfaces__msg__MpStatus__Sequence *
tutorial_interfaces__msg__MpStatus__Sequence__create(size_t size)
{
  tutorial_interfaces__msg__MpStatus__Sequence * array = (tutorial_interfaces__msg__MpStatus__Sequence *)malloc(sizeof(tutorial_interfaces__msg__MpStatus__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__msg__MpStatus__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__msg__MpStatus__Sequence__destroy(tutorial_interfaces__msg__MpStatus__Sequence * array)
{
  if (array) {
    tutorial_interfaces__msg__MpStatus__Sequence__fini(array);
  }
  free(array);
}
