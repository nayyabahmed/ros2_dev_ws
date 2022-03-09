// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/MpStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/mp_status__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/mp_status__functions.h"
#include "tutorial_interfaces/msg/detail/mp_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MpStatus__rosidl_typesupport_introspection_c__MpStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__MpStatus__init(message_memory);
}

void MpStatus__rosidl_typesupport_introspection_c__MpStatus_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__MpStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_member_array[5] = {
  {
    "mp_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__MpStatus, mp_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mp_lat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__MpStatus, mp_lat),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mp_longt",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__MpStatus, mp_longt),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mp_bearing",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__MpStatus, mp_bearing),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__MpStatus, yaw_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "MpStatus",  // message name
  5,  // number of fields
  sizeof(tutorial_interfaces__msg__MpStatus),
  MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_member_array,  // message members
  MpStatus__rosidl_typesupport_introspection_c__MpStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  MpStatus__rosidl_typesupport_introspection_c__MpStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_type_support_handle = {
  0,
  &MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, MpStatus)() {
  if (!MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_type_support_handle.typesupport_identifier) {
    MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MpStatus__rosidl_typesupport_introspection_c__MpStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
