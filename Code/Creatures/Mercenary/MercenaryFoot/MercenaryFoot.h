//
// Created by Vlad on 30.12.2020.
//

#ifndef GAME_MERCENARYFOOT_H
#define GAME_MERCENARYFOOT_H

#include "../MercenaryClass.h"

class MercenaryFoot : public MercenaryClass {

public:

    void change_length();

    MercenaryFoot(level lvl,int field_length_int,int field_height_int, coord locate){
        caste = Mercenary; /// Смотри класс Creature.
        location = locate; /// Смотри класс Creature.
        is_ally = false; /// Смотри класс Creature.
        is_alive = true; /// Смотри класс Creature.
        lvl = lvl; /// Смотри класс Creature.
        condition = alive; /// Смотри класс Creature.
        max_points = get_max_points(lvl); /// Смотри класс Creature.
        health = max_points/2; /// Смотри класс Creature.
        damage = max_points/2; /// Смотри класс Creature.
        radius_of_hitting = 1; /// Смотри класс Creature.
        stride_length = 1; /// Смотри класс Creature.
        field_length = field_length_int; /// Смотри класс Creature.
        field_height = field_height_int; /// Смотри класс Creature.
    }

    void reload();

    std::string get_view(); /// Функция возвращает строковой символ состояния данного персонажа.
};


#endif //GAME_MERCENARYFOOT_H
