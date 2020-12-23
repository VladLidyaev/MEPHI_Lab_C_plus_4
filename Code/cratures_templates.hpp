//
// Created by Vlad on 22.12.2020.
//

#ifndef GAME_CRATURES_TEMPLATES_HPP
#define GAME_CRATURES_TEMPLATES_HPP

#include <variant>

template <typename T, typename S, typename V>
class creatures_templates{  /// Шаблонный класс для хранения указателя на один из трех классов персонажей.
private:
    T * first;
    S * second;
    V * third;
public:
    creatures_templates(){
        first = nullptr;
        second = nullptr;
        third = nullptr;
    }
    creatures_templates(T * ptr){
        first = ptr;
        second = nullptr;
        third = nullptr;
    }
    creatures_templates(S * ptr){
        first = nullptr;
        second = ptr;
        third = nullptr;
    }
    creatures_templates(V * ptr){
        first = nullptr;
        second = nullptr;
        third = ptr;
    }

    std::variant<T *, S *, V *> get_value(){
        std::variant<T *, S *, V *> ans;
        if (first != nullptr){
            ans = first;
        }
        if (second != nullptr){
            ans = second;
        }
        if (third != nullptr){
            ans = third;
        }
        return ans;
    }
    ~creatures_templates() = default;
};

#endif //GAME_CRATURES_TEMPLATES_HPP
