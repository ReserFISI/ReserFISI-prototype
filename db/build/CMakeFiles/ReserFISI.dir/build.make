# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/sebastianrojas/Escritorio/ReserFISI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sebastianrojas/Escritorio/ReserFISI/build

# Include any dependencies generated for this target.
include CMakeFiles/ReserFISI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ReserFISI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ReserFISI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReserFISI.dir/flags.make

CMakeFiles/ReserFISI.dir/index.cpp.o: CMakeFiles/ReserFISI.dir/flags.make
CMakeFiles/ReserFISI.dir/index.cpp.o: /home/sebastianrojas/Escritorio/ReserFISI/index.cpp
CMakeFiles/ReserFISI.dir/index.cpp.o: CMakeFiles/ReserFISI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastianrojas/Escritorio/ReserFISI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReserFISI.dir/index.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ReserFISI.dir/index.cpp.o -MF CMakeFiles/ReserFISI.dir/index.cpp.o.d -o CMakeFiles/ReserFISI.dir/index.cpp.o -c /home/sebastianrojas/Escritorio/ReserFISI/index.cpp

CMakeFiles/ReserFISI.dir/index.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ReserFISI.dir/index.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastianrojas/Escritorio/ReserFISI/index.cpp > CMakeFiles/ReserFISI.dir/index.cpp.i

CMakeFiles/ReserFISI.dir/index.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ReserFISI.dir/index.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastianrojas/Escritorio/ReserFISI/index.cpp -o CMakeFiles/ReserFISI.dir/index.cpp.s

CMakeFiles/ReserFISI.dir/db.cpp.o: CMakeFiles/ReserFISI.dir/flags.make
CMakeFiles/ReserFISI.dir/db.cpp.o: /home/sebastianrojas/Escritorio/ReserFISI/db.cpp
CMakeFiles/ReserFISI.dir/db.cpp.o: CMakeFiles/ReserFISI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastianrojas/Escritorio/ReserFISI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ReserFISI.dir/db.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ReserFISI.dir/db.cpp.o -MF CMakeFiles/ReserFISI.dir/db.cpp.o.d -o CMakeFiles/ReserFISI.dir/db.cpp.o -c /home/sebastianrojas/Escritorio/ReserFISI/db.cpp

CMakeFiles/ReserFISI.dir/db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ReserFISI.dir/db.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastianrojas/Escritorio/ReserFISI/db.cpp > CMakeFiles/ReserFISI.dir/db.cpp.i

CMakeFiles/ReserFISI.dir/db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ReserFISI.dir/db.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastianrojas/Escritorio/ReserFISI/db.cpp -o CMakeFiles/ReserFISI.dir/db.cpp.s

# Object files for target ReserFISI
ReserFISI_OBJECTS = \
"CMakeFiles/ReserFISI.dir/index.cpp.o" \
"CMakeFiles/ReserFISI.dir/db.cpp.o"

# External object files for target ReserFISI
ReserFISI_EXTERNAL_OBJECTS =

ReserFISI: CMakeFiles/ReserFISI.dir/index.cpp.o
ReserFISI: CMakeFiles/ReserFISI.dir/db.cpp.o
ReserFISI: CMakeFiles/ReserFISI.dir/build.make
ReserFISI: CMakeFiles/ReserFISI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sebastianrojas/Escritorio/ReserFISI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ReserFISI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReserFISI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReserFISI.dir/build: ReserFISI
.PHONY : CMakeFiles/ReserFISI.dir/build

CMakeFiles/ReserFISI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReserFISI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReserFISI.dir/clean

CMakeFiles/ReserFISI.dir/depend:
	cd /home/sebastianrojas/Escritorio/ReserFISI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sebastianrojas/Escritorio/ReserFISI /home/sebastianrojas/Escritorio/ReserFISI /home/sebastianrojas/Escritorio/ReserFISI/build /home/sebastianrojas/Escritorio/ReserFISI/build /home/sebastianrojas/Escritorio/ReserFISI/build/CMakeFiles/ReserFISI.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ReserFISI.dir/depend
