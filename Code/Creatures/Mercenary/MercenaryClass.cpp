//
// Created by Vlad on 22.12.2020.
//

#include "MercenaryClass.h"

void MercenaryClass::upgrade_lvl(){
    if ((location.X <= 5) || (location.Y <= 5)) {
        lvl = pro;
        max_points = get_max_points(lvl);
        health = max_points/2;
        damage = max_points/2;
    }
}



int MercenaryClass::get_max_points(level level){
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

MercenaryClass::MercenaryClass() {

}
