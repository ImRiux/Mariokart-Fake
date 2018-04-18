#include <iostream>
#include "conio.h"
#include "windows.h"
#include "Map.h"

int x{0}, y{0}, x2{1}, y2{0};
const int mapSize{32};

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
Direction dir2;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Draw();
void Input();
void Logic();

int main()
{
    while(true)
    {
        Draw();
        Input();
        Logic();
        Sleep(1000);
    }

}


void Draw()
{
    system("cls");
    for(int i = 0; i < mapSize; i++)
        {
            for(int j = 0; j < mapSize; j++)
            {

                if(i == y && j == x)
                {
                    std::cout << "1";
                    j++;
                }
                if(i == y2 && j == x2)
                {
                    std::cout << "2";
                    j++;
                }
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
                default:
                    std::cout << Map[i][j];
                }
                SetConsoleTextAttribute(hConsole, 15);
            }
            std::cout << "\n";
        }
}

void Logic()
{
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
