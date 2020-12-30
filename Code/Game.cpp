#include "Game.h"

    int Game::getRandomNumber(int max){
        int min = 0;
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    coord Game::generate_coordinates() {
        return coord(getRandomNumber(length-1),getRandomNumber(height-1));
    }

std::vector<std::unique_ptr<Creature>> Game::generate_creatures(){
    std::vector<std::unique_ptr<Creature>> array;
        std::vector<int> Ogr_Gobl_Merc;
        switch (level) {
            case stupid:
                Ogr_Gobl_Merc = {1,0,-2,-2,-1,-1};
                break;
            case beginner:
                Ogr_Gobl_Merc = {1,1,-1,-1,0,0};
                break;
            case middle:
                Ogr_Gobl_Merc = {2,1,0,0,1,1};
                break;
            case pro:
                Ogr_Gobl_Merc = {1,1,1,1,1,1};
                break;}

        int a = Ogr_Gobl_Merc[0]+floor;
        int b = Ogr_Gobl_Merc[1]+floor;
        int c = Ogr_Gobl_Merc[2]+floor;
        int d = Ogr_Gobl_Merc[3]+floor;
        int e = Ogr_Gobl_Merc[4]+floor;
        int f = Ogr_Gobl_Merc[5]+floor;

        std::vector<coord> ban_list = {coord(0,0),coord(0,1),coord(1,0),coord(1,1),coord(2,0),coord(2,1),coord(2,2),coord(1,2),coord(0,2)};

        if (a>0){
            for(int i=0; i < a; i++){
                bool flag = false;
                while (!flag){
                    coord new_loc = generate_coordinates();
                    if (!is_content(new_loc,ban_list)){
                        Creature *ogre = new OgreClass(level,length,height,new_loc);
                        array.push_back(static_cast<std::unique_ptr<Creature, std::default_delete<Creature>>>(ogre));
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
                        Creature *goblin = new MercenaryFoot(level,length,height,new_loc);
                        array.push_back(static_cast<std::unique_ptr<Creature, std::default_delete<Creature>>>(goblin));
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
                        Creature *mercenary = new MercenaryHorse(level,length,height,new_loc);
                        array.push_back(
                                static_cast<std::unique_ptr<Creature, std::default_delete<Creature>>>(mercenary));
                        ban_list.push_back(new_loc);
                        flag = true;
                    }
                }
            }
        }

        if (d>0){
            for(int i=0; i < c; i++){
                bool flag = false;
                while (!flag){
                    coord new_loc = generate_coordinates();
                    if (!is_content(new_loc,ban_list)){
                        Creature *mercenary = new GoblinSpear(level,length,height,new_loc);
                        array.push_back(
                                static_cast<std::unique_ptr<Creature, std::default_delete<Creature>>>(mercenary));
                        ban_list.push_back(new_loc);
                        flag = true;
                    }
                }
            }
        }

        if (e>0){
            for(int i=0; i < c; i++){
                bool flag = false;
                while (!flag){
                    coord new_loc = generate_coordinates();
                    if (!is_content(new_loc,ban_list)){
                        Creature *mercenary = new GoblinBowShort(level,length,height,new_loc);
                        array.push_back(
                                static_cast<std::unique_ptr<Creature, std::default_delete<Creature>>>(mercenary));
                        ban_list.push_back(new_loc);
                        flag = true;
                    }
                }
            }
        }

        if (f>0){
            for(int i=0; i < c; i++){
                bool flag = false;
                while (!flag){
                    coord new_loc = generate_coordinates();
                    if (!is_content(new_loc,ban_list)){
                        Creature *mercenary = new GoblinBowTail(level,length,height,new_loc);
                        array.push_back(
                                static_cast<std::unique_ptr<Creature, std::default_delete<Creature>>>(mercenary));
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
        switch (level) {
            case stupid:
                user.update_exp(140);
                break;
            case beginner:
                user.update_exp(120);
                break;
            case middle:
                user.update_exp(100);
                break;
            case pro:
                user.update_exp(80);
                break;
        }
        main_vector = generate_creatures();
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
            if (main_vector[i]->is_alive == false) {
                main_vector.erase(main_vector.begin()+i);
            }
        }
        for (int i=0; i< main_vector.size(); i++){
            if (main_vector[i]->condition != dead) {
                array.push_back(players_info(main_vector[i]->location,main_vector[i]->is_ally));
            }
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
                if ((main_vector[i]->location == hit)&&((main_vector[i]->condition == alive) || (main_vector[i]->condition == undead))){
                    main_vector[i]->reload_statistic(user.damage);
                } else {
                    if ((main_vector[i]->location == hit)&&(main_vector[i]->condition == dead)){
                        switch (a) {
                            case 0:
                                if (user.mana >= main_vector[i]->max_points){
                                    main_vector[i]->rebirth();
                                    main_vector[i]->is_ally = true;
                                    user.mana -= main_vector[i]->max_points;
                                }
                                break;
                            case 1:
                                user.upgrade_health(main_vector[i]->max_points);
                                main_vector[i]->is_alive = false;
                                break;
                            case 2:
                                user.upgrade_mana(main_vector[i]->max_points);
                                main_vector[i]->is_alive = false;
                                break;
                        }
                    }
                }
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
                            if (main_vector[k]->location == coord(j,i)){
                                add = true;
                                str += (main_vector[k]->get_view());
                            }
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
            reload_info();
            coord step = main_vector[i]->action(all_info);
            if (!(step == main_vector[i]->location)){
                if (!((main_vector[i]->condition == dead) || (main_vector[i]->is_alive == false))){
                    bool flag = false;
                    for(int j=0; j<main_vector.size();j++){
                        if (user.location == step){
                            flag = true;
                            user.reload_statistic(main_vector[i]->damage);
                        }
                        if (i!=j){
                            if (main_vector[j]->location == step){
                                flag = true;
                                main_vector[j]->reload_statistic(main_vector[i]->damage);
                                if ((main_vector[j]->condition == dead) || (main_vector[j]->is_alive == false)){
                                    main_vector[i]->upgrade();
                                }
                            }
                        }
                    }
                    if (!flag){
                        main_vector[i]->location = step;
                    }
                }
            }
            main_vector[i]->reload();
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
                    if (loc == main_vector[i]->location){
                        flag = false;
                    }
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
                    if (loc == main_vector[i]->location){
                        flag = false;
                    }
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
                    if (loc == main_vector[i]->location){
                        flag = false;
                    }
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
                    if (loc == main_vector[i]->location){
                        flag = false;
                    }
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
        if (loc == main_vector[i]->location){
            flag = true;
            ans.push_back("▶ENEMY INFO: ");
            ans.push_back(" ۞CASTE: " + get_type(main_vector[i]->caste));
            ans.push_back("   ?CONDITION: " + get_cond(main_vector[i]->condition,main_vector[i]->is_ally));
            ans.push_back("   ❥MAXHEALTH: " + std::to_string(main_vector[i]->max_points));
            ans.push_back("   ❤HEALTH: " + std::to_string(main_vector[i]->health));
            ans.push_back("   †DAMAGE: " + std::to_string(main_vector[i]->damage));
        }
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
