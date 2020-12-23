//
// Created by Vlad on 22.12.2020.
//

#include "GoblinClass.h"

int GoblinClass::get_goblin_max_points(level level){
    switch (level) {
        case stupid:
            return 20;
        case beginner:
            return 30;
        case middle:
            return 40;
        case pro:
            return 50;
    }
}

std::string GoblinClass::get_view() {
    switch (condition) {
        case alive:
            return "G";
        case dead:
            return "✖";
        case undead:
            return "g";
    }
}