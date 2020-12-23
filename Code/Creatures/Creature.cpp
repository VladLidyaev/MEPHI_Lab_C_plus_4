#include "Creature.h"

    std::vector<coord> Creature::get_fields_for_step(std::vector<players_info> players_array){
        std::vector<coord> ans;
        if (stride_length == 1){
            for (int i=0; i<One_Step_Array.size(); i++){
                coord new_coord = coord(location.X+One_Step_Array[i].X,location.Y+One_Step_Array[i].Y);
                bool is_free = true;
                for (int j=0; j < players_array.size(); j++){
                    if (players_array[j].location == new_coord){
                        is_free = false;
                    }
                }
                if (is_free){
                    if ((new_coord.X>=0)&&(new_coord.X<field_length)){
                        if ((new_coord.Y>=0)&&(new_coord.Y<field_height)){
                            ans.push_back(new_coord);
                        }
                    }
                }
            }
        } else {
            for (int i=0; i<Two_Steps_Array.size(); i++){
                coord new_coord = coord(location.X+Two_Steps_Array[i].X,location.Y+Two_Steps_Array[i].Y);
                bool is_free = true;
                for (int j=0; j < players_array.size(); j++){
                    if (players_array[j].location == new_coord){
                        is_free = false;
                    }
                }
                if (is_free){
                    if ((new_coord.X>=0)&&(new_coord.X<field_length)){
                        if ((new_coord.Y>=0)&&(new_coord.Y<field_height)){
                            ans.push_back(new_coord);
                        }
                    }
                }
            }
        }
        return ans;
    }


    coord Creature::field_to_move(std::vector<players_info> players_array){
        std::vector<coord> fields = get_fields_for_step(players_array);
        coord target = get_target(players_array);
        coord step = coord(-1,-1);
        float main_length = get_length(location,target);
        if (fields.size() != 0){
            for (int i=0; i < fields.size(); i++){
                if (!(fields[i] == target)) {
                    if (get_length(fields[i],target) < main_length){
                        step = fields[i];
                        main_length = get_length(fields[i],target);
                    }
                }
            }
            if (step == coord(-1,-1)) {
                step = fields[0];
            }
        } else {
            step = location;
        }
        return step;
    }

    void Creature::reload_statistic(int points){
        health = health - points;
        if (health < 1){
            if (condition == alive){
                health = 0;
                condition = dead;
            }
            if (condition == undead){
                health = 0;
                is_alive = false;
            }
        }
    }

    void Creature::upgrade(){
        damage += damage/4;
        health += health/2;
    }

    void Creature::rebirth(){
        condition = undead;
        health = max_points;
    }

    coord Creature::get_target(std::vector<players_info> players_array){
        coord loco = location;
        coord target = coord(1,1);
        float len = 100000;
        if (is_ally){
            for (int i=0; i < players_array.size(); i++){
                if (!(players_array[i].is_ally) && (get_length(loco, players_array[i].location) < len)){
                    len = get_length(loco, players_array[i].location);
                    target = players_array[i].location;
                }
            }
        } else {
            for (int i=0; i < players_array.size(); i++){
                if ((players_array[i].is_ally) && (get_length(loco, players_array[i].location) < len)){
                    len = get_length(loco, players_array[i].location);
                    target = players_array[i].location;
                }
            }
        }
        return target;
    }

    coord Creature::action(std::vector<players_info> players_array){
        std::vector<coord> fields_for_hitting = get_fields_for_hitting();
        coord target = get_target(players_array);
        if (is_content(target,fields_for_hitting)){
            return target;
        } else {
            return field_to_move(players_array);
        }
    }

    std::vector<coord> Creature::get_fields_for_hitting(){
        std::vector<coord> fields;
        for (int i=location.X-radius_of_hitting;i<=location.X+radius_of_hitting;i++){
            for (int j=location.Y-radius_of_hitting;j<=location.Y+radius_of_hitting;j++){
                if ((i>=0)&&(i<field_length)){
                    if ((j>=0)&&(j<field_height)){
                        if (!(coord(i,j) == location)){
                            fields.push_back(coord(i,j));
                        }
                    }
                }
            }
        }
        return fields;
    }

Creature::Creature() {}
