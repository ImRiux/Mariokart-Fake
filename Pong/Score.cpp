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
        if(index) temp3 -= (temp1 * 1000 + temp2 * 100); // Do this if m_score > 99. If score is < 999 temp1 will be zero
        temp3 /= 10;
        singleDigits[index] = temp3;
        ++index;
    }
    if(m_score >= 0)
    {
        temp4 = m_score;
        if(index) temp4 -= (temp1 * 1000 + temp2 * 100 + temp3 * 10);  // Do this if m_score > 9. If score is < 99 temp1 and temp2 will be zero
        singleDigits[index] = temp4;
        ++index;
    }
}

void score::drawScore()
{
    int digitsToDraw = length();
    int x{0};
    getDigits();
    int tempScorePos = m_scorePosX;
    while(digitsToDraw)
    {
        --digitsToDraw;
        int currentDigit = singleDigits[x];
        ++x;
        std::string fileName;
        switch(currentDigit)
        {
        case 0:
            fileName = "Digits/Zero.txt";
            break;
        case 1:
            fileName = "Digits/One.txt";
            break;
        case 2:
            fileName = "Digits/Two.txt";
            break;
        case 3:
            fileName = "Digits/Three.txt";
            break;
        case 4:
            fileName = "Digits/Four.txt";
            break;
        case 5:
            fileName = "Digits/Five.txt";
            break;
        case 6:
            fileName = "Digits/Six.txt";
            break;
        case 7:
            fileName = "Digits/Seven.txt";
            break;
        case 8:
            fileName = "Digits/Eight.txt";
            break;
        case 9:
            fileName = "Digits/Nine.txt";
            break;
        }
        std::ifstream DigitTextFile;
        DigitTextFile.open(fileName);
        char digitInstructions[45];
        DigitTextFile >> digitInstructions;
        char square = 219;
        char half = 220;
        int x = 0;
        int tempScorePosCopy = tempScorePos;
        int tempPosY = m_scorePosY;
        setCursorPosition(tempScorePosCopy, tempPosY);
        while(digitInstructions[x] != '3')
        {
            switch(digitInstructions[x])
            {
            case '0':
//                setCursorPosition((++tempScorePos), tempPosY);
                std::cout << " ";
                break;
            case '1':
                std::cout << square;
                break;
            case '2':
                tempScorePosCopy = tempScorePos;
                setCursorPosition(tempScorePosCopy, (++tempPosY));
                break;
            case '4':
                std::cout << half;
                break;
            }
            ++x;
        }
//        std::cout << "\n\n";
        tempScorePos += 7;
    }
}
