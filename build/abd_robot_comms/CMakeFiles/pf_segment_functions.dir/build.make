# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nayab/dev_ws/src/abd_robot_comms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nayab/dev_ws/build/abd_robot_comms

# Include any dependencies generated for this target.
include CMakeFiles/pf_segment_functions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pf_segment_functions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pf_segment_functions.dir/flags.make

CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.o: CMakeFiles/pf_segment_functions.dir/flags.make
CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.o: /home/nayab/dev_ws/src/abd_robot_comms/src/pf_segment_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nayab/dev_ws/build/abd_robot_comms/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.o   -c /home/nayab/dev_ws/src/abd_robot_comms/src/pf_segment_functions.c

CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nayab/dev_ws/src/abd_robot_comms/src/pf_segment_functions.c > CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.i

CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nayab/dev_ws/src/abd_robot_comms/src/pf_segment_functions.c -o CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.s

# Object files for target pf_segment_functions
pf_segment_functions_OBJECTS = \
"CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.o"

# External object files for target pf_segment_functions
pf_segment_functions_EXTERNAL_OBJECTS =

libpf_segment_functions.a: CMakeFiles/pf_segment_functions.dir/src/pf_segment_functions.c.o
libpf_segment_functions.a: CMakeFiles/pf_segment_functions.dir/build.make
libpf_segment_functions.a: CMakeFiles/pf_segment_functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nayab/dev_ws/build/abd_robot_comms/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libpf_segment_functions.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pf_segment_functions.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pf_segment_functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pf_segment_functions.dir/build: libpf_segment_functions.a

.PHONY : CMakeFiles/pf_segment_functions.dir/build

CMakeFiles/pf_segment_functions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pf_segment_functions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pf_segment_functions.dir/clean

CMakeFiles/pf_segment_functions.dir/depend:
	cd /home/nayab/dev_ws/build/abd_robot_comms && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nayab/dev_ws/src/abd_robot_comms /home/nayab/dev_ws/src/abd_robot_comms /home/nayab/dev_ws/build/abd_robot_comms /home/nayab/dev_ws/build/abd_robot_comms /home/nayab/dev_ws/build/abd_robot_comms/CMakeFiles/pf_segment_functions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pf_segment_functions.dir/depend
