//
//  player.cpp
//  chess
//
//  Created by Janujan Selva on 2018-11-18.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#include "player.hpp"

//Initialize name and piece status
Player::Player(std::string player_name)
{
    name = player_name;
    
    for(int i = 0; i < PIECE_NUM; i++)
    {
        piece_status.push_back(1);
    }
}

std::string Player::getName()
{
    return name;
}

std::vector<int> Player::getPieces()
{
    return piece_status;
}
