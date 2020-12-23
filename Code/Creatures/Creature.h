//
// Created by Vlad on 16.12.2020.
//
#ifndef GAME_CREATURE_H
#define GAME_CREATURE_H

#include "../tools/tools.h"

class Creature{

public:

    std::vector<coord> One_Step_Array = {coord(1,0),coord(-1,0),coord(0,1),coord(0,-1),}; /// Массив, содержащий всевозможные комбинации ходов для персонажа с длиной шага 1.
    std::vector<coord> Two_Steps_Array = {coord(1,0),coord(-1,0),coord(0,1),coord(0,-1),coord(2,0),coord(-2,0),coord(0,2),coord(0,-2),coord(1,1),coord(1,-1),coord(-1,1),coord(-1,-1)}; /// Массив, содержащий всевозможные комбинации ходов для персонажа с длиной шага 2.

    std::vector<coord> get_fields_for_step(std::vector<players_info> players_array); /// Функция возвращает массив координат полей, куда может пойти персонаж.

    coord field_to_move(std::vector<players_info> players_array); /// Функция возвращает координаты поля, на которое выгоднее всего пойти.

    coord get_target(std::vector<players_info> players_array); /// Функция возвращает координаты поля преследумой цели.

    std::vector<coord> get_fields_for_hitting(); /// Функция возвращает массив координат полей, которые бьет данный персонаж.

    caste_types caste; /// Каста персонажа.
    coord location; /// Метоположение персонажа.
    bool is_ally; /// В команде ли персонаж с игроком.
    bool is_alive; /// Жив ли персонаж.
    level lvl; /// Уровень игрока.
    condition condition; /// Состояние персонажа.
    int health; /// Уровень здоровья персонажа.
    int damage; /// Урон, наносимый персонажем.
    int max_points; /// Максимальное колличесвто очков за данного персонажа.
    int radius_of_hitting; /// Радиус удара персонажа.
    int stride_length; /// Длина шага персонажа.
    int field_length; /// Длина игрового поля.
    int field_height; /// Высота игрового поля.

    Creature();

    void reload_statistic(int points); /// Обновление данных с учетом урона.

    void upgrade(); /// Повышение статистики(за убийство другого персонажа).

    void rebirth(); /// Возраждение персонажа.

    coord action(std::vector<players_info> players_array); /// Возвращает координаты действия.
};

#endif //GAME_CREATURE_H
