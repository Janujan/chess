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
    chessboard.resize(COL);
    for(int i = 0; i < COL; i++)
    {
        for(int j = 0; j < ROW; j++)
        {
            if((j == 0) || (j == 1) || (j==6) || (j==7))
            {
                chessboard[i].push_back(' ');
            }
            else{
                chessboard[i].push_back('x');
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
    std::cout<< "  1 2 3 4 5 6 7 8" << std::endl;
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
    std::cout<< "  1 2 3 4 5 6 7 8" << std::endl;
    
    std::cout<< "I " << i << " J " << j << std::endl;

}
