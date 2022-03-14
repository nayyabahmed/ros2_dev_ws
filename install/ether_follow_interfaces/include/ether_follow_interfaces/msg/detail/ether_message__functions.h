// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice

#ifndef ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__FUNCTIONS_H_
#define ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ether_follow_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ether_follow_interfaces/msg/detail/ether_message__struct.h"

/// Initialize msg/EtherMessage message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ether_follow_interfaces__msg__EtherMessage
 * )) before or use
 * ether_follow_interfaces__msg__EtherMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
bool
ether_follow_interfaces__msg__EtherMessage__init(ether_follow_interfaces__msg__EtherMessage * msg);

/// Finalize msg/EtherMessage message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
void
ether_follow_interfaces__msg__EtherMessage__fini(ether_follow_interfaces__msg__EtherMessage * msg);

/// Create msg/EtherMessage message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ether_follow_interfaces__msg__EtherMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
ether_follow_interfaces__msg__EtherMessage *
ether_follow_interfaces__msg__EtherMessage__create();

/// Destroy msg/EtherMessage message.
/**
 * It calls
 * ether_follow_interfaces__msg__EtherMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
void
ether_follow_interfaces__msg__EtherMessage__destroy(ether_follow_interfaces__msg__EtherMessage * msg);


/// Initialize array of msg/EtherMessage messages.
/**
 * It allocates the memory for the number of elements and calls
 * ether_follow_interfaces__msg__EtherMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
bool
ether_follow_interfaces__msg__EtherMessage__Sequence__init(ether_follow_interfaces__msg__EtherMessage__Sequence * array, size_t size);

/// Finalize array of msg/EtherMessage messages.
/**
 * It calls
 * ether_follow_interfaces__msg__EtherMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
void
ether_follow_interfaces__msg__EtherMessage__Sequence__fini(ether_follow_interfaces__msg__EtherMessage__Sequence * array);

/// Create array of msg/EtherMessage messages.
/**
 * It allocates the memory for the array and calls
 * ether_follow_interfaces__msg__EtherMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
ether_follow_interfaces__msg__EtherMessage__Sequence *
ether_follow_interfaces__msg__EtherMessage__Sequence__create(size_t size);

/// Destroy array of msg/EtherMessage messages.
/**
 * It calls
 * ether_follow_interfaces__msg__EtherMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ether_follow_interfaces
void
ether_follow_interfaces__msg__EtherMessage__Sequence__destroy(ether_follow_interfaces__msg__EtherMessage__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__FUNCTIONS_H_
