// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__RC_STATUS__FUNCTIONS_H_
#define RC_INTERFACES__MSG__DETAIL__RC_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rc_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rc_interfaces/msg/detail/rc_status__struct.h"

/// Initialize msg/RcStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rc_interfaces__msg__RcStatus
 * )) before or use
 * rc_interfaces__msg__RcStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
bool
rc_interfaces__msg__RcStatus__init(rc_interfaces__msg__RcStatus * msg);

/// Finalize msg/RcStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
void
rc_interfaces__msg__RcStatus__fini(rc_interfaces__msg__RcStatus * msg);

/// Create msg/RcStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rc_interfaces__msg__RcStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
rc_interfaces__msg__RcStatus *
rc_interfaces__msg__RcStatus__create();

/// Destroy msg/RcStatus message.
/**
 * It calls
 * rc_interfaces__msg__RcStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
void
rc_interfaces__msg__RcStatus__destroy(rc_interfaces__msg__RcStatus * msg);


/// Initialize array of msg/RcStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * rc_interfaces__msg__RcStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
bool
rc_interfaces__msg__RcStatus__Sequence__init(rc_interfaces__msg__RcStatus__Sequence * array, size_t size);

/// Finalize array of msg/RcStatus messages.
/**
 * It calls
 * rc_interfaces__msg__RcStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
void
rc_interfaces__msg__RcStatus__Sequence__fini(rc_interfaces__msg__RcStatus__Sequence * array);

/// Create array of msg/RcStatus messages.
/**
 * It allocates the memory for the array and calls
 * rc_interfaces__msg__RcStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
rc_interfaces__msg__RcStatus__Sequence *
rc_interfaces__msg__RcStatus__Sequence__create(size_t size);

/// Destroy array of msg/RcStatus messages.
/**
 * It calls
 * rc_interfaces__msg__RcStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rc_interfaces
void
rc_interfaces__msg__RcStatus__Sequence__destroy(rc_interfaces__msg__RcStatus__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // RC_INTERFACES__MSG__DETAIL__RC_STATUS__FUNCTIONS_H_
