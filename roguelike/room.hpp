//
//  room.hpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/8/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "enums.h"
#include "square.hpp"

using namespace std;

class Room {
private:
    int _x;
    int _y;
    int _w;
    int _l;
    Direction _dir;
    vector<Square> _room;
    void createRoom();
    int getLowerBounds(int& i, int& len) { return floor(i - len / 2); };
    int getUpperBounds(int& i, int& len) { return floor(i + (len +1) / 2); };
    
public:
    Room(int& x, int& y, int& w, int& l, Direction& dir);
    ~Room();
    vector<Square> getRoom() const { return _room; };
};

#endif /* room_hpp */
