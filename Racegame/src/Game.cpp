#include <iostream>
#include <string>
#include "conio.h"
#include "windows.h"
#include "Game.h"

//sets the console cursor to position x, y
void setCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//dis/enable the console cursor
void showConsoleCursor(bool showFlag) {
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//returns a string with length space
std::string spaceForCharacters(int length) {
    std::string space;
    switch(length) {
        case 1:
            space = " ";
            break;
        case 2:
            space = "  ";
            break;
        case 3:
            space = "   ";
            break;
        case 4:
            space = "    ";
            break;
        case 5:
            space = "     ";
            break;
        case 6:
            space = "      ";
            break;
        case 7:
            space = "       ";
            break;
        case 8:
            space = "        ";
            break;
        case 9:
            space = "         ";
            break;
        case 10:
            space = "          ";
            break;
        default :
            space = "";
            break;
    }
    return space;
}

void Game::setMode() {
    std::cout << "Select your mode: 1) Don't hit a wall\n";
    std::cout << "                  2) 6 Rounds\n";
    unsigned int input;
    std::cin >> input;
    while(input > 2 || input < 1 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Please select a mode!\n";
        std::cin >> input;
    }
    std::cin.ignore(32767, '\n');
    if(input == 1) {
        m_mode = MODE_DONT_HIT_WALL;
    }else if(input == 2) {
        m_mode = MODE_6_ROUNDS;
    }else{std::cout << "Error: File: Game.cpp Function: setMode()";}
    system("cls");
}

void Game::setName(Player &player) {
    static int counter = 1;
    std::cout << "Player ";
    switch(counter) {
        case 1:
            std::cout << "1";
            break;
        case 2:
            std::cout << "2";
            break;
        default: break;
    }
    std::cout << " enter your name: ";
    std::string tempName;
    std::getline(std::cin, tempName);
    while(tempName.length() > 10 || std::cin.fail()) {
        std::cin.clear();
        std::cout << "Your name can't be longer than 10 characters!\n";
        std::cout << "Please enter a new one: ";
        std::getline(std::cin, tempName);
    }
    player.setName(tempName);
    counter++;
    system("cls");
}

void Game::setCar(Player &player) {
    std::cout << "1) " << CAR_DOLLAR << "\n";
    std::cout << "2) " << CAR_STAR << "\n";
    std::cout << "3) " << CAR_CROSS << "\n";
    std::cout << "4) " << CAR_YEN << "\n";
    std::cout << player.getName() << " choose your car: ";
    int choice;
    std::cin >> choice;
    while(choice > 4 || choice < 1 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Please choose one of the given cars!\n";
        std::cout << "Enter a new one: ";
        std::cin >> choice;
    }
    std::cin.ignore(32767, '\n');

    switch(choice) {
        case 1:
            player.setCar(CAR_DOLLAR);
            break;
        case 2:
            player.setCar(CAR_STAR);
            break;
        case 3:
            player.setCar(CAR_CROSS);
            break;
        case 4:
            player.setCar(CAR_YEN);
            break;
        default: break;
    }
    system("cls");
}

void Game::drawMap() {
    for(int y = 0; y < mapHeight; y++) {
        for(int x = 0; x < mapLength; x++) {
            switch(map_[y][x]) {
                case BLOCK:
                    std::cout << P_BLOCK;
                    break;
                case SPACE:
                    std::cout << P_SPACE;
                    break;
                case C1_P1:
                case C2_P1:
                case C3_P1:
                case C1_P2:
                case C2_P2:
                case C3_P2:
                    std::cout << P_CHECKPOINT;
                    break;
                default: break;
            }
        }
        std::cout << "\n";
    }
}

void Game::drawControls() {
    std::string space1 = spaceForCharacters(m_player1.getName().length());
    std::string space2 = spaceForCharacters(m_player2.getName().length());
    std::string endSpace;
    //search for the longer name and set the end-space
    if(space1.length() > space2.length()) {
        endSpace = space1;
    }else {
        endSpace = space2;
    }

    setCursor(90, 8);
    //if player2s name is longer we have to add the difference
    if(space2.length() > space1.length()) {
        int difference = space2.length() - space1.length();
        std::string addition = spaceForCharacters(difference);
        std::cout << m_player1.getName() << ":" << addition << " w = up\n";
    }else {
        std::cout << m_player1.getName() << ": w = up\n";
    }
    setCursor(90, 9);
    std::cout << endSpace << "  s = down\n";
     setCursor(90, 10);
    std::cout << endSpace << "  a = left\n";
     setCursor(90, 11);
    std::cout << endSpace << "  s = right\n";

    setCursor(90, 13);
    //if player1s name is longer we have to add the difference
    if(space1.length() > space2.length()) {
        int differenz = space1.length() - space2.length();
        std::string addition = spaceForCharacters(differenz);
        std::cout << m_player2.getName() << ":" << addition << " i = up\n";
    }else {
        std::cout << m_player2.getName() << ": i = up\n";
    }

    setCursor(90, 14);
    std::cout << endSpace << "  k = down\n";
     setCursor(90, 15);
    std::cout << endSpace << "  j = left\n";
     setCursor(90, 16);
    std::cout << endSpace << "  l = right\n";
}

void Game::movement() {
    if(_kbhit()) {
        switch(_getch()) {
            case 'w':
                m_player1.setDir(DIRECTION_UP);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            m_player2.setDir(DIRECTION_UP);
                            break;
                        case 'k':
                            m_player2.setDir(DIRECTION_DOWN);
                            break;
                        case 'j':
                            m_player2.setDir(DIRECTION_LEFT);
                            break;
                        case 'l':
                            m_player2.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 's':
                m_player1.setDir(DIRECTION_DOWN);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            m_player2.setDir(DIRECTION_UP);
                            break;
                        case 'k':
                            m_player2.setDir(DIRECTION_DOWN);
                            break;
                        case 'j':
                            m_player2.setDir(DIRECTION_LEFT);
                            break;
                        case 'l':
                            m_player2.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'a':
                m_player1.setDir(DIRECTION_LEFT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            m_player2.setDir(DIRECTION_UP);
                            break;
                        case 'k':
                            m_player2.setDir(DIRECTION_DOWN);
                            break;
                        case 'j':
                            m_player2.setDir(DIRECTION_LEFT);
                            break;
                        case 'l':
                            m_player2.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'd':
                m_player1.setDir(DIRECTION_RIGHT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'i':
                            m_player2.setDir(DIRECTION_UP);
                            break;
                        case 'k':
                            m_player2.setDir(DIRECTION_DOWN);
                            break;
                        case 'j':
                            m_player2.setDir(DIRECTION_LEFT);
                            break;
                        case 'l':
                            m_player2.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'i':
                m_player2.setDir(DIRECTION_UP);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            m_player1.setDir(DIRECTION_UP);
                            break;
                        case 's':
                            m_player1.setDir(DIRECTION_DOWN);
                            break;
                        case 'a':
                            m_player1.setDir(DIRECTION_LEFT);
                            break;
                        case 'd':
                            m_player1.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'k':
                m_player2.setDir(DIRECTION_DOWN);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            m_player1.setDir(DIRECTION_UP);
                            break;
                        case 's':
                            m_player1.setDir(DIRECTION_DOWN);
                            break;
                        case 'a':
                            m_player1.setDir(DIRECTION_LEFT);
                            break;
                        case 'd':
                            m_player1.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'j':
                m_player2.setDir(DIRECTION_LEFT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            m_player1.setDir(DIRECTION_UP);
                            break;
                        case 's':
                            m_player1.setDir(DIRECTION_DOWN);
                            break;
                        case 'a':
                            m_player1.setDir(DIRECTION_LEFT);
                            break;
                        case 'd':
                            m_player1.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            case 'l':
                m_player2.setDir(DIRECTION_RIGHT);
                if(_kbhit()) {
                    switch(_getch()) {
                        case 'w':
                            m_player1.setDir(DIRECTION_UP);
                            break;
                        case 's':
                            m_player1.setDir(DIRECTION_DOWN);
                            break;
                        case 'a':
                            m_player1.setDir(DIRECTION_LEFT);
                            break;
                        case 'd':
                            m_player1.setDir(DIRECTION_RIGHT);
                            break;
                        default: break;
                    }
                }
                break;
            default: break;

        }
    }

    //saves both player positions
    m_player1.setLastXPosition(m_player1.getXPosition());
    m_player1.setLastYPosition(m_player1.getYPosition());
    m_player2.setLastXPosition(m_player2.getXPosition());
    m_player2.setLastYPosition(m_player2.getYPosition());

    //changes the position of player 1
    switch(m_player1.getDir()) {
        case DIRECTION_UP:
            m_player1.changeYPosition(-1);
            break;
        case DIRECTION_DOWN:
            m_player1.changeYPosition(1);
            break;
        case DIRECTION_LEFT:
            m_player1.changeXPosition(-1);
            break;
        case DIRECTION_RIGHT:
            m_player1.changeXPosition(1);
            break;
            default: break;
    }
    //changes the position of player 2
    switch(m_player2.getDir()) {
        case DIRECTION_UP:
            m_player2.changeYPosition(-1);
            break;
        case DIRECTION_DOWN:
            m_player2.changeYPosition(1);
            break;
        case DIRECTION_LEFT:
            m_player2.changeXPosition(-1);
            break;
        case DIRECTION_RIGHT:
            m_player2.changeXPosition(1);
            break;
            default: break;
    }

    /*if player 1 hits he wall
     *  resets him to the last position (which is saved above)
     *  if the mode don't hit a wall is activated
     *      player1s crash status is true
     */
    if(map_[m_player1.getYPosition()][m_player1.getXPosition()] == BLOCK) {
        m_player1.setXPosition(m_player1.getLastXPosition());
        m_player1.setYPosition(m_player1.getLastYPosition());
        if(m_mode == MODE_DONT_HIT_WALL) {
            m_player1.setCrashed(true);
        }
    }

    /*if player 2 hits he wall
     *  resets him to the last position (which is saved above)
     *  if the mode don't hit a wall is activated
     *      player2s crash status is true
     */
    if(map_[m_player2.getYPosition()][m_player2.getXPosition()] == BLOCK) {
        m_player2.setXPosition(m_player2.getLastXPosition());
        m_player2.setYPosition(m_player2.getLastYPosition());
        if(m_mode == MODE_DONT_HIT_WALL) {
            m_player2.setCrashed(true);
        }
    }
}

void Game::checkCheckpoints() {
    /*switch player1s position on the map
     *  case checkpoint 1 -> get activated
     *  case checkpoint 2 -> get activated (if checkpoint 1 is activated)
     *  case checkpoint 3 -> get activated (if checkpoint 1 && 2 is activated)
     */
    switch(map_[m_player1.getYPosition()][m_player1.getXPosition()]) {
		case C1_P1:
			m_p1c1 = true;
			break;
		case C2_P1:
			if(m_p1c1) {
				m_p1c2 = true;
			}
			break;
		case C3_P1:
			if(m_p1c1 && m_p1c2) {
				m_p1c3 = true;
			}
			break;
	}

    /*switch player2s position on the map
     *  case checkpoint 1 -> get activated
     *  case checkpoint 2 -> get activated (if checkpoint 1 is activated)
     *  case checkpoint 3 -> get activated (if checkpoint 1 && 2 is activated)
     */
	switch(map_[m_player2.getYPosition()][m_player2.getXPosition()]) {
		case C1_P2:
			m_p2c1 = true;
			break;
		case C2_P2:
			if(m_p2c1) {
				m_p2c2 = true;
			}
			break;
		case C3_P2:
			if(m_p2c1 && m_p2c2) {
				m_p2c3 = true;
			}
			break;
	}

    //if player 1 activated checkpoint 3 -> +1 round
	if(m_p1c3) {
        m_player1.changeRound(1);
        //sets all checkpoints to false for the next round
        m_p1c1 = false;
        m_p1c2 = false;
        m_p1c3 = false;
	}
    //if player 2 activated checkpoint 3 -> +1 round
	if(m_p2c3) {
        m_player2.changeRound(1);
        //sets all checkpoints to false for the next round
        m_p2c1 = false;
        m_p2c2 = false;
        m_p2c3 = false;
	}

    //print the rounds
    setCursor(0, mapHeight);
    std::cout << m_player1.getName() <<  ": Runde " << m_player1.getRound();
    setCursor(0, mapHeight + 1);
    std::cout << m_player2.getName() <<  ": Runde " << m_player2.getRound();
}

Game::Game() {
    //player1s start position
    m_player1.setXPosition(2);
    m_player1.setLastXPosition(2);
    m_player1.setYPosition(23);
    m_player1.setLastYPosition(23);

    //player2s start position
    m_player2.setXPosition(48);
    m_player2.setLastXPosition(48);
    m_player2.setYPosition(23);
    m_player2.setLastYPosition(23);
}

Game::~Game() {
    // :(
}

void Game::runGame() {
    showConsoleCursor(true);
    setMode();
    setName(m_player1);
    setName(m_player2);
    setCar(m_player1);
    setCar(m_player2);

    showConsoleCursor(false);
    drawMap();
    drawControls();
    while(m_running) {
        m_player1.drawPlayer(m_player1);
        m_player2.drawPlayer(m_player2);
        movement();

        if(m_mode == MODE_DONT_HIT_WALL) {
            if(m_player1.isCrashed() && m_player2.isCrashed()) {
                setCursor(0, mapHeight);
                std::cout << "Ou no, both hit a wall simultaneously...\n";
                std::cout << "Noone has won the game!\n";
                m_running = false;
            }else if(m_player1.isCrashed()) {
                setCursor(0, mapHeight);
                std::cout << "Ou no, " << m_player1.getName() << " hit a wall...\n";
                std::cout << m_player2.getName() << " has won the game!\n";
                m_running = false;
            }else if(m_player2.isCrashed()) {
                setCursor(0, mapHeight);
                std::cout << "Ou no, " << m_player2.getName() << " hit a wall...\n";
                std::cout << m_player1.getName() << " has won the game!\n";
                m_running = false;
            }
            Sleep(150);
        }

        if(m_mode == MODE_6_ROUNDS) {
            checkCheckpoints();
            if(m_player1.getRound() == 6 && m_player2.getRound() == 6) {
                setCursor(0, mapHeight + 2);
                std::cout << "Ou no, both reached 6 rounds simultaneously...\n";
                std::cout << "Noone has won the game!\n";
                m_player1.drawPlayer(m_player1);
                m_player2.drawPlayer(m_player2);
                setCursor(0, mapHeight + 3);
                m_running = false;
            }else if(m_player1.getRound() == 6) {
                setCursor(0, mapHeight + 2);
                std::cout << m_player1.getName() << " has won the game!\n";
                m_player1.drawPlayer(m_player1);
                m_player2.drawPlayer(m_player2);
                setCursor(0, mapHeight + 3);
                m_running = false;
            }else if(m_player2.getRound() == 6) {
                setCursor(0, mapHeight + 2);
                std::cout << m_player2.getName() << " has won the game!\n";
                m_player1.drawPlayer(m_player1);
                m_player2.drawPlayer(m_player2);
                setCursor(0, mapHeight + 3);
                m_running = false;
            }
            Sleep(200);
        }
    }
    system("pause");
}
