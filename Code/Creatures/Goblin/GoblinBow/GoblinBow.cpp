//
// Created by Vlad on 30.12.2020.
//

#include "GoblinBow.h"

void GoblinBow::change_the_range() {
    if ((location.X<5)&&(location.Y<5)){
        radius_of_hitting = 2;
    }
}

GoblinBow::GoblinBow() {

}
