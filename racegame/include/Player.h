#include <string>
#include "References.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        std::string name;
        unsigned char car;
        int xPosition;
        int yPosition;
        int lastXPosition;
        int lastYPosition;
        Direction dir = DIRECTION_STOP;
    public:
        Player();
        ~Player();
        void setName(std::string name);
        void setCar(unsigned char car);
        void setXPosition(int x);
        void setLastXPostion(int x);
        void setYPosition(int y);
        void setLastYPosition(int y);
        void setDirection(Direction dir);

        void changeXPosition(int x);
        void changeYPosition(int y);

        std::string getName() const;
        unsigned char getCar() const;
        int getXPosition() const;
        int getLastXPosition() const;
        int getYPosition() const;
        int getLastYPosition() const;
        Direction getDirection() const;
};

#endif // PLAYER_H
