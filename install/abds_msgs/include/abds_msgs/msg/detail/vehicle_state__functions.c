// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_msgs:msg/VehicleState.idl
// generated code does not contain a copyright notice
#include "abds_msgs/msg/detail/vehicle_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `state`
#include "abds_msgs/msg/detail/trajectory_point__functions.h"
// Member `delta`
#include "geometry_msgs/msg/detail/transform__functions.h"

bool
abds_msgs__msg__VehicleState__init(abds_msgs__msg__VehicleState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    abds_msgs__msg__VehicleState__fini(msg);
    return false;
  }
  // state
  if (!abds_msgs__msg__TrajectoryPoint__init(&msg->state)) {
    abds_msgs__msg__VehicleState__fini(msg);
    return false;
  }
  // delta
  if (!geometry_msgs__msg__Transform__init(&msg->delta)) {
    abds_msgs__msg__VehicleState__fini(msg);
    return false;
  }
  return true;
}

void
abds_msgs__msg__VehicleState__fini(abds_msgs__msg__VehicleState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // state
  abds_msgs__msg__TrajectoryPoint__fini(&msg->state);
  // delta
  geometry_msgs__msg__Transform__fini(&msg->delta);
}

abds_msgs__msg__VehicleState *
abds_msgs__msg__VehicleState__create()
{
  abds_msgs__msg__VehicleState * msg = (abds_msgs__msg__VehicleState *)malloc(sizeof(abds_msgs__msg__VehicleState));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_msgs__msg__VehicleState));
  bool success = abds_msgs__msg__VehicleState__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_msgs__msg__VehicleState__destroy(abds_msgs__msg__VehicleState * msg)
{
  if (msg) {
    abds_msgs__msg__VehicleState__fini(msg);
  }
  free(msg);
}


bool
abds_msgs__msg__VehicleState__Sequence__init(abds_msgs__msg__VehicleState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_msgs__msg__VehicleState * data = NULL;
  if (size) {
    data = (abds_msgs__msg__VehicleState *)calloc(size, sizeof(abds_msgs__msg__VehicleState));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_msgs__msg__VehicleState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_msgs__msg__VehicleState__fini(&data[i - 1]);
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
abds_msgs__msg__VehicleState__Sequence__fini(abds_msgs__msg__VehicleState__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_msgs__msg__VehicleState__fini(&array->data[i]);
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

abds_msgs__msg__VehicleState__Sequence *
abds_msgs__msg__VehicleState__Sequence__create(size_t size)
{
  abds_msgs__msg__VehicleState__Sequence * array = (abds_msgs__msg__VehicleState__Sequence *)malloc(sizeof(abds_msgs__msg__VehicleState__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_msgs__msg__VehicleState__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_msgs__msg__VehicleState__Sequence__destroy(abds_msgs__msg__VehicleState__Sequence * array)
{
  if (array) {
    abds_msgs__msg__VehicleState__Sequence__fini(array);
  }
  free(array);
}
