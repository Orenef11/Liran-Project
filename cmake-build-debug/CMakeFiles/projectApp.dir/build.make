# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion-2017.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/Desktop/LiranProject-Oren

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projectApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projectApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projectApp.dir/flags.make

CMakeFiles/projectApp.dir/main.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projectApp.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/main.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/main.c

CMakeFiles/projectApp.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/main.c > CMakeFiles/projectApp.dir/main.c.i

CMakeFiles/projectApp.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/main.c -o CMakeFiles/projectApp.dir/main.c.s

CMakeFiles/projectApp.dir/main.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/main.c.o.requires

CMakeFiles/projectApp.dir/main.c.o.provides: CMakeFiles/projectApp.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/main.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/main.c.o.provides

CMakeFiles/projectApp.dir/main.c.o.provides.build: CMakeFiles/projectApp.dir/main.c.o


CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o: ../C/Code/argumentsParser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/argumentsParser.c

CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/argumentsParser.c > CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.i

CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/argumentsParser.c -o CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.s

CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.requires

CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.provides: CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.provides

CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o


CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o: ../C/Code/consumner_and_producer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/consumner_and_producer.c

CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/consumner_and_producer.c > CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.i

CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/consumner_and_producer.c -o CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.s

CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.requires

CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.provides: CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.provides

CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o


CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o: ../C/Code/create_pipe.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/create_pipe.c

CMakeFiles/projectApp.dir/C/Code/create_pipe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/create_pipe.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/create_pipe.c > CMakeFiles/projectApp.dir/C/Code/create_pipe.c.i

CMakeFiles/projectApp.dir/C/Code/create_pipe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/create_pipe.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/create_pipe.c -o CMakeFiles/projectApp.dir/C/Code/create_pipe.c.s

CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.requires

CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.provides: CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.provides

CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o


CMakeFiles/projectApp.dir/C/Code/my_signal.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/my_signal.c.o: ../C/Code/my_signal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/projectApp.dir/C/Code/my_signal.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/my_signal.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/my_signal.c

CMakeFiles/projectApp.dir/C/Code/my_signal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/my_signal.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/my_signal.c > CMakeFiles/projectApp.dir/C/Code/my_signal.c.i

CMakeFiles/projectApp.dir/C/Code/my_signal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/my_signal.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/my_signal.c -o CMakeFiles/projectApp.dir/C/Code/my_signal.c.s

CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.requires

CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.provides: CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.provides

CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/my_signal.c.o


CMakeFiles/projectApp.dir/C/Code/path.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/path.c.o: ../C/Code/path.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/projectApp.dir/C/Code/path.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/path.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/path.c

CMakeFiles/projectApp.dir/C/Code/path.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/path.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/path.c > CMakeFiles/projectApp.dir/C/Code/path.c.i

CMakeFiles/projectApp.dir/C/Code/path.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/path.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/path.c -o CMakeFiles/projectApp.dir/C/Code/path.c.s

CMakeFiles/projectApp.dir/C/Code/path.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/path.c.o.requires

CMakeFiles/projectApp.dir/C/Code/path.c.o.provides: CMakeFiles/projectApp.dir/C/Code/path.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/path.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/path.c.o.provides

CMakeFiles/projectApp.dir/C/Code/path.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/path.c.o


CMakeFiles/projectApp.dir/C/Code/question.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/question.c.o: ../C/Code/question.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/projectApp.dir/C/Code/question.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/question.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/question.c

CMakeFiles/projectApp.dir/C/Code/question.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/question.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/question.c > CMakeFiles/projectApp.dir/C/Code/question.c.i

CMakeFiles/projectApp.dir/C/Code/question.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/question.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/question.c -o CMakeFiles/projectApp.dir/C/Code/question.c.s

CMakeFiles/projectApp.dir/C/Code/question.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/question.c.o.requires

CMakeFiles/projectApp.dir/C/Code/question.c.o.provides: CMakeFiles/projectApp.dir/C/Code/question.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/question.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/question.c.o.provides

CMakeFiles/projectApp.dir/C/Code/question.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/question.c.o


CMakeFiles/projectApp.dir/C/Code/server.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/server.c.o: ../C/Code/server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/projectApp.dir/C/Code/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/server.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/server.c

CMakeFiles/projectApp.dir/C/Code/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/server.c > CMakeFiles/projectApp.dir/C/Code/server.c.i

CMakeFiles/projectApp.dir/C/Code/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/server.c -o CMakeFiles/projectApp.dir/C/Code/server.c.s

CMakeFiles/projectApp.dir/C/Code/server.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/server.c.o.requires

CMakeFiles/projectApp.dir/C/Code/server.c.o.provides: CMakeFiles/projectApp.dir/C/Code/server.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/server.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/server.c.o.provides

CMakeFiles/projectApp.dir/C/Code/server.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/server.c.o


CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o: CMakeFiles/projectApp.dir/flags.make
CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o: ../C/Code/shared_memory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o   -c /home/ubuntu/Desktop/LiranProject-Oren/C/Code/shared_memory.c

CMakeFiles/projectApp.dir/C/Code/shared_memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projectApp.dir/C/Code/shared_memory.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/LiranProject-Oren/C/Code/shared_memory.c > CMakeFiles/projectApp.dir/C/Code/shared_memory.c.i

CMakeFiles/projectApp.dir/C/Code/shared_memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projectApp.dir/C/Code/shared_memory.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/LiranProject-Oren/C/Code/shared_memory.c -o CMakeFiles/projectApp.dir/C/Code/shared_memory.c.s

CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.requires:

.PHONY : CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.requires

CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.provides: CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.requires
	$(MAKE) -f CMakeFiles/projectApp.dir/build.make CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.provides.build
.PHONY : CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.provides

CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.provides.build: CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o


# Object files for target projectApp
projectApp_OBJECTS = \
"CMakeFiles/projectApp.dir/main.c.o" \
"CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o" \
"CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o" \
"CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o" \
"CMakeFiles/projectApp.dir/C/Code/my_signal.c.o" \
"CMakeFiles/projectApp.dir/C/Code/path.c.o" \
"CMakeFiles/projectApp.dir/C/Code/question.c.o" \
"CMakeFiles/projectApp.dir/C/Code/server.c.o" \
"CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o"

# External object files for target projectApp
projectApp_EXTERNAL_OBJECTS =

projectApp: CMakeFiles/projectApp.dir/main.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/my_signal.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/path.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/question.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/server.c.o
projectApp: CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o
projectApp: CMakeFiles/projectApp.dir/build.make
projectApp: CMakeFiles/projectApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable projectApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projectApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projectApp.dir/build: projectApp

.PHONY : CMakeFiles/projectApp.dir/build

CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/main.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/argumentsParser.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/consumner_and_producer.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/create_pipe.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/my_signal.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/path.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/question.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/server.c.o.requires
CMakeFiles/projectApp.dir/requires: CMakeFiles/projectApp.dir/C/Code/shared_memory.c.o.requires

.PHONY : CMakeFiles/projectApp.dir/requires

CMakeFiles/projectApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projectApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projectApp.dir/clean

CMakeFiles/projectApp.dir/depend:
	cd /home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/Desktop/LiranProject-Oren /home/ubuntu/Desktop/LiranProject-Oren /home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug /home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug /home/ubuntu/Desktop/LiranProject-Oren/cmake-build-debug/CMakeFiles/projectApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projectApp.dir/depend

