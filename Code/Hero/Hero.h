//
// Created by Vlad on 16.12.2020.
//
#ifndef GAME_HERO_H
#define GAME_HERO_H

#include <utility>
#include "../tools/tools.h"

class Hero{

public:

    coord location{}; /// Координаты расположения игрока.
    std::string name; /// Имя игрока.
    caste_types caste; /// Каста игрока.
    bool is_ally; /// Всегда правда.
    bool is_alive; /// Жив ли игрок.
    int health; /// Здоровье игрока.
    int damage; /// Урон игрока.
    int mana; /// Мана игрока.
    int experience; /// Опыт игрока.
    int field_length; /// Длина карты.
    int field_height; /// Высота карты.

    void update_exp(int exp);  /// Функция для обновления опыта игрока.

    Hero(std::string user_name, int field_length_int,int field_height_int){
        is_alive = true;
        is_ally = true;
        name = std::move(user_name);
        caste = User;
        location = coord(0,0);
        field_height = field_height_int;
        field_length = field_length_int;
    }

    Hero() = default;

    void reload_statistic(int points);  /// Функция для учета урона, нанесенного игроку.

    void upgrade_health(int points); /// Увеличение здоровья.

    void upgrade_mana(int points);  /// Увеличение манны.

    std::string get_view();  /// Возвращает строковой символ обозначающий игрока для отображения на карте.

    void move_right();  /// Перемещение игрока, если это возможно.

    void move_left(); /// Перемещение игрока, если это возможно.

    void move_up(); /// Перемещение игрока, если это возможно.

    void move_down(); /// Перемещение игрока, если это возможно.

};

#endif //GAME_HERO_H
