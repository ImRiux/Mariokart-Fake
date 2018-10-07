#pragma once

#include "Player.h"

void setCursor(int x, int y);

class Map {
private:
	const int *m_mapLength;
	const int *m_mapHeight;
	int **m_map;

	const int m_range = 5;

	void setupClass();
	void setupMap();
public:
	Map();
	~Map();

	void printMap(const Player &player);
};
