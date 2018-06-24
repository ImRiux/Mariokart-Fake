#ifndef INTRO_H_INCLUDED
#define INTRO_H_INCLUDED

#include <fstream>
#include <iostream>
#include "windows.h"
#include "Player.h"
#include "Ball.h"
#include "conio.h"
#include <string>
#include "drawFrame.h"

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

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    ifstream ReadAnimation;  // ifstream, i stands for input. Object for reading files
    ReadAnimation.open("Intro/Animation.txt");
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
    ReadLogo.open("Intro/Ponglogo.txt");
    char LogoInstructions[627];    // every line has 57 characters, the are 11 lines ( 57 * 11 = 627 )
    ReadLogo >> LogoInstructions;
    yCoord = -1; // for some reason the first few lines of the logo are blank/whitespaces (idk what I was doing wrong lmao) so I start at -1 to compensate for that
    for(int j = 0; j < 30; j++)
    {
        SetConsoleTextAttribute(hConsole, 0);

        yCoord = 0;
        char temp[57];
        int i2{0};
        SetConsoleTextAttribute(hConsole, 11); // draws the blue PONG
        for(int i = 0; i <= 627; i++)
        {

            if(!(i % 57) && i > 0) { xCoord = j; setCursorPosition(xCoord, yCoord); std::cout << temp; ++yCoord; } // if(!(i % 57)) is true when i is dividable by 57 without rest. 57 is the length of a line of the logo
            switch(LogoInstructions[i])
            {
            case '0':
                temp[i2] = ' ';
                break;
            case '1':
                temp[i2] = halfDown;
                break;
            case '2':
                temp[i2] = halfUp;
                break;
            case '3':
                temp[i2] = square;
                break;
            }
            i2++;
            if(i2 > 56) i2 = 0;
        }
        for(int i = 0; i < 12; i++)
        {
            setCursorPosition(xCoord = (j - 1), i);
            std::cout << "\n";
            setCursorPosition(xCoord = (j - 1), i);
            std::cout << " ";
            setCursorPosition(xCoord = (j + 57), i);
            std::cout << " ";
            setCursorPosition(xCoord = (j + 58), i);
            std::cout << " ";
            setCursorPosition(xCoord = (j + 59), i);
            std::cout << " ";
        }
        i2 = 0;
        yCoord = 1;
        SetConsoleTextAttribute(hConsole, 10); // draws the green PONG
        for(int i = 0; i <= 627; i++)
        {

            if(!(i % 57) && i > 0) { xCoord = (59 - j); setCursorPosition(xCoord, yCoord); std::cout << temp; ++yCoord;} // if(!(i % 57)) is true when i is dividable by 57 without rest. 57 is the length of a line of the logo
            switch(LogoInstructions[i])
            {
            case '0':
                temp[i2] = ' ';
                break;
            case '1':
                temp[i2] = halfDown;
                break;
            case '2':
                temp[i2] = halfUp;
                break;
            case '3':
                temp[i2] = square;
                break;
            }
            i2++;
            if(i2 > 56) i2 = 0;
        }
        for(int i = 0; i < 12; i++)
        {
            setCursorPosition(xCoord = (116 - j), i);
            std::cout << " ";
            setCursorPosition(xCoord = (117 - j), i);
            std::cout << " ";
            setCursorPosition(xCoord = (118 - j), i);
            std::cout << " ";
        }
        if(j == 29) { for(int m = 0; m < 61; ++m) { setCursorPosition((m + 30), 1); SetConsoleTextAttribute(hConsole, 186); if( LogoInstructions[(m)] == '1')std::cout << halfDown; } } // executes the last iteration of the for loop -
        Sleep(50);  // - it's for aesthetic.. it removes the black outline between the green and the blue PONG, at least between the top lines.
    }
    SetConsoleTextAttribute(hConsole, 7); // 7 is white on black
    Sleep(2500);
    system("cls");


    // Intro done //

    // choosing gamemode //

    drawFrame(19, 10, 50, 10);

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

    drawFrame(19, 10, 50, 10);

    setCursorPosition(51, 11);
    std::cout << "Enter a name";
    if(Gamemode)
    {
        setCursorPosition(51, 14);
        std::cout << "Player 1";
    }
    setCursorPosition(51, 15);
    std::string tempName;
    std::cin >> tempName;
    Player1.setName(tempName);
    if(Gamemode)
    {
        setCursorPosition(51, 17);
        std::cout << "Player 2";
        setCursorPosition(51, 18);
        std::cin >> tempName;
        Player2.setName(tempName);
    }
    system("cls");

    // Name was chosen //

    drawFrame(119, 29, 0, 0);
}


#endif // INTRO_H_INCLUDED
