//
// Created by Vlad on 16.12.2020.
//
#ifndef GAME_TOOLS_H
#define GAME_TOOLS_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

struct coord{ /// Структура для хранения координат.
    coord(int x, int y){
        X = x;
        Y = y;
    }
    coord() = default;
    int X;
    int Y;
};

struct players_info{ /// Структура для хранения данных о всех объектах на поле, используемая симулятором для нахождения симуляцией цели данного объекта.
    players_info(coord coord1,bool is_friend){
        location = coord1;
        is_ally = is_friend;
    }
    players_info() = default;
    coord location{};
    bool is_ally{};
};

bool operator== (const coord &c1, const coord &c2); /// Перегрузка оператора равенства для координат.

enum level{ /// Перечисление возможных уровней сложности игры.
    stupid,
    beginner,
    middle,
    pro,
};

enum condition{ /// Перечисление возможных состояний объектов на карте.
    alive,
    undead,
    dead,
};

enum caste_types{ /// Перечисление всех каст персонажей.
    Ogre,
    Goblin,
    Mercenary,
    User,
};

level str_to_level(int x); /// Функция преобразования индекса уровня сложности в параметр пересичления сложности.

struct file_for_upload{ /// Структура для загрузки/выгрузки состояния персонажа и уровня из конфигурационного файла.
    file_for_upload(std::vector<std::string> txt){
        floor = std::stoi(txt[0]);
        experience = std::stoi(txt[1]);
        user_name = txt[2];
        field_length_int = std::stoi(txt[3]);
        field_height_int = std::stoi(txt[4]);
        lvl = str_to_level(std::stoi(txt[5]));
    }
    int floor;
    int experience;
    std::string user_name;
    int field_length_int;
    int field_height_int;
    level lvl;
};

float get_length(coord a, coord b); /// Функция возвращает расстояние между двумя точками.

bool is_content(coord a,std::vector<coord> b); /// Функция проверяет содержание данных координат в данном массиве координат.

std::string add_space(std::string str); /// Функция добавляет пробелов к строке для корректоного отображения данных в консоли.

#endif //GAME_TOOLS_H
