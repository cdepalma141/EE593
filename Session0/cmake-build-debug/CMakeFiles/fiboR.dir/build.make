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
CMAKE_COMMAND = "/Users/connordepalma/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4323.58/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/connordepalma/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4323.58/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/connordepalma/Documents/Git/EE593/Session0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/connordepalma/Documents/Git/EE593/Session0/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fiboR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fiboR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fiboR.dir/flags.make

CMakeFiles/fiboR.dir/fiboR.cpp.o: CMakeFiles/fiboR.dir/flags.make
CMakeFiles/fiboR.dir/fiboR.cpp.o: ../fiboR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connordepalma/Documents/Git/EE593/Session0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fiboR.dir/fiboR.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fiboR.dir/fiboR.cpp.o -c /Users/connordepalma/Documents/Git/EE593/Session0/fiboR.cpp

CMakeFiles/fiboR.dir/fiboR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fiboR.dir/fiboR.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connordepalma/Documents/Git/EE593/Session0/fiboR.cpp > CMakeFiles/fiboR.dir/fiboR.cpp.i

CMakeFiles/fiboR.dir/fiboR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fiboR.dir/fiboR.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connordepalma/Documents/Git/EE593/Session0/fiboR.cpp -o CMakeFiles/fiboR.dir/fiboR.cpp.s

# Object files for target fiboR
fiboR_OBJECTS = \
"CMakeFiles/fiboR.dir/fiboR.cpp.o"

# External object files for target fiboR
fiboR_EXTERNAL_OBJECTS =

fiboR: CMakeFiles/fiboR.dir/fiboR.cpp.o
fiboR: CMakeFiles/fiboR.dir/build.make
fiboR: CMakeFiles/fiboR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/connordepalma/Documents/Git/EE593/Session0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fiboR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fiboR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fiboR.dir/build: fiboR

.PHONY : CMakeFiles/fiboR.dir/build

CMakeFiles/fiboR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fiboR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fiboR.dir/clean

CMakeFiles/fiboR.dir/depend:
	cd /Users/connordepalma/Documents/Git/EE593/Session0/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/connordepalma/Documents/Git/EE593/Session0 /Users/connordepalma/Documents/Git/EE593/Session0 /Users/connordepalma/Documents/Git/EE593/Session0/cmake-build-debug /Users/connordepalma/Documents/Git/EE593/Session0/cmake-build-debug /Users/connordepalma/Documents/Git/EE593/Session0/cmake-build-debug/CMakeFiles/fiboR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fiboR.dir/depend

