// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice

#ifndef ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__STRUCT_H_
#define ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ip_address'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/EtherMessage in the package ether_follow_interfaces.
typedef struct ether_follow_interfaces__msg__EtherMessage
{
  rosidl_runtime_c__String ip_address;
  uint8_t version;
  double steering_cmd;
  double brake_cmd;
  double accel_cmd;
  int8_t gear_cmd;
} ether_follow_interfaces__msg__EtherMessage;

// Struct for a sequence of ether_follow_interfaces__msg__EtherMessage.
typedef struct ether_follow_interfaces__msg__EtherMessage__Sequence
{
  ether_follow_interfaces__msg__EtherMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ether_follow_interfaces__msg__EtherMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__STRUCT_H_
