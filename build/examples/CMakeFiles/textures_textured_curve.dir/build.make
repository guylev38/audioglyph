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
include examples/CMakeFiles/textures_textured_curve.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/textures_textured_curve.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/textures_textured_curve.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/textures_textured_curve.dir/flags.make

examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o: examples/CMakeFiles/textures_textured_curve.dir/flags.make
examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o: /home/guy/Projects/audioglyph/build/external/raylib-master/examples/textures/textures_textured_curve.c
examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o: examples/CMakeFiles/textures_textured_curve.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o -MF CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o.d -o CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o -c /home/guy/Projects/audioglyph/build/external/raylib-master/examples/textures/textures_textured_curve.c

examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.i"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/guy/Projects/audioglyph/build/external/raylib-master/examples/textures/textures_textured_curve.c > CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.i

examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.s"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/guy/Projects/audioglyph/build/external/raylib-master/examples/textures/textures_textured_curve.c -o CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.s

# Object files for target textures_textured_curve
textures_textured_curve_OBJECTS = \
"CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o"

# External object files for target textures_textured_curve
textures_textured_curve_EXTERNAL_OBJECTS =

examples/textures_textured_curve: examples/CMakeFiles/textures_textured_curve.dir/textures/textures_textured_curve.c.o
examples/textures_textured_curve: examples/CMakeFiles/textures_textured_curve.dir/build.make
examples/textures_textured_curve: raylib/libraylib.a
examples/textures_textured_curve: /usr/lib/x86_64-linux-gnu/libOpenGL.so
examples/textures_textured_curve: /usr/lib/x86_64-linux-gnu/libGLX.so
examples/textures_textured_curve: /usr/lib/x86_64-linux-gnu/libGLU.so
examples/textures_textured_curve: /usr/lib/x86_64-linux-gnu/librt.a
examples/textures_textured_curve: /usr/lib/x86_64-linux-gnu/libm.so
examples/textures_textured_curve: examples/CMakeFiles/textures_textured_curve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable textures_textured_curve"
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/textures_textured_curve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/textures_textured_curve.dir/build: examples/textures_textured_curve
.PHONY : examples/CMakeFiles/textures_textured_curve.dir/build

examples/CMakeFiles/textures_textured_curve.dir/clean:
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/textures_textured_curve.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/textures_textured_curve.dir/clean

examples/CMakeFiles/textures_textured_curve.dir/depend:
	cd /home/guy/Projects/audioglyph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guy/Projects/audioglyph/build/external/raylib-master /home/guy/Projects/audioglyph/build/external/raylib-master/examples /home/guy/Projects/audioglyph/build /home/guy/Projects/audioglyph/build/examples /home/guy/Projects/audioglyph/build/examples/CMakeFiles/textures_textured_curve.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/textures_textured_curve.dir/depend

