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

/*
 Move has to occur, where input is taken from players
 then move function should state whether move was valid or not
 once move is made, game status needs to be updated on whether checkmate occured
 checkmate can only occur IF check occurs, so build into that logic
 */
void ChessGame::move(std::tuple<std::string, std::string, int> player_move)
{
    std::string piece = std::get<0>(player_move);
    std::string col = std::get<1>(player_move);
    int row = std::get<2>(player_move);
    std::cout<<"Move piece " << piece << " to " << col << row << std::endl;
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

//Moves are comma delimited
std::tuple<std::string, std::string, int> ChessGame::readMove()
{
    std::cout << "What is your move? format ( string piece, char column, int row )" << std::endl;
    
    std::string piece = "kn";
    std::string col = "a";
    int row = 1;
    
    std::string userInput;
    std::cin>> userInput;
    
    std::string delim = ",";
    piece  = userInput.substr(0, userInput.find(delim));
    userInput.erase(0, userInput.find(delim) + delim.length());
    
    col = userInput.substr(0, userInput.find(delim));
    userInput.erase(0, userInput.find(delim) + delim.length());
    
    row = std::stoi(userInput);
    
    
    return std::make_tuple(piece, col, row);
}


//Controller function to begin game
//White moves first

int ChessGame::chessGameStart(ChessGame *ch)
{
    std::cout <<"Player " << ch->white->getName() << " will start first" << std::endl;
    
    
    std::tuple<std::string, std::string, int> player_move = ch->readMove();
    ch->move(player_move);
    
    
    /*
    //keep game going until game is finished
    while(!game_status)
    {
        
    }
    return 1;
     */
    return 1;
}
