//
//  ChessGame.cpp
//  chess
//
//  Created by Janujan Selva on 2018-11-19.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#include "ChessGame.hpp"

ChessGame::ChessGame(std::string player_black, std::string player_white)
{
    black = new Player(player_black);
    white = new Player(player_white);
}


void ChessGame::move(char piece, int loc)
{
    std::cout<<"Move piece " << piece << " to " << loc << std::endl;
}

void ChessGame::printBoard()
{
    std::cout<<"Printing Board"<< std::endl;
}

int ChessGame::turnCount()
{
    return turn_count;
}

int ChessGame::checkStatus()
{
    return check_status;
}
