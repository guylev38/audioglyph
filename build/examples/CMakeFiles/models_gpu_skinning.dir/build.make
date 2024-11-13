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
include examples/CMakeFiles/models_gpu_skinning.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/models_gpu_skinning.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/models_gpu_skinning.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/models_gpu_skinning.dir/flags.make

examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o: examples/CMakeFiles/models_gpu_skinning.dir/flags.make
examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o: /home/guy/Projects/audioglyph/build/external/raylib-master/examples/models/models_gpu_skinning.c
examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o: examples/CMakeFiles/models_gpu_skinning.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o -MF CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o.d -o CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o -c /home/guy/Projects/audioglyph/build/external/raylib-master/examples/models/models_gpu_skinning.c

examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.i"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/guy/Projects/audioglyph/build/external/raylib-master/examples/models/models_gpu_skinning.c > CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.i

examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.s"
	cd /home/guy/Projects/audioglyph/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/guy/Projects/audioglyph/build/external/raylib-master/examples/models/models_gpu_skinning.c -o CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.s

# Object files for target models_gpu_skinning
models_gpu_skinning_OBJECTS = \
"CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o"

# External object files for target models_gpu_skinning
models_gpu_skinning_EXTERNAL_OBJECTS =

examples/models_gpu_skinning: examples/CMakeFiles/models_gpu_skinning.dir/models/models_gpu_skinning.c.o
examples/models_gpu_skinning: examples/CMakeFiles/models_gpu_skinning.dir/build.make
examples/models_gpu_skinning: raylib/libraylib.a
examples/models_gpu_skinning: /usr/lib/x86_64-linux-gnu/libOpenGL.so
examples/models_gpu_skinning: /usr/lib/x86_64-linux-gnu/libGLX.so
examples/models_gpu_skinning: /usr/lib/x86_64-linux-gnu/libGLU.so
examples/models_gpu_skinning: /usr/lib/x86_64-linux-gnu/librt.a
examples/models_gpu_skinning: /usr/lib/x86_64-linux-gnu/libm.so
examples/models_gpu_skinning: examples/CMakeFiles/models_gpu_skinning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/guy/Projects/audioglyph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable models_gpu_skinning"
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/models_gpu_skinning.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/models_gpu_skinning.dir/build: examples/models_gpu_skinning
.PHONY : examples/CMakeFiles/models_gpu_skinning.dir/build

examples/CMakeFiles/models_gpu_skinning.dir/clean:
	cd /home/guy/Projects/audioglyph/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/models_gpu_skinning.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/models_gpu_skinning.dir/clean

examples/CMakeFiles/models_gpu_skinning.dir/depend:
	cd /home/guy/Projects/audioglyph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guy/Projects/audioglyph/build/external/raylib-master /home/guy/Projects/audioglyph/build/external/raylib-master/examples /home/guy/Projects/audioglyph/build /home/guy/Projects/audioglyph/build/examples /home/guy/Projects/audioglyph/build/examples/CMakeFiles/models_gpu_skinning.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/models_gpu_skinning.dir/depend

