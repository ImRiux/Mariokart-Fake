#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Score.h"
#include "Directions.h"

class player{
private:
    int m_yPos, m_xPos;
    float m_vel{1.0};
    char m_inputUP, m_inputDOWN;
    int scoreX;

public:
    score playerScore;
    player(int yPos, int xPos, int inputUP, int inputDOWN, int scoreX);
    ~player();
    void score();
    void Move(direction dirOfMove);
    bool collDet();
    void Erase();
    void draw();
    void input();
    float getPosY() {return m_yPos; };
    float getPosX(){ return m_xPos; };
    void setVel(float vel);

};

#endif // PLAYER_H_INCLUDED
