//
// Created by Vlad on 30.12.2020.
//

#include "GoblinBowShort.h"

void GoblinBowShort::accumulates_strength() {
    radius_of_hitting--;
}

void GoblinBowShort::reload() {
    accumulates_strength();
    change_the_range();
    check_the_trap();
}

std::string GoblinBowShort::get_view() {
    switch (condition) {
        case alive:
            return "→";
        case dead:
            return "✖";
        case undead:
            return "↔";
    }
}