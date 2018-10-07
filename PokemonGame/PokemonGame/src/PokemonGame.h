#pragma once

#include "Map.h"
#include "Player.h"

void showConsoleCursor(bool showFlag);

class PokemonGame {
private:
	Map m_map;
	Player m_player;

	void print(const char *message);
	void printOakText(const char *message);
	void printOakText(const char *message1, const char *message2, const char *message3);

	void beginningDialog();
public:
	PokemonGame();
	~PokemonGame();

	void runGame();
};