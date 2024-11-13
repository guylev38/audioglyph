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
include examples/CMakeFiles/shaders_texture_tiling.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/shaders_texture_tiling.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/shaders_texture_tiling.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/shaders_texture_tiling.dir/flags.make

examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o: examples/CMakeFiles/shaders_texture_tiling.dir/flags.make
examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o: /home/guy/Projects/audioglyph/build/external/raylib-master/examples/shaders/shaders_texture_tiling.c
examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o: examples/CMakeFiles/shaders_texture_tiling.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o -MF CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o.d -o CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o -c /home/guy/Projects/audioglyph/build/external/raylib-master/examples/shaders/shaders_texture_tiling.c

examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.i"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/guy/Projects/audioglyph/build/external/raylib-master/examples/shaders/shaders_texture_tiling.c > CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.i

examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.s"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/guy/Projects/audioglyph/build/external/raylib-master/examples/shaders/shaders_texture_tiling.c -o CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.s

# Object files for target shaders_texture_tiling
shaders_texture_tiling_OBJECTS = \
"CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o"

# External object files for target shaders_texture_tiling
shaders_texture_tiling_EXTERNAL_OBJECTS =

examples/shaders_texture_tiling: examples/CMakeFiles/shaders_texture_tiling.dir/shaders/shaders_texture_tiling.c.o
examples/shaders_texture_tiling: examples/CMakeFiles/shaders_texture_tiling.dir/build.make
examples/shaders_texture_tiling: raylib/libraylib.a
examples/shaders_texture_tiling: /usr/lib/x86_64-linux-gnu/libOpenGL.so
examples/shaders_texture_tiling: /usr/lib/x86_64-linux-gnu/libGLX.so
examples/shaders_texture_tiling: /usr/lib/x86_64-linux-gnu/libGLU.so
examples/shaders_texture_tiling: /usr/lib/x86_64-linux-gnu/librt.a
examples/shaders_texture_tiling: /usr/lib/x86_64-linux-gnu/libm.so
examples/shaders_texture_tiling: examples/CMakeFiles/shaders_texture_tiling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable shaders_texture_tiling"
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shaders_texture_tiling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/shaders_texture_tiling.dir/build: examples/shaders_texture_tiling
.PHONY : examples/CMakeFiles/shaders_texture_tiling.dir/build

examples/CMakeFiles/shaders_texture_tiling.dir/clean:
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/shaders_texture_tiling.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/shaders_texture_tiling.dir/clean

examples/CMakeFiles/shaders_texture_tiling.dir/depend:
	cd /home/guy/Projects/audioglyph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guy/Projects/audioglyph/build/external/raylib-master /home/guy/Projects/audioglyph/build/external/raylib-master/examples /home/guy/Projects/audioglyph/build /home/guy/Projects/audioglyph/build/examples /home/guy/Projects/audioglyph/build/examples/CMakeFiles/shaders_texture_tiling.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/shaders_texture_tiling.dir/depend

