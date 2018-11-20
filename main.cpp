//
//  main.cpp
//  chess
//
//  Created by Janujan Selva on 2018-11-18.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "player.hpp"
#include "ChessGame.hpp"

using namespace std;
int main()
{
    string player_black = "Jay";
    string player_white = "Sunny";
    
    ChessGame *ch = new ChessGame(player_black, player_white);
    
    ch->printBoard();
    ch->printPieceStatus();
    
    ch->chessGameStart(ch);
    return 0;
}
