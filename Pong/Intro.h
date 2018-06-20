#ifndef INTRO_H_INCLUDED
#define INTRO_H_INCLUDED

#include <fstream>
#include <iostream>
#include "windows.h"
#include "Player.h"
#include "Ball.h"
#include "conio.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

ball Ball;                            // ball gets defined, no variables needed since there will always only be one ball so the numbers are always the same
player Player1(15, 28, 72, 80, 1);     // first player is defined with ( Y - Coordinates, X - Coordinates, button to go up, button to got down, score )
player Player2(15, 89, 119, 115, 91);

enum gamemode
{
    SINGLE_PLAYER = 0,
    MULTI_PLAYER,
};

gamemode Gamemode;

int charToInt(char input) // pretty self-explanatory function.. You input a char 'number' and it outputs the number as an integer :D
{

    int output;
    switch(input)
    {
    case '0':
        output = 0;
        break;
    case '1':
        output = 1;
        break;
    case '2':
        output = 2;
        break;
    case '3':
        output = 3;
        break;
    case '4':
        output = 4;
        break;
    case '5':
        output = 5;
        break;
    case '6':
        output = 6;
        break;
    case '7':
        output = 7;
        break;
    case '8':
        output = 8;
        break;
    case '9':
        output = 9;
        break;
    }
    return output;
}

void Setup()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);  // These five lines make the cursor invisible. I don't understand how it works, I just copied it from the internet..
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = 0;
    lpCursor.dwSize = 1;
    SetConsoleCursorInfo(console,&lpCursor);

    ifstream ReadAnimation;  // ifstream, i stands for input. Object for reading files
    ReadAnimation.open("Animation.txt");
    char AnimationInstructions[800]; // I don't know the exact length of the string in Animation.txt but 400 was too small so I just went for 800...
    ReadAnimation >> AnimationInstructions;
    int index{0};
    char square = 219, ball = 254, halfUp = 223, halfDown = 220;
    int xCoord{0}, yCoord{0}; // Coordinates for the individual ASCII characters.
    while(AnimationInstructions[index] != 'X')
    {
        switch(AnimationInstructions[index])
        {
        case '0':
            std::cout << " ";
            break;
        case '1':
            std::cout << square;
            break;
        case '2':
            std::cout << ball << "\n";
            setCursorPosition(--xCoord, yCoord); // << "\n"; setCursorPosition(--xCoord, yCoord); std::cout << " "; after outputting the ball char, it prints a new line, then moves the cursor to where it just printed the new line
            std::cout << " ";                    // and then replaces it with a whitespace. The newline is output to remove the glitch with the colored lines but we don't actually want a \n there so its removed afterwards.
            break;
        case '3':
            ++yCoord;
            setCursorPosition(xCoord, yCoord); // used instead of a \n because those would affect everything in the same line, that's to the right of the \n, which would fuck up everything.
            break;
        case '4':
            Sleep(25); // waits 25ms
            break;
        case '5': // X - Coordinates are stored between two 5s (example: 5135 -> X = 13). This section reads those coordinates.. that's it
            int temp1, temp2; // temp1 and 2 are just there to convert two chars into a single integer
            ++index;
            temp1 = charToInt(AnimationInstructions[index]);
            ++index;
            temp2 = charToInt(AnimationInstructions[index]);
            xCoord = ((temp1 * 10) + temp2);
            ++index;
            if(!(AnimationInstructions[index] == '5')) { std::cout << "X Coordinates not read correctly\n"; std::cout << AnimationInstructions[index]; system("Pause"); } // I thought of making a while loop that reads every number after a 5 until it finds another 5,
            setCursorPosition(xCoord, yCoord); // but that doesn't work because X - Coordinates can be something like 5 or 25 and the program wouldn't know that the 5 is part of the coordinate...
            break;
        case '6': // same thing as with the '5' but instead of X - Coordinates it's Y - Coordinates
            ++index;
            temp1 = charToInt(AnimationInstructions[index]);
            ++index;
            temp2 = charToInt(AnimationInstructions[index]);
            yCoord = ((temp1 * 10) + temp2);
            ++index;
            if(!(AnimationInstructions[index] == '6')) { std::cout << "Y Coordinates not read correctly\n"; std::cout << AnimationInstructions[index]; system("Pause"); }
            setCursorPosition(xCoord, yCoord);
            break;
        }
        ++index;
    }
    ReadAnimation.close(); // closing the .txt

    // Line 117 - 213 only do one thing: draw the logo (Pong)

    ifstream ReadLogo;
    ReadLogo.open("Ponglogo.txt");
    char LogoInstructions[627];    // every line has 57 characters, the are 11 lines ( 57 * 11 = 627 )
    ReadLogo >> LogoInstructions;
    yCoord = -1; // for some reason the first few lines of the logo are blank/whitespaces (idk what I was doing wrong lmao) so I start at -1 to compensate for that
    for(int j = 0; j < 30; j++)
    {
        yCoord = 0;
        SetConsoleTextAttribute(hConsole, 0); // These first two for loops have a color attribute of 0, which is black on black. They overwrite the colored text. So it's similar to clearing the screen.
        for(int i = 0; i < 627; i++) // This one erases the right one (green)
        {
            if(!(i % 57)) { xCoord = (59 - j + 1) ; ++yCoord; setCursorPosition(xCoord, yCoord); }

            switch(LogoInstructions[i])
            {
            case '0':
                std::cout << " ";
                break;
            case '1':
                std::cout << halfDown;
                break;
            case '2':
                std::cout << halfUp;
                break;
            case '3':
                std::cout << square;
                break;
            }
        }
        yCoord = -1;
        SetConsoleTextAttribute(hConsole, 0);
        for(int i = 0; i < 627; i++) // This one erases the left one (light blue)
        {
            if(!(i % 57)) { xCoord = j - 1; ++yCoord; setCursorPosition(xCoord, yCoord); }

            switch(LogoInstructions[i])
            {
            case '1':
                std::cout << halfDown;
                break;
            case '2':
                std::cout << halfUp;
                break;
            case '3':
                std::cout << square;
                break;
            }
        } // Btw I know it flickers like crazy but tbh idk a better way of erasing them so yea

        yCoord = -1;
        SetConsoleTextAttribute(hConsole, 11); // draws the blue PONG
        for(int i = 0; i < 627; i++)
        {
            if(!(i % 57)) { xCoord = j; ++yCoord; setCursorPosition(xCoord, yCoord); } // if(!(i % 57)) is true when i is dividable by 57 without rest. 57 is the length of a line of the logo

            switch(LogoInstructions[i])
            {
            case '0':
                std::cout << " ";
                break;
            case '1':
                std::cout << halfDown;
                break;
            case '2':
                std::cout << halfUp;
                break;
            case '3':
                std::cout << square;
                break;
            }
        }
        yCoord = 0;
        SetConsoleTextAttribute(hConsole, 10); // draws the green PONG
        for(int i = 0; i < 627; i++)
        {
            if(!(i % 57)) { xCoord = (59 - j) ; ++yCoord; setCursorPosition(xCoord, yCoord); }

            switch(LogoInstructions[i])
            {
            case '0':
                std::cout << " ";
                break;
            case '1':
                std::cout << halfDown;
                break;
            case '2':
                std::cout << halfUp;
                break;
            case '3':
                std::cout << square;
                break;
            }
        }
        if(j == 29) { for(int m = 0; m < 61; ++m) { setCursorPosition((m + 30), 1); SetConsoleTextAttribute(hConsole, 186); if( LogoInstructions[(m)] == '1')std::cout << halfDown; } } // executes the last iteration of the for loop -
        Sleep(25);  // - it's for aesthetic.. it removes the black outline between the green and the blue PONG, at least between the top lines.
    }
    SetConsoleTextAttribute(hConsole, 7); // 7 is white on black
    Sleep(2500);
    system("cls");


    // Intro done //

    // choosing gamemode //

    char temp;
	setCursorPosition(50, 10);    // Line 30 - 58 are drawing the frame to the screen
	temp = 201;
    cout << temp;               // These first 12 Lines draw the corners in the order: left upper, right upper, left bottom, right bottom
    setCursorPosition(69, 10);
    temp = 187;
    cout << temp;
    setCursorPosition(50, 20);
    temp = 200;
    cout << temp;
    setCursorPosition(69, 20);
    temp = 188;
    cout << temp;
    for(int i = 51; i < 69; ++i) // this for loop draws the horizontal lines of the frame
    {
        temp = 205;
        setCursorPosition(i, 10); // draws the upper one
        cout << temp;
        setCursorPosition(i, 20); // draws the bottom one
        cout << temp;
    }
    for(int i = 11; i < 20; ++i) // this loop draws the vertical lines of the frame
    {
        temp = 186;
        setCursorPosition(50, i); // left
        cout << temp;
        setCursorPosition(69, i); // right
        cout << temp;
    }

    setCursorPosition(51, 11);
    std::cout << "Choose a game mode";
    setCursorPosition(51, 13);
    std::cout << " 1." << " Single-Player";
    setCursorPosition(51, 17);
    std::cout << " 2." << " Multi-Player";

    char input = '0';
    while(input != '1' && input != '2')
    {
        input = _getch();
    }
    system("cls");
    if(input == '1') Gamemode = SINGLE_PLAYER;
    else if(input == '2') Gamemode = MULTI_PLAYER;

    // Gamemode was chosen //

	setCursorPosition(0, 0);    // Line 30 - 58 are drawing the frame to the screen
	temp = 201;
    cout << temp;               // These first 12 Lines draw the corners in the order: left upper, right upper, left bottom, right bottom
    setCursorPosition(119, 0);
    temp = 187;
    cout << temp;
    setCursorPosition(0, 29);
    temp = 200;
    cout << temp;
    setCursorPosition(119, 29);
    temp = 188;
    cout << temp;
    for(int i = 1; i < 119; ++i) // this for loop draws the horizontal lines of the frame
    {
        temp = 205;
        setCursorPosition(i, 0); // draws the upper one
        cout << temp;
        setCursorPosition(i, 29); // draws the bottom one
        cout << temp;
    }
    for(int i = 1; i < 29; ++i) // this loop draws the vertical lines of the frame
    {
        temp = 186;
        setCursorPosition(0, i); // left
        cout << temp;
        setCursorPosition(119, i); // right
        cout << temp;
    }
}


#endif // INTRO_H_INCLUDED
