#include "Game.h"

    int Game::getRandomNumber(int max){
        int min = 0;
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    coord Game::generate_coordinates() {
        return coord(getRandomNumber(length-1),getRandomNumber(height-1));
    }

std::vector<creatures_templates<OgreClass,GoblinClass,MercenaryClass>> Game::generate_creatures(){
    std::vector<creatures_templates<OgreClass,GoblinClass,MercenaryClass>> array;
        std::vector<int> Ogr_Gobl_Merc;
        switch (level) {
            case stupid:
                Ogr_Gobl_Merc = {1,0,-2};
                break;
            case beginner:
                Ogr_Gobl_Merc = {1,1,-1};
                break;
            case middle:
                Ogr_Gobl_Merc = {2,1,0};
                break;
            case pro:
                Ogr_Gobl_Merc = {1,1,1};
                break;
        }

        int a = Ogr_Gobl_Merc[0]+floor;
        int b = Ogr_Gobl_Merc[1]+floor;
        int c = Ogr_Gobl_Merc[2]+floor;

        std::vector<coord> ban_list = {coord(0,0),coord(0,1),coord(1,0),coord(1,1),coord(2,0),coord(2,1),coord(2,2),coord(1,2),coord(0,2)};

        if (a>0){
            for(int i=0; i < a; i++){
                bool flag = false;
                while (!flag){
                    coord new_loc = generate_coordinates();
                    if (!is_content(new_loc,ban_list)){
                        auto* ogre = new OgreClass(level,length,height,new_loc);
                        array.push_back(ogre);
                        ban_list.push_back(new_loc);
                        flag = true;
                    }
                }
            }
        }

        if (b>0){
            for(int i=0; i < b; i++){
                bool flag = false;
                while (!flag){
                    coord new_loc = generate_coordinates();
                    if (!is_content(new_loc,ban_list)){
                        auto* goblin = new GoblinClass(level,length,height,new_loc);
                        array.push_back(goblin);
                        ban_list.push_back(new_loc);
                        flag = true;
                    }
                }
            }
        }

        if (c>0){
            for(int i=0; i < c; i++){
                bool flag = false;
                while (!flag){
                    coord new_loc = generate_coordinates();
                    if (!is_content(new_loc,ban_list)){
                        auto* mercenary = new MercenaryClass(level,length,height,new_loc);
                        array.push_back(mercenary);
                        ban_list.push_back(new_loc);
                        flag = true;
                    }
                }
            }
        }
        return array;
    }

    void Game::starting(){
        system("clear");
        graph_logo();
        std::string var;
        std::cout << "Welcome to the dungeon.\nYou are a necromancer and your weapon is magic.\nTry to get out alive.\n\n\n" << std::endl;
        std::cout << "Press any key to start." << std::endl;
        system("stty raw");
        var = getchar();
        system("stty cooked");
        system("clear");

        graph_logo();
        std::cout << "You want to download the game from a file? \n Press Y (yes) or N (no)" << std::endl;
        system("stty raw");
        char file_button = getchar();
        system("stty cooked");
        system("clear");
        if (file_button == 'y'){
            Upload_from_file(read_from_file());
        } else {
            graph_logo();
            std::cout << "Enter your name:" << std::endl;
            std::cin >> user.name;
            system("clear");
            graph_logo();
            std::cout << "Select the difficulty level,\nenter a number from 1 to 4." << std::endl;
            system("stty raw");
            char lvl = getchar();
            system("stty cooked");
            while (!((lvl == '1')||(lvl == '2')||(lvl == '3')||(lvl == '4'))){
                system("stty raw");
                char count = getchar();
                lvl = count;
                system("stty cooked");
            }
            switch (lvl) {
                case '1':
                    level = stupid;
                    break;
                case '2':
                    level = beginner;
                    break;
                case '3':
                    level = middle;
                    break;
                case '4':
                    level = pro;
                    break;
            }
            system("clear");
        }
        main_vector = generate_creatures();
//        usleep(5000000);
    }

    void Game::ending(bool win){
        if (win) {
            system("clear");
            graph_logo();
            std::cout << "" << std::endl;
            std::cout << "▲▼▲▼" <<  user.name << ", YOU WIN▲▼▲▼" << std::endl;
        } else {
            system("clear");
            graph_logo();
            std::cout << "" << std::endl;
            std::cout << "▲▼▲▼YOU LOST▲▼▲▼" << std::endl;
        }
        std::cout << "Press q to exit or press z to start a new game" << std::endl;
    }

    void Game::check(){
        if (user.health <= 0){
            end = true;
            ending(false);
        } else {
            if (user.location == win_field){
                if (floor == 5){
                    end = true;
                    ending(true);
                } else {
                    floor += 1;
                    write_in_file();
                    main_vector = generate_creatures();
                    user.location = coord(0,0);
                }
            }
        }
    }

    void Game::reload_info(){
        all_info = get_all_info();
    }

    std::vector<players_info> Game::get_all_info(){
        std::vector<players_info> array;
        array.push_back(players_info(user.location,user.is_ally));
        for (int i=0; i< main_vector.size(); i++) {
            std::visit([this,&i](auto&&  x){
                if (x->is_alive == false) {
                    main_vector.erase(main_vector.begin()+i);
                }
            }, main_vector[i].get_value());
        }
        for (int i=0; i< main_vector.size(); i++){
            std::visit([this,&i,&array](auto&&  x){
                if (x->condition != dead) {
                    array.push_back(players_info(x->location,x->is_ally));
                }
            }, main_vector[i].get_value());
        }
        return array;
    }

    void Game::hit_mode_switch(){
        if (hit_mode){
            hit_mode = false;
            hit = coord(-1,-1);
        } else {
            hit_mode = true;
            hit = user.location;
        }
    }

    void Game::hero_hit(int a){
        if (hit_mode){
            for(int i=0; i<main_vector.size();i++){
                std::visit([this,&i,&a](auto&&  x){
                    if ((x->location == hit)&&((x->condition == alive) || (x->condition == undead))){
                        x->reload_statistic(user.damage);
                    } else {
                        if ((x->location == hit)&&(x->condition == dead)){
                            switch (a) {
                                case 0:
                                    if (user.mana >= x->max_points){
                                        x->rebirth();
                                        x->is_ally = true;
                                        user.mana -= x->max_points;
                                    }
                                    break;
                                case 1:
                                    user.upgrade_health(x->max_points);
                                    x->is_alive = false;
                                    break;
                                case 2:
                                    user.upgrade_mana(x->max_points);
                                    x->is_alive = false;
                                    break;
                            }
                        }
                    }
                }, main_vector[i].get_value());
            }
            hit_mode_switch();
            next_step();
        }
    }

    std::vector<std::string> Game::get_matrix(){
        std::vector<std::string> ans;
        for (int i=0; i < height; i++) {
            std::string str = "";
            for (int j = 0; j < length; j++) {
                bool add = false;
                if ((hit_mode == true)&&(hit == coord(j,i))){
                    str += "✴";
                } else {
                    if (user.location == coord(j,i)){
                        add = true;
                        str += (user.get_view());
                    } else {
                        for (int k=0; k < main_vector.size(); k++){
                            std::visit([this,&k,&add,&str,&i,&j](auto&&  x){
                                if (x->location == coord(j,i)){
                                    add = true;
                                    str += (x->get_view());
                                }
                            }, main_vector[k].get_value());
                        }
                    }
                    if (!add){
                        str += " ";
                    }
                }
            }
            ans.push_back(str);
        }
        return ans;
    }

    void Game::graph_logo(){
        std::string  prelogo = "╔═══════════════════════╗";
        std::string     logo = "║DUNGEON AND NECROMANCER║";
        std::string postlogo = "╚═══════════════════════╝";
        if (length < 25) {
            std::cout << prelogo << std::endl;
            std::cout << logo << std::endl;
            std::cout << postlogo << std::endl;
        } else {
            std::string vst;
            for (int i=0; i<((length - 23)/2)+1;i++){
                vst += " ";
            }
            std::cout << vst << prelogo << vst << std::endl;
            std::cout << vst << logo << vst << std::endl;
            std::cout << vst << postlogo << vst << std::endl;
        }
    }

    void Game::graph_info() {
        std::vector<std::string> array_enemies_statistic = get_enemy_stat(hit);
        std::cout << add_space("▶YOUR INFO:") << array_enemies_statistic[0] << std::endl;
        std::cout << add_space("   NECROMANCER: " + user.name) << array_enemies_statistic[1] << std::endl;
        std::cout << add_space("   ❤HEALTH: " + std::to_string(user.health)) << array_enemies_statistic[2] << std::endl;
        std::cout << add_space("   ✞MANA: " + std::to_string(user.mana)) << array_enemies_statistic[3] << std::endl;
        std::cout << add_space("   ☹ENEMIES: " + std::to_string(main_vector.size())) << array_enemies_statistic[4] << std::endl;
        std::cout << add_space("   ➡FLOOR: " + std::to_string(floor) + "/5") << array_enemies_statistic[5] << std::endl;
        std::cout << "" << std::endl;
        std::cout << "▶HELP:" << std::endl;
        std::cout << "  Press W,A,S,D to move." << std::endl;
        std::cout << "  Press E to use magic (and see enemies statistic)." << std::endl;
        std::cout << "  Press R to hit creature." << std::endl;
        std::cout << "     - Press R to rebirth creature from dead body." << std::endl;
        std::cout << "     - Press H to get Health from dead body." << std::endl;
        std::cout << "     - Press M to get Mana from dead body." << std::endl;
    }

    void Game::graph(){
        reload_info();
        graph_logo();
        graph_info();

        std::vector<std::string> array = get_matrix();
        std::string border_string = "";
        for (int i=0;i<(length+2);i++){
            border_string += "#";
        }
        std::cout << border_string << std::endl;
        for (int j=0;j<height;j++){
            if (j==0){
                std::cout << "[" << array[j] << "#" << std::endl;
            } else {
                if (j==height-1){
                    std::cout << "#" << array[j] << "]" << std::endl;
                } else {
                    std::cout << "#" << array[j] << "#" << std::endl;
                }
            }
        }
        std::cout << border_string << std::endl;
    }

    void Game::next_step(){
        reload_info();
        for(int i=0; i<main_vector.size();i++){
            std::visit([this,&i](auto&&  x){
                reload_info();
                coord step = x->action(all_info);
                if (!(step == x->location)){
                    if (!((x->condition == dead) || (x->is_alive == false))){
                        bool flag = false;
                        for(int j=0; j<main_vector.size();j++){
                            std::visit([this,&i,&step,&flag,&x,&j](auto&&  y){
                                if (user.location == step){
                                    flag = true;
                                    user.reload_statistic(x->damage);
                                }
                                if (i!=j){
                                    if (y->location == step){
                                        flag = true;
                                        y->reload_statistic(x->damage);
                                        if ((y->condition == dead) || (y->is_alive == false)){
                                            x->upgrade();
                                        }
                                    }
                                }
                            }, main_vector[j].get_value());
                        }
                        if (!flag){
                            x->location = step;
                        }
                    }
                }
            }, main_vector[i].get_value());
            system("clear");
            graph();
            check();
            usleep(50000);
        }
    }

    void Game::move_left(){
        if (!hit_mode){
            if (user.location.X != 0) {
                user.move_left();
                coord loc = user.location;
                bool flag = true;
                for (int i=0; i < main_vector.size(); i++){
                    std::visit([this,&i,&loc,&flag](auto&&  x){
                        if (loc == x->location){
                            flag = false;
                        }
                    }, main_vector[i].get_value());
                }
                if (flag == false){
                    user.move_right();
                }
            }
        } else {
            if (hit.X != 0){
                hit.X-=1;
            }
        }
        check();
    }

    void Game::move_right(){
        if (!hit_mode){
            if (user.location.X != length-1) {
                user.move_right();
                coord loc = user.location;
                bool flag = true;
                for (int i=0; i < main_vector.size(); i++){
                    std::visit([this,&i,&loc,&flag](auto&&  x){
                        if (loc == x->location){
                            flag = false;
                        }
                    }, main_vector[i].get_value());
                }
                if (flag == false){
                    user.move_left();
                }
            }
        } else {
            if (hit.X != length-1){
                hit.X+=1;
            }
        }
        check();
    }

    void Game::move_up(){
        if (!hit_mode){
            if (user.location.Y != 0) {
                user.move_up();
                coord loc = user.location;
                bool flag = true;
                for (int i=0; i < main_vector.size(); i++){
                    std::visit([this,&i,&loc,&flag](auto&&  x){
                        if (loc == x->location){
                            flag = false;
                        }
                    }, main_vector[i].get_value());
                }
                if (flag == false){
                    user.move_down();
                }
            }
        } else {
            if (hit.Y != 0){
                hit.Y-=1;
            }
        }
        check();
    }

    void Game::move_down(){
        if (!hit_mode){
            if (user.location.Y != height-1) {
                user.move_down();
                coord loc = user.location;
                bool flag = true;
                for (int i=0; i < main_vector.size(); i++){
                    std::visit([this,&loc,&flag](auto&&  x){
                        if (loc == x->location){
                            flag = false;
                        }
                    }, main_vector[i].get_value());
                }
                if (!flag){
                    user.move_up();
                }
            }
        } else {
            if (hit.Y != height-1){
                hit.Y+=1;
            }
        }
        check();
    }

std::vector<std::string> Game::get_enemy_stat(coord loc) {
    bool flag = false;
    std::vector<std::string> ans = {};
    for (int i=0; i < main_vector.size(); i++){
        std::visit([this,&i,&loc,&flag,&ans](auto&&  x){
            if (loc == x->location){
                flag = true;
                ans.push_back("▶ENEMY INFO: ");
                ans.push_back(" ۞CASTE: " + get_type(x->caste));
                ans.push_back("   ?CONDITION: " + get_cond(x->condition,x->is_ally));
                ans.push_back("   ❥MAXHEALTH: " + std::to_string(x->max_points));
                ans.push_back("   ❤HEALTH: " + std::to_string(x->health));
                ans.push_back("   †DAMAGE: " + std::to_string(x->damage));
            }
        }, main_vector[i].get_value());
    }
    if (!flag){
        ans.push_back("▶ENEMY INFO:");
        ans.push_back("  NO");
        ans.push_back("    SUCH");
        ans.push_back("    ENEMY");
        ans.push_back("    SELECTED");
        ans.push_back("    ...");
    }
    return ans;
}

std::string Game::get_type(caste_types cast) {
    switch (cast) {
        case Ogre:
            return "Ogre";
        case Goblin:
            return "Goblin";
        case Mercenary:
            return "Mercenary";
    }
}

std::string Game::get_cond(condition cond, bool ally) {
    switch (cond) {
        case alive:
            return "Alive";
        case undead:
            switch (ally) {
                case true:
                    return "Undead & Friend";
                case false:
                    return "Undead & Enemy";
            };
        case dead:
            return "Dead";
    }
}

void Game::write_in_file() {
    std::ofstream out;
    out.open("/Users/vlad/CLionProjects/Game/text");
    if (out.is_open()){
        out << floor << std::endl;
        out << user.experience << std::endl;
        out << user.name << std::endl;
        out << length << std::endl;
        out << height << std::endl;
        out << get_int_by_level(level) << std::endl;
    }
}

int Game::get_int_by_level(enum level lvl){
    switch (lvl) {
        case stupid:
            return 1;
        case beginner:
            return 2;
        case middle:
            return 3;
        case pro:
            return 4;
    }
}

file_for_upload Game::read_from_file() {
    std::vector<std::string> txt;
    std::string line;
    std::ifstream in("/Users/vlad/CLionProjects/Game/text"); // окрываем файл для чтения
    if (in.is_open()){
        while (getline(in, line)){
            txt.push_back(line);
        }
    }
    in.close();
    return file_for_upload(txt);
}

void Game::Upload_from_file(file_for_upload txt) {
    floor = txt.floor;
    level = txt.lvl;
    end = false;
    length = 40;
    height = 20;
    hit_mode = false;
    user = Hero(txt.user_name,txt.field_length_int,txt.field_height_int);
    user.update_exp(txt.experience);
    win_field = coord((length-1),(height-1));
    all_info = get_all_info();
}
