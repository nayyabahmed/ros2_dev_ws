// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice
#include "rc_interfaces/msg/detail/rc_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
rc_interfaces__msg__RcStatus__init(rc_interfaces__msg__RcStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rc_interfaces__msg__RcStatus__fini(msg);
    return false;
  }
  // test_index
  // test_phase
  // mpf_phase
  // path_dist
  // desire_speed
  // pf_test_true
  // max_path_err_left
  // max_path_err_right
  // current_path_exit_index
  // dl_status_1
  // dl_status_2
  // dl_test_procedure_state
  // test_in_progress
  // ar_control_mode
  // mp_status
  // g_sr_err_1
  // br_ar_err_2
  // cr_gr_err_3
  // sr_mp_err_4
  // syn_temp_err_5
  // dl_err_1
  // dl_err_2
  return true;
}

void
rc_interfaces__msg__RcStatus__fini(rc_interfaces__msg__RcStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // test_index
  // test_phase
  // mpf_phase
  // path_dist
  // desire_speed
  // pf_test_true
  // max_path_err_left
  // max_path_err_right
  // current_path_exit_index
  // dl_status_1
  // dl_status_2
  // dl_test_procedure_state
  // test_in_progress
  // ar_control_mode
  // mp_status
  // g_sr_err_1
  // br_ar_err_2
  // cr_gr_err_3
  // sr_mp_err_4
  // syn_temp_err_5
  // dl_err_1
  // dl_err_2
}

rc_interfaces__msg__RcStatus *
rc_interfaces__msg__RcStatus__create()
{
  rc_interfaces__msg__RcStatus * msg = (rc_interfaces__msg__RcStatus *)malloc(sizeof(rc_interfaces__msg__RcStatus));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rc_interfaces__msg__RcStatus));
  bool success = rc_interfaces__msg__RcStatus__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rc_interfaces__msg__RcStatus__destroy(rc_interfaces__msg__RcStatus * msg)
{
  if (msg) {
    rc_interfaces__msg__RcStatus__fini(msg);
  }
  free(msg);
}


bool
rc_interfaces__msg__RcStatus__Sequence__init(rc_interfaces__msg__RcStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rc_interfaces__msg__RcStatus * data = NULL;
  if (size) {
    data = (rc_interfaces__msg__RcStatus *)calloc(size, sizeof(rc_interfaces__msg__RcStatus));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rc_interfaces__msg__RcStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rc_interfaces__msg__RcStatus__fini(&data[i - 1]);
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
rc_interfaces__msg__RcStatus__Sequence__fini(rc_interfaces__msg__RcStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rc_interfaces__msg__RcStatus__fini(&array->data[i]);
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

rc_interfaces__msg__RcStatus__Sequence *
rc_interfaces__msg__RcStatus__Sequence__create(size_t size)
{
  rc_interfaces__msg__RcStatus__Sequence * array = (rc_interfaces__msg__RcStatus__Sequence *)malloc(sizeof(rc_interfaces__msg__RcStatus__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rc_interfaces__msg__RcStatus__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rc_interfaces__msg__RcStatus__Sequence__destroy(rc_interfaces__msg__RcStatus__Sequence * array)
{
  if (array) {
    rc_interfaces__msg__RcStatus__Sequence__fini(array);
  }
  free(array);
}
