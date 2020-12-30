#include "Game.h"
#include <gtest/gtest.h>

int main(){
    bool exit = false;
    Game game;
    std::cout << " " << std::endl;
    system("clear");
    game.starting();
    game.graph();
    system("stty raw");
    char input4 = getchar();
    system("stty cooked");
    system("clear");
    while (input4 != 'q'){
        switch (input4) {
            case 'w':
                game.move_up();
                if (!game.hit_mode && !game.end){
                    game.next_step();
                }
                break;
            case 'a':
                game.move_left();
                if (!game.hit_mode && !game.end){
                    game.next_step();
                }
                break;
            case 's':
                game.move_down();
                if (!game.hit_mode && !game.end){
                    game.next_step();
                }
                break;
            case 'd':
                game.move_right();
                if (!game.hit_mode && !game.end){
                    game.next_step();
                }
                break;
            case 'e':
                game.hit_mode_switch();
                break;
            case 'r':
                game.hero_hit(0);
                break;
            case 'h':
                game.hero_hit(1);
                break;
            case 'm':
                game.hero_hit(2);
                break;
            case 'q':
                break;
            case 'x':
                game.next_step();
                break;
            case 'z':
                if (game.end){
                    exit = true;
                    input4 = 'q';
                    main();
                }
        }
        if (!exit) {
            system("stty cooked");
            if (!game.end){
                system("clear");
                game.graph();
            }
            system("stty raw");
            input4 = getchar();
            system("stty cooked");
            system("clear");
        }
    }
    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();
    return 0;
};

//int main(int argc, char *argv[]){
//    testing::InitGoogleTest(&argc,argv);
//    RUN_ALL_TESTS();
//    return 0;
//}