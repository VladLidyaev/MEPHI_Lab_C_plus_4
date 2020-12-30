//
// Created by Vlad on 22.12.2020.
//

#include "OgreClass.h"

int OgreClass::get_damage(){
    if ((location.X + location.Y)%2 == 0){
        damage = max_points/4;
    } else {
        damage = max_points/8;
    }
}

int OgreClass::get_stride_length(){
    if (health<max_points/8) {
        stride_length = 2;
    } else if (health<max_points/4) {
        stride_length = 1;
    }
}

void OgreClass::reload(){
    get_stride_length();
    get_damage();
}

int OgreClass::get_max_points(level level){
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