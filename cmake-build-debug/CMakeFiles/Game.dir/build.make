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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vlad/CLionProjects/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vlad/CLionProjects/Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game.dir/flags.make

CMakeFiles/Game.dir/Code/main.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/main.cpp.o: ../Code/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game.dir/Code/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/main.cpp.o -c /Users/vlad/CLionProjects/Game/Code/main.cpp

CMakeFiles/Game.dir/Code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/main.cpp > CMakeFiles/Game.dir/Code/main.cpp.i

CMakeFiles/Game.dir/Code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/main.cpp -o CMakeFiles/Game.dir/Code/main.cpp.s

CMakeFiles/Game.dir/Code/tools/tools.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/tools/tools.cpp.o: ../Code/tools/tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game.dir/Code/tools/tools.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/tools/tools.cpp.o -c /Users/vlad/CLionProjects/Game/Code/tools/tools.cpp

CMakeFiles/Game.dir/Code/tools/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/tools/tools.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/tools/tools.cpp > CMakeFiles/Game.dir/Code/tools/tools.cpp.i

CMakeFiles/Game.dir/Code/tools/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/tools/tools.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/tools/tools.cpp -o CMakeFiles/Game.dir/Code/tools/tools.cpp.s

CMakeFiles/Game.dir/Code/Hero/Hero.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/Hero/Hero.cpp.o: ../Code/Hero/Hero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Game.dir/Code/Hero/Hero.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/Hero/Hero.cpp.o -c /Users/vlad/CLionProjects/Game/Code/Hero/Hero.cpp

CMakeFiles/Game.dir/Code/Hero/Hero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/Hero/Hero.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/Hero/Hero.cpp > CMakeFiles/Game.dir/Code/Hero/Hero.cpp.i

CMakeFiles/Game.dir/Code/Hero/Hero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/Hero/Hero.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/Hero/Hero.cpp -o CMakeFiles/Game.dir/Code/Hero/Hero.cpp.s

CMakeFiles/Game.dir/Code/Game.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/Game.cpp.o: ../Code/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Game.dir/Code/Game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/Game.cpp.o -c /Users/vlad/CLionProjects/Game/Code/Game.cpp

CMakeFiles/Game.dir/Code/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/Game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/Game.cpp > CMakeFiles/Game.dir/Code/Game.cpp.i

CMakeFiles/Game.dir/Code/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/Game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/Game.cpp -o CMakeFiles/Game.dir/Code/Game.cpp.s

CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.o: ../Code/Creatures/Creature.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.o -c /Users/vlad/CLionProjects/Game/Code/Creatures/Creature.cpp

CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/Creatures/Creature.cpp > CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.i

CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/Creatures/Creature.cpp -o CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.s

CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.o: ../Code/Creatures/Ogre/OgreClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.o -c /Users/vlad/CLionProjects/Game/Code/Creatures/Ogre/OgreClass.cpp

CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/Creatures/Ogre/OgreClass.cpp > CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.i

CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/Creatures/Ogre/OgreClass.cpp -o CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.s

CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.o: ../Code/Creatures/Goblin/GoblinClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.o -c /Users/vlad/CLionProjects/Game/Code/Creatures/Goblin/GoblinClass.cpp

CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/Creatures/Goblin/GoblinClass.cpp > CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.i

CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/Creatures/Goblin/GoblinClass.cpp -o CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.s

CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.o: ../Code/Creatures/Mercenary/MercenaryClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.o -c /Users/vlad/CLionProjects/Game/Code/Creatures/Mercenary/MercenaryClass.cpp

CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vlad/CLionProjects/Game/Code/Creatures/Mercenary/MercenaryClass.cpp > CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.i

CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vlad/CLionProjects/Game/Code/Creatures/Mercenary/MercenaryClass.cpp -o CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.s

# Object files for target Game
Game_OBJECTS = \
"CMakeFiles/Game.dir/Code/main.cpp.o" \
"CMakeFiles/Game.dir/Code/tools/tools.cpp.o" \
"CMakeFiles/Game.dir/Code/Hero/Hero.cpp.o" \
"CMakeFiles/Game.dir/Code/Game.cpp.o" \
"CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.o" \
"CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.o" \
"CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.o" \
"CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.o"

# External object files for target Game
Game_EXTERNAL_OBJECTS =

Game: CMakeFiles/Game.dir/Code/main.cpp.o
Game: CMakeFiles/Game.dir/Code/tools/tools.cpp.o
Game: CMakeFiles/Game.dir/Code/Hero/Hero.cpp.o
Game: CMakeFiles/Game.dir/Code/Game.cpp.o
Game: CMakeFiles/Game.dir/Code/Creatures/Creature.cpp.o
Game: CMakeFiles/Game.dir/Code/Creatures/Ogre/OgreClass.cpp.o
Game: CMakeFiles/Game.dir/Code/Creatures/Goblin/GoblinClass.cpp.o
Game: CMakeFiles/Game.dir/Code/Creatures/Mercenary/MercenaryClass.cpp.o
Game: CMakeFiles/Game.dir/build.make
Game: lib/libgtestd.a
Game: lib/libgtest_maind.a
Game: lib/libgtestd.a
Game: CMakeFiles/Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game.dir/build: Game

.PHONY : CMakeFiles/Game.dir/build

CMakeFiles/Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game.dir/clean

CMakeFiles/Game.dir/depend:
	cd /Users/vlad/CLionProjects/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vlad/CLionProjects/Game /Users/vlad/CLionProjects/Game /Users/vlad/CLionProjects/Game/cmake-build-debug /Users/vlad/CLionProjects/Game/cmake-build-debug /Users/vlad/CLionProjects/Game/cmake-build-debug/CMakeFiles/Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game.dir/depend

