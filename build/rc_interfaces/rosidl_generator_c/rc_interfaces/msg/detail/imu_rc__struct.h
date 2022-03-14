// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rc_interfaces:msg/ImuRc.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__IMU_RC__STRUCT_H_
#define RC_INTERFACES__MSG__DETAIL__IMU_RC__STRUCT_H_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.h"
// Member 'accel'
#include "geometry_msgs/msg/detail/accel__struct.h"

// Struct defined in msg/ImuRc in the package rc_interfaces.
typedef struct rc_interfaces__msg__ImuRc
{
  std_msgs__msg__Header header;
  int32_t msg_count;
  double mp_time;
  float mp_lat;
  float mp_longt;
  float mp_bearing;
  float yaw_angle;
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Twist twist;
  geometry_msgs__msg__Accel accel;
} rc_interfaces__msg__ImuRc;

// Struct for a sequence of rc_interfaces__msg__ImuRc.
typedef struct rc_interfaces__msg__ImuRc__Sequence
{
  rc_interfaces__msg__ImuRc * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rc_interfaces__msg__ImuRc__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RC_INTERFACES__MSG__DETAIL__IMU_RC__STRUCT_H_
