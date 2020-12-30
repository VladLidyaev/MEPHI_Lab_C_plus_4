//
// Created by Vlad on 30.12.2020.
//

#include <gtest/gtest.h>
#include "../Hero/Hero.h"

TEST(HeroConstructor,Params1){
    Hero user("vlad",20,10);
    ASSERT_EQ(user.location,coord(0,0));
}

TEST(HeroConstructor,Params2){
    Hero user("vlad",20,10);
    ASSERT_EQ(user.caste,User);
}

TEST(HeroConstructor,Params3){
    Hero user("vlad",20,10);
    ASSERT_EQ(user.name,"vlad");
}

TEST(HeroConstructor,Params4){
    Hero user("vlad",20,10);
    ASSERT_EQ(user.is_ally,true);
}

TEST(HeroMethods,view){
    Hero user("vlad",20,10);
    ASSERT_EQ(user.get_view(),"ߐ");
}

TEST(HeroMethods,move_r){
    Hero user("vlad",20,10);
    user.move_right();
    ASSERT_EQ(user.location,coord(1,0));
}

TEST(HeroMethods,move_l1){
    Hero user("vlad",20,10);
    user.move_left();
    ASSERT_EQ(user.location,coord(0,0));
}

TEST(HeroMethods,move_l2){
    Hero user("vlad",20,10);
    user.move_right();
    user.move_left();
    ASSERT_EQ(user.location,coord(0,0));
}

TEST(HeroMethods,move_d){
    Hero user("vlad",20,10);
    user.move_down();
    ASSERT_EQ(user.location,coord(0,1));
}

TEST(HeroMethods,move_t1){
    Hero user("vlad",20,10);
    user.move_up();
    ASSERT_EQ(user.location,coord(0,0));
}

TEST(HeroMethods,move_t2){
    Hero user("vlad",20,10);
    user.move_down();
    user.move_up();
    ASSERT_EQ(user.location,coord(0,0));
}