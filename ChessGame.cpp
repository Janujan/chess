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


void ChessGame::move(char piece, _loc loc)
{
    std::cout<<"Move piece " << piece << " to " << loc.col << loc.row << std::endl;
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

void ChessGame::printPieceStatus()
{
    
    std::vector<int> piece_status = black->getPieces();
    std::cout<<"Player "<< black->getName() << std::endl;
    for(int i = 0; i < PIECE_NUM; i++)
    {
        std::cout << "Piece " << i + 1 << " " << piece_status[i] << std::endl;
    }
    
    piece_status = white->getPieces();
    std::cout<<"Player " << white->getName() << std::endl;
    for(int i = 0; i < PIECE_NUM; i++)
    {
        std::cout << "Piece " << i + 1 << " " << piece_status[i] << std::endl;
    }
}
