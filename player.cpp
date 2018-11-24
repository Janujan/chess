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
    
    //initialize pawns
    for(int i = 0; i < 8; i++)
    {
        piece_status.push_back(std::make_pair("p" + std::to_string(i), 1));
    }
    

    piece_status.push_back(std::make_pair("r1", 1));
    piece_status.push_back(std::make_pair("k1", 1));
    piece_status.push_back(std::make_pair("b1", 1));
    piece_status.push_back(std::make_pair("qu", 1));
    piece_status.push_back(std::make_pair("r2", 1));
    piece_status.push_back(std::make_pair("k2", 1));
    piece_status.push_back(std::make_pair("b2", 1));
    piece_status.push_back(std::make_pair("ki", 1));
    
}

std::string Player::getName()
{
    return name;
}

std::vector<std::string> Player::pieceNames()
{
    std::vector<std::string> names;
    
    for(int i =0; i < 16; i++)
    {
        names.push_back(std::get<0>(piece_status[i]));
    }
    return names;
}

//Search if the piece is valid
int Player::validPiece(std::string piece)
{
    int flag = 0;
    int idx = 0;
    while(!flag && idx < 16)
    {
        std::string name = std::get<0>(piece_status[idx]);
        int status = std::get<1>(piece_status[idx]);
        if(name == piece && status == 1)
        {
            flag = 1;
        }
        idx++;
    }
    
    return (idx < 16)?flag:0;
    
}
