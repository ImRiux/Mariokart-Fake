#include <iostream>
#include "conio.h"
#include "windows.h"
#include "Map.h"
#include "chrono"

float x{10}, y{10}, x2{15}, y2{15};
float P1VelX{1}, P1VelY{0}, P2VelX{0}, P2VelY{0};
int lastX{0}, lastY{0}, lastX2{0}, lastY2{0};
char inputP1, inputP2;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Draw();
void Input();
void Logic();
void Setup();
void drawMap();
void drawMap(int x, int y);

//using namespace std::chrono;
//high_resolution_clock::time_point t1 = high_resolution_clock::now();

//        high_resolution_clock::time_point t2 = high_resolution_clock::now();
//        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
//        int time = time_span.count() * 10;
//        if(!(time % 10))

int main()
{
    Setup();
    while(true)
    {
        inputP1 = x;
        inputP2 = x;
        Draw();
        if(_kbhit())
            Input();
        Logic();
        Sleep(100);
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
    int X = x, Y = y, X2 = x2, Y2 = y2;
    char mapSaveP1 = Map[X][Y];
    char mapSaveP2 = Map[X2][Y2];

    if(lastX != x || lastY != y)
    {
//        setCursorPosition(x, y);
//        std::cout << " ";
        setCursorPosition(x, y);
        SetConsoleTextAttribute(hConsole, 14); // Player 1 is yellow
        std::cout << Player;
        setCursorPosition(lastX, lastY);
        SetConsoleTextAttribute(hConsole, 15); // Resetting the console color
        drawMap(lastX, lastY);
    }

    if(lastX2 != x2 || lastY2 != y2)
    {
        setCursorPosition(x2, y2);
        SetConsoleTextAttribute(hConsole, 11); // Player 2 is cyan
        std::cout << Player;
        setCursorPosition(lastX2, lastY2);
        SetConsoleTextAttribute(hConsole, 15); // Resetting the console color
        drawMap(lastX2, lastY2);
    }
    setCursorPosition(32, 1);

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

    switch(inputP1)
    {
    case 'w':
        if(P1VelY > -1)
            P1VelY -= 0.2;
        break;
    case 'a':
        if(P1VelX > -1)
            P1VelX -= 0.2;
        break;
    case 's':
        if(P1VelY < 1)
            P1VelY += 0.2;
        break;
    case 'd':
        if(P1VelX < 1)
            P1VelX += 0.2;
        break;
    default:
        if(P1VelY > 0)
            P1VelY -= 0.1;
        else if(P1VelY < 0)
            P1VelY += 0.1;
        if(P1VelX > 0)
            P1VelX -= 0.1;
        else if(P1VelX < 0)
            P1VelX += 0.1;
        break;
    }

    if(x > 1 && x < mapSize)
        x += P1VelX;
    if(y > 1 && y < mapSize)
        y += P1VelY;

    switch(inputP2)
    {
    case 'i':
        if(P2VelY > -1)
            P2VelY -= 0.2;
        break;
    case 'j':
        if(P2VelX > -1)
            P2VelX -= 0.2;
        break;
    case 'k':
        if(P2VelY < 1)
            P2VelY += 0.2;
        break;
    case 'l':
        if(P2VelX < 1)
            P2VelX += 0.2;
        break;
    default:
        break;
    }

    if(x2 > 1 && x2 < mapSize)
        x2 += P2VelX;
    if(y2 > 1 && y2 < mapSize)
        y2 += P2VelY;


}

void Input()
{
    inputP1 = x;
    inputP2 = x;

    inputP1 = _getch();
    inputP2 = _getch();

}
