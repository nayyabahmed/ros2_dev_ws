// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from abds_msgs:msg/TestState.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "abds_msgs/msg/rosidl_typesupport_c__visibility_control.h"
#include "abds_msgs/msg/detail/test_state__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace abds_msgs
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _TestState_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TestState_type_support_ids_t;

static const _TestState_type_support_ids_t _TestState_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TestState_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TestState_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TestState_type_support_symbol_names_t _TestState_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, abds_msgs, msg, TestState)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_msgs, msg, TestState)),
  }
};

typedef struct _TestState_type_support_data_t
{
  void * data[2];
} _TestState_type_support_data_t;

static _TestState_type_support_data_t _TestState_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TestState_message_typesupport_map = {
  2,
  "abds_msgs",
  &_TestState_message_typesupport_ids.typesupport_identifier[0],
  &_TestState_message_typesupport_symbol_names.symbol_name[0],
  &_TestState_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TestState_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TestState_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace abds_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_abds_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, abds_msgs, msg, TestState)() {
  return &::abds_msgs::msg::rosidl_typesupport_c::TestState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif