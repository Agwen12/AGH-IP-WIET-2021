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
CMAKE_SOURCE_DIR = /cygdrive/d/sem2/PI/jedno_kwadrat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/sem2/PI/jedno_kwadrat/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/jedno_kwadrat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jedno_kwadrat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jedno_kwadrat.dir/flags.make

CMakeFiles/jedno_kwadrat.dir/main.c.o: CMakeFiles/jedno_kwadrat.dir/flags.make
CMakeFiles/jedno_kwadrat.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/sem2/PI/jedno_kwadrat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/jedno_kwadrat.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/jedno_kwadrat.dir/main.c.o   -c /cygdrive/d/sem2/PI/jedno_kwadrat/main.c

CMakeFiles/jedno_kwadrat.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jedno_kwadrat.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/sem2/PI/jedno_kwadrat/main.c > CMakeFiles/jedno_kwadrat.dir/main.c.i

CMakeFiles/jedno_kwadrat.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jedno_kwadrat.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/sem2/PI/jedno_kwadrat/main.c -o CMakeFiles/jedno_kwadrat.dir/main.c.s

# Object files for target jedno_kwadrat
jedno_kwadrat_OBJECTS = \
"CMakeFiles/jedno_kwadrat.dir/main.c.o"

# External object files for target jedno_kwadrat
jedno_kwadrat_EXTERNAL_OBJECTS =

jedno_kwadrat.exe: CMakeFiles/jedno_kwadrat.dir/main.c.o
jedno_kwadrat.exe: CMakeFiles/jedno_kwadrat.dir/build.make
jedno_kwadrat.exe: CMakeFiles/jedno_kwadrat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/sem2/PI/jedno_kwadrat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable jedno_kwadrat.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jedno_kwadrat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jedno_kwadrat.dir/build: jedno_kwadrat.exe

.PHONY : CMakeFiles/jedno_kwadrat.dir/build

CMakeFiles/jedno_kwadrat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jedno_kwadrat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jedno_kwadrat.dir/clean

CMakeFiles/jedno_kwadrat.dir/depend:
	cd /cygdrive/d/sem2/PI/jedno_kwadrat/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/sem2/PI/jedno_kwadrat /cygdrive/d/sem2/PI/jedno_kwadrat /cygdrive/d/sem2/PI/jedno_kwadrat/cmake-build-debug /cygdrive/d/sem2/PI/jedno_kwadrat/cmake-build-debug /cygdrive/d/sem2/PI/jedno_kwadrat/cmake-build-debug/CMakeFiles/jedno_kwadrat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jedno_kwadrat.dir/depend
