#include <iostream>
#include "conio.h"
#include "windows.h"
#include "Map.h"
#include "chrono"
#include <math.h>

float x{10}, y{10}, x2{15}, y2{15};
float P1VelX{1}, P1VelY{0}, P2VelX{0}, P2VelY{0};
int lastX{0}, lastY{0}, lastX2{0}, lastY2{0};
bool calculatedRespawn{false}, calculatedRespawn2{false};
float respawnDistance{100}, respawnDistance2{100};
char inputP1, inputP2;
int respawnTime{0}, spawnX, spawnY;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Draw();
void Input();
void Logic();
void Setup();
void drawMap(int x, int y);

int main()
{
    Setup();
    while(true)
    {
        inputP1 = x;
        inputP2 = x;
        Draw();
        Input();
        Logic();
        Sleep(50);
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


void Draw()
{
    int X = x, Y = y, X2 = x2, Y2 = y2;
    char mapSaveP1 = Map[X][Y];
    char mapSaveP2 = Map[X2][Y2];

    if(lastX != x || lastY != y)
    {
        setCursorPosition(lastX, lastY);
        drawMap(lastX, lastY);

        setCursorPosition(x, y);
        SetConsoleTextAttribute(hConsole, 14); // Player 1 is yellow
        std::cout << Player;
    }

    if(lastX2 != x2 || lastY2 != y2)
    {
        setCursorPosition(lastX2, lastY2);
        drawMap(lastX2, lastY2);

        setCursorPosition(x2, y2);
        SetConsoleTextAttribute(hConsole, 11); // Player 2 is cyan
        std::cout << Player;
    }
    setCursorPosition(32, 1);

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

//    if(P1VelX > 0 && P1VelX < 0.2)
//        P1VelX = 0;
//    if(P1VelY > 0 && P1VelY < 0.2)
//        P1VelY = 0;
//
//    if(x > 1 && x <= (mapSize - 2) && P1VelX < 0)
//        x += P1VelX;
//    else if(x >= 1 && x < (mapSize - 2) && P1VelX > 0)
//        x += P1VelX;
//    else if(x < 1)
//        x = 1;
//    else if(x > (mapSize - 2))
//        x = (mapSize - 2);
//
//    if(y > 1 && y <= (mapSize - 2) && P1VelY < 0)
//        y += P1VelY;
//    else if(y >= 1 && y < (mapSize - 2) && P1VelY > 0)
//        y += P1VelY;
//    else if(y < 1)
//        y = 1;
//
    if(P1VelX > 0 && P1VelX < 0.2)
        P1VelX = 0;
    if(P1VelY > 0 && P1VelY < 0.2)
        P1VelY = 0;

    if(x > 1 && x <= (mapSize - 2) && P1VelX < 0)
        x += P1VelX;
    else if(x >= 1 && x < (mapSize - 2) && P1VelX > 0)
        x += P1VelX;
    else if(x < 1)
        x = 1;
    else if(x > (mapSize - 2))
        x = (mapSize - 2);

    if(y > 1 && y <= (mapSize - 2) && P1VelY < 0)
        y += P1VelY;
    else if(y >= 1 && y < (mapSize - 2) && P1VelY > 0)
        y += P1VelY;
    else if(y < 1)
        y = 1;
    else if(y > (mapSize - 2))
        y = (mapSize - 2);
    else if(y > (mapSize - 2))
        y = (mapSize - 2);

    int X = x, Y = y;

    if(Map[Y][X] == 'G')
    {
        if(P1VelX > 0 || P1VelX < 0)
            P1VelX /= 4;
        if(P1VelY > 0 || P1VelY < 0)
            P1VelY /= 4;
    }
    if(Map[Y][X] == 'W' || Map[lastX][lastY] == 'W')
    {
        respawnTime += 50;
        if(!calculatedRespawn)
        {
            for(int i = 0; i < mapSize; i++)
            {
                for(int j = 0; j < mapSize; j++)
                {
                    if(Map[i][j] == 'S')
                    {
                        int distanceX = j - x;
                        if(distanceX < 0) distanceX *= -1;
                        int distanceY = i - y;
                        if(distanceY < 0) distanceY *= -1;
                        float distance =  pow((pow(distanceX, 2.0) + pow(distanceY, 2.0)), 0.5);
                        if(distance < respawnDistance)
                        {
                            respawnDistance = distance;
                            spawnX = j;
                            spawnY = i;
                        }
                    }
                }
            }
            calculatedRespawn = true;
        }
        P1VelX = 0;
        P1VelY = 0;
        if(respawnTime > 100)
        {
            x = lastX;
            y = lastY;
        }
        if(respawnTime == 1000)
        {
            setCursorPosition(lastX, lastY);
            SetConsoleTextAttribute(hConsole, 23);
            std::cout << Water;
            x = spawnX;
            y = spawnY;
            lastX = spawnX;
            lastY = spawnY;
            setCursorPosition(lastX, lastY);
            SetConsoleTextAttribute(hConsole, 14);
            std::cout << Player;
            respawnTime = 0;
            calculatedRespawn = false;
            respawnDistance = 1000;
        }
    }

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

    if(P2VelX > 0 && P2VelX < 0.2)
        P2VelX = 0;
    if(P2VelY > 0 && P2VelY < 0.2)
        P2VelY = 0;

    if(x2 > 1 && x2 <= (mapSize - 2) && P2VelX < 0)
        x2 += P2VelX;
    else if(x2 >= 1 && x2 < (mapSize - 2) && P2VelX > 0)
        x2 += P2VelX;
    else if(x2 < 1)
        x2 = 1;
    else if(x2 > (mapSize - 2))
        x2 = (mapSize - 2);

    if(y2 > 1 && y2 <= (mapSize - 2) && P2VelY < 0)
        y2 += P2VelY;
    else if(y2 >= 1 && y2 < (mapSize - 2) && P2VelY > 0)
        y2 += P2VelY;
    else if(y2 < 1)
        y2 = 1;
    else if(y2 > (mapSize - 2))
        y2 = (mapSize - 2);
}

void Input()
{
    inputP1 = 'x';
    inputP2 = 'x';

    if(_kbhit())
    {
        inputP1 = _getch();
        if(_kbhit())
            inputP2 = _getch();
    }

    if(inputP2 == 'x' && _kbhit())
        inputP2 = _getch();


}
