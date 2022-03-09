// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from abds_core_common:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "abds_core_common/msg/detail/bounding_boxes__rosidl_typesupport_introspection_c.h"
#include "abds_core_common/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "abds_core_common/msg/detail/bounding_boxes__functions.h"
#include "abds_core_common/msg/detail/bounding_boxes__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `boxes`
#include "abds_core_common/msg/bounding_box.h"
// Member `boxes`
#include "abds_core_common/msg/detail/bounding_box__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  abds_core_common__msg__BoundingBoxes__init(message_memory);
}

void BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_fini_function(void * message_memory)
{
  abds_core_common__msg__BoundingBoxes__fini(message_memory);
}

size_t BoundingBoxes__rosidl_typesupport_introspection_c__size_function__BoundingBox__boxes(
  const void * untyped_member)
{
  const abds_core_common__msg__BoundingBox__Sequence * member =
    (const abds_core_common__msg__BoundingBox__Sequence *)(untyped_member);
  return member->size;
}

const void * BoundingBoxes__rosidl_typesupport_introspection_c__get_const_function__BoundingBox__boxes(
  const void * untyped_member, size_t index)
{
  const abds_core_common__msg__BoundingBox__Sequence * member =
    (const abds_core_common__msg__BoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void * BoundingBoxes__rosidl_typesupport_introspection_c__get_function__BoundingBox__boxes(
  void * untyped_member, size_t index)
{
  abds_core_common__msg__BoundingBox__Sequence * member =
    (abds_core_common__msg__BoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

bool BoundingBoxes__rosidl_typesupport_introspection_c__resize_function__BoundingBox__boxes(
  void * untyped_member, size_t size)
{
  abds_core_common__msg__BoundingBox__Sequence * member =
    (abds_core_common__msg__BoundingBox__Sequence *)(untyped_member);
  abds_core_common__msg__BoundingBox__Sequence__fini(member);
  return abds_core_common__msg__BoundingBox__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common__msg__BoundingBoxes, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "boxes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common__msg__BoundingBoxes, boxes),  // bytes offset in struct
    NULL,  // default value
    BoundingBoxes__rosidl_typesupport_introspection_c__size_function__BoundingBox__boxes,  // size() function pointer
    BoundingBoxes__rosidl_typesupport_introspection_c__get_const_function__BoundingBox__boxes,  // get_const(index) function pointer
    BoundingBoxes__rosidl_typesupport_introspection_c__get_function__BoundingBox__boxes,  // get(index) function pointer
    BoundingBoxes__rosidl_typesupport_introspection_c__resize_function__BoundingBox__boxes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_members = {
  "abds_core_common__msg",  // message namespace
  "BoundingBoxes",  // message name
  2,  // number of fields
  sizeof(abds_core_common__msg__BoundingBoxes),
  BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_member_array,  // message members
  BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_init_function,  // function to initialize message memory (memory has to be allocated)
  BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_type_support_handle = {
  0,
  &BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_abds_core_common
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, msg, BoundingBoxes)() {
  BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, msg, BoundingBox)();
  if (!BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_type_support_handle.typesupport_identifier) {
    BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &BoundingBoxes__rosidl_typesupport_introspection_c__BoundingBoxes_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
