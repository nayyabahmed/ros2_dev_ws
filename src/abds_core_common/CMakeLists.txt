cmake_minimum_required(VERSION 3.5)
project(abds_core_common)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

find_package(rosidl_default_generators REQUIRED)

ament_auto_add_library(${PROJECT_NAME}_lib SHARED
include/msg_buffer.hpp
include/calculations.hpp
include/types.hpp
include/data_storage/quad_storage.hpp
include/data_storage/quad_storage.cpp
include/data_storage/spatial_hash.hpp
include/data_storage/spatial_hash.cpp
include/geometry/bounding_box.hpp
include/network/udp_client_server.hpp
include/network/udp_client_server.cpp
include/lidar_util/point_cloud_transformer.hpp)

rosidl_generate_interfaces(${PROJECT_NAME}
"interfaces/LuminarConnect.srv"
"interfaces/LuminarDiscoverSensors.srv"
"interfaces/LuminarSetDuration.srv"
"interfaces/LuminarSetFov.srv"
"interfaces/LuminarSetFrequency.srv"
"msg/Cluster.msg"
"msg/Clusters.msg"
"msg/BoundingBox.msg"
"msg/BoundingBoxes.msg"
"msg/TrajectoryPoint.msg"
"msg/Trajectory.msg"
"msg/VehicleCommand.msg"
"msg/VehicleState.msg"
"msg/TestState.msg"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()
