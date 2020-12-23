//
// Created by Vlad on 22.12.2020.
//

#include "MercenaryClass.h"

int MercenaryClass::get_mercenary_max_points(level level){
    switch (level) {
        case stupid:
            return 50;
        case beginner:
            return 60;
        case middle:
            return 70;
        case pro:
            return 80;
    }
}

std::string MercenaryClass::get_view() {
    switch (condition) {
        case alive:
            return "M";
        case dead:
            return "✖";
        case undead:
            return "m";
    }
}