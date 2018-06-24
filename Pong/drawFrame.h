#ifndef DRAWFRAME_H_INCLUDED
#define DRAWFRAME_H_INCLUDED

#include "windows.h"
#include "SetCursorPosition.h"
#include <iostream>

void drawFrame(int width, int height, int xPos, int yPos)
{
    system("cls");
    int left, right;
    left = xPos;
    right = (xPos + width);
    int top, bottom;
    top = yPos;
    bottom = (yPos + height);

    char temp;  // These first 12 Lines draw the corners in the order: left upper, right upper, left bottom, right bottom
    setCursorPosition(left, top);
    temp = 201;
    std::cout << temp;
    setCursorPosition(right, top);
    temp = 187;
    std::cout << temp;
    setCursorPosition(left, bottom);
    temp = 200;
    std::cout << temp;
    setCursorPosition(right, bottom);
    temp = 188;
    std::cout << temp;
    for(int i = (left + 1); i < right; ++i) // this for loop draws the horizontal lines of the frame
    {
        temp = 205;
        setCursorPosition(i, top); // draws the upper one
        std::cout << temp;
        setCursorPosition(i, bottom); // draws the bottom one
        std::cout << temp;
    }
    for(int i = (top + 1); i < bottom; ++i) // this loop draws the vertical lines of the frame
    {
        temp = 186;
        setCursorPosition(left, i); // left
        std::cout << temp;
        setCursorPosition(right, i); // right
        std::cout << temp;
    }
}

#endif // DRAWFRAME_H_INCLUDED
