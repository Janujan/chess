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
            if((j == 1) || (j==6))
            {
                std::string piece = "p" + std::to_string(i);
                chessboard[i].push_back(piece);
            }
            //major pieces
            else if((j==0)||(j==7))
            {
                chessboard[i].push_back(pieces[i]);
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
    
    std::cout<< "I " << i << " J " << j << std::endl;

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
