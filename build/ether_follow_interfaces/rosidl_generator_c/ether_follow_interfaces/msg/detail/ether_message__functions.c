// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice
#include "ether_follow_interfaces/msg/detail/ether_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `ip_address`
#include "rosidl_runtime_c/string_functions.h"

bool
ether_follow_interfaces__msg__EtherMessage__init(ether_follow_interfaces__msg__EtherMessage * msg)
{
  if (!msg) {
    return false;
  }
  // ip_address
  if (!rosidl_runtime_c__String__init(&msg->ip_address)) {
    ether_follow_interfaces__msg__EtherMessage__fini(msg);
    return false;
  }
  // version
  // steering_cmd
  // brake_cmd
  // accel_cmd
  // gear_cmd
  return true;
}

void
ether_follow_interfaces__msg__EtherMessage__fini(ether_follow_interfaces__msg__EtherMessage * msg)
{
  if (!msg) {
    return;
  }
  // ip_address
  rosidl_runtime_c__String__fini(&msg->ip_address);
  // version
  // steering_cmd
  // brake_cmd
  // accel_cmd
  // gear_cmd
}

ether_follow_interfaces__msg__EtherMessage *
ether_follow_interfaces__msg__EtherMessage__create()
{
  ether_follow_interfaces__msg__EtherMessage * msg = (ether_follow_interfaces__msg__EtherMessage *)malloc(sizeof(ether_follow_interfaces__msg__EtherMessage));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ether_follow_interfaces__msg__EtherMessage));
  bool success = ether_follow_interfaces__msg__EtherMessage__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ether_follow_interfaces__msg__EtherMessage__destroy(ether_follow_interfaces__msg__EtherMessage * msg)
{
  if (msg) {
    ether_follow_interfaces__msg__EtherMessage__fini(msg);
  }
  free(msg);
}


bool
ether_follow_interfaces__msg__EtherMessage__Sequence__init(ether_follow_interfaces__msg__EtherMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ether_follow_interfaces__msg__EtherMessage * data = NULL;
  if (size) {
    data = (ether_follow_interfaces__msg__EtherMessage *)calloc(size, sizeof(ether_follow_interfaces__msg__EtherMessage));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ether_follow_interfaces__msg__EtherMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ether_follow_interfaces__msg__EtherMessage__fini(&data[i - 1]);
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
ether_follow_interfaces__msg__EtherMessage__Sequence__fini(ether_follow_interfaces__msg__EtherMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ether_follow_interfaces__msg__EtherMessage__fini(&array->data[i]);
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

ether_follow_interfaces__msg__EtherMessage__Sequence *
ether_follow_interfaces__msg__EtherMessage__Sequence__create(size_t size)
{
  ether_follow_interfaces__msg__EtherMessage__Sequence * array = (ether_follow_interfaces__msg__EtherMessage__Sequence *)malloc(sizeof(ether_follow_interfaces__msg__EtherMessage__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ether_follow_interfaces__msg__EtherMessage__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ether_follow_interfaces__msg__EtherMessage__Sequence__destroy(ether_follow_interfaces__msg__EtherMessage__Sequence * array)
{
  if (array) {
    ether_follow_interfaces__msg__EtherMessage__Sequence__fini(array);
  }
  free(array);
}
