# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/d/Development/back_to_the_future

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Development/back_to_the_future

# Include any dependencies generated for this target.
include minizip/CMakeFiles/minizip.dir/depend.make

# Include the progress variables for this target.
include minizip/CMakeFiles/minizip.dir/progress.make

# Include the compile flags for this target's objects.
include minizip/CMakeFiles/minizip.dir/flags.make

minizip/CMakeFiles/minizip.dir/ioapi.c.o: minizip/CMakeFiles/minizip.dir/flags.make
minizip/CMakeFiles/minizip.dir/ioapi.c.o: minizip/ioapi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Development/back_to_the_future/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object minizip/CMakeFiles/minizip.dir/ioapi.c.o"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/ioapi.c.o   -c /mnt/d/Development/back_to_the_future/minizip/ioapi.c

minizip/CMakeFiles/minizip.dir/ioapi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/ioapi.c.i"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Development/back_to_the_future/minizip/ioapi.c > CMakeFiles/minizip.dir/ioapi.c.i

minizip/CMakeFiles/minizip.dir/ioapi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/ioapi.c.s"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Development/back_to_the_future/minizip/ioapi.c -o CMakeFiles/minizip.dir/ioapi.c.s

minizip/CMakeFiles/minizip.dir/ioapi.c.o.requires:

.PHONY : minizip/CMakeFiles/minizip.dir/ioapi.c.o.requires

minizip/CMakeFiles/minizip.dir/ioapi.c.o.provides: minizip/CMakeFiles/minizip.dir/ioapi.c.o.requires
	$(MAKE) -f minizip/CMakeFiles/minizip.dir/build.make minizip/CMakeFiles/minizip.dir/ioapi.c.o.provides.build
.PHONY : minizip/CMakeFiles/minizip.dir/ioapi.c.o.provides

minizip/CMakeFiles/minizip.dir/ioapi.c.o.provides.build: minizip/CMakeFiles/minizip.dir/ioapi.c.o


minizip/CMakeFiles/minizip.dir/unzip.c.o: minizip/CMakeFiles/minizip.dir/flags.make
minizip/CMakeFiles/minizip.dir/unzip.c.o: minizip/unzip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Development/back_to_the_future/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object minizip/CMakeFiles/minizip.dir/unzip.c.o"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/unzip.c.o   -c /mnt/d/Development/back_to_the_future/minizip/unzip.c

minizip/CMakeFiles/minizip.dir/unzip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/unzip.c.i"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Development/back_to_the_future/minizip/unzip.c > CMakeFiles/minizip.dir/unzip.c.i

minizip/CMakeFiles/minizip.dir/unzip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/unzip.c.s"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Development/back_to_the_future/minizip/unzip.c -o CMakeFiles/minizip.dir/unzip.c.s

minizip/CMakeFiles/minizip.dir/unzip.c.o.requires:

.PHONY : minizip/CMakeFiles/minizip.dir/unzip.c.o.requires

minizip/CMakeFiles/minizip.dir/unzip.c.o.provides: minizip/CMakeFiles/minizip.dir/unzip.c.o.requires
	$(MAKE) -f minizip/CMakeFiles/minizip.dir/build.make minizip/CMakeFiles/minizip.dir/unzip.c.o.provides.build
.PHONY : minizip/CMakeFiles/minizip.dir/unzip.c.o.provides

minizip/CMakeFiles/minizip.dir/unzip.c.o.provides.build: minizip/CMakeFiles/minizip.dir/unzip.c.o


minizip/CMakeFiles/minizip.dir/zip.c.o: minizip/CMakeFiles/minizip.dir/flags.make
minizip/CMakeFiles/minizip.dir/zip.c.o: minizip/zip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Development/back_to_the_future/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object minizip/CMakeFiles/minizip.dir/zip.c.o"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minizip.dir/zip.c.o   -c /mnt/d/Development/back_to_the_future/minizip/zip.c

minizip/CMakeFiles/minizip.dir/zip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minizip.dir/zip.c.i"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Development/back_to_the_future/minizip/zip.c > CMakeFiles/minizip.dir/zip.c.i

minizip/CMakeFiles/minizip.dir/zip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minizip.dir/zip.c.s"
	cd /mnt/d/Development/back_to_the_future/minizip && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Development/back_to_the_future/minizip/zip.c -o CMakeFiles/minizip.dir/zip.c.s

minizip/CMakeFiles/minizip.dir/zip.c.o.requires:

.PHONY : minizip/CMakeFiles/minizip.dir/zip.c.o.requires

minizip/CMakeFiles/minizip.dir/zip.c.o.provides: minizip/CMakeFiles/minizip.dir/zip.c.o.requires
	$(MAKE) -f minizip/CMakeFiles/minizip.dir/build.make minizip/CMakeFiles/minizip.dir/zip.c.o.provides.build
.PHONY : minizip/CMakeFiles/minizip.dir/zip.c.o.provides

minizip/CMakeFiles/minizip.dir/zip.c.o.provides.build: minizip/CMakeFiles/minizip.dir/zip.c.o


# Object files for target minizip
minizip_OBJECTS = \
"CMakeFiles/minizip.dir/ioapi.c.o" \
"CMakeFiles/minizip.dir/unzip.c.o" \
"CMakeFiles/minizip.dir/zip.c.o"

# External object files for target minizip
minizip_EXTERNAL_OBJECTS =

minizip/libminizip.a: minizip/CMakeFiles/minizip.dir/ioapi.c.o
minizip/libminizip.a: minizip/CMakeFiles/minizip.dir/unzip.c.o
minizip/libminizip.a: minizip/CMakeFiles/minizip.dir/zip.c.o
minizip/libminizip.a: minizip/CMakeFiles/minizip.dir/build.make
minizip/libminizip.a: minizip/CMakeFiles/minizip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Development/back_to_the_future/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libminizip.a"
	cd /mnt/d/Development/back_to_the_future/minizip && $(CMAKE_COMMAND) -P CMakeFiles/minizip.dir/cmake_clean_target.cmake
	cd /mnt/d/Development/back_to_the_future/minizip && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minizip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
minizip/CMakeFiles/minizip.dir/build: minizip/libminizip.a

.PHONY : minizip/CMakeFiles/minizip.dir/build

minizip/CMakeFiles/minizip.dir/requires: minizip/CMakeFiles/minizip.dir/ioapi.c.o.requires
minizip/CMakeFiles/minizip.dir/requires: minizip/CMakeFiles/minizip.dir/unzip.c.o.requires
minizip/CMakeFiles/minizip.dir/requires: minizip/CMakeFiles/minizip.dir/zip.c.o.requires

.PHONY : minizip/CMakeFiles/minizip.dir/requires

minizip/CMakeFiles/minizip.dir/clean:
	cd /mnt/d/Development/back_to_the_future/minizip && $(CMAKE_COMMAND) -P CMakeFiles/minizip.dir/cmake_clean.cmake
.PHONY : minizip/CMakeFiles/minizip.dir/clean

minizip/CMakeFiles/minizip.dir/depend:
	cd /mnt/d/Development/back_to_the_future && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Development/back_to_the_future /mnt/d/Development/back_to_the_future/minizip /mnt/d/Development/back_to_the_future /mnt/d/Development/back_to_the_future/minizip /mnt/d/Development/back_to_the_future/minizip/CMakeFiles/minizip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : minizip/CMakeFiles/minizip.dir/depend
