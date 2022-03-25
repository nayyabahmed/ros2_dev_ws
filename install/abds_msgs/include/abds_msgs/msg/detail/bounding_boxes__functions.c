// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_msgs:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice
#include "abds_msgs/msg/detail/bounding_boxes__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `boxes`
#include "abds_msgs/msg/detail/bounding_box__functions.h"

bool
abds_msgs__msg__BoundingBoxes__init(abds_msgs__msg__BoundingBoxes * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    abds_msgs__msg__BoundingBoxes__fini(msg);
    return false;
  }
  // boxes
  if (!abds_msgs__msg__BoundingBox__Sequence__init(&msg->boxes, 0)) {
    abds_msgs__msg__BoundingBoxes__fini(msg);
    return false;
  }
  return true;
}

void
abds_msgs__msg__BoundingBoxes__fini(abds_msgs__msg__BoundingBoxes * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // boxes
  abds_msgs__msg__BoundingBox__Sequence__fini(&msg->boxes);
}

abds_msgs__msg__BoundingBoxes *
abds_msgs__msg__BoundingBoxes__create()
{
  abds_msgs__msg__BoundingBoxes * msg = (abds_msgs__msg__BoundingBoxes *)malloc(sizeof(abds_msgs__msg__BoundingBoxes));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_msgs__msg__BoundingBoxes));
  bool success = abds_msgs__msg__BoundingBoxes__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_msgs__msg__BoundingBoxes__destroy(abds_msgs__msg__BoundingBoxes * msg)
{
  if (msg) {
    abds_msgs__msg__BoundingBoxes__fini(msg);
  }
  free(msg);
}


bool
abds_msgs__msg__BoundingBoxes__Sequence__init(abds_msgs__msg__BoundingBoxes__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_msgs__msg__BoundingBoxes * data = NULL;
  if (size) {
    data = (abds_msgs__msg__BoundingBoxes *)calloc(size, sizeof(abds_msgs__msg__BoundingBoxes));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_msgs__msg__BoundingBoxes__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_msgs__msg__BoundingBoxes__fini(&data[i - 1]);
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
abds_msgs__msg__BoundingBoxes__Sequence__fini(abds_msgs__msg__BoundingBoxes__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_msgs__msg__BoundingBoxes__fini(&array->data[i]);
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

abds_msgs__msg__BoundingBoxes__Sequence *
abds_msgs__msg__BoundingBoxes__Sequence__create(size_t size)
{
  abds_msgs__msg__BoundingBoxes__Sequence * array = (abds_msgs__msg__BoundingBoxes__Sequence *)malloc(sizeof(abds_msgs__msg__BoundingBoxes__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_msgs__msg__BoundingBoxes__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_msgs__msg__BoundingBoxes__Sequence__destroy(abds_msgs__msg__BoundingBoxes__Sequence * array)
{
  if (array) {
    abds_msgs__msg__BoundingBoxes__Sequence__fini(array);
  }
  free(array);
}
