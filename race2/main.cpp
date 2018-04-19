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

    //if the user chosen 1(single player)
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
                    if(x != 16) {
                        std::cout << "#";
                    }
                }
                std::cout << "\n";
            }

            //keyboard
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

        //change player1s position
        switch(player.dir) {
                case DIRECTION_UP:
                    player.changeY(-1);
                    if(player.getY() < 0) {
                        player.changeY(1);
                    }
                    break;
                case DIRECTION_DOWN:
                    player.changeY(1);
                    if(player.getY() > 15) {
                        player.changeY(-1);
                    }
                    break;
                case DIRECTION_LEFT:
                    player.changeX(-1);
                    if(player.getX() < 0) {
                        player.changeX(1);
                    }
                    break;
                case DIRECTION_RIGHT:
                    player.changeX(1);
                    if(player.getX() > 15) {
                        player.changeX(-1);
                    }
                    break;
                default: break;
            }
        }

    //if the user chosen 2(multi player)
    }else {
        Player player1;
        player1.setX(0);
        player1.setY(0);
        Player player2;
        player2.setX(19);
        player2.setY(0);
        while(1) {
            Sleep(100);
            system("cls");
            //map
            for(int y = 0; y < 20; y++) {
                for(int x = 0; x < 20; x++) {
                    if(player1.getX() == x && player1.getY() == y) {
                        std::cout << "1";
                        x++;
                    }
                    if(player2.getX() == x && player2.getY() == y) {
                        std::cout << "2";
                        x++;
                    }
                    if(x != 20){
                      std::cout << "#";
                    }
                }
                std::cout << "\n";
            }

            //keyboard
            if(_kbhit()) {
                switch(_getch()) {
                    case 'w':
                        player1.dir = DIRECTION_UP;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'i':
                                    player2.dir = DIRECTION_UP;
                                    break;
                                case 'k':
                                    player2.dir = DIRECTION_DOWN;
                                    break;
                                case 'j':
                                    player2.dir = DIRECTION_LEFT;
                                    break;
                                case 'l':
                                    player2.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;
                    case 's':
                        player1.dir = DIRECTION_DOWN;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'i':
                                    player2.dir = DIRECTION_UP;
                                    break;
                                case 'k':
                                    player2.dir = DIRECTION_DOWN;
                                    break;
                                case 'j':
                                    player2.dir = DIRECTION_LEFT;
                                    break;
                                case 'l':
                                    player2.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;
                    case 'a':
                        player1.dir = DIRECTION_LEFT;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'i':
                                    player2.dir = DIRECTION_UP;
                                    break;
                                case 'k':
                                    player2.dir = DIRECTION_DOWN;
                                    break;
                                case 'j':
                                    player2.dir = DIRECTION_LEFT;
                                    break;
                                case 'l':
                                    player2.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;
                    case 'd':
                        player1.dir = DIRECTION_RIGHT;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'i':
                                    player2.dir = DIRECTION_UP;
                                    break;
                                case 'k':
                                    player2.dir = DIRECTION_DOWN;
                                    break;
                                case 'j':
                                    player2.dir = DIRECTION_LEFT;
                                    break;
                                case 'l':
                                    player2.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;
                    case 'i':
                        player2.dir = DIRECTION_UP;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'w':
                                    player1.dir = DIRECTION_UP;
                                    break;
                                case 's':
                                    player1.dir = DIRECTION_DOWN;
                                    break;
                                case 'a':
                                    player1.dir = DIRECTION_LEFT;
                                    break;
                                case 'd':
                                    player1.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;
                    case 'k':
                        player2.dir = DIRECTION_DOWN;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'w':
                                    player1.dir = DIRECTION_UP;
                                    break;
                                case 's':
                                    player1.dir = DIRECTION_DOWN;
                                    break;
                                case 'a':
                                    player1.dir = DIRECTION_LEFT;
                                    break;
                                case 'd':
                                    player1.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;
                    case 'j':
                        player2.dir = DIRECTION_LEFT;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'w':
                                    player1.dir = DIRECTION_UP;
                                    break;
                                case 's':
                                    player1.dir = DIRECTION_DOWN;
                                    break;
                                case 'a':
                                    player1.dir = DIRECTION_LEFT;
                                    break;
                                case 'd':
                                    player1.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;
                    case 'l':
                        player2.dir = DIRECTION_RIGHT;
                        if(_kbhit()) {
                            switch(_getch()) {
                                case 'w':
                                    player1.dir = DIRECTION_UP;
                                    break;
                                case 's':
                                    player1.dir = DIRECTION_DOWN;
                                    break;
                                case 'a':
                                    player1.dir = DIRECTION_LEFT;
                                    break;
                                case 'd':
                                    player1.dir = DIRECTION_RIGHT;
                                    break;
                                default: break;
                            }
                        }
                        break;

                    default: break;
                }
            }

            //change player1s position
            switch(player1.dir) {
                case DIRECTION_UP:
                    player1.changeY(-1);
                    //if player1 is outside the map
                    if(player1.getY() < 0) {
                        player1.changeY(1);
                    }
                    //if player1 gets blocked by player2
                    if(player1.getX() == player2.getX() && player1.getY() == player2.getY()) {
                        player1.changeY(1);
                    }
                    break;
                case DIRECTION_DOWN:
                    player1.changeY(1);
                    //if player1 is outside the map
                    if(player1.getY() > 19) {
                        player1.changeY(-1);
                    }
                    //if player1 gets blocked by player2
                    if(player1.getX() == player2.getX() && player1.getY() == player2.getY()) {
                        player1.changeY(-1);
                    }
                    break;
                case DIRECTION_LEFT:
                    player1.changeX(-1);
                    //if player1 is outside the map
                    if(player1.getX() < 0) {
                        player1.changeX(1);
                    }
                    //if player1 gets blocked by player2
                    if(player1.getX() == player2.getX() && player1.getY() == player2.getY()) {
                        player1.changeX(1);
                    }
                    break;
                case DIRECTION_RIGHT:
                    //if player1 is outside the map
                    player1.changeX(1);
                    if(player1.getX() > 19) {
                        player1.changeX(-1);
                    }
                    //if player1 gets blocked by player2
                    if(player1.getX() == player2.getX() && player1.getY() == player2.getY()) {
                        player1.changeX(-1);
                    }
                    break;
                default: break;
            }

            //change player2s position
            switch(player2.dir) {
                case DIRECTION_UP:
                    player2.changeY(-1);
                    //if player2 is outside the map
                    if(player2.getY() < 0) {
                        player2.changeY(1);
                    }
                    //if player2 gets blocked by player1
                    if(player2.getX() == player1.getX() && player2.getY() == player1.getY()) {
                        player2.changeY(1);
                    }
                    break;
                case DIRECTION_DOWN:
                    player2.changeY(1);
                    //if player2 is outside the map
                    if(player2.getY() > 19) {
                        player2.changeY(-1);
                    }
                    //if player2 gets blocked by player1
                    if(player2.getX() == player1.getX() && player2.getY() == player1.getY()) {
                        player2.changeY(-1);
                    }
                    break;
                case DIRECTION_LEFT:
                    player2.changeX(-1);
                    //if player2 is outside the map
                    if(player2.getX() < 0) {
                        player2.changeX(1);
                    }
                    //if player2 gets blocked by player1
                    if(player2.getX() == player1.getX() && player2.getY() == player1.getY()) {
                        player2.changeX(1);
                    }
                    break;
                case DIRECTION_RIGHT:
                    player2.changeX(1);
                    //if player2 is outside the map
                    if(player2.getX() > 19) {
                        player2.changeX(-1);
                    }
                    //if player2 gets blocked by player1
                    if(player2.getX() == player1.getX() && player2.getY() == player1.getY()) {
                        player2.changeX(-1);
                    }
                    break;
                default: break;
            }
        }
    }
    return 0;
}

