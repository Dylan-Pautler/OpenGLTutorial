# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dylan/CLionProjects/OpenGLTutorialProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGLTutorialProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGLTutorialProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGLTutorialProject.dir/flags.make

CMakeFiles/OpenGLTutorialProject.dir/main.cpp.o: CMakeFiles/OpenGLTutorialProject.dir/flags.make
CMakeFiles/OpenGLTutorialProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGLTutorialProject.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLTutorialProject.dir/main.cpp.o -c /home/dylan/CLionProjects/OpenGLTutorialProject/main.cpp

CMakeFiles/OpenGLTutorialProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLTutorialProject.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dylan/CLionProjects/OpenGLTutorialProject/main.cpp > CMakeFiles/OpenGLTutorialProject.dir/main.cpp.i

CMakeFiles/OpenGLTutorialProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLTutorialProject.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dylan/CLionProjects/OpenGLTutorialProject/main.cpp -o CMakeFiles/OpenGLTutorialProject.dir/main.cpp.s

CMakeFiles/OpenGLTutorialProject.dir/display.cpp.o: CMakeFiles/OpenGLTutorialProject.dir/flags.make
CMakeFiles/OpenGLTutorialProject.dir/display.cpp.o: ../display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGLTutorialProject.dir/display.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLTutorialProject.dir/display.cpp.o -c /home/dylan/CLionProjects/OpenGLTutorialProject/display.cpp

CMakeFiles/OpenGLTutorialProject.dir/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLTutorialProject.dir/display.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dylan/CLionProjects/OpenGLTutorialProject/display.cpp > CMakeFiles/OpenGLTutorialProject.dir/display.cpp.i

CMakeFiles/OpenGLTutorialProject.dir/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLTutorialProject.dir/display.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dylan/CLionProjects/OpenGLTutorialProject/display.cpp -o CMakeFiles/OpenGLTutorialProject.dir/display.cpp.s

CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.o: CMakeFiles/OpenGLTutorialProject.dir/flags.make
CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.o: ../shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.o -c /home/dylan/CLionProjects/OpenGLTutorialProject/shader.cpp

CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dylan/CLionProjects/OpenGLTutorialProject/shader.cpp > CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.i

CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dylan/CLionProjects/OpenGLTutorialProject/shader.cpp -o CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.s

CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.o: CMakeFiles/OpenGLTutorialProject.dir/flags.make
CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.o: ../mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.o -c /home/dylan/CLionProjects/OpenGLTutorialProject/mesh.cpp

CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dylan/CLionProjects/OpenGLTutorialProject/mesh.cpp > CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.i

CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dylan/CLionProjects/OpenGLTutorialProject/mesh.cpp -o CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.s

# Object files for target OpenGLTutorialProject
OpenGLTutorialProject_OBJECTS = \
"CMakeFiles/OpenGLTutorialProject.dir/main.cpp.o" \
"CMakeFiles/OpenGLTutorialProject.dir/display.cpp.o" \
"CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.o" \
"CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.o"

# External object files for target OpenGLTutorialProject
OpenGLTutorialProject_EXTERNAL_OBJECTS =

OpenGLTutorialProject: CMakeFiles/OpenGLTutorialProject.dir/main.cpp.o
OpenGLTutorialProject: CMakeFiles/OpenGLTutorialProject.dir/display.cpp.o
OpenGLTutorialProject: CMakeFiles/OpenGLTutorialProject.dir/shader.cpp.o
OpenGLTutorialProject: CMakeFiles/OpenGLTutorialProject.dir/mesh.cpp.o
OpenGLTutorialProject: CMakeFiles/OpenGLTutorialProject.dir/build.make
OpenGLTutorialProject: /usr/lib/x86_64-linux-gnu/libOpenGL.so
OpenGLTutorialProject: /usr/lib/x86_64-linux-gnu/libGLX.so
OpenGLTutorialProject: /usr/lib/x86_64-linux-gnu/libGLU.so
OpenGLTutorialProject: /usr/lib/x86_64-linux-gnu/libGLEW.so
OpenGLTutorialProject: CMakeFiles/OpenGLTutorialProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable OpenGLTutorialProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGLTutorialProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGLTutorialProject.dir/build: OpenGLTutorialProject

.PHONY : CMakeFiles/OpenGLTutorialProject.dir/build

CMakeFiles/OpenGLTutorialProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGLTutorialProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGLTutorialProject.dir/clean

CMakeFiles/OpenGLTutorialProject.dir/depend:
	cd /home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dylan/CLionProjects/OpenGLTutorialProject /home/dylan/CLionProjects/OpenGLTutorialProject /home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug /home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug /home/dylan/CLionProjects/OpenGLTutorialProject/cmake-build-debug/CMakeFiles/OpenGLTutorialProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGLTutorialProject.dir/depend

