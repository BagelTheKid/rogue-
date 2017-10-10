//
//  map.hpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/10/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <array>
#include <list>
#include <tuple>
#include "enums.h"
#include "room.hpp"
#include "square.hpp"

using namespace std;

class Map {
private:
    int _w;
    int _h;
    Tile* _map;
    int _room;
    void init();
    bool makeRoom(int& x, int& y, Direction& dir);
    bool isWall(int& x, int& y, int& width, int& height, int& xpos, int& ypos, Direction& dir);
    Direction randomDirection();
    list<tuple<Square, Direction, Tile>> getSurroundings(int& x, int& y);
    Tile getTile(int& x, int&y);
    string getTileChar(Tile& t);
    
    
public:
    Map(int& w, int& h, int& rooms);
    ~Map();
    void createMap();
    string toString();
    
};

#endif /* map_hpp */
