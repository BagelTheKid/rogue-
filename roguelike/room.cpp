//
//  room.cpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/8/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#include "room.hpp"
#include "enums.h"

Room::Room(int& x, int& y, int& w, int& l, Direction& dir) :
_x(x), _y(y), _w(w), _l(l), _dir(dir) {
    createRoom();
}

Room::~Room() {
}

void Room::createRoom() {
    int xS = 0;
    int yS = 0;
    switch(_dir) {
        case Direction::North:
            for (xS = getLowerBounds(_x, _w); xS < getUpperBounds(_x, _w); xS++) {
                for (yS = _y; yS > _y - _l; yS--) {
                    _room.push_back(Square(xS, yS));
                }
            }
            break;
        case Direction::East:
            for (xS = _x; xS < _x + _w; xS++) {
                for (yS = getLowerBounds(_y, _l); yS < getUpperBounds(_y, _l); yS++) {
                    _room.push_back(Square(xS, yS));
                }
            }
            break;
        case Direction::South:
            for (xS = getLowerBounds(_x, _w); xS < getUpperBounds(_x, _w); xS++) {
                for (yS = _y; yS < _y + _l; yS++) {
                    _room.push_back(Square(xS, yS));
                }
            }
            break;
        case Direction::West:
            for (xS = _x; xS > _x - _w; xS--) {
                for (yS = getLowerBounds(_y, _l); yS < getUpperBounds(_y, _l); yS++) {
                    _room.push_back(Square(xS, yS));
                }
            }
            break;
    }
}
