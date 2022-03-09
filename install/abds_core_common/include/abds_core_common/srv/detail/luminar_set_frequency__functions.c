// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from abds_core_common:srv/LuminarSetFrequency.idl
// generated code does not contain a copyright notice
#include "abds_core_common/srv/detail/luminar_set_frequency__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
abds_core_common__srv__LuminarSetFrequency_Request__init(abds_core_common__srv__LuminarSetFrequency_Request * msg)
{
  if (!msg) {
    return false;
  }
  // frequency
  return true;
}

void
abds_core_common__srv__LuminarSetFrequency_Request__fini(abds_core_common__srv__LuminarSetFrequency_Request * msg)
{
  if (!msg) {
    return;
  }
  // frequency
}

abds_core_common__srv__LuminarSetFrequency_Request *
abds_core_common__srv__LuminarSetFrequency_Request__create()
{
  abds_core_common__srv__LuminarSetFrequency_Request * msg = (abds_core_common__srv__LuminarSetFrequency_Request *)malloc(sizeof(abds_core_common__srv__LuminarSetFrequency_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_core_common__srv__LuminarSetFrequency_Request));
  bool success = abds_core_common__srv__LuminarSetFrequency_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_core_common__srv__LuminarSetFrequency_Request__destroy(abds_core_common__srv__LuminarSetFrequency_Request * msg)
{
  if (msg) {
    abds_core_common__srv__LuminarSetFrequency_Request__fini(msg);
  }
  free(msg);
}


bool
abds_core_common__srv__LuminarSetFrequency_Request__Sequence__init(abds_core_common__srv__LuminarSetFrequency_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_core_common__srv__LuminarSetFrequency_Request * data = NULL;
  if (size) {
    data = (abds_core_common__srv__LuminarSetFrequency_Request *)calloc(size, sizeof(abds_core_common__srv__LuminarSetFrequency_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_core_common__srv__LuminarSetFrequency_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_core_common__srv__LuminarSetFrequency_Request__fini(&data[i - 1]);
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
abds_core_common__srv__LuminarSetFrequency_Request__Sequence__fini(abds_core_common__srv__LuminarSetFrequency_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_core_common__srv__LuminarSetFrequency_Request__fini(&array->data[i]);
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

abds_core_common__srv__LuminarSetFrequency_Request__Sequence *
abds_core_common__srv__LuminarSetFrequency_Request__Sequence__create(size_t size)
{
  abds_core_common__srv__LuminarSetFrequency_Request__Sequence * array = (abds_core_common__srv__LuminarSetFrequency_Request__Sequence *)malloc(sizeof(abds_core_common__srv__LuminarSetFrequency_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_core_common__srv__LuminarSetFrequency_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_core_common__srv__LuminarSetFrequency_Request__Sequence__destroy(abds_core_common__srv__LuminarSetFrequency_Request__Sequence * array)
{
  if (array) {
    abds_core_common__srv__LuminarSetFrequency_Request__Sequence__fini(array);
  }
  free(array);
}


bool
abds_core_common__srv__LuminarSetFrequency_Response__init(abds_core_common__srv__LuminarSetFrequency_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
abds_core_common__srv__LuminarSetFrequency_Response__fini(abds_core_common__srv__LuminarSetFrequency_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

abds_core_common__srv__LuminarSetFrequency_Response *
abds_core_common__srv__LuminarSetFrequency_Response__create()
{
  abds_core_common__srv__LuminarSetFrequency_Response * msg = (abds_core_common__srv__LuminarSetFrequency_Response *)malloc(sizeof(abds_core_common__srv__LuminarSetFrequency_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(abds_core_common__srv__LuminarSetFrequency_Response));
  bool success = abds_core_common__srv__LuminarSetFrequency_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
abds_core_common__srv__LuminarSetFrequency_Response__destroy(abds_core_common__srv__LuminarSetFrequency_Response * msg)
{
  if (msg) {
    abds_core_common__srv__LuminarSetFrequency_Response__fini(msg);
  }
  free(msg);
}


bool
abds_core_common__srv__LuminarSetFrequency_Response__Sequence__init(abds_core_common__srv__LuminarSetFrequency_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  abds_core_common__srv__LuminarSetFrequency_Response * data = NULL;
  if (size) {
    data = (abds_core_common__srv__LuminarSetFrequency_Response *)calloc(size, sizeof(abds_core_common__srv__LuminarSetFrequency_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = abds_core_common__srv__LuminarSetFrequency_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        abds_core_common__srv__LuminarSetFrequency_Response__fini(&data[i - 1]);
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
abds_core_common__srv__LuminarSetFrequency_Response__Sequence__fini(abds_core_common__srv__LuminarSetFrequency_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      abds_core_common__srv__LuminarSetFrequency_Response__fini(&array->data[i]);
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

abds_core_common__srv__LuminarSetFrequency_Response__Sequence *
abds_core_common__srv__LuminarSetFrequency_Response__Sequence__create(size_t size)
{
  abds_core_common__srv__LuminarSetFrequency_Response__Sequence * array = (abds_core_common__srv__LuminarSetFrequency_Response__Sequence *)malloc(sizeof(abds_core_common__srv__LuminarSetFrequency_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = abds_core_common__srv__LuminarSetFrequency_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
abds_core_common__srv__LuminarSetFrequency_Response__Sequence__destroy(abds_core_common__srv__LuminarSetFrequency_Response__Sequence * array)
{
  if (array) {
    abds_core_common__srv__LuminarSetFrequency_Response__Sequence__fini(array);
  }
  free(array);
}
