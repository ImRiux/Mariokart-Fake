#include <iostream>
#include "Game.h"
#include "windows.h"
#include <ctime>
#include <cstdlib>

int main() {
    //seed
	std::srand(static_cast<unsigned int>(time(0)));

	Game game;
	game.runGame();
	system("pause");
	return 0;
}

