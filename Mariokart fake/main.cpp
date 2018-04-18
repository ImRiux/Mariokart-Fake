#include <iostream>
#include "conio.h"
#include "windows.h"

int x{0}, y{0}, x2{1}, y2{1};
const int mapSize{64};

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
Direction dir2;

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
        system("cls");
        Sleep(1000);
    }

}


void Draw()
{
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
               std::cout << "-";
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
    x > mapSize ? x = mapSize : x = x; // Setzt x zur�ck, wenn Spieler eins rechts au�erhalb der map ist
    y > mapSize ? y = mapSize : y = y; // Setzt y zur�ck, wenn Spieler eins unten au�erhalb der map ist
    x < 0 ? x = 0 : x = x; // Setzt x zur�ck, wenn Spieler eins links au�erhalb der map ist
    y < 0 ? y = 0 : y = y; // Setzt y zur�ck, wenn Spieler eins oben au�erhalb der map ist
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
    x2 > mapSize ? x2 = mapSize : x2 = x2; // Setzt x2 zur�ck, wenn Spieler zwei rechts au�erhalb der map ist
    y2 > mapSize ? y2 = mapSize : y2 = y2; // Setzt y2 zur�ck, wenn Spieler zwei unten au�erhalb der map ist
    x2 < 0 ? x2 = 0 : x2 = x2; // Setzt x2 zur�ck, wenn Spieler zwei links au�erhalb der map ist
    y2 < 0 ? y2 = 0 : y2 = y2; // Setzt y2 zur�ck, wenn Spieler zwei oben au�erhalb der map ist
}

void Input()
{
     if(_kbhit())
    {
        switch(_getch())
        {
        case 'w':
            dir = UP;
            switch(_getch())
            {
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
            }
            break;
        case 'a':
            dir = LEFT;
            switch(_getch())
            {
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
            }
            break;
        case 's':
            dir = DOWN;
            switch(_getch())
            {
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
            }
            break;
        case 'd':
            dir = RIGHT;
            switch(_getch())
            {
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
            }
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
