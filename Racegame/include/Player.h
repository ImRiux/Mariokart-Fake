#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

enum Direction {DIRECTION_STOP, DIRECTION_UP, DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_RIGHT};

class Player {
    private:
        Direction m_dir;
        std::string m_name = "";
        int m_xPosition;
        int m_yPosition;
        int m_lastXPosition;
        int m_lastYPosition;
        int m_round = 1;
        unsigned char m_car = ' ';
        bool m_crashed = false;
    public:
        Player();
        ~Player();
        void drawPlayer(Player &player);

        void changeXPosition(int x) {m_xPosition += x;}
        void changeYPosition(int y) {m_yPosition += y;}
        void changeRound(int round) {m_round += round;}

        void setDir(Direction dir) {m_dir = dir;}
        void setName(std::string name) {m_name = name;}
        void setXPosition(int x) {m_xPosition = x;}
        void setYPosition(int y) {m_yPosition = y;}
        void setLastXPosition(int x) {m_lastXPosition = x;}
        void setLastYPosition(int y) {m_lastYPosition = y;}
        void setCar(unsigned char car) {m_car = car;}
        void setCrashed(bool crashed) {m_crashed =  crashed;}

        Direction getDir() const {return m_dir;}
        std::string getName() const {return m_name;}
        int getXPosition() const {return m_xPosition;}
        int getYPosition() const {return m_yPosition;}
        int getLastXPosition() const {return m_lastXPosition;}
        int getLastYPosition() const {return m_lastYPosition;}
        int getRound() const {return m_round;}
        unsigned char getCar() const {return m_car;}
        bool isCrashed() const {return m_crashed;}
};

#endif // PLAYER_H
