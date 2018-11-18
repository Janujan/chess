//
//  main.cpp
//  chess
//
//  Created by Janujan Selva on 2018-11-18.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "player.hpp"

using namespace std;
int main()
{
    string name = "Jay";
    Player P = Player(name);
    
    cout <<"Player Name: " << P.getName() << endl;
    
    vector<int> piece_status = P.getPieces();
    for(int i = 0; i < PIECE_NUM; i++)
    {
        cout << "Piece " << i + 1 << " " << piece_status[i] << endl;
    }
    return 0;
}
