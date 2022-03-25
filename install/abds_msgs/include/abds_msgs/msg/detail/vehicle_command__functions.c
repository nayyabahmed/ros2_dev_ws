// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice
#include "abds_msgs/msg/detail/vehicle_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
abds_msgs__msg__VehicleCommand__init(abds_msgs__msg__VehicleCommand * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    abds_msgs__msg__VehicleCommand__fini(msg);
    return false;
  }
  // long_accel
  // velocity_modifier
  // front_wheel_angle
  // rear_wheel_angle
  return true;
}

void
abds_msgs__msg__VehicleCommand__fini(abds_msgs__msg__VehicleCommand * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // long_accel
  // velocity_modifier
  // front_wheel_angle
  // rear_wheel_angle
}

abds_msgs__msg__VehicleCommand *
abds_msgs__msg__VehicleCommand__create()
{
  abds_msgs__msg__VehicleCommand * msg = (abds_msgs__msg__VehicleCommand *)malloc(sizeof(abds_msgs__msg__VehicleCommand));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_msgs__msg__VehicleCommand));
  bool success = abds_msgs__msg__VehicleCommand__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_msgs__msg__VehicleCommand__destroy(abds_msgs__msg__VehicleCommand * msg)
{
  if (msg) {
    abds_msgs__msg__VehicleCommand__fini(msg);
  }
  free(msg);
}


bool
abds_msgs__msg__VehicleCommand__Sequence__init(abds_msgs__msg__VehicleCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_msgs__msg__VehicleCommand * data = NULL;
  if (size) {
    data = (abds_msgs__msg__VehicleCommand *)calloc(size, sizeof(abds_msgs__msg__VehicleCommand));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_msgs__msg__VehicleCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_msgs__msg__VehicleCommand__fini(&data[i - 1]);
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
abds_msgs__msg__VehicleCommand__Sequence__fini(abds_msgs__msg__VehicleCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_msgs__msg__VehicleCommand__fini(&array->data[i]);
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

abds_msgs__msg__VehicleCommand__Sequence *
abds_msgs__msg__VehicleCommand__Sequence__create(size_t size)
{
  abds_msgs__msg__VehicleCommand__Sequence * array = (abds_msgs__msg__VehicleCommand__Sequence *)malloc(sizeof(abds_msgs__msg__VehicleCommand__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_msgs__msg__VehicleCommand__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_msgs__msg__VehicleCommand__Sequence__destroy(abds_msgs__msg__VehicleCommand__Sequence * array)
{
  if (array) {
    abds_msgs__msg__VehicleCommand__Sequence__fini(array);
  }
  free(array);
}
