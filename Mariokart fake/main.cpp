#include <iostream>
#include "conio.h"
#include "windows.h"
#include "Map.h"

int x{0}, y{0}, x2{1}, y2{0};
int lastX{0}, lastY{0}, lastX2{0}, lastY2{0};


enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
Direction dir2;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Draw();
void Input();
void Logic();
void Setup();
void drawMap();
void drawMap(int x, int y);

int main()
{
    Setup();
    while(true)
    {
        Draw();
        Input();
        Logic();
        Sleep(1000);
    }

}
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void Setup()
{
    drawMap();
}


void Draw()
{
    char mapSaveP1 = Map[x][y];
    char mapSaveP2 = Map[x2][y2];

    if(lastX != x || lastY != y)
    {
        setCursorPosition(x, y);
        std::cout << " ";
        setCursorPosition(x, y);
        SetConsoleTextAttribute(hConsole, 14); // Player 1 is yellow
        std::cout << Player;
        setCursorPosition(lastX, lastY);
        drawMap(lastX, lastY);
    }

    if(lastX2 != x2 || lastY2 != y2)
    {
        setCursorPosition(x2, y2);
        SetConsoleTextAttribute(hConsole, 11); // Player 2 is cyan
        std::cout << Player;
        setCursorPosition(lastX2, lastY2);
        drawMap(lastX2, lastY2);
    }
    setCursorPosition(32, 1);
    SetConsoleTextAttribute(hConsole, 15); // Resetting the console color

}

void drawMap()
{
    for(int i = 0; i < mapSize; i++)
        {
            for(int j = 0; j < mapSize; j++)
            {
                switch(Map[i][j])
                {
                case 'G':
                    SetConsoleTextAttribute(hConsole, 2);
                    std::cout << Gras;
                    break;
                case 'W':
                    SetConsoleTextAttribute(hConsole, 23);
                    std::cout << Water;
                    break;
                case 'F':
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << FinishLine;
                    break;
                case 'C':
                    SetConsoleTextAttribute(hConsole, 13);
                    std::cout << Checkpoint;
                    break;
                case 'R':
                    SetConsoleTextAttribute(hConsole, 128);
                    std::cout << Checkpoint;
                    break;
                case 'B':
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << Booster;
                    break;
                default:
                    std::cout << Map[i][j];
                }
                SetConsoleTextAttribute(hConsole, 15);
            }
            std::cout << "\n";
        }
}

void drawMap(int x, int y)
{
    switch(Map[y][x])
    {
    case 'G':
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << Gras;
        break;
    case 'W':
        SetConsoleTextAttribute(hConsole, 23);
        std::cout << Water;
        break;
    case 'F':
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << FinishLine;
        break;
    case 'C':
        SetConsoleTextAttribute(hConsole, 13);
        std::cout << Checkpoint;
        break;
    case 'R':
        SetConsoleTextAttribute(hConsole, 128);
        std::cout << Checkpoint;
        break;
    case 'B':
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << Booster;
        break;
    default:
        std::cout << Map[y][x];
    }
    SetConsoleTextAttribute(hConsole, 15);
}


void Logic()
{
    lastX = x;
    lastY = y;
    lastX2 = x2;
    lastY2 = y2;

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    x > mapSize ? x = mapSize : x = x; // Setzt x zurück, wenn Spieler eins rechts außerhalb der map ist
    y > mapSize ? y = mapSize : y = y; // Setzt y zurück, wenn Spieler eins unten außerhalb der map ist
    x < 0 ? x = 0 : x = x; // Setzt x zurück, wenn Spieler eins links außerhalb der map ist
    y < 0 ? y = 0 : y = y; // Setzt y zurück, wenn Spieler eins oben außerhalb der map ist
    switch (dir2)
    {
    case LEFT:
        x2--;
        break;
    case RIGHT:
        x2++;
        break;
    case UP:
        y2--;
        break;
    case DOWN:
        y2++;
        break;
    default:
        break;
    }
    x2 > mapSize ? x2 = mapSize : x2 = x2; // Setzt x2 zurück, wenn Spieler zwei rechts außerhalb der map ist
    y2 > mapSize ? y2 = mapSize : y2 = y2; // Setzt y2 zurück, wenn Spieler zwei unten außerhalb der map ist
    x2 < 0 ? x2 = 0 : x2 = x2; // Setzt x2 zurück, wenn Spieler zwei links außerhalb der map ist
    y2 < 0 ? y2 = 0 : y2 = y2; // Setzt y2 zurück, wenn Spieler zwei oben außerhalb der map ist
}

void Input()
{
     if(_kbhit())
    {
        switch(_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'i':
            dir2 = UP;
            break;
        case 'j':
            dir2 = LEFT;
            break;
        case 'k':
            dir2 = DOWN;
            break;
        case 'l':
            dir2 = RIGHT;
            break;
        default:
            dir = STOP;
            break;
        }
    }
}
