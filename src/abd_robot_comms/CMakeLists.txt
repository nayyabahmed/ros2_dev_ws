cmake_minimum_required(VERSION 3.5)
project(abd_robot_comms)

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
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(abds_msgs REQUIRED)
find_package(rc_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_library( comms src/comms.c src/comms.h)
add_library( network_utils src/network_utils.c src/network_utils.h )
add_library( numeric_analysis src/numeric_analysis.c src/numeric_analysis.h)
add_library( pf_segment_functions src/pf_segment_functions.c src/pf_segment_functions.h)

add_executable(trajectory_calculator src/trajectory_calculator.cpp)

ament_target_dependencies(trajectory_calculator rclcpp std_msgs visualization_msgs abds_msgs rc_interfaces)

target_link_libraries( pf_segment_functions numeric_analysis )

target_link_libraries( trajectory_calculator comms network_utils numeric_analysis pf_segment_functions )

target_include_directories(trajectory_calculator PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)


install(TARGETS
	trajectory_calculator
	DESTINATION lib/${PROJECT_NAME})


ament_package()
