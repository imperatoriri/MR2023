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
CMAKE_SOURCE_DIR = /home/marsel/Polikek/programming/Matrix_lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marsel/Polikek/programming/Matrix_lib/build

# Include any dependencies generated for this target.
include CMakeFiles/Matrix_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Matrix_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Matrix_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Matrix_lib.dir/flags.make

CMakeFiles/Matrix_lib.dir/matrix.c.o: CMakeFiles/Matrix_lib.dir/flags.make
CMakeFiles/Matrix_lib.dir/matrix.c.o: ../matrix.c
CMakeFiles/Matrix_lib.dir/matrix.c.o: CMakeFiles/Matrix_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsel/Polikek/programming/Matrix_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Matrix_lib.dir/matrix.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Matrix_lib.dir/matrix.c.o -MF CMakeFiles/Matrix_lib.dir/matrix.c.o.d -o CMakeFiles/Matrix_lib.dir/matrix.c.o -c /home/marsel/Polikek/programming/Matrix_lib/matrix.c

CMakeFiles/Matrix_lib.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Matrix_lib.dir/matrix.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marsel/Polikek/programming/Matrix_lib/matrix.c > CMakeFiles/Matrix_lib.dir/matrix.c.i

CMakeFiles/Matrix_lib.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Matrix_lib.dir/matrix.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marsel/Polikek/programming/Matrix_lib/matrix.c -o CMakeFiles/Matrix_lib.dir/matrix.c.s

# Object files for target Matrix_lib
Matrix_lib_OBJECTS = \
"CMakeFiles/Matrix_lib.dir/matrix.c.o"

# External object files for target Matrix_lib
Matrix_lib_EXTERNAL_OBJECTS =

libMatrix_lib.a: CMakeFiles/Matrix_lib.dir/matrix.c.o
libMatrix_lib.a: CMakeFiles/Matrix_lib.dir/build.make
libMatrix_lib.a: CMakeFiles/Matrix_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marsel/Polikek/programming/Matrix_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libMatrix_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Matrix_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Matrix_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Matrix_lib.dir/build: libMatrix_lib.a
.PHONY : CMakeFiles/Matrix_lib.dir/build

CMakeFiles/Matrix_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Matrix_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Matrix_lib.dir/clean

CMakeFiles/Matrix_lib.dir/depend:
	cd /home/marsel/Polikek/programming/Matrix_lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marsel/Polikek/programming/Matrix_lib /home/marsel/Polikek/programming/Matrix_lib /home/marsel/Polikek/programming/Matrix_lib/build /home/marsel/Polikek/programming/Matrix_lib/build /home/marsel/Polikek/programming/Matrix_lib/build/CMakeFiles/Matrix_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Matrix_lib.dir/depend

