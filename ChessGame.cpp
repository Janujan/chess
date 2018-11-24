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
    chb = new ChessBoard();
}

void ChessGame::printBoard()
{
    std::cout<<"Printing Board"<< std::endl;
    chb->printBoard();
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
    
    //std::vector<int> piece_status = black->getPieces();
    std::cout<<"Player "<< black->getName() << std::endl;
    for(int i = 0; i < PIECE_NUM; i++)
    {
        //std::cout << "Piece " << i + 1 << " " << piece_status[i] << std::endl;
    }
    
    //piece_status = white->getPieces();
    std::cout<<"Player " << white->getName() << std::endl;
    for(int i = 0; i < PIECE_NUM; i++)
    {
        //std::cout << "Piece " << i + 1 << " " << piece_status[i] << std::endl;
    }
}

//Moves are comma delimited
//Convert col to lower
std::tuple<std::string, std::string, int> ChessGame::readMove()
{
    std::cout << "What is your move? format ( string piece, char column, int row )" << std::endl;
    
    std::string piece = "k1";
    std::string row = "c";
    int col = 4;
    
//    std::string userInput;
//    std::cin>> userInput;
//
//    std::string delim = ",";
//    piece  = userInput.substr(0, userInput.find(delim));
//    userInput.erase(0, userInput.find(delim) + delim.length());
//
//    col = userInput.substr(0, userInput.find(delim));
//    userInput.erase(0, userInput.find(delim) + delim.length());
//
//    row = std::stoi(userInput);
    
    
    return std::make_tuple(piece, row, col);
}

/*
 Move has to occur, where input is taken from players
 then move function should state whether move was valid or not
 once move is made, game status needs to be updated on whether checkmate occured
 checkmate can only occur IF check occurs, so build into that logic
 */
void ChessGame::move(std::tuple<std::string, std::string, int> player_move, int player)
{
    std::string piece = std::get<0>(player_move);
    std::string row = std::get<1>(player_move);
    int col = std::get<2>(player_move);
    
    auto player_check = (player == 0) ? white:black;
    int validPiece = player_check->validPiece(piece);
    if(!validPiece)
    {
        std::cout<<"Not a valid Piece"<<std::endl;
        return;
    }
    //Convert col to a column index (assuming row is lower case)
    int row_int = int(row.at(0)) - 97;
    
    int loc_status = chb->isEmpty(col, row_int);
    
    switch(loc_status)
    {
        case 1:
            std::cout<<"Move piece " << piece << " to " << row << col << std::endl;
            chb->move(piece, col, row_int, player);
            break;
        case -1:
            std::cout<<"Please make a valid move" << std::endl;
            break;
        case 0:
            std::cout<<"Location is not Empty"<<std::endl;
            std::cout<<"ROW " << row << "("<< row_int << ") " <<  "COL " << col << std::endl;
            break;
            
    }
}

//Controller function to begin game
//White moves first

int ChessGame::chessGameStart(ChessGame *ch)
{
    std::cout <<"Player " << ch->white->getName() << " will start first" << std::endl;
    int player = 0;
    
    std::tuple<std::string, std::string, int> player_move = ch->readMove();
    ch->move(player_move, player);
    test_move(ch);
    /*
    //keep game going until game is finished
    while(!game_status)
    {
        
    }
    return 1;kn
     */
    return 1;
}


void ChessGame::test_move(ChessGame *ch){
    std::cout<<std::endl<< std::endl <<"TESTING CHESSGAME::MOVE FUNCTIONALITY" << std::endl <<std::endl;
    ch->move(std::make_tuple("k1", "f", 5), 0);
    ch->printBoard();
    ch->move(std::make_tuple("k1", "g", 3), 0);
    ch->printBoard();
    ch->move(std::make_tuple("k1", "l", 2), 0);
    ch->move(std::make_tuple("k1", "e", 10), 0);
    ch->move(std::make_tuple("k3", "f", 5), 0);
    ch->printBoard();
}
