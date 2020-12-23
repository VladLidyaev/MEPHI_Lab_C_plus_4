#include "Hero.h"

    void Hero::update_exp(int exp){
        experience = exp;
        damage = experience/4;
        health = experience/2;
        mana = experience/2;
    };

    void Hero::reload_statistic(int points){
        health = health - points;
        if (health < 1){
            is_alive = false;
        }
    }

    void Hero::upgrade_health(int points){
        experience += points;
        damage = experience/4;
        health = experience/2;
    }

    void Hero::upgrade_mana(int points){
        experience += points;
        damage = experience/4;
        mana = experience/2;
    }

    std::string Hero::get_view(){
        return "ߐ";
    }

    void Hero::move_right(){
        if (location.X != field_length-1){
            location.X+=1;
        }
    }

    void Hero::move_left(){
        if (location.X != 0){
            location.X-=1;
        }
    }

    void Hero::move_up(){
        if (location.Y != 0){
            location.Y-=1;
        }
    }

    void Hero::move_down(){
        if (location.Y != field_height-1){
            location.Y+=1;
        }
    }