//
// Created by Vlad on 22.12.2020.
//

#ifndef GAME_OGRECLASS_HPP
#define GAME_OGRECLASS_HPP

#include "../Creature.h"

class OgreClass : public Creature {

private:

    int get_damage();

    int get_stride_length();

public:

    OgreClass(level lvl,int field_length_int,int field_height_int, coord locate){
        caste = Ogre; /// Смотри класс Creature.
        location = locate; /// Смотри класс Creature.
        is_ally = false; /// Смотри класс Creature.
        is_alive = true; /// Смотри класс Creature.
        lvl = lvl; /// Смотри класс Creature.
        condition = alive; /// Смотри класс Creature.
        max_points = get_max_points(lvl); /// Смотри класс Creature.
        health = max_points/4; /// Смотри класс Creature.
        damage = max_points/8; /// Смотри класс Creature.
        radius_of_hitting = 1; /// Смотри класс Creature.
        stride_length = 1; /// Смотри класс Creature.
        field_length = field_length_int; /// Смотри класс Creature.
        field_height = field_height_int; /// Смотри класс Creature.
        talent = "More HP - less speed.";
    }

    std::string get_view(); /// Функция возвращает строковой символ состояния данного персонажа.

    int get_max_points(level level);/// Функция возвращает максимальное количество очков, за убийство данного персонажа.

    void reload();
};

#endif //GAME_OGRECLASS_HPP
