#include "Ball.h"
#include <iostream>
#include "windows.h"
#include "conio.h"
#include "SetCursorPosition.h"
#include "Player.h"
#include <random>
#include "time.h"

std::random_device rd;
std::mt19937 mersenne(time(0));
std::uniform_int_distribution<> rdmVel(-1, 1);
std::uniform_int_distribution<> rdmPosY(10, 20);
std::uniform_int_distribution<> rdmPosX(50, 70);

ball::ball()
{
    m_xVel = 1;
    m_yVel = 1;
    m_xPos = 60;
    m_yPos = 15;
}

ball::~ball()
{
}

void ball::update(int Player1PosX, int Player1PosY, int Player2PosX, int Player2PosY)
{
    if(!collDet(Player1PosX, Player1PosY, Player2PosX, Player2PosY))
        eraseBall();
    m_yPos += m_yVel;
    m_xPos += m_xVel;
    draw();
    setCursorPosition(1,1);
}

void ball::respawn()
{
    clearBehind();
    m_xVel = 0;
    m_yVel = 0;
    while(m_yVel == 0)
        m_yVel = rdmVel(mersenne);
    while(m_xVel == 0)
        m_xVel = rdmVel(mersenne);
    m_yPos = rdmPosY(mersenne);
    m_xPos = rdmPosX(mersenne);
}

void ball::eraseBall()
{
    int tempX = m_xPos;
    int tempY = m_yPos;
    setCursorPosition(tempX, tempY);
    std::cout << " ";
}

void ball::clearBehind()
{
//    char temp = 205;
    setCursorPosition(m_xPos, m_yPos);
    std::cout << " ";
}

void ball::draw()
{
    int tempX = m_xPos;
    int tempY = m_yPos;
    setCursorPosition(tempX, tempY);
    char Ball = 254;
    std::cout << Ball;
}

bool ball::collDet(int Player1PosX, int Player1PosY, int Player2PosX, int Player2PosY)
{
    if(m_yPos == 28) m_yVel *= -1;
    else if(m_yPos == 1) m_yVel *= -1;
    if(m_xPos == 119) m_xVel *= -1;
    else if(m_xPos == 0) m_xVel *= -1;

    if(m_yPos > 29)
    {
        m_yPos = 28;
        m_yVel *= -1;
        char temp;
        for(int i = (m_xPos - 5); i < (m_xPos + 5); ++i)
        {
            temp = 205;
            setCursorPosition(i, 0);
            std::cout << temp;
            setCursorPosition(i, 29);
            std::cout << temp;
        }
        return true;
    }
    else if(m_yPos < 0)
    {
        m_yPos = 1;
        m_yVel *= -1;
        char temp;
        for(int i = (m_xPos - 5); i < (m_xPos + 5); ++i)
        {
            temp = 205;
            setCursorPosition(i, 0);
            std::cout << temp;
            setCursorPosition(i, 29);
            std::cout << temp;
        }
        return true;
    }

    std::uniform_int_distribution<> rdmVelChange(-25, 25);

    if((m_xPos + m_xVel) == Player1PosX && m_yPos >= Player1PosY && m_yPos <= (Player1PosY + 11))
    {
        m_xVel *= -1;
        m_yVel = rdmVelChange(mersenne) / 10;
        while(m_yVel < 1 && m_yVel > -1) m_yVel = rdmVelChange(mersenne) / 10;
    }

    else if((m_xPos + m_xVel) == Player2PosX && m_yPos >= Player2PosY && m_yPos <= (Player2PosY + 11))
    {
        m_xVel *= -1;
        m_yVel = rdmVelChange(mersenne) / 10;
        while(m_yVel < 1 && m_yVel > -1) m_yVel = rdmVelChange(mersenne) / 10;
    }
    return false;
}
