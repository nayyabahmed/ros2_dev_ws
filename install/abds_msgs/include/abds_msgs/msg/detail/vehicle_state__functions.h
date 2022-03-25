// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from abds_msgs:msg/VehicleState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__FUNCTIONS_H_
#define ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "abds_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "abds_msgs/msg/detail/vehicle_state__struct.h"

/// Initialize msg/VehicleState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * abds_msgs__msg__VehicleState
 * )) before or use
 * abds_msgs__msg__VehicleState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
bool
abds_msgs__msg__VehicleState__init(abds_msgs__msg__VehicleState * msg);

/// Finalize msg/VehicleState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__VehicleState__fini(abds_msgs__msg__VehicleState * msg);

/// Create msg/VehicleState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * abds_msgs__msg__VehicleState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
abds_msgs__msg__VehicleState *
abds_msgs__msg__VehicleState__create();

/// Destroy msg/VehicleState message.
/**
 * It calls
 * abds_msgs__msg__VehicleState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__VehicleState__destroy(abds_msgs__msg__VehicleState * msg);


/// Initialize array of msg/VehicleState messages.
/**
 * It allocates the memory for the number of elements and calls
 * abds_msgs__msg__VehicleState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
bool
abds_msgs__msg__VehicleState__Sequence__init(abds_msgs__msg__VehicleState__Sequence * array, size_t size);

/// Finalize array of msg/VehicleState messages.
/**
 * It calls
 * abds_msgs__msg__VehicleState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__VehicleState__Sequence__fini(abds_msgs__msg__VehicleState__Sequence * array);

/// Create array of msg/VehicleState messages.
/**
 * It allocates the memory for the array and calls
 * abds_msgs__msg__VehicleState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
abds_msgs__msg__VehicleState__Sequence *
abds_msgs__msg__VehicleState__Sequence__create(size_t size);

/// Destroy array of msg/VehicleState messages.
/**
 * It calls
 * abds_msgs__msg__VehicleState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__VehicleState__Sequence__destroy(abds_msgs__msg__VehicleState__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__FUNCTIONS_H_
