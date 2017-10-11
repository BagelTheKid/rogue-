//
//  main.cpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/4/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#include <iostream>
#include "room.hpp"
#include "enums.h"

int main(int argc, const char * argv[]) {
    int y = 1;
    int x = 1;
    int width = 80;
    int height = 60;
    Direction d = Direction::South;
    string room = "";
    
    Room r = *new Room(y, x, width, height, d);
    
    for (int ydx = 0; ydx < height; ydx++) {
        for (int xdx = 0; xdx < width; xdx++) {
            
        }
    }
    return 0;
}
