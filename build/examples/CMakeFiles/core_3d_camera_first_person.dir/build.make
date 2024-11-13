# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guy/Projects/audioglyph/build/external/raylib-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guy/Projects/audioglyph/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/core_3d_camera_first_person.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/core_3d_camera_first_person.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/core_3d_camera_first_person.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/core_3d_camera_first_person.dir/flags.make

examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o: examples/CMakeFiles/core_3d_camera_first_person.dir/flags.make
examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o: /home/guy/Projects/audioglyph/build/external/raylib-master/examples/core/core_3d_camera_first_person.c
examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o: examples/CMakeFiles/core_3d_camera_first_person.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o -MF CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o.d -o CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o -c /home/guy/Projects/audioglyph/build/external/raylib-master/examples/core/core_3d_camera_first_person.c

examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.i"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/guy/Projects/audioglyph/build/external/raylib-master/examples/core/core_3d_camera_first_person.c > CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.i

examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.s"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/guy/Projects/audioglyph/build/external/raylib-master/examples/core/core_3d_camera_first_person.c -o CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.s

# Object files for target core_3d_camera_first_person
core_3d_camera_first_person_OBJECTS = \
"CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o"

# External object files for target core_3d_camera_first_person
core_3d_camera_first_person_EXTERNAL_OBJECTS =

examples/core_3d_camera_first_person: examples/CMakeFiles/core_3d_camera_first_person.dir/core/core_3d_camera_first_person.c.o
examples/core_3d_camera_first_person: examples/CMakeFiles/core_3d_camera_first_person.dir/build.make
examples/core_3d_camera_first_person: raylib/libraylib.a
examples/core_3d_camera_first_person: /usr/lib/x86_64-linux-gnu/libOpenGL.so
examples/core_3d_camera_first_person: /usr/lib/x86_64-linux-gnu/libGLX.so
examples/core_3d_camera_first_person: /usr/lib/x86_64-linux-gnu/libGLU.so
examples/core_3d_camera_first_person: /usr/lib/x86_64-linux-gnu/librt.a
examples/core_3d_camera_first_person: /usr/lib/x86_64-linux-gnu/libm.so
examples/core_3d_camera_first_person: examples/CMakeFiles/core_3d_camera_first_person.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable core_3d_camera_first_person"
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core_3d_camera_first_person.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/core_3d_camera_first_person.dir/build: examples/core_3d_camera_first_person
.PHONY : examples/CMakeFiles/core_3d_camera_first_person.dir/build

examples/CMakeFiles/core_3d_camera_first_person.dir/clean:
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/core_3d_camera_first_person.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/core_3d_camera_first_person.dir/clean

examples/CMakeFiles/core_3d_camera_first_person.dir/depend:
	cd /home/guy/Projects/audioglyph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guy/Projects/audioglyph/build/external/raylib-master /home/guy/Projects/audioglyph/build/external/raylib-master/examples /home/guy/Projects/audioglyph/build /home/guy/Projects/audioglyph/build/examples /home/guy/Projects/audioglyph/build/examples/CMakeFiles/core_3d_camera_first_person.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/core_3d_camera_first_person.dir/depend

