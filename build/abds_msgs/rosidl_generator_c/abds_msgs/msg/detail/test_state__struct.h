// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_msgs:msg/TestState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__TEST_STATE__STRUCT_H_
#define ABDS_MSGS__MSG__DETAIL__TEST_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/TestState in the package abds_msgs.
typedef struct abds_msgs__msg__TestState
{
  int32_t test_id;
  int32_t test_phase;
  int32_t test_state;
  float path_distance;
  float deceleration_rate;
  float abort_deceleration_rate;
  float desired_speed;
} abds_msgs__msg__TestState;

// Struct for a sequence of abds_msgs__msg__TestState.
typedef struct abds_msgs__msg__TestState__Sequence
{
  abds_msgs__msg__TestState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_msgs__msg__TestState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_MSGS__MSG__DETAIL__TEST_STATE__STRUCT_H_
