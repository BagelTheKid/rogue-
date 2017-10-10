//
//  map.cpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/10/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#include "map.hpp"
#include <random>

using namespace std;

Map::Map(int& w, int& h, int& rooms)
    : _w(w), _h(h), _room(rooms) {
        _map[_w * _h] = {};
}

Map::~Map() { }

void Map::init() {
    for (int y = 0; y < _h; y++) {
        for (int x = 0; x < _w; x++) {
            if (y == 0 || y == _h - 1 || x == 0 || x == _w - 1) {
                _map[x + _w * y] = Tile::StoneWall;
            } else {
                _map[x + _w * y] = Tile::Empty;
            }
        }
    }
}

bool Map::makeRoom(int& x, int& y, Direction& dir) {
    bool result = true;
    int mapWidth = _w;
    int mapHeight = _h;
    Tile* mapMap = _map;
    mt19937 gen (123);
    uniform_real_distribution<int> random(3, 10);
    int width = random(gen);
    int height = random(gen);
    
    
    return result;
}

