//
//  main.cpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/4/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "room.hpp"
#include "enums.h"
#include "square.hpp"

int main(int argc, const char * argv[]) {
    int y = 1;
    int x = 1;
    int width = 5;
    int height = 5;
    Direction d = Direction::South;
    string s = "";
    
    Room r = *new Room(y, x, width, height, d);
    vector<Square> room = r.getRoom();
    long size = room.size();
    std::stringstream str;
    
    for (int i = 0; i < size; i++) {
        str << "Point " << i << ": X - " << room.at(i).GetX() << ", Y - " << room.at(i).GetY() << "\n";
        s.append(str.str());
    }
    std::cout << s << std::endl;
    return 0;
}
