# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/dean/Desktop/C++Project/Basic Code/Serial"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/dean/Desktop/C++Project/Basic Code/Serial/build"

# Include any dependencies generated for this target.
include CMakeFiles/Serialization.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Serialization.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Serialization.dir/flags.make

CMakeFiles/Serialization.dir/main.o: CMakeFiles/Serialization.dir/flags.make
CMakeFiles/Serialization.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/dean/Desktop/C++Project/Basic Code/Serial/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Serialization.dir/main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Serialization.dir/main.o -c "/Users/dean/Desktop/C++Project/Basic Code/Serial/main.cpp"

CMakeFiles/Serialization.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serialization.dir/main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dean/Desktop/C++Project/Basic Code/Serial/main.cpp" > CMakeFiles/Serialization.dir/main.i

CMakeFiles/Serialization.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serialization.dir/main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dean/Desktop/C++Project/Basic Code/Serial/main.cpp" -o CMakeFiles/Serialization.dir/main.s

CMakeFiles/Serialization.dir/serialize_xml.o: CMakeFiles/Serialization.dir/flags.make
CMakeFiles/Serialization.dir/serialize_xml.o: ../serialize_xml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/dean/Desktop/C++Project/Basic Code/Serial/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Serialization.dir/serialize_xml.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Serialization.dir/serialize_xml.o -c "/Users/dean/Desktop/C++Project/Basic Code/Serial/serialize_xml.cpp"

CMakeFiles/Serialization.dir/serialize_xml.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serialization.dir/serialize_xml.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dean/Desktop/C++Project/Basic Code/Serial/serialize_xml.cpp" > CMakeFiles/Serialization.dir/serialize_xml.i

CMakeFiles/Serialization.dir/serialize_xml.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serialization.dir/serialize_xml.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dean/Desktop/C++Project/Basic Code/Serial/serialize_xml.cpp" -o CMakeFiles/Serialization.dir/serialize_xml.s

CMakeFiles/Serialization.dir/tinyxml2.o: CMakeFiles/Serialization.dir/flags.make
CMakeFiles/Serialization.dir/tinyxml2.o: ../tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/dean/Desktop/C++Project/Basic Code/Serial/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Serialization.dir/tinyxml2.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Serialization.dir/tinyxml2.o -c "/Users/dean/Desktop/C++Project/Basic Code/Serial/tinyxml2.cpp"

CMakeFiles/Serialization.dir/tinyxml2.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serialization.dir/tinyxml2.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dean/Desktop/C++Project/Basic Code/Serial/tinyxml2.cpp" > CMakeFiles/Serialization.dir/tinyxml2.i

CMakeFiles/Serialization.dir/tinyxml2.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serialization.dir/tinyxml2.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dean/Desktop/C++Project/Basic Code/Serial/tinyxml2.cpp" -o CMakeFiles/Serialization.dir/tinyxml2.s

# Object files for target Serialization
Serialization_OBJECTS = \
"CMakeFiles/Serialization.dir/main.o" \
"CMakeFiles/Serialization.dir/serialize_xml.o" \
"CMakeFiles/Serialization.dir/tinyxml2.o"

# External object files for target Serialization
Serialization_EXTERNAL_OBJECTS =

Serialization: CMakeFiles/Serialization.dir/main.o
Serialization: CMakeFiles/Serialization.dir/serialize_xml.o
Serialization: CMakeFiles/Serialization.dir/tinyxml2.o
Serialization: CMakeFiles/Serialization.dir/build.make
Serialization: CMakeFiles/Serialization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/dean/Desktop/C++Project/Basic Code/Serial/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Serialization"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Serialization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Serialization.dir/build: Serialization

.PHONY : CMakeFiles/Serialization.dir/build

CMakeFiles/Serialization.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Serialization.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Serialization.dir/clean

CMakeFiles/Serialization.dir/depend:
	cd "/Users/dean/Desktop/C++Project/Basic Code/Serial/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/dean/Desktop/C++Project/Basic Code/Serial" "/Users/dean/Desktop/C++Project/Basic Code/Serial" "/Users/dean/Desktop/C++Project/Basic Code/Serial/build" "/Users/dean/Desktop/C++Project/Basic Code/Serial/build" "/Users/dean/Desktop/C++Project/Basic Code/Serial/build/CMakeFiles/Serialization.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Serialization.dir/depend

