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
    std::string name;
    std::vector<int> piece_status;
public:
    Player(std::string player_name = "w");
    std::vector<int> getPieces();
    std::string getName();
    enum Piece{p1, p2, p3, p4, p5, p6, p7, p8, kn1, kn2, b1, b2, r1, r2, queen, king };
};

#endif /* player_hpp */
