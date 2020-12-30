//
// Created by Vlad on 16.12.2020.
//
#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <unistd.h>
#include "Hero/Hero.h"
#include "Creatures/Ogre/OgreClass.h"
#include "Creatures/Mercenary/MercenaryHorse/MercenaryHorse.hpp"
#include "Creatures/Mercenary/MercenaryFoot/MercenaryFoot.h"
#include "Creatures/Goblin/GoblinSpear/GoblinSpear.h"
#include "Creatures/Goblin/GoblinBow/GoblinBowShort/GoblinBowShort.h"
#include "Creatures/Goblin/GoblinBow/GoblinBowTall/GoblinBowTail.hpp"
#include <fstream>
#include "cratures_templates.hpp"

class Game{

private:
    static int getRandomNumber(int max);  /// Получение случайного целого числа.

    coord generate_coordinates();  /// Получение случайных коориднат.

    std::vector<std::unique_ptr<Creature>> generate_creatures();  /// Генерация персонажей.

    std::vector<std::string> get_enemy_stat(coord loc);  /// Получение информации о персонаже по координатам.

    std::string get_type(caste_types cast);  /// Преобразовать касту персонажа в строку.

    std::string get_cond(condition cond, bool ally);  /// Преобразовать состояние и команду персонажа в строку.

    int get_int_by_level(level lvl);  /// Получение целого чила, обозначающего уровень игрока для сохранения в конфигурационный файл.

    void graph_info();  /// Вывод информации об ироке и персонаже по выбранным координатам.

    void Upload_from_file(file_for_upload txt); /// Загрузка состояния игры из конфигурационного файла.

    file_for_upload read_from_file();  /// Функция прочтения файла.

    void write_in_file();  /// Функция записи в файл.

    void ending(bool win);  /// Функция, вызывающаяся при окончании игры.

    void check();  /// Функция проверки состояния игры.

    void reload_info();  /// Функция обновления информации о местоположении персонажей.

    std::vector<players_info> get_all_info();  /// Получение информации о местоположении персонажей из вектора персонажей.

    std::vector<std::string> get_matrix();  /// Получение матрицы строк для отображения в консоли.

    void graph_logo();  /// Вывод логотипа игры.

public:

    std::vector<std::unique_ptr<Creature>> main_vector;  /// Вектор, хранящий ссылки на всех персонажей и игрока.
    level level; /// Уровень игрока.
    std::string name;  /// Имя игрока.
    coord win_field;  /// Координаты поля для перехода на след уровень.
    int length;  /// Длина поля.
    int height; /// Высота поля.
    Hero user;  /// Игрок.
    std::vector<players_info> all_info;  /// Вектор информации о местоположении всех персонажей и игрока.
    bool hit_mode;  /// Перключатель режима выбора цели и перемещения игрока.
    coord hit;  /// Координаты удара игрока.
    int floor;  /// Целое число - номер уровня.
    bool end;  /// Конец игры.

    Game(){
        floor = 1;
        end = false;
        length = 40;
        height = 20;
        hit_mode = false;
        user = Hero(name,length,height);
        win_field = coord((length-1),(height-1));
        all_info = get_all_info();
        switch (level) {
            case stupid:
                user.update_exp(100);
                break;
            case beginner:
                user.update_exp(80);
                break;
            case middle:
                user.update_exp(60);
                break;
            case pro:
                user.update_exp(40);
                break;
        }
    }

    void hit_mode_switch();  /// Смена режима прицеливания на режим перемещения.

    void starting();  /// Функция запускается при запуске новой игры.

    void hero_hit(int a);  /// Функция удара игрока.

    void graph();  /// Функция отрисовки в консоль.

    void next_step();  /// Функция хода для всех персонажей.

    void move_left();  /// Функция перемещения игрока либо прицела.

    void move_right(); /// Функция перемещения игрока либо прицела.

    void move_up(); /// Функция перемещения игрока либо прицела.

    void move_down(); /// Функция перемещения игрока либо прицела.
};
#endif //GAME_GAME_H
