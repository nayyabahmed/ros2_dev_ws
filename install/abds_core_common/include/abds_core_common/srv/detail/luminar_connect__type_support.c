// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from abds_core_common:srv/LuminarConnect.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "abds_core_common/srv/detail/luminar_connect__rosidl_typesupport_introspection_c.h"
#include "abds_core_common/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "abds_core_common/srv/detail/luminar_connect__functions.h"
#include "abds_core_common/srv/detail/luminar_connect__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  abds_core_common__srv__LuminarConnect_Request__init(message_memory);
}

void LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_fini_function(void * message_memory)
{
  abds_core_common__srv__LuminarConnect_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_member_array[1] = {
  {
    "sensor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common__srv__LuminarConnect_Request, sensor_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_members = {
  "abds_core_common__srv",  // message namespace
  "LuminarConnect_Request",  // message name
  1,  // number of fields
  sizeof(abds_core_common__srv__LuminarConnect_Request),
  LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_member_array,  // message members
  LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_type_support_handle = {
  0,
  &LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_abds_core_common
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarConnect_Request)() {
  if (!LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_type_support_handle.typesupport_identifier) {
    LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LuminarConnect_Request__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "abds_core_common/srv/detail/luminar_connect__rosidl_typesupport_introspection_c.h"
// already included above
// #include "abds_core_common/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_connect__functions.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_connect__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  abds_core_common__srv__LuminarConnect_Response__init(message_memory);
}

void LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_fini_function(void * message_memory)
{
  abds_core_common__srv__LuminarConnect_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(abds_core_common__srv__LuminarConnect_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_members = {
  "abds_core_common__srv",  // message namespace
  "LuminarConnect_Response",  // message name
  1,  // number of fields
  sizeof(abds_core_common__srv__LuminarConnect_Response),
  LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_member_array,  // message members
  LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_type_support_handle = {
  0,
  &LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_abds_core_common
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarConnect_Response)() {
  if (!LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_type_support_handle.typesupport_identifier) {
    LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LuminarConnect_Response__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "abds_core_common/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "abds_core_common/srv/detail/luminar_connect__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_service_members = {
  "abds_core_common__srv",  // service namespace
  "LuminarConnect",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_Request_message_type_support_handle,
  NULL  // response message
  // abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_Response_message_type_support_handle
};

static rosidl_service_type_support_t abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_service_type_support_handle = {
  0,
  &abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarConnect_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarConnect_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_abds_core_common
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarConnect)() {
  if (!abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_service_type_support_handle.typesupport_identifier) {
    abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarConnect_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, abds_core_common, srv, LuminarConnect_Response)()->data;
  }

  return &abds_core_common__srv__detail__luminar_connect__rosidl_typesupport_introspection_c__LuminarConnect_service_type_support_handle;
}
