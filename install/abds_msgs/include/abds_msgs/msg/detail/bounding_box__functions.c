// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "abds_msgs/msg/detail/bounding_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `centroid`
// Member `size`
// Member `corners`
#include "geometry_msgs/msg/detail/point32__functions.h"
// Member `orientation`
#include "geometry_msgs/msg/detail/quaternion__functions.h"

bool
abds_msgs__msg__BoundingBox__init(abds_msgs__msg__BoundingBox * msg)
{
  if (!msg) {
    return false;
  }
  // centroid
  if (!geometry_msgs__msg__Point32__init(&msg->centroid)) {
    abds_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  // size
  if (!geometry_msgs__msg__Point32__init(&msg->size)) {
    abds_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__init(&msg->orientation)) {
    abds_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  // velocity
  // heading
  // heading_rate
  // corners
  for (size_t i = 0; i < 4; ++i) {
    if (!geometry_msgs__msg__Point32__init(&msg->corners[i])) {
      abds_msgs__msg__BoundingBox__fini(msg);
      return false;
    }
  }
  // variance
  // vehicle_label
  // class_likelihood
  return true;
}

void
abds_msgs__msg__BoundingBox__fini(abds_msgs__msg__BoundingBox * msg)
{
  if (!msg) {
    return;
  }
  // centroid
  geometry_msgs__msg__Point32__fini(&msg->centroid);
  // size
  geometry_msgs__msg__Point32__fini(&msg->size);
  // orientation
  geometry_msgs__msg__Quaternion__fini(&msg->orientation);
  // velocity
  // heading
  // heading_rate
  // corners
  for (size_t i = 0; i < 4; ++i) {
    geometry_msgs__msg__Point32__fini(&msg->corners[i]);
  }
  // variance
  // vehicle_label
  // class_likelihood
}

abds_msgs__msg__BoundingBox *
abds_msgs__msg__BoundingBox__create()
{
  abds_msgs__msg__BoundingBox * msg = (abds_msgs__msg__BoundingBox *)malloc(sizeof(abds_msgs__msg__BoundingBox));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_msgs__msg__BoundingBox));
  bool success = abds_msgs__msg__BoundingBox__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_msgs__msg__BoundingBox__destroy(abds_msgs__msg__BoundingBox * msg)
{
  if (msg) {
    abds_msgs__msg__BoundingBox__fini(msg);
  }
  free(msg);
}


bool
abds_msgs__msg__BoundingBox__Sequence__init(abds_msgs__msg__BoundingBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_msgs__msg__BoundingBox * data = NULL;
  if (size) {
    data = (abds_msgs__msg__BoundingBox *)calloc(size, sizeof(abds_msgs__msg__BoundingBox));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_msgs__msg__BoundingBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_msgs__msg__BoundingBox__fini(&data[i - 1]);
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
abds_msgs__msg__BoundingBox__Sequence__fini(abds_msgs__msg__BoundingBox__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_msgs__msg__BoundingBox__fini(&array->data[i]);
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

abds_msgs__msg__BoundingBox__Sequence *
abds_msgs__msg__BoundingBox__Sequence__create(size_t size)
{
  abds_msgs__msg__BoundingBox__Sequence * array = (abds_msgs__msg__BoundingBox__Sequence *)malloc(sizeof(abds_msgs__msg__BoundingBox__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_msgs__msg__BoundingBox__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_msgs__msg__BoundingBox__Sequence__destroy(abds_msgs__msg__BoundingBox__Sequence * array)
{
  if (array) {
    abds_msgs__msg__BoundingBox__Sequence__fini(array);
  }
  free(array);
}
