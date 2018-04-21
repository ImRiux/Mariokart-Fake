#ifndef REFERENCES_H_INCLUDED
#define REFERENCES_H_INCLUDED

enum Direction {
    DIRECTION_STOP = 0,
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

enum Mode {
    MODE_NONE = 0,
    MODE_SINGLEPLAYER,
    MODE_MULTIPLAYER,
    MODE_TEN_ROUNDS,
    MODE_DONT_HIT_WALL
};

//available cars
unsigned char dollarCar = 36;
unsigned char starCar = 42;
unsigned char crossCar = 158;
unsigned char yenCar = 190;

#endif // REFERENCES_H_INCLUDED
