//
//  player.hpp
//  chess
//
//  Created by Janujan Selva on 2018-11-18.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define PIECE_NUM 16
class Player{
private:
    typedef std::pair<std::string, int> piece;
    std::string name;
    std::vector<piece> piece_status;
public:
    Player(std::string player_name = "w");
    std::vector<std::string> pieceNames();
    int validPiece(std::string piece);
    std::string getName();
};

#endif /* player_hpp */
