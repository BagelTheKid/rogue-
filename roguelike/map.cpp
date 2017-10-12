//
//  map.cpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/10/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#include "map.hpp"
#include <random>
#include <math.h>

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
    int mapLength = _h;
    Tile* mapMap = _map;
    mt19937 gen (123);
    uniform_real_distribution<int> random(3, 10);
    // Used in room generation
    int width = random(gen);
    int height = random(gen);
    
    const Tile floor = Tile::DirtFloor;
    const Tile wall = Tile::DirtWall;
    
    // Making the room
    Room room = Room(x, y, width, height, dir);
    vector<Square> sqr = room.getRoom();
    long size = sqr.size();
    
    for (int i = 0; i < size; i++) {
        if (sqr.at(i).GetY() < 0 || sqr.at(i).GetY() > mapLength || sqr.at(i).GetX() < 0 || sqr.at(i).GetX() > mapWidth || (mapMap[sqr.at(i).GetX() + mapWidth * sqr.at(i).GetX()]) != Tile::Empty) {
            result = false;
        }
    }
    
    if (result) {
        for (int i = 0; i < size; i++) {
            int pos = sqr.at(i).GetX() + mapWidth * sqr.at(i).GetY();
            _map[pos] = isWall(x, y, width, height, sqr.at(i).GetX(), sqr.at(i).GetY(), dir) ?
            wall : floor;
        }
    }
    
    return result;
}

bool Map::isWall(int& x, int& y, int& width, int& height, int xpos, int ypos, Direction& dir) {
    bool res = false;
    switch (dir) {
        case Direction::North:
            res = xpos == floor(x - width / 2) || xpos == floor(x + (width - 1) / 2) || ypos == y || ypos == y - height + 1;
            break;
        case Direction::East:
            res = xpos == x || xpos == x + width - 1 || ypos == floor(y - height / 2) || ypos == floor(y + (height - 1) / 2);
            break;
        case Direction::South:
            res = xpos == floor(x - width / 2) || xpos == floor(x + (width - 1) / 2) || ypos == y || ypos == y + height - 1;
            break;
        case Direction::West:
            res = xpos == x || xpos == x - width + 1 || ypos == floor(y - height / 2) || ypos == floor(y + (height - 1) / 2);
            break;
    }
    return res;
}

Direction Map::randomDirection() {
    mt19937 gen (123);
    uniform_real_distribution<int> random(0, 4);
    int r = random(gen);
    Direction dir = Direction::North;
    
    switch (r) {
        case 0:
            dir = Direction::North;
            break;
        case 1:
            dir = Direction::East;
            break;
        case 2:
            dir = Direction::South;
            break;
        case 3:
            dir = Direction::West;
            break;
    }
    
    return dir;
}

vector<tuple<Square, Direction, Tile>> Map::getSurroundings(int& x, int& y) {
    int north = y + 1;
    int east = x - 1;
    int south = y - 1;
    int west = x + 1;
    
    vector<tuple<Square, Direction>> surroundings = {
        std::make_tuple(Square(x, north), Direction::North),
        std::make_tuple(Square(east, y), Direction::East),
        std::make_tuple(Square(x, south), Direction::South),
        std::make_tuple(Square(west, y), Direction::West)
    };
    
    vector<tuple<Square, Direction>> surroundingsInBounds;
    for (vector<tuple<Square, Direction>>::iterator i = surroundings.begin(); i != surroundings.end(); ++i) {
        Square s = get<0>(*i);
        if (s.GetX() > 0 && s.GetX() < _w && s.GetY() > 0 && s.GetY() < _h) {
            surroundingsInBounds.push_back(*i);
        }
    }
    
    vector<tuple<Square, Direction, Tile>> surroundingsWithTiles;
    for (vector<tuple<Square, Direction>>::iterator it = surroundingsInBounds.begin(); it != surroundingsInBounds.end(); ++it) {
        surroundingsWithTiles.push_back(std::make_tuple(get<0>(*it), get<1>(*it), getTile(get<0>(*it).GetX(), get<0>(*it).GetY())));
    }
    
    return surroundingsWithTiles;
}

Tile Map::getTile(int x, int y) {
    Tile mapTile;
    try {
        mapTile = _map[x + _w * y];
    } catch (const std::exception& exc) {
        throw exc.what();
    } catch (const std::range_error exc) {
        throw exc.what();
    }
    
    return mapTile;
}

string Map::getTileChar(Tile& t) {
    string tile;
    switch (t) {
        case Tile::Empty:
            tile = " ";
            break;
        case Tile::DirtFloor:
            tile = (char) 9472;
            break;
        case Tile::DirtWall:
            tile = (char) 9474;
            break;
        case Tile::DirtCorridor:
            tile = (char) 9552;
            break;
        case Tile::StoneWall:
            tile = (char) 9553;
            break;
        case Tile::WoodDoor:
            tile = (char) 9532;
            break;
        case Tile::Downstairs:
            tile = (char) 8690;
            break;
        case Tile::Upstairs:
            tile = (char) 8689;
            break;
    }
    
    return tile;
}
