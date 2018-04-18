#include <conio.h>
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "References.h"

int main() {
    Mode mode;
    int input;

    //menu
    do {
        std::cout << "1) 1 Player\n";
        std::cout << "2) 2 Player\n";
        std::cin >> input;
        if(std::cin.fail()) {
            std::cin.clear();
        }
        std::cin.ignore(32767, '\n');
        switch(input) {
            case 1:
                mode = MODE_SINGLEPLAYER;
                break;
            case 2:
                mode = MODE_MULTIPLAYER;
            default: break;
        }

    }while(mode != 1 && mode != 2);

    if(mode == MODE_SINGLEPLAYER) {
        Player player;
        player.setX(8);
        player.setY(8);
        while(1) {
            Sleep(100);
            system("cls");
            //map
            for(int y = 0; y < 16; y++) {
                for(int x = 0; x < 16; x++) {
                    if(player.getX() == x && player.getY() == y) {
                        std::cout << "P";
                        x++;
                    }
                    std::cout << "#";
                }
                std::cout << "\n";
            }

            if(_kbhit()) {
                switch(_getch()) {
                case 'w':
                    player.dir = DIRECTION_UP;
                    break;
                case 's':
                    player.dir = DIRECTION_DOWN;
                    break;
                case 'a':
                    player.dir = DIRECTION_LEFT;
                    break;
                case 'd':
                    player.dir = DIRECTION_RIGHT;
                default: break;

                }
            }

            switch(player.dir) {
                case DIRECTION_UP:
                    player.changeY(1);
                    break;
                case DIRECTION_DOWN:
                    player.changeY(-1);
                    break;
                case DIRECTION_LEFT:
                    player.changeX(-1);
                    break;
                case DIRECTION_RIGHT:
                    player.changeX(1);
                    break;
            }
        }

    }else {

    }

    return 0;
}

// ne du bich
