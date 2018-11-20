//
//  ChessGame.hpp
//  chess
//
//  Created by Janujan Selva on 2018-11-19.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#ifndef ChessGame_hpp
#define ChessGame_hpp

#include <stdio.h>
#include "player.hpp"
#include <string>
#include <iostream>
class ChessGame{
private:
    Player *black;
    Player *white;
    int turn_count = 0;
    int check_status = 0;
public:
    ChessGame(std::string player_black, std::string player_white);
    void move(char piece, int loc);
    void printBoard();
    int turnCount();
    int checkStatus();
};


#endif /* ChessGame_hpp */
