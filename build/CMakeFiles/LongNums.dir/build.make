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
CMAKE_SOURCE_DIR = "/home/user/Documents/redactor bobba"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/user/Documents/redactor bobba/build"

# Include any dependencies generated for this target.
include CMakeFiles/LongNums.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LongNums.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LongNums.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LongNums.dir/flags.make

CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o: CMakeFiles/LongNums.dir/flags.make
CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o: ../libs/LongNums/LongNums.cpp
CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o: CMakeFiles/LongNums.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/user/Documents/redactor bobba/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o -MF CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o.d -o CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o -c "/home/user/Documents/redactor bobba/libs/LongNums/LongNums.cpp"

CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/user/Documents/redactor bobba/libs/LongNums/LongNums.cpp" > CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.i

CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/user/Documents/redactor bobba/libs/LongNums/LongNums.cpp" -o CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.s

# Object files for target LongNums
LongNums_OBJECTS = \
"CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o"

# External object files for target LongNums
LongNums_EXTERNAL_OBJECTS =

libLongNums.a: CMakeFiles/LongNums.dir/libs/LongNums/LongNums.cpp.o
libLongNums.a: CMakeFiles/LongNums.dir/build.make
libLongNums.a: CMakeFiles/LongNums.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/user/Documents/redactor bobba/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLongNums.a"
	$(CMAKE_COMMAND) -P CMakeFiles/LongNums.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LongNums.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LongNums.dir/build: libLongNums.a
.PHONY : CMakeFiles/LongNums.dir/build

CMakeFiles/LongNums.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LongNums.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LongNums.dir/clean

CMakeFiles/LongNums.dir/depend:
	cd "/home/user/Documents/redactor bobba/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/user/Documents/redactor bobba" "/home/user/Documents/redactor bobba" "/home/user/Documents/redactor bobba/build" "/home/user/Documents/redactor bobba/build" "/home/user/Documents/redactor bobba/build/CMakeFiles/LongNums.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LongNums.dir/depend
