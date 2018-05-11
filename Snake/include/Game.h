#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Snake.h"

enum Difficulty{DIFFICULTY_NONE, DIFFICULTY_EASY, DIFFICULTY_NORMAL, DIFFICULTY_HARD};

const int mapHeight = 20;
const int mapWidth = 20;

const char Map[mapHeight][mapWidth] =
{
	{'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 'f', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 'f', 's', 's', 's', 's', 's', 'p', 's', 's', 's', 's', 's', 's', 'f', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 'f', 's', 's', 's', 's', 's', 's', 's', 's', 'f', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 'b', 'b', 'b', 'b', 'b', 'b', 's', 's', 's', 's', 's', 's', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 'f', 's', 's', 's', 'f', 's', 's', 's', 's', 'f', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 'f', 's', 's', 's', 's', 's', 'b', 's', 's', 's', 's', 's', 's', 'f', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 's', 's', 's', 's', 's', 's', 's', 's', 'b', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'b'},
	{'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
};

typedef const unsigned char CUC;
CUC BLOCK = 219;
CUC SPACE = 32;
CUC SNAKE = 79;
CUC TAIL = 111;
CUC FRUIT = 70;

void setCursor(int x, int y);
void showConsoleCursor(bool showFlag);
int getRandomNumber(int min, int max);

class Game {
private:
	bool m_running;

	Snake m_snake;
	Difficulty m_difficulty;
	int m_score;

	int m_FruitX;
	int m_FruitY;
	//if true generate the next fruit coordinate
	bool m_nextFruit;
	//if true spawns the next fruit
	bool m_spawnFruit;

public:
	Game();
	~Game();
	void setDifficulty();
	std::string printDifficulty() const;
	void drawMap();
	void spawnFruit();
	void hitFruit();
	void runGame();
};

#endif // REFERENCES_H_INCLUDED
