// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from abds_core_common:msg/Clusters.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "abds_core_common/msg/detail/clusters__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace abds_core_common
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Clusters_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) abds_core_common::msg::Clusters(_init);
}

void Clusters_fini_function(void * message_memory)
{
  auto typed_message = static_cast<abds_core_common::msg::Clusters *>(message_memory);
  typed_message->~Clusters();
}

size_t size_function__Clusters__clusters(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<abds_core_common::msg::Cluster> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Clusters__clusters(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<abds_core_common::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void * get_function__Clusters__clusters(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<abds_core_common::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void resize_function__Clusters__clusters(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<abds_core_common::msg::Cluster> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Clusters_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common::msg::Clusters, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "clusters",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<abds_core_common::msg::Cluster>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common::msg::Clusters, clusters),  // bytes offset in struct
    nullptr,  // default value
    size_function__Clusters__clusters,  // size() function pointer
    get_const_function__Clusters__clusters,  // get_const(index) function pointer
    get_function__Clusters__clusters,  // get(index) function pointer
    resize_function__Clusters__clusters  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Clusters_message_members = {
  "abds_core_common::msg",  // message namespace
  "Clusters",  // message name
  2,  // number of fields
  sizeof(abds_core_common::msg::Clusters),
  Clusters_message_member_array,  // message members
  Clusters_init_function,  // function to initialize message memory (memory has to be allocated)
  Clusters_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Clusters_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Clusters_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace abds_core_common


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<abds_core_common::msg::Clusters>()
{
  return &::abds_core_common::msg::rosidl_typesupport_introspection_cpp::Clusters_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, abds_core_common, msg, Clusters)() {
  return &::abds_core_common::msg::rosidl_typesupport_introspection_cpp::Clusters_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
