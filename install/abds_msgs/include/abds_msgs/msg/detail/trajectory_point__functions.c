// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_msgs:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice
#include "abds_msgs/msg/detail/trajectory_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `time_from_start`
#include "builtin_interfaces/msg/detail/duration__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
abds_msgs__msg__TrajectoryPoint__init(abds_msgs__msg__TrajectoryPoint * msg)
{
  if (!msg) {
    return false;
  }
  // time_from_start
  if (!builtin_interfaces__msg__Duration__init(&msg->time_from_start)) {
    abds_msgs__msg__TrajectoryPoint__fini(msg);
    return false;
  }
  // datum_bearing
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    abds_msgs__msg__TrajectoryPoint__fini(msg);
    return false;
  }
  // dist_along_path
  // longitudinal_velocity
  // lateral_velocity
  // acceleration
  // heading_rate
  // instantanious_curvature
  return true;
}

void
abds_msgs__msg__TrajectoryPoint__fini(abds_msgs__msg__TrajectoryPoint * msg)
{
  if (!msg) {
    return;
  }
  // time_from_start
  builtin_interfaces__msg__Duration__fini(&msg->time_from_start);
  // datum_bearing
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // dist_along_path
  // longitudinal_velocity
  // lateral_velocity
  // acceleration
  // heading_rate
  // instantanious_curvature
}

abds_msgs__msg__TrajectoryPoint *
abds_msgs__msg__TrajectoryPoint__create()
{
  abds_msgs__msg__TrajectoryPoint * msg = (abds_msgs__msg__TrajectoryPoint *)malloc(sizeof(abds_msgs__msg__TrajectoryPoint));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_msgs__msg__TrajectoryPoint));
  bool success = abds_msgs__msg__TrajectoryPoint__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_msgs__msg__TrajectoryPoint__destroy(abds_msgs__msg__TrajectoryPoint * msg)
{
  if (msg) {
    abds_msgs__msg__TrajectoryPoint__fini(msg);
  }
  free(msg);
}


bool
abds_msgs__msg__TrajectoryPoint__Sequence__init(abds_msgs__msg__TrajectoryPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_msgs__msg__TrajectoryPoint * data = NULL;
  if (size) {
    data = (abds_msgs__msg__TrajectoryPoint *)calloc(size, sizeof(abds_msgs__msg__TrajectoryPoint));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_msgs__msg__TrajectoryPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_msgs__msg__TrajectoryPoint__fini(&data[i - 1]);
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
abds_msgs__msg__TrajectoryPoint__Sequence__fini(abds_msgs__msg__TrajectoryPoint__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_msgs__msg__TrajectoryPoint__fini(&array->data[i]);
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

abds_msgs__msg__TrajectoryPoint__Sequence *
abds_msgs__msg__TrajectoryPoint__Sequence__create(size_t size)
{
  abds_msgs__msg__TrajectoryPoint__Sequence * array = (abds_msgs__msg__TrajectoryPoint__Sequence *)malloc(sizeof(abds_msgs__msg__TrajectoryPoint__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_msgs__msg__TrajectoryPoint__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_msgs__msg__TrajectoryPoint__Sequence__destroy(abds_msgs__msg__TrajectoryPoint__Sequence * array)
{
  if (array) {
    abds_msgs__msg__TrajectoryPoint__Sequence__fini(array);
  }
  free(array);
}
