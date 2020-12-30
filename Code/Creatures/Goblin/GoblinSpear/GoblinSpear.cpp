//
// Created by Vlad on 30.12.2020.
//

#include "GoblinSpear.h"

void GoblinSpear::mystical_disappearance() {
    if (location == coord(5,5)){
        is_alive = false;
    }
}

void GoblinSpear::reload(){
    check_the_trap();
    mystical_disappearance();
}

std::string GoblinSpear::get_view() {
    switch (condition) {
        case alive:
            return "G";
        case dead:
            return "✖";
        case undead:
            return "g";
    }
}