# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/cygdrive/c/Users/Focusing Iris/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/Focusing Iris/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/sem2/PI/Roman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/sem2/PI/Roman/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Roman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Roman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Roman.dir/flags.make

CMakeFiles/Roman.dir/main.c.o: CMakeFiles/Roman.dir/flags.make
CMakeFiles/Roman.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/sem2/PI/Roman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Roman.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Roman.dir/main.c.o   -c /cygdrive/d/sem2/PI/Roman/main.c

CMakeFiles/Roman.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Roman.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/sem2/PI/Roman/main.c > CMakeFiles/Roman.dir/main.c.i

CMakeFiles/Roman.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Roman.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/sem2/PI/Roman/main.c -o CMakeFiles/Roman.dir/main.c.s

# Object files for target Roman
Roman_OBJECTS = \
"CMakeFiles/Roman.dir/main.c.o"

# External object files for target Roman
Roman_EXTERNAL_OBJECTS =

Roman.exe: CMakeFiles/Roman.dir/main.c.o
Roman.exe: CMakeFiles/Roman.dir/build.make
Roman.exe: CMakeFiles/Roman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/sem2/PI/Roman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Roman.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Roman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Roman.dir/build: Roman.exe

.PHONY : CMakeFiles/Roman.dir/build

CMakeFiles/Roman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Roman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Roman.dir/clean

CMakeFiles/Roman.dir/depend:
	cd /cygdrive/d/sem2/PI/Roman/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/sem2/PI/Roman /cygdrive/d/sem2/PI/Roman /cygdrive/d/sem2/PI/Roman/cmake-build-debug /cygdrive/d/sem2/PI/Roman/cmake-build-debug /cygdrive/d/sem2/PI/Roman/cmake-build-debug/CMakeFiles/Roman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Roman.dir/depend
