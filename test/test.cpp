#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "rule.h"
using namespace std;
TEST_CASE("Check game is well initialised"){
    Rule game;
    REQUIRE(game.getSize()==10000);
    game.NewState();
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            REQUIRE(game.getState()[i][j]<2);
        }
    }
    
    
}

TEST_CASE("Check new state is well calculated in trivial cases"){
    vector<vector<int > > board(3, vector<int> (3));
    vector<int > raw(3);
    
    SECTION("Test a living cell is killed by overpopulation"){
        for (int i=0;i<3;i++) raw[i]=1;
    for (int i=0;i<3;i++){
        board[i]=raw;
    }
        
    Rule game1(3,3,board);
        cout<<"here"<<endl;
    game1.NewState();
       CHECK(game1.getState()[1][1]==0);
        raw.clear();
        board.clear();
    }
        
   SECTION("Test cell becomes or stays alive "){
       raw[0]=0;
       raw[1]=0;
       raw[2]=1;
    
    for (int i=0;i<3;i++){
        board[i]=raw;
    }
    
    Rule game2(3,3,board);
    game2.NewState();
    REQUIRE(game2.getState()[1][1]==1);//test dead cell becomes alive
    REQUIRE(game2.getState()[1][2]==1);
    raw.clear();
    board.clear();
    }
    
}