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
#include "player.hpp"
#define COL 8
#define ROW 8
class ChessBoard{
private:
    typedef std::vector<std::string> row;
    
    //piece, row, col
    typedef std::tuple<std::string, int, int> status;
    std::vector< row > chessboard;
    std::map<int, char> row_pair;
    std::map<int,char>::iterator itr;
    std::vector<std::string> pieces;
    void initPieces();
    std::vector<status> piece_status_w, piece_status_b;
    void printPieces();
public:
    ChessBoard();
    void printBoard();
    int isEmpty(int col, int row);
    int move(std::string piece, int col, int row);
};
#endif /* ChessBoard_hpp */
