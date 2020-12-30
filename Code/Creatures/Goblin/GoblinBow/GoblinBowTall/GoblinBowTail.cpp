//
// Created by Vlad on 30.12.2020.
//

#include "GoblinBowTail.hpp"

void GoblinBowTail::increased_impact() {
    radius_of_hitting++;
}

void GoblinBowTail::reload() {
    increased_impact();
    change_the_range();
    check_the_trap();
}

std::string GoblinBowTail::get_view() {
    switch (condition) {
        case alive:
            return "↑";
        case dead:
            return "✖";
        case undead:
            return "↕";
    }
}