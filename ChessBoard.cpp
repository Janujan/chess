//
//  ChessBoard.cpp
//  chess
//
//  Created by Janujan Selva on 2018-11-22.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#include "ChessBoard.hpp"
ChessBoard::ChessBoard()
{
    //Set up the major pieces
    initPieces();
    
    //Resize the columns of chessboard to avoid seg fault
    chessboard.resize(COL);
    
    //Populate chessboard with appropriate pieces
    for(int i = 0; i < COL; i++)
    {
        for(int j = 0; j < ROW; j++)
        {
            //pawns
            if(j == 1)
            {
                std::string pawns = "p" + std::to_string(i);
                chessboard[i].push_back(pawns);
                piece_status_b.push_back(std::make_tuple(pawns, j, i));
            }
            else if(j == 6)
            {
                std::string pawns = "p" + std::to_string(i);
                chessboard[i].push_back(pawns);
                piece_status_w.push_back(std::make_tuple(pawns, j, i));
            }
            //major pieces
            else if(j == 0)
            {
                chessboard[i].push_back(pieces[i]);
                piece_status_b.push_back(std::make_tuple(pieces[i],j, i));
            }
            else if(j == 7)
            {
                chessboard[i].push_back(pieces[i]);
                piece_status_w.push_back(std::make_tuple(pieces[i],j, i));
            }
            
            //Empty spots
            else{
                chessboard[i].push_back(" x");
            }
        }
    }
    for(int j = 0; j < ROW; j++)
    {
        row_pair.insert({j, (char)(65+j)});
    }
}

void ChessBoard::printBoard()
{

    std::cout<<"Board Status" << std::endl;
    std::cout<< "   1  2  3  4  5  6  7  8" << std::endl;
    int j = 0;
    int i = 0;
    for(itr=row_pair.begin(); itr != row_pair.end();++itr)
    {
        std::cout<<itr->second << ' ';
        for(i = 0; i < COL; i++)
        {
            std::cout<< chessboard[i][j] << ' ';
        }
        std::cout<< itr->second << std::endl;
        j++;
    }
    std::cout<< "   1  2  3  4  5  6  7  8" << std::endl;
    
}

//vector to hold the major pieces
void ChessBoard::initPieces()
{
    pieces.push_back("r1");
    pieces.push_back("k1");
    pieces.push_back("b1");
    pieces.push_back("qu");
    pieces.push_back("ki");
    pieces.push_back("b2");
    pieces.push_back("k2");
    pieces.push_back("r2");
}

//Return whether the location is empty or not
int ChessBoard::isEmpty(int col, int row)
{
    int is_empty = 0;
    if(col >= COL || row >= ROW || col < 0 || row < 0)
    {
        std::cout<<"Location out of bounds"<<std::endl;
        std::cout<<"ROW " << row << " COL " << col << std::endl;
        return -1;
    }
    else{
        if(chessboard[col][row] == " x")
        {
            is_empty = 1;
        }
        return is_empty;
    }
}

void ChessBoard::printPieces()
{
    std::cout<< "Print status of white: " << std::endl;
    int i =0;
    while(i<16)
    {
        std::cout<< "Piece: " << std::get<0>(piece_status_w[i]);
        std::cout<<" Row: " << std::get<1>(piece_status_w[i]);
        std::cout<<" Col: " << std::get<2>(piece_status_w[i]);
        std::cout<< std::endl;;
        i++;
    }
    
    std::cout<<"Print status of black: "<< std::endl;
    i =0;
    while(i<16)
    {
        std::cout<< "Piece: " << std::get<0>(piece_status_b[i]);
        std::cout<<" Row: " << std::get<1>(piece_status_b[i]);
        std::cout<<" Col: " << std::get<2>(piece_status_b[i]);
        std::cout<< std::endl;;
        i++;
    }
    
    
}
//add logic to this for making move once move call is made by chessgame object
//This function will only be called if the piece is located on the board (not captured)
std::pair<int,int> ChessBoard::move(std::string piece, int col, int row, int player)
{
    int prev_row;
    int prev_col;
    int idx = 0;
    int flag = 1;
    
    auto &piece_set = (player == 0) ? piece_status_w : piece_status_b;
    while(flag && (idx < 16))
    {
        if(std::get<0>(piece_set[idx]) == piece)
        {
            flag = 0;
        }
        else{
            idx++;
        }
    }
    
    prev_row = std::get<1>(piece_set[idx]);
    prev_col = std::get<2>(piece_set[idx]);
    

    piece_set[idx] = std::make_tuple(piece, row, col);
    
    updateBoard(piece, prev_row, prev_col);
    return std::make_pair(prev_row, prev_col);
}

//update piece that was moved, along with making prev location empty
void ChessBoard::updateBoard(std::string piece, int prev_row, int prev_col)
{
    int idx = 0;
    
    while(std::get<0>(piece_status_w[idx]) != piece)
    {
        idx++;
    }
    
    int row = std::get<1>(piece_status_w[idx]);
    int col = std::get<2>(piece_status_w[idx]);
    
    chessboard[col][row] = piece;
    chessboard[prev_col][prev_row] = " x";
}
