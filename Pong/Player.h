#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Score.h"
#include "Directions.h"
#include <string>

class player{
private:
    int m_yPos, m_xPos;
    float m_vel{1.0};
    char m_inputUP, m_inputDOWN;
    int scoreX;
    std::string m_name;

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
    std::string getName() { return m_name; };
    void setVel(float vel);
    void setName(std::string name) { m_name = name; }

};

#endif // PLAYER_H_INCLUDED
