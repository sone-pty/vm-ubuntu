# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sone/vm-ubuntu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sone/vm-ubuntu/build

# Include any dependencies generated for this target.
include CMakeFiles/sone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sone.dir/flags.make

CMakeFiles/sone.dir/main.cpp.o: CMakeFiles/sone.dir/flags.make
CMakeFiles/sone.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sone/vm-ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sone.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sone.dir/main.cpp.o -c /home/sone/vm-ubuntu/main.cpp

CMakeFiles/sone.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sone.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sone/vm-ubuntu/main.cpp > CMakeFiles/sone.dir/main.cpp.i

CMakeFiles/sone.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sone.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sone/vm-ubuntu/main.cpp -o CMakeFiles/sone.dir/main.cpp.s

CMakeFiles/sone.dir/extern/http_parser/http_parser.c.o: CMakeFiles/sone.dir/flags.make
CMakeFiles/sone.dir/extern/http_parser/http_parser.c.o: ../extern/http_parser/http_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sone/vm-ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sone.dir/extern/http_parser/http_parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sone.dir/extern/http_parser/http_parser.c.o   -c /home/sone/vm-ubuntu/extern/http_parser/http_parser.c

CMakeFiles/sone.dir/extern/http_parser/http_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sone.dir/extern/http_parser/http_parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sone/vm-ubuntu/extern/http_parser/http_parser.c > CMakeFiles/sone.dir/extern/http_parser/http_parser.c.i

CMakeFiles/sone.dir/extern/http_parser/http_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sone.dir/extern/http_parser/http_parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sone/vm-ubuntu/extern/http_parser/http_parser.c -o CMakeFiles/sone.dir/extern/http_parser/http_parser.c.s

CMakeFiles/sone.dir/extern/json11/json11.cpp.o: CMakeFiles/sone.dir/flags.make
CMakeFiles/sone.dir/extern/json11/json11.cpp.o: ../extern/json11/json11.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sone/vm-ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sone.dir/extern/json11/json11.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sone.dir/extern/json11/json11.cpp.o -c /home/sone/vm-ubuntu/extern/json11/json11.cpp

CMakeFiles/sone.dir/extern/json11/json11.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sone.dir/extern/json11/json11.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sone/vm-ubuntu/extern/json11/json11.cpp > CMakeFiles/sone.dir/extern/json11/json11.cpp.i

CMakeFiles/sone.dir/extern/json11/json11.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sone.dir/extern/json11/json11.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sone/vm-ubuntu/extern/json11/json11.cpp -o CMakeFiles/sone.dir/extern/json11/json11.cpp.s

# Object files for target sone
sone_OBJECTS = \
"CMakeFiles/sone.dir/main.cpp.o" \
"CMakeFiles/sone.dir/extern/http_parser/http_parser.c.o" \
"CMakeFiles/sone.dir/extern/json11/json11.cpp.o"

# External object files for target sone
sone_EXTERNAL_OBJECTS =

../bin/sone: CMakeFiles/sone.dir/main.cpp.o
../bin/sone: CMakeFiles/sone.dir/extern/http_parser/http_parser.c.o
../bin/sone: CMakeFiles/sone.dir/extern/json11/json11.cpp.o
../bin/sone: CMakeFiles/sone.dir/build.make
../bin/sone: ../lib/libutils.so
../bin/sone: CMakeFiles/sone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sone/vm-ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/sone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sone.dir/build: ../bin/sone

.PHONY : CMakeFiles/sone.dir/build

CMakeFiles/sone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sone.dir/clean

CMakeFiles/sone.dir/depend:
	cd /home/sone/vm-ubuntu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sone/vm-ubuntu /home/sone/vm-ubuntu /home/sone/vm-ubuntu/build /home/sone/vm-ubuntu/build /home/sone/vm-ubuntu/build/CMakeFiles/sone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sone.dir/depend

