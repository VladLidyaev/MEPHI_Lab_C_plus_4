//
// Created by Vlad on 22.12.2020.
//

#ifndef GAME_GOBLINCLASS_H
#define GAME_GOBLINCLASS_H

#include "../Creature.h"

class GoblinClass : public Creature {

public:

    void check_the_trap();

    GoblinClass();

    int get_max_points(level level); /// Функция возвращает максимальное количество очков, за убийство данного персонажа.
};


#endif //GAME_GOBLINCLASS_H
