// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rc_interfaces:msg/TargetCoordinates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rc_interfaces/msg/detail/target_coordinates__rosidl_typesupport_introspection_c.h"
#include "rc_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rc_interfaces/msg/detail/target_coordinates__functions.h"
#include "rc_interfaces/msg/detail/target_coordinates__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rc_interfaces__msg__TargetCoordinates__init(message_memory);
}

void TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_fini_function(void * message_memory)
{
  rc_interfaces__msg__TargetCoordinates__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_member_array[2] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rc_interfaces__msg__TargetCoordinates, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rc_interfaces__msg__TargetCoordinates, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_members = {
  "rc_interfaces__msg",  // message namespace
  "TargetCoordinates",  // message name
  2,  // number of fields
  sizeof(rc_interfaces__msg__TargetCoordinates),
  TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_member_array,  // message members
  TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_type_support_handle = {
  0,
  &TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rc_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rc_interfaces, msg, TargetCoordinates)() {
  TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_type_support_handle.typesupport_identifier) {
    TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TargetCoordinates__rosidl_typesupport_introspection_c__TargetCoordinates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
