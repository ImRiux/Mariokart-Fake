#include "Player.h"
#include "SetCursorPosition.h"
#include "fstream"
#include "windows.h"
#include "conio.h"
#include <iostream>

player::player(int yPos, int xPos, int inputUP, int inputDOWN, int scoreX) : playerScore(scoreX, 10)
{
    m_yPos = yPos;
    m_xPos = xPos;
    m_inputUP = inputUP;
    m_inputDOWN = inputDOWN;
}

player::~player()
{
}

void player::score()
{
    playerScore.add(1);
}

void player::input()
{
    char input;
    if(_kbhit())
    {
        input = _getch();
        if(input == 0 || input == 0xE0) input = _getch();
        if(input == m_inputUP) Move(UP);
        else if(input == m_inputDOWN) Move(DOWN);
    }
}

void player::Move(direction dirOfMove)
{
    int temp = m_yPos;
    if(dirOfMove == UP) m_yPos -= m_vel;
    else if(dirOfMove == DOWN) m_yPos += m_vel;
    if(collDet()) m_yPos = temp;
}

void player::setVel(float vel)
{
    m_vel = vel;
}

bool player::collDet()
{
    if(m_yPos < 1 || m_yPos > 17) return true;
    else return false;
}

void player::Erase()
{
    for(int i = 1; i < 29; i++)
    {
        setCursorPosition(m_xPos, i);
        if(!(i >= m_yPos && i <= (m_yPos + 11)))
            std::cout << " ";
    }
}

void player::draw()
{
    std::ifstream PlayerFile;
    PlayerFile.open("Player.txt");
    char playerInstructions[25];
    PlayerFile >> playerInstructions;
    setCursorPosition(m_xPos, m_yPos);
    int index{0}, temp{m_yPos};
    char square = 219;
    while(playerInstructions[index] != 'X') // This while loop draws the player at its new position
    {
        switch(playerInstructions[index])
        {
        case '0':
            std::cout << square;
            break;
        case '1':
            setCursorPosition(m_xPos, (++temp));
            break;
        }
        ++index;
    }
    std::cout << "\n";
    setCursorPosition((m_xPos + 1), temp);
    std::cout << " ";
    PlayerFile.close();
}
