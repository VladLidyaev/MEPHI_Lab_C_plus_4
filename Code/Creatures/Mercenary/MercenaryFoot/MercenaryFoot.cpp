//
// Created by Vlad on 30.12.2020.
//

#include "MercenaryFoot.h"

void MercenaryFoot::change_length(){
    if ((location.X%3 == 0)&&(location.Y%3 == 0)){
        stride_length = 2;
    } else {
        stride_length = 1;
    }
}

void MercenaryFoot::reload() {
    upgrade_lvl();
    change_length();
}

std::string MercenaryFoot::get_view() {
    switch (condition) {
        case alive:
            return "M";
        case dead:
            return "✖";
        case undead:
            return "m";
    }
}