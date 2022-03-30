# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_abd_robot_comms_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED abd_robot_comms_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(abd_robot_comms_FOUND FALSE)
  elseif(NOT abd_robot_comms_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(abd_robot_comms_FOUND FALSE)
  endif()
  return()
endif()
set(_abd_robot_comms_CONFIG_INCLUDED TRUE)

# output package information
if(NOT abd_robot_comms_FIND_QUIETLY)
  message(STATUS "Found abd_robot_comms: 0.0.0 (${abd_robot_comms_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'abd_robot_comms' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${abd_robot_comms_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(abd_robot_comms_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${abd_robot_comms_DIR}/${_extra}")
endforeach()
