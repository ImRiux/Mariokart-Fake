#include <conio.h>
#include <iostream>
#include <string>
#include "windows.h"

#include "Map.h"
#include "Player.h"
#include "References.h"

static Player player;
static Player player1;
static Player player2;

//function prototype
void setCursor(int x, int y);
void showConsoleCursor(bool showFlag);
void drawMap1P();
void movement1P();
void drawMap2P();
void movement2P();

int main() {
    showConsoleCursor(true);
    Mode playermode = MODE_NONE;
    Mode gamemode = MODE_NONE;
    unsigned int input;
    //draw the player-menu
    do {
        std::cout << "Select the number of players\n";
        std::cout << "1) 1 Player\n";
        std::cout << "2) 2 Player\n";
        std::cout << "Your choice: ";
        std::cin >> input;
        if(std::cin.fail()) {
            std::cin.clear();
        }
        std::cin.ignore(32767, '\n');
        switch(input) {
            case 1:
                playermode = MODE_SINGLEPLAYER;
                break;
            case 2:
                playermode = MODE_MULTIPLAYER;
                break;
            default: break;
        }
    }while(input != 1 && input != 2);

    input = 0; //when we need it later
    //clear screen
    system("cls");

    //if the user selected 1 Player
    if(playermode == MODE_SINGLEPLAYER) {
        showConsoleCursor(false);
        drawMap1P();

        player.setXPosition(2); //start x position
        player.setLastXPostion(2);
        player.setYPosition(23); //start y position
        player.setLastYPosition(23);

        while(1) {
            Sleep(200);
            movement1P();
        }

    //if the user selected 2 Players
    }else if(playermode == MODE_MULTIPLAYER) {
        //draw the game-mode-menu
        do{
            std::cout << "Select a mode\n";
            std::cout << "1) 10 Rounds\n";
            std::cout << "2) Don't hit a wall\n";
            std::cout << "Your choice: ";
            std::cin >> input;
            if(std::cin.fail()) {
                std::cin.clear();
            }
            std::cin.ignore(32767, '\n');
            switch(input) {
                case 1:
                    gamemode = MODE_TEN_ROUNDS;
                    break;
                case 2:
                    gamemode = MODE_DONT_HIT_WALL;
                    break;
                default: break;
            }
        }while(input != 1 && input != 2);

        //clear screen
        system("cls");

        //player 1 enters his name
        std::cout << "Player 1 enter your name: ";
        {
            std::string tempPlayer1Name;
            std::getline(std::cin, tempPlayer1Name);
            if(std::cin.fail()) {
                std::cin.clear();
            }
            while(tempPlayer1Name.length() > 10) {
                std::cout << "A name larger then 10 characters is not supported!\n";
                std::cout << "Please enter a new one: ";
                std::getline(std::cin, tempPlayer1Name);
                if(std::cin.fail()) {
                    std::cin.clear();
                }
            }
            player1.setName(tempPlayer1Name);
        }

        //player 2 enters his name
        std::cout << "Player 2 enter your name: ";
        {
            std::string tempPlayer2Name;
            std::getline(std::cin, tempPlayer2Name);
            if(std::cin.fail()) {
                std::cin.clear();
            }
            while(tempPlayer2Name.length() > 10) {
                std::cout << "A name larger than 10 characters is not supported!\n";
                std::cout << "Please enter a new one: ";
                std::getline(std::cin, tempPlayer2Name);
                if(std::cin.fail()) {
                    std::cin.clear();
                }
            }
            player2.setName(tempPlayer2Name);
        }

        //clear screen
        system("cls");
        std::cout << player1.getName() << " choose a car.\n";
        std::cout << "1) " << dollarCar << "\n";
        std::cout << "2) " << starCar << "\n";
        std::cout << "3) " << crossCar << "\n";
        std::cout << "4) " << yenCar << "\n";
        std::cout << "Your choice: ";
        {
            int tempPlayer1Car;
            std::cin >> tempPlayer1Car;
            if(std::cin.fail()) {
                std::cin.ignore();
            }
            std::cin.ignore(32767, '\n');
            while(tempPlayer1Car < 0 || tempPlayer1Car > 4) {
                std::cout << "Please choose one of the given cars!\n";
                std::cout << "Enter a new one: ";
                std::cin >> tempPlayer1Car;
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                }
            }
            switch(tempPlayer1Car) {
                case '1':
                    player1.setCar(dollarCar);
                    break;
                case '2':
                    player1.setCar(starCar);
                    break;
                case 3:
                    player1.setCar(crossCar);
                    break;
                case 4:
                    player1.setCar(yenCar);
                    break;
                default: break;

            }
        }

        std::cout << player1.getCar();

        showConsoleCursor(false);
        drawMap2P();

        player1.setXPosition(2); //start x position of player 1
        player1.setLastXPostion(2);
        player1.setYPosition(23); //start y position of player 1
        player1.setLastYPosition(23);

        player2.setXPosition(48); //start x position of player 2
        player2.setLastXPostion(48);
        player2.setYPosition(23);//start y position of player 2
        player2.setLastYPosition(23);

        //if the user selected ten rounds
        if(gamemode == MODE_TEN_ROUNDS) {
            while(1) {
                Sleep(200);
                movement2P();
                setCursor(0, 25);
            }

        //if the user selected don't hit a wall
        }else if(gamemode == MODE_DONT_HIT_WALL) {
            while(1) {
                Sleep(200);
                movement2P();
                setCursor(0, 25);
            }

        //error printing
        }else {
            std::cout << "Failed to set the gamemode\n";
        }

    //error printing
    }else {
        std::cout << "Failed to set the playermode\n";
    }
    return 0;
}

//sets the cursor to the position (x/y)
void setCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//renders the cursor visible or invisible
void showConsoleCursor(bool showFlag) {
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//draws the hole 1 player map
void drawMap1P() {
    for(int y = 0; y < map1PYL; y++) {
        for(int x = 0; x < map1PXL; x++) {
            switch(Map1P[y][x]) {
                case 's':
                    std::cout << space;
                    break;
                case 'b':
                    std::cout << block;
                    break;
                default: break;
            }
        }
        std::cout << "\n";
    }
}

void movement1P() {
    /*sets the cursor the the last players position
      and removes the player-symbol with a whitespace*/
    setCursor(player.getLastXPosition(), player.getLastYPosition());
    std::cout << space;

    /*sets the cursor the the players position
      and prints the player-symbol*/
    setCursor(player.getXPosition(), player.getYPosition());
    std::cout << "*";

    //changes the players movement direction
    if(_kbhit()) {
        switch(_getch()) {
            case 'w':
                player.setDirection(DIRECTION_UP);
                break;
            case 's':
                player.setDirection(DIRECTION_DOWN);
                break;
            case 'a':
                player.setDirection(DIRECTION_LEFT);
                break;
            case 'd':
                player.setDirection(DIRECTION_RIGHT);
                break;
            default: break;
        }
    }

    //saves the last x and y position before it gets edited
    player.setLastXPostion(player.getXPosition());
    player.setLastYPosition(player.getYPosition());

    //changes the players position with the movement direction of it
    switch(player.getDirection()) {
        case DIRECTION_UP:
            player.changeYPosition(-1);
            break;
        case DIRECTION_DOWN:
            player.changeYPosition(1);
            break;
        case DIRECTION_LEFT:
            player.changeXPosition(-1);
            break;
        case DIRECTION_RIGHT:
            player.changeXPosition(1);
            break;
        default: break;
    }

    /*if the player hits a wall
     *the player gets his old x coordinate
     *and his old y coordinate
     */
    if(Map1P[player.getYPosition()][player.getXPosition()] == 'b') {
        player.setXPosition(player.getLastXPosition());
        player.setYPosition(player.getLastYPosition());
    }
}

void drawMap2P() {
    for(int y = 0; y < map2PYL; y++) {
        for(int x = 0; x < map2PXL; x++) {
            switch(Map2P[y][x]) {
                case 's':
                    std::cout << space;
                    break;
                case 'b':
                    std::cout << block;
                    break;
                default: break;
            }
        }
        std::cout << "\n";
    }
}

void movement2P() {
    /*sets the cursor the the last player1s position
      and removes the player1-symbol with a whitespace*/
    setCursor(player1.getLastXPosition(), player1.getLastYPosition());
    std::cout << space;

    /*sets the cursor the the player1s position
      and prints the player1-symbol*/
    setCursor(player1.getXPosition(), player1.getYPosition());
    std::cout << "*";

    /*sets the cursor the the last player2s position
      and removes the player2-symbol with a whitespace*/
    setCursor(player2.getLastXPosition(), player2.getLastYPosition());
    std::cout << space;

    /*sets the cursor the the player2s position
      and prints the player2-symbol*/
    setCursor(player2.getXPosition(), player2.getYPosition());
    std::cout << "*";

    //changes the players movement direction
    if(_kbhit()) {
        switch(_getch()) {
            case 'w':
                player1.setDirection(DIRECTION_UP);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            player2.setDirection(DIRECTION_UP);
                            break;
                        case 'k':
                            player2.setDirection(DIRECTION_DOWN);
                            break;
                        case 'j':
                            player2.setDirection(DIRECTION_LEFT);
                            break;
                        case 'l':
                            player2.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 's':
                player1.setDirection(DIRECTION_DOWN);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            player2.setDirection(DIRECTION_UP);
                            break;
                        case 'k':
                            player2.setDirection(DIRECTION_DOWN);
                            break;
                        case 'j':
                            player2.setDirection(DIRECTION_LEFT);
                            break;
                        case 'l':
                            player2.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'a':
                player1.setDirection(DIRECTION_LEFT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            player2.setDirection(DIRECTION_UP);
                            break;
                        case 'k':
                            player2.setDirection(DIRECTION_DOWN);
                            break;
                        case 'j':
                            player2.setDirection(DIRECTION_LEFT);
                            break;
                        case 'l':
                            player2.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'd':
                player1.setDirection(DIRECTION_RIGHT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            player2.setDirection(DIRECTION_UP);
                            break;
                        case 'k':
                            player2.setDirection(DIRECTION_DOWN);
                            break;
                        case 'j':
                            player2.setDirection(DIRECTION_LEFT);
                            break;
                        case 'l':
                            player2.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'i':
                player2.setDirection(DIRECTION_UP);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            player1.setDirection(DIRECTION_UP);
                            break;
                        case 's':
                            player1.setDirection(DIRECTION_DOWN);
                            break;
                        case 'a':
                            player1.setDirection(DIRECTION_LEFT);
                            break;
                        case 'd':
                            player1.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'k':
                player2.setDirection(DIRECTION_DOWN);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            player1.setDirection(DIRECTION_UP);
                            break;
                        case 's':
                            player1.setDirection(DIRECTION_DOWN);
                            break;
                        case 'a':
                            player1.setDirection(DIRECTION_LEFT);
                            break;
                        case 'd':
                            player1.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'j':
                player2.setDirection(DIRECTION_LEFT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            player1.setDirection(DIRECTION_UP);
                            break;
                        case 's':
                            player1.setDirection(DIRECTION_DOWN);
                            break;
                        case 'a':
                            player1.setDirection(DIRECTION_LEFT);
                            break;
                        case 'd':
                            player1.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'l':
                player2.setDirection(DIRECTION_RIGHT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            player1.setDirection(DIRECTION_UP);
                            break;
                        case 's':
                            player1.setDirection(DIRECTION_DOWN);
                            break;
                        case 'a':
                            player1.setDirection(DIRECTION_LEFT);
                            break;
                        case 'd':
                            player1.setDirection(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            default: break;

        }
    }

    //saves player1s last position
    player1.setLastXPostion(player1.getXPosition());
    player1.setLastYPosition(player1.getYPosition());

    //changes the player1s position with the movement direction of it
    switch(player1.getDirection()) {
        case DIRECTION_UP:
            player1.changeYPosition(-1);
            break;
        case DIRECTION_DOWN:
            player1.changeYPosition(1);
            break;
        case DIRECTION_LEFT:
            player1.changeXPosition(-1);
            break;
        case DIRECTION_RIGHT:
            player1.changeXPosition(1);
            break;
        default: break;

    }

    /*if player1 hits a wall
     *player1 gets his old x coordinate
     *and his old y coordinate
     */
    if(Map2P[player1.getYPosition()][player1.getXPosition()] == 'b') {
        player1.setXPosition(player1.getLastXPosition());
        player1.setYPosition(player1.getLastYPosition());
    }

    //saves player2s last position
    player2.setLastXPostion(player2.getXPosition());
    player2.setLastYPosition(player2.getYPosition());

    //changes the player2s position with the movement direction of it
    switch(player2.getDirection()) {
        case DIRECTION_UP:
            player2.changeYPosition(-1);
            break;
        case DIRECTION_DOWN:
            player2.changeYPosition(1);
            break;
        case DIRECTION_LEFT:
            player2.changeXPosition(-1);
            break;
        case DIRECTION_RIGHT:
            player2.changeXPosition(1);
            break;
        default: break;
    }

    /*if player2 hits a wall
     *player2 gets his old x coordinate
     *and his old y coordinate
     */
    if(Map2P[player2.getYPosition()][player2.getXPosition()] == 'b') {
        player2.setXPosition(player2.getLastXPosition());
        player2.setYPosition(player2.getLastYPosition());
    }
}
