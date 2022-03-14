// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__RC_STATUS__STRUCT_H_
#define RC_INTERFACES__MSG__DETAIL__RC_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/RcStatus in the package rc_interfaces.
typedef struct rc_interfaces__msg__RcStatus
{
  std_msgs__msg__Header header;
  uint16_t test_index;
  int16_t test_phase;
  int32_t mpf_phase;
  float path_dist;
  float desire_speed;
  uint8_t pf_test_true;
  float max_path_err_left;
  float max_path_err_right;
  int16_t current_path_exit_index;
  uint8_t dl_status_1;
  uint8_t dl_status_2;
  uint8_t dl_test_procedure_state;
  uint8_t test_in_progress;
  int32_t ar_control_mode;
  int32_t mp_status;
  uint32_t g_sr_err_1;
  uint32_t br_ar_err_2;
  uint32_t cr_gr_err_3;
  uint32_t sr_mp_err_4;
  uint32_t syn_temp_err_5;
  uint32_t dl_err_1;
  uint32_t dl_err_2;
} rc_interfaces__msg__RcStatus;

// Struct for a sequence of rc_interfaces__msg__RcStatus.
typedef struct rc_interfaces__msg__RcStatus__Sequence
{
  rc_interfaces__msg__RcStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rc_interfaces__msg__RcStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RC_INTERFACES__MSG__DETAIL__RC_STATUS__STRUCT_H_
