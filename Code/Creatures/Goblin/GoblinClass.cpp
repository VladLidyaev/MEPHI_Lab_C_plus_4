//
// Created by Vlad on 22.12.2020.
//

#include "GoblinClass.h"

void GoblinClass::check_the_trap() {
    if (((location == coord(2,3))||(location == coord(1,7))||(location == coord(5,2))||(location == coord(4,4)))&&(condition==alive)){
        condition == dead;
    }
}

int GoblinClass::get_max_points(level level){
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

GoblinClass::GoblinClass() {

}
