# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/yaaaniks/VSCode/domashka_proga/MR2023/Semikozov.Ian/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yaaaniks/VSCode/domashka_proga/MR2023/build

# Include any dependencies generated for this target.
include example/CMakeFiles/example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include example/CMakeFiles/example.dir/compiler_depend.make

# Include the progress variables for this target.
include example/CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/example.dir/flags.make

example/CMakeFiles/example.dir/example.c.o: example/CMakeFiles/example.dir/flags.make
example/CMakeFiles/example.dir/example.c.o: /home/yaaaniks/VSCode/domashka_proga/MR2023/Semikozov.Ian/task2/example/example.c
example/CMakeFiles/example.dir/example.c.o: example/CMakeFiles/example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaaaniks/VSCode/domashka_proga/MR2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object example/CMakeFiles/example.dir/example.c.o"
	cd /home/yaaaniks/VSCode/domashka_proga/MR2023/build/example && /usr/bin/gcc-12 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT example/CMakeFiles/example.dir/example.c.o -MF CMakeFiles/example.dir/example.c.o.d -o CMakeFiles/example.dir/example.c.o -c /home/yaaaniks/VSCode/domashka_proga/MR2023/Semikozov.Ian/task2/example/example.c

example/CMakeFiles/example.dir/example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example.dir/example.c.i"
	cd /home/yaaaniks/VSCode/domashka_proga/MR2023/build/example && /usr/bin/gcc-12 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yaaaniks/VSCode/domashka_proga/MR2023/Semikozov.Ian/task2/example/example.c > CMakeFiles/example.dir/example.c.i

example/CMakeFiles/example.dir/example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example.dir/example.c.s"
	cd /home/yaaaniks/VSCode/domashka_proga/MR2023/build/example && /usr/bin/gcc-12 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yaaaniks/VSCode/domashka_proga/MR2023/Semikozov.Ian/task2/example/example.c -o CMakeFiles/example.dir/example.c.s

# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/example.c.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

example/example: example/CMakeFiles/example.dir/example.c.o
example/example: example/CMakeFiles/example.dir/build.make
example/example: libmatrix.a
example/example: example/CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yaaaniks/VSCode/domashka_proga/MR2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable example"
	cd /home/yaaaniks/VSCode/domashka_proga/MR2023/build/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/CMakeFiles/example.dir/build: example/example
.PHONY : example/CMakeFiles/example.dir/build

example/CMakeFiles/example.dir/clean:
	cd /home/yaaaniks/VSCode/domashka_proga/MR2023/build/example && $(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : example/CMakeFiles/example.dir/clean

example/CMakeFiles/example.dir/depend:
	cd /home/yaaaniks/VSCode/domashka_proga/MR2023/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yaaaniks/VSCode/domashka_proga/MR2023/Semikozov.Ian/task2 /home/yaaaniks/VSCode/domashka_proga/MR2023/Semikozov.Ian/task2/example /home/yaaaniks/VSCode/domashka_proga/MR2023/build /home/yaaaniks/VSCode/domashka_proga/MR2023/build/example /home/yaaaniks/VSCode/domashka_proga/MR2023/build/example/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/CMakeFiles/example.dir/depend

