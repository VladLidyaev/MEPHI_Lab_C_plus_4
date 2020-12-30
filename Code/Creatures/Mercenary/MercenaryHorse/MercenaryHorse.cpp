//
// Created by Vlad on 30.12.2020.
//

#include "MercenaryHorse.hpp"

void MercenaryHorse::change_hitting(){
    if ((location.X%3 == 0)&&(location.Y%3 == 0)){
        radius_of_hitting = 4;
    } else {
        radius_of_hitting = 2;
    }
}

void MercenaryHorse::reload() {
    upgrade_lvl();
    change_hitting();
}

std::string MercenaryHorse::get_view() {
    switch (condition) {
        case alive:
            return "Λ";
        case dead:
            return "✖";
        case undead:
            return "λ";
    }
}