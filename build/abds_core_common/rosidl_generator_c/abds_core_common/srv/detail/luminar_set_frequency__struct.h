// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_core_common:srv/LuminarSetFrequency.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FREQUENCY__STRUCT_H_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FREQUENCY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/LuminarSetFrequency in the package abds_core_common.
typedef struct abds_core_common__srv__LuminarSetFrequency_Request
{
  float frequency;
} abds_core_common__srv__LuminarSetFrequency_Request;

// Struct for a sequence of abds_core_common__srv__LuminarSetFrequency_Request.
typedef struct abds_core_common__srv__LuminarSetFrequency_Request__Sequence
{
  abds_core_common__srv__LuminarSetFrequency_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_core_common__srv__LuminarSetFrequency_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/LuminarSetFrequency in the package abds_core_common.
typedef struct abds_core_common__srv__LuminarSetFrequency_Response
{
  int8_t result;
} abds_core_common__srv__LuminarSetFrequency_Response;

// Struct for a sequence of abds_core_common__srv__LuminarSetFrequency_Response.
typedef struct abds_core_common__srv__LuminarSetFrequency_Response__Sequence
{
  abds_core_common__srv__LuminarSetFrequency_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_core_common__srv__LuminarSetFrequency_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FREQUENCY__STRUCT_H_
