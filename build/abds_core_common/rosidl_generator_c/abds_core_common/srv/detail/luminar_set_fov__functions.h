// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from abds_core_common:srv/LuminarSetFov.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__FUNCTIONS_H_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "abds_core_common/msg/rosidl_generator_c__visibility_control.h"

#include "abds_core_common/srv/detail/luminar_set_fov__struct.h"

/// Initialize srv/LuminarSetFov message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * abds_core_common__srv__LuminarSetFov_Request
 * )) before or use
 * abds_core_common__srv__LuminarSetFov_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
bool
abds_core_common__srv__LuminarSetFov_Request__init(abds_core_common__srv__LuminarSetFov_Request * msg);

/// Finalize srv/LuminarSetFov message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Request__fini(abds_core_common__srv__LuminarSetFov_Request * msg);

/// Create srv/LuminarSetFov message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * abds_core_common__srv__LuminarSetFov_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
abds_core_common__srv__LuminarSetFov_Request *
abds_core_common__srv__LuminarSetFov_Request__create();

/// Destroy srv/LuminarSetFov message.
/**
 * It calls
 * abds_core_common__srv__LuminarSetFov_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Request__destroy(abds_core_common__srv__LuminarSetFov_Request * msg);


/// Initialize array of srv/LuminarSetFov messages.
/**
 * It allocates the memory for the number of elements and calls
 * abds_core_common__srv__LuminarSetFov_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
bool
abds_core_common__srv__LuminarSetFov_Request__Sequence__init(abds_core_common__srv__LuminarSetFov_Request__Sequence * array, size_t size);

/// Finalize array of srv/LuminarSetFov messages.
/**
 * It calls
 * abds_core_common__srv__LuminarSetFov_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Request__Sequence__fini(abds_core_common__srv__LuminarSetFov_Request__Sequence * array);

/// Create array of srv/LuminarSetFov messages.
/**
 * It allocates the memory for the array and calls
 * abds_core_common__srv__LuminarSetFov_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
abds_core_common__srv__LuminarSetFov_Request__Sequence *
abds_core_common__srv__LuminarSetFov_Request__Sequence__create(size_t size);

/// Destroy array of srv/LuminarSetFov messages.
/**
 * It calls
 * abds_core_common__srv__LuminarSetFov_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Request__Sequence__destroy(abds_core_common__srv__LuminarSetFov_Request__Sequence * array);

/// Initialize srv/LuminarSetFov message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * abds_core_common__srv__LuminarSetFov_Response
 * )) before or use
 * abds_core_common__srv__LuminarSetFov_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
bool
abds_core_common__srv__LuminarSetFov_Response__init(abds_core_common__srv__LuminarSetFov_Response * msg);

/// Finalize srv/LuminarSetFov message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Response__fini(abds_core_common__srv__LuminarSetFov_Response * msg);

/// Create srv/LuminarSetFov message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * abds_core_common__srv__LuminarSetFov_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
abds_core_common__srv__LuminarSetFov_Response *
abds_core_common__srv__LuminarSetFov_Response__create();

/// Destroy srv/LuminarSetFov message.
/**
 * It calls
 * abds_core_common__srv__LuminarSetFov_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Response__destroy(abds_core_common__srv__LuminarSetFov_Response * msg);


/// Initialize array of srv/LuminarSetFov messages.
/**
 * It allocates the memory for the number of elements and calls
 * abds_core_common__srv__LuminarSetFov_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
bool
abds_core_common__srv__LuminarSetFov_Response__Sequence__init(abds_core_common__srv__LuminarSetFov_Response__Sequence * array, size_t size);

/// Finalize array of srv/LuminarSetFov messages.
/**
 * It calls
 * abds_core_common__srv__LuminarSetFov_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Response__Sequence__fini(abds_core_common__srv__LuminarSetFov_Response__Sequence * array);

/// Create array of srv/LuminarSetFov messages.
/**
 * It allocates the memory for the array and calls
 * abds_core_common__srv__LuminarSetFov_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
abds_core_common__srv__LuminarSetFov_Response__Sequence *
abds_core_common__srv__LuminarSetFov_Response__Sequence__create(size_t size);

/// Destroy array of srv/LuminarSetFov messages.
/**
 * It calls
 * abds_core_common__srv__LuminarSetFov_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_core_common
void
abds_core_common__srv__LuminarSetFov_Response__Sequence__destroy(abds_core_common__srv__LuminarSetFov_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__FUNCTIONS_H_
