//
// Created by Vlad on 22.12.2020.
//

#include "OgreClass.h"

int OgreClass::get_ogre_max_points(level level){
    switch (level) {
        case stupid:
            return 40;
        case beginner:
            return 60;
        case middle:
            return 80;
        case pro:
            return 100;
    }
}

std::string OgreClass::get_view() {
    switch (condition) {
        case alive:
            return "O";
        case dead:
            return "✖";
        case undead:
            return "o";
    }
}