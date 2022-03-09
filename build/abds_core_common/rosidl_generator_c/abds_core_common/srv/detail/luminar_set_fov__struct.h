// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from abds_core_common:srv/LuminarSetFov.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__STRUCT_H_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/LuminarSetFov in the package abds_core_common.
typedef struct abds_core_common__srv__LuminarSetFov_Request
{
  float fov;
  float fov_center;
} abds_core_common__srv__LuminarSetFov_Request;

// Struct for a sequence of abds_core_common__srv__LuminarSetFov_Request.
typedef struct abds_core_common__srv__LuminarSetFov_Request__Sequence
{
  abds_core_common__srv__LuminarSetFov_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_core_common__srv__LuminarSetFov_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/LuminarSetFov in the package abds_core_common.
typedef struct abds_core_common__srv__LuminarSetFov_Response
{
  int8_t result;
} abds_core_common__srv__LuminarSetFov_Response;

// Struct for a sequence of abds_core_common__srv__LuminarSetFov_Response.
typedef struct abds_core_common__srv__LuminarSetFov_Response__Sequence
{
  abds_core_common__srv__LuminarSetFov_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} abds_core_common__srv__LuminarSetFov_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__STRUCT_H_
