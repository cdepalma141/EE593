# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "/Users/connordepalma/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4505.18/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/connordepalma/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4505.18/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/connordepalma/Documents/Git/EE593/Session5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/connordepalma/Documents/Git/EE593/Session5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Session5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Session5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Session5.dir/flags.make

CMakeFiles/Session5.dir/main.cpp.o: CMakeFiles/Session5.dir/flags.make
CMakeFiles/Session5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connordepalma/Documents/Git/EE593/Session5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Session5.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Session5.dir/main.cpp.o -c /Users/connordepalma/Documents/Git/EE593/Session5/main.cpp

CMakeFiles/Session5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Session5.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connordepalma/Documents/Git/EE593/Session5/main.cpp > CMakeFiles/Session5.dir/main.cpp.i

CMakeFiles/Session5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Session5.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connordepalma/Documents/Git/EE593/Session5/main.cpp -o CMakeFiles/Session5.dir/main.cpp.s

# Object files for target Session5
Session5_OBJECTS = \
"CMakeFiles/Session5.dir/main.cpp.o"

# External object files for target Session5
Session5_EXTERNAL_OBJECTS =

Session5: CMakeFiles/Session5.dir/main.cpp.o
Session5: CMakeFiles/Session5.dir/build.make
Session5: CMakeFiles/Session5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/connordepalma/Documents/Git/EE593/Session5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Session5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Session5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Session5.dir/build: Session5

.PHONY : CMakeFiles/Session5.dir/build

CMakeFiles/Session5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Session5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Session5.dir/clean

CMakeFiles/Session5.dir/depend:
	cd /Users/connordepalma/Documents/Git/EE593/Session5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/connordepalma/Documents/Git/EE593/Session5 /Users/connordepalma/Documents/Git/EE593/Session5 /Users/connordepalma/Documents/Git/EE593/Session5/cmake-build-debug /Users/connordepalma/Documents/Git/EE593/Session5/cmake-build-debug /Users/connordepalma/Documents/Git/EE593/Session5/cmake-build-debug/CMakeFiles/Session5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Session5.dir/depend

