// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rc_interfaces:msg/TargetCoordinates.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rc_interfaces/msg/detail/target_coordinates__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rc_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TargetCoordinates_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rc_interfaces::msg::TargetCoordinates(_init);
}

void TargetCoordinates_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rc_interfaces::msg::TargetCoordinates *>(message_memory);
  typed_message->~TargetCoordinates();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TargetCoordinates_message_member_array[2] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rc_interfaces::msg::TargetCoordinates, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rc_interfaces::msg::TargetCoordinates, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TargetCoordinates_message_members = {
  "rc_interfaces::msg",  // message namespace
  "TargetCoordinates",  // message name
  2,  // number of fields
  sizeof(rc_interfaces::msg::TargetCoordinates),
  TargetCoordinates_message_member_array,  // message members
  TargetCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  TargetCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TargetCoordinates_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TargetCoordinates_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rc_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rc_interfaces::msg::TargetCoordinates>()
{
  return &::rc_interfaces::msg::rosidl_typesupport_introspection_cpp::TargetCoordinates_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rc_interfaces, msg, TargetCoordinates)() {
  return &::rc_interfaces::msg::rosidl_typesupport_introspection_cpp::TargetCoordinates_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
