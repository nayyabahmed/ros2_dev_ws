// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/MpStatus.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/MpStatus in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__MpStatus
{
  double mp_time;
  float mp_lat;
  float mp_longt;
  float mp_bearing;
  float yaw_angle;
} tutorial_interfaces__msg__MpStatus;

// Struct for a sequence of tutorial_interfaces__msg__MpStatus.
typedef struct tutorial_interfaces__msg__MpStatus__Sequence
{
  tutorial_interfaces__msg__MpStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__MpStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__STRUCT_H_
