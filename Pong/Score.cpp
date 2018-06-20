#include "Score.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include "SetCursorPosition.h"

score::score(int scorePosX, int scorePosY)
{
    m_scorePosX = scorePosX;
    m_scorePosY = scorePosY;
}

score::~score()
{
}

void score::add(int amount)
{
    m_score += amount;
    if(m_score < 0) m_score = 0;
}

int score::getScore()
{
    return m_score;
}

int score::length()
{
    if(m_score > 999) return 4;
    else if(m_score >= 100 && m_score < 1000) return 3;
    else if(m_score >= 10 && m_score < 100) return 2;
    else if(m_score >= 0 && m_score < 10) return 1;
}

void score::getDigits()
{
    int index{0};
    int temp1{0}, temp2{0}, temp3{0}, temp4{0};
    if(m_score > 999)
    {
        temp1 = m_score;
        temp1 /= 1000;
        singleDigits[index] = temp1;
        ++index;
    }
    if(m_score > 99)
    {
        temp2 = m_score;
        if(index) temp2 -= (temp1 * 1000); // Only do this if m_score > 999
        temp2 /= 100;
        singleDigits[index] = temp2;
        ++index;
    }
    if(m_score > 9)
    {
        temp3 = m_score;
        if(index) temp3 -= (temp1 * 1000 + temp2 * 100);
        temp3 /= 10;
        singleDigits[index] = temp3;
        ++index;
    }
    if(m_score >= 0)
    {
        temp4 = m_score;
        if(index) temp4 -= (temp1 * 1000 + temp2 * 100 + temp3 * 10);
        singleDigits[index] = temp4;
        ++index;
    }
}

void score::drawScore()
{
    int digitsToDraw = length();
    int x{0};
    getDigits();
    int temp1 = m_scorePosX;
    while(digitsToDraw)
    {
        --digitsToDraw;
        int currentDigit = singleDigits[x];
        ++x;
        std::string fileName;
        switch(currentDigit)
        {
        case 0:
            fileName = "Zero.txt";
            break;
        case 1:
            fileName = "One.txt";
            break;
        case 2:
            fileName = "Two.txt";
            break;
        case 3:
            fileName = "Three.txt";
            break;
        case 4:
            fileName = "Four.txt";
            break;
        case 5:
            fileName = "Five.txt";
            break;
        case 6:
            fileName = "Six.txt";
            break;
        case 7:
            fileName = "Seven.txt";
            break;
        case 8:
            fileName = "Eight.txt";
            break;
        case 9:
            fileName = "Nine.txt";
            break;
        }
        std::ifstream DigitTextFile;
        DigitTextFile.open(fileName);
        char digitInstructions[45];
        DigitTextFile >> digitInstructions;
        char square = 219;
        char half = 220;
        int x = 0;
        int temp1copy = temp1;
        int temp2 = m_scorePosY;
        setCursorPosition(temp1copy, temp2);
        while(digitInstructions[x] != '3')
        {
            switch(digitInstructions[x])
            {
            case '0':
//                setCursorPosition((++temp1), temp2);
                std::cout << " ";
                break;
            case '1':
                std::cout << square;
                break;
            case '2':
                temp1copy = temp1;
                setCursorPosition(temp1copy, (++temp2));
                break;
            case '4':
                std::cout << half;
                break;
            }
            ++x;
        }
//        std::cout << "\n\n";
        temp1 += 7;
    }
}
