//
//  square.hpp
//  roguelike
//
//  Created by Nicolas Polhamus on 5/5/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#ifndef square_hpp
#define square_hpp

#include <iostream>
#include <stdio.h>
#include "enums.h"

using namespace std;

class Square {
private:
    int _x;
    int _y;
    Tile _t;
public:
    Square(int& X, int& Y);
    ~Square();
    int GetX() const { return _x; };
    int GetY() const { return _y; };
    Tile GetTile() const { return _t; };
    void SetX(const int& x) { _x = x; };
    void SetY(const int& y) { _y = y; };
    void SetTile(const Tile& t) { _t = t; };
};

#endif /* square_hpp */
