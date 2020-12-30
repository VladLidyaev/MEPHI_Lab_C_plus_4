cmake_minimum_required(VERSION 3.17)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game Code/Tests/HeroClassTest.cpp Code/main.cpp Code/tools/tools.cpp Code/Hero/Hero.cpp Code/Game.cpp Code/Creatures/Creature.cpp Code/cratures_templates.hpp Code/Creatures/Ogre/OgreClass.cpp Code/Creatures/Goblin/GoblinClass.cpp Code/Creatures/Mercenary/MercenaryClass.cpp Code/Creatures/Mercenary/MercenaryFoot/MercenaryFoot.cpp Code/Creatures/Mercenary/MercenaryHorse/MercenaryHorse.cpp Code/Creatures/Goblin/GoblinClass.cpp Code/Creatures/Goblin/GoblinBow/GoblinBow.cpp Code/Creatures/Goblin/GoblinSpear/GoblinSpear.cpp Code/Creatures/Goblin/GoblinBow/GoblinBowTall/GoblinBowTail.cpp Code/Creatures/Goblin/GoblinBow/GoblinBowShort/GoblinBowShort.cpp)

add_subdirectory(Code/lib/googletest-master)
include_directories(Code/lib/googletest-master/googletest/include)
include_directories(Code/lib/googletest-master/googlemock/include)

target_link_libraries(Game gtest gtest_main)