//
//  enums.h
//  roguelike
//
//  Created by Nicolas Polhamus on 5/4/17.
//  Copyright © 2017 Nicolas Polhamus. All rights reserved.
//

#ifndef enums_h
#define enums_h

enum class Tile {
    DirtFloor = 0,
    DirtWall = 1,
    DirtCorridor = 2,
    WoodDoor = 3,
    StoneWall = 4,
    Upstairs = 5,
    Downstairs = 6,
    Empty = 7
};

enum class Direction {
    North = 0,
    Northeast = 1,
    East = 2,
    Southeast = 3,
    South = 4,
    Southwest = 5,
    West = 6,
    Northwest = 7
};
#endif /* enums_h */
