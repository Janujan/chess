//
//  ChessBoard.hpp
//  chess
//
//  Created by Janujan Selva on 2018-11-22.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#define COL 8
#define ROW 8
class ChessBoard{
private:
    typedef std::vector<char> row;
    std::vector< row > chessboard;
    std::map<int, char> row_pair;
    std::map<int,char>::iterator itr;

public:
    ChessBoard();
    void printBoard();
};
#endif /* ChessBoard_hpp */
