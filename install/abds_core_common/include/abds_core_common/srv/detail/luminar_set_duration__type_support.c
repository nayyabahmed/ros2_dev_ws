// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from abds_core_common:srv/LuminarSetDuration.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "abds_core_common/srv/detail/luminar_set_duration__rosidl_typesupport_introspection_c.h"
#include "abds_core_common/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "abds_core_common/srv/detail/luminar_set_duration__functions.h"
#include "abds_core_common/srv/detail/luminar_set_duration__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  abds_core_common__srv__LuminarSetDuration_Request__init(message_memory);
}

void LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_fini_function(void * message_memory)
{
  abds_core_common__srv__LuminarSetDuration_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_member_array[1] = {
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common__srv__LuminarSetDuration_Request, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_members = {
  "abds_core_common__srv",  // message namespace
  "LuminarSetDuration_Request",  // message name
  1,  // number of fields
  sizeof(abds_core_common__srv__LuminarSetDuration_Request),
  LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_member_array,  // message members
  LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_type_support_handle = {
  0,
  &LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_abds_core_common
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarSetDuration_Request)() {
  if (!LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_type_support_handle.typesupport_identifier) {
    LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LuminarSetDuration_Request__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "abds_core_common/srv/detail/luminar_set_duration__rosidl_typesupport_introspection_c.h"
// already included above
// #include "abds_core_common/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_set_duration__functions.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_set_duration__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  abds_core_common__srv__LuminarSetDuration_Response__init(message_memory);
}

void LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_fini_function(void * message_memory)
{
  abds_core_common__srv__LuminarSetDuration_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common__srv__LuminarSetDuration_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_members = {
  "abds_core_common__srv",  // message namespace
  "LuminarSetDuration_Response",  // message name
  1,  // number of fields
  sizeof(abds_core_common__srv__LuminarSetDuration_Response),
  LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_member_array,  // message members
  LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_type_support_handle = {
  0,
  &LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_abds_core_common
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarSetDuration_Response)() {
  if (!LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_type_support_handle.typesupport_identifier) {
    LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LuminarSetDuration_Response__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "abds_core_common/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_set_duration__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_service_members = {
  "abds_core_common__srv",  // service namespace
  "LuminarSetDuration",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_Request_message_type_support_handle,
  NULL  // response message
  // abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_Response_message_type_support_handle
};

static rosidl_service_type_support_t abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_service_type_support_handle = {
  0,
  &abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarSetDuration_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarSetDuration_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_abds_core_common
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarSetDuration)() {
  if (!abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_service_type_support_handle.typesupport_identifier) {
    abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarSetDuration_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarSetDuration_Response)()->data;
  }

  return &abds_core_common__srv__detail__luminar_set_duration__rosidl_typesupport_introspection_c__LuminarSetDuration_service_type_support_handle;
}
