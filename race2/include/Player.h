#include "References.h"

#ifndef PLAYER_H
#define PLAYER_H


class Player {
    private:
        int x;
        int y;
    public:
        Player();
        ~Player();
        Direction dir;
        void setX(int x);
        void setY(int y);
        void changeX(int x);
        void changeY(int y);
        int getX() const;
        int getY() const;
};

#endif // PLAYER_H
