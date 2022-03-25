// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from abds_msgs:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__FUNCTIONS_H_
#define ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "abds_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "abds_msgs/msg/detail/bounding_boxes__struct.h"

/// Initialize msg/BoundingBoxes message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * abds_msgs__msg__BoundingBoxes
 * )) before or use
 * abds_msgs__msg__BoundingBoxes__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
bool
abds_msgs__msg__BoundingBoxes__init(abds_msgs__msg__BoundingBoxes * msg);

/// Finalize msg/BoundingBoxes message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__BoundingBoxes__fini(abds_msgs__msg__BoundingBoxes * msg);

/// Create msg/BoundingBoxes message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * abds_msgs__msg__BoundingBoxes__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
abds_msgs__msg__BoundingBoxes *
abds_msgs__msg__BoundingBoxes__create();

/// Destroy msg/BoundingBoxes message.
/**
 * It calls
 * abds_msgs__msg__BoundingBoxes__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__BoundingBoxes__destroy(abds_msgs__msg__BoundingBoxes * msg);


/// Initialize array of msg/BoundingBoxes messages.
/**
 * It allocates the memory for the number of elements and calls
 * abds_msgs__msg__BoundingBoxes__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
bool
abds_msgs__msg__BoundingBoxes__Sequence__init(abds_msgs__msg__BoundingBoxes__Sequence * array, size_t size);

/// Finalize array of msg/BoundingBoxes messages.
/**
 * It calls
 * abds_msgs__msg__BoundingBoxes__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__BoundingBoxes__Sequence__fini(abds_msgs__msg__BoundingBoxes__Sequence * array);

/// Create array of msg/BoundingBoxes messages.
/**
 * It allocates the memory for the array and calls
 * abds_msgs__msg__BoundingBoxes__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
abds_msgs__msg__BoundingBoxes__Sequence *
abds_msgs__msg__BoundingBoxes__Sequence__create(size_t size);

/// Destroy array of msg/BoundingBoxes messages.
/**
 * It calls
 * abds_msgs__msg__BoundingBoxes__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_abds_msgs
void
abds_msgs__msg__BoundingBoxes__Sequence__destroy(abds_msgs__msg__BoundingBoxes__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__FUNCTIONS_H_
