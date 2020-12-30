//
// Created by Vlad on 22.12.2020.
//

#ifndef GAME_MERCENARYCLASS_H
#define GAME_MERCENARYCLASS_H

#include "../Creature.h"

class MercenaryClass : public Creature {

public:

    void upgrade_lvl();

    MercenaryClass();

    int get_max_points(level level); /// Функция возвращает максимальное количество очков, за убийство данного персонажа.

};


#endif //GAME_MERCENARYCLASS_H
