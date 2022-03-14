// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rc_interfaces:msg/ImuRc.idl
// generated code does not contain a copyright notice
#include "rc_interfaces/msg/detail/imu_rc__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `twist`
#include "geometry_msgs/msg/detail/twist__functions.h"
// Member `accel`
#include "geometry_msgs/msg/detail/accel__functions.h"

bool
rc_interfaces__msg__ImuRc__init(rc_interfaces__msg__ImuRc * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rc_interfaces__msg__ImuRc__fini(msg);
    return false;
  }
  // msg_count
  // mp_time
  // mp_lat
  // mp_longt
  // mp_bearing
  // yaw_angle
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    rc_interfaces__msg__ImuRc__fini(msg);
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__init(&msg->twist)) {
    rc_interfaces__msg__ImuRc__fini(msg);
    return false;
  }
  // accel
  if (!geometry_msgs__msg__Accel__init(&msg->accel)) {
    rc_interfaces__msg__ImuRc__fini(msg);
    return false;
  }
  return true;
}

void
rc_interfaces__msg__ImuRc__fini(rc_interfaces__msg__ImuRc * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // msg_count
  // mp_time
  // mp_lat
  // mp_longt
  // mp_bearing
  // yaw_angle
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // twist
  geometry_msgs__msg__Twist__fini(&msg->twist);
  // accel
  geometry_msgs__msg__Accel__fini(&msg->accel);
}

rc_interfaces__msg__ImuRc *
rc_interfaces__msg__ImuRc__create()
{
  rc_interfaces__msg__ImuRc * msg = (rc_interfaces__msg__ImuRc *)malloc(sizeof(rc_interfaces__msg__ImuRc));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rc_interfaces__msg__ImuRc));
  bool success = rc_interfaces__msg__ImuRc__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rc_interfaces__msg__ImuRc__destroy(rc_interfaces__msg__ImuRc * msg)
{
  if (msg) {
    rc_interfaces__msg__ImuRc__fini(msg);
  }
  free(msg);
}


bool
rc_interfaces__msg__ImuRc__Sequence__init(rc_interfaces__msg__ImuRc__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rc_interfaces__msg__ImuRc * data = NULL;
  if (size) {
    data = (rc_interfaces__msg__ImuRc *)calloc(size, sizeof(rc_interfaces__msg__ImuRc));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rc_interfaces__msg__ImuRc__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rc_interfaces__msg__ImuRc__fini(&data[i - 1]);
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
rc_interfaces__msg__ImuRc__Sequence__fini(rc_interfaces__msg__ImuRc__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rc_interfaces__msg__ImuRc__fini(&array->data[i]);
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

rc_interfaces__msg__ImuRc__Sequence *
rc_interfaces__msg__ImuRc__Sequence__create(size_t size)
{
  rc_interfaces__msg__ImuRc__Sequence * array = (rc_interfaces__msg__ImuRc__Sequence *)malloc(sizeof(rc_interfaces__msg__ImuRc__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rc_interfaces__msg__ImuRc__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rc_interfaces__msg__ImuRc__Sequence__destroy(rc_interfaces__msg__ImuRc__Sequence * array)
{
  if (array) {
    rc_interfaces__msg__ImuRc__Sequence__fini(array);
  }
  free(array);
}
