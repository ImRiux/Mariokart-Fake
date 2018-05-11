#include <iostream>
#include "Game.h"
#include "windows.h"
#include <cstdlib>
#include <string>

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

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

Game::Game():m_difficulty(DIFFICULTY_NONE) {
	m_running = true;
	m_score = 0;
	m_snake.setCoordX(9);
	m_snake.setCoordY(3);
	m_FruitX = 0;
	m_FruitY = 0;
	m_nextFruit = true;
	m_spawnFruit = false;
}

Game::~Game() {
}

void Game::setDifficulty() {
    //unnecessary (do/while), but to lazy to remove it
	do {
		std::cout << "Select your mode.\n";
		std::cout << "1) Easy\n";
		std::cout << "2) Normal\n";
		std::cout << "3) Hard\n";
		std::cout << "Your choice: ";
		int input;
		std::cin >> input;
		std::cin.ignore(32767, '\n');
		while((std::cin.fail()) || (input > 3) || (input <= 0)) {
			std::cin.clear();
			std::cout << "You have to select a mode!\n";
			std::cout << "Your choice: ";
			std::cin >> input;
			if(std::cin.fail()) {
				std::cin.clear();
			}
			std::cin.ignore(32767, '\n');
		}

		switch(input) {
			case 1:
				m_difficulty = DIFFICULTY_EASY;
				break;
			case 2:
				m_difficulty = DIFFICULTY_NORMAL;
				break;
			case 3:
				m_difficulty = DIFFICULTY_HARD;
				break;
			default: break;
		}
		system("cls");
	}while(m_difficulty == DIFFICULTY_NONE);
}

std::string Game::printDifficulty() const {
	switch(m_difficulty) {
		case DIFFICULTY_EASY:
			return "easy";
			break;
		case DIFFICULTY_NORMAL:
			return "normal";
			break;
		case DIFFICULTY_HARD:
			return "hard";
			break;
		default:
			return "none";
			break;
	}
}

void Game::drawMap() {
	for(int y = 0; y < mapHeight; y++) {
		for(int x = 0; x < mapWidth; x++) {
			switch(Map[y][x]) {
				case 'b':
					std::cout << BLOCK;
					break;
				case 'p':
				case 'f':
				case 's':
					std::cout << SPACE;
					break;
				default: break;
			}
		}
		std::cout << "\n";
	}
}

void Game::spawnFruit() {
    //otherwise you will get the same number every time, don't know why :o
	for(int i = 0; i < 100; i++) {
		getRandomNumber(1, 100);
	}
	int rndmNumber = getRandomNumber(1, 100);

    //sets the fruit coordinate
	if(m_nextFruit) {
		switch(rndmNumber) {
			case 10:
				m_FruitX = 3;
				m_FruitY = 3;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 20:
				m_FruitX = 3;
				m_FruitY = 16;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 30:
				m_FruitX = 16;
				m_FruitY = 3;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 40:
				m_FruitX = 16;
				m_FruitY = 16;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 50:
				m_FruitX = 9;
				m_FruitY = 14;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 60:
				m_FruitX = 9;
				m_FruitY = 1;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 70:
				m_FruitX = 5;
				m_FruitY = 5;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 80:
				m_FruitX = 14;
				m_FruitY = 5;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 90:
				m_FruitX = 5;
				m_FruitY = 14;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			case 100:
				m_FruitX = 14;
				m_FruitY = 14;
				m_nextFruit = false;
				m_spawnFruit = true;
				break;
			default: break;
		}
	}

	//draw fruit on the map
	if(m_spawnFruit) {
		setCursor(m_FruitX, m_FruitY);
		std::cout << FRUIT;
		m_spawnFruit = false;
	}
}

void Game::hitFruit() {
    /*if the snake has the same coordinate like a fruit
     *  +10 score, tail length + 1...
     */
	if(m_snake.getCoordX() == m_FruitX && m_snake.getCoordY() == m_FruitY) {
		m_score += 10;
		m_snake.changeTailLength(1);
		m_FruitX = 0;
		m_FruitY = 0;
		m_nextFruit = true;
	}
}

void Game::runGame() {
	showConsoleCursor(true);
	setDifficulty();
	showConsoleCursor(false);
	drawMap();
	while(m_running) {
		spawnFruit();
		hitFruit();
		setCursor(0, 20);
		std::cout << "Score: " << m_score;
		if(m_score == 100) {
			setCursor(0, 21);
			std::cout << "Congratulations you won! (Difficulty: " << printDifficulty() << ")";
			m_running = false;
		}

		if (m_running) {
			m_snake.movement();
			m_snake.drawSnake();
		}
		if(m_running && m_snake.hitWall()) {
			setCursor(0, 21);
			std::cout << "Ups, you hit a wall...gameover.";
			m_running = false;
		}

		if(m_running && m_snake.hitTail()) {
			setCursor(0, 21);
			std::cout << "Ups, you hit yourself...gameover.";
			m_running = false;

		}
		switch(m_difficulty) {
			case DIFFICULTY_EASY:
				Sleep(200);
				break;
			case DIFFICULTY_NORMAL:
				Sleep(150);
				break;
			case DIFFICULTY_HARD:
				Sleep(100);
				break;
			default: break;
		}
	}
	if(!m_running) {
		setCursor(0, 22);
		showConsoleCursor(true);
	}
}
