#include "Map.h"

#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>


void setCursor(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Map::Map() {
	setupClass();

	/*we allocate the map with mapHeight and mapLength which we setted up in setupClass()*/
	m_map = new int*[(*m_mapHeight)];
	for (int y = 0; y < (*m_mapHeight); ++y) {
		m_map[y] = new int[(*m_mapLength)];
	}

	setupMap();
}
Map::~Map() {

	/*we deallocate the map for no memory leaks :D*/
	for (int y = 0; y < (*m_mapHeight); ++y) {
		delete[] m_map[y];
	}
	delete[] m_map;

	/*we deallocate mapLength and mapHeight as well for no memory leaks :D*/
	delete m_mapLength;
	delete m_mapHeight;
}

void Map::setupClass() {
	/*we are going to allocate our map height and length variables with help from MapSupport.txt
	 *MapSupport.txt is needed, because it doesn't contain whitespaces between to numbers, which is in Map.txt the case
	 */
	std::ifstream read;
	read.open("../PokemonGame/src/MapSupport.txt");

	/*by reading all the lines we can determine the needed array height for our 2d array and allocate it our mapHeight variable*/
	if (read.is_open()) {
		std::string line;
		int temp_height = 0;
		while (std::getline(read, line)) {
			++temp_height;
		}
		m_mapHeight = new int(temp_height);
		//std::cout << *m_mapHeight << std::endl;
		read.close();
	}
	else {
		std::cout << "Can't access MapSupport.txt\n";
	}

	/*we have to close and reopen the text file, otherwise we will not start reading at the beginning*/
	read.open("../PokemonGame/src/MapSupport.txt");

	/*With a for-loop we're searching for the longest line and allocate the length to our mapLength variable*/
	if (read.is_open()) {
		std::string line;
		int temp_length = 0;
		for (int i = 0; i < (*m_mapHeight); ++i) {
			std::getline(read, line);
			if (line.length() > temp_length) {
				temp_length = line.length();
			}
		}
		m_mapLength = new int(temp_length);
		//std::cout << *m_mapLength << std::endl;
		read.close();
	}
	else {
		std::cout << "Can't access MapSupport.txt\n";
	}
}

void Map::setupMap() {
	std::ifstream read;
	read.open("../PokemonGame/src/Map.txt");
	/*we read each number from the text file and paste it into our map array*/
	if (read.is_open()) {
		for (int y = 0; y < (*m_mapHeight); ++y) {
			for (int x = 0; x < (*m_mapLength); ++x) {
				read >> m_map[y][x];
			}
		}
		read.close();
	}
	else {
		std::cout << "Can't access Map.txt\n";
	}
	read.close();
}

void Map::printMap(const Player &player) {
	unsigned char block = 219;
	/*we iterate through the map in the specified visibility range
	 *y and x are equal our player coordinate minus our specified visibility range, so we can display the player range up and left
	 *with the condition y and x are less/equal than our player coordinate plus our specified visibility range we can display the player range down and right
	*/
	for (int y = player.getYCoordinate() - m_range; y <= player.getYCoordinate() + m_range; ++y) {

		/*If players y coordinate is out of the array-range(because we subtract the visibility range), we have to bring it back into the array-range*/
		if (y < 0) {
			y = 0;
		}
		/*If players y coordinate is out of the array-range(because we add the visibility range in the condition), we can end the whole function*/
		else if (y >= (*m_mapHeight)) {
			return;
		}

		for (int x = player.getXCoordinate() - m_range; x <= player.getXCoordinate() + m_range; ++x) {

			/*If players x coordinate is out of the array-range(because we subtract the visibility range), we have to bring it back into the array-range*/
			if (x < 0) {
				x = 0;
			}
			/*If players x coordinate is out of the array-range(because we add the visibility range in the condition), we can end this for loop and continue with the next y-line*/
			else if (x >= (*m_mapLength)) {
				break;
			}

			/*If we find players y and x coordinate we can print the player*/
			if (y == player.getYCoordinate() && x == player.getXCoordinate()) {
				std::cout << "*";
			}
			/*Else we can print the map symbols */
			else {
				switch (m_map[y][x]) {
				case 1:
					std::cout << block;
					break;
				case 2:
					std::cout << "A";
					break;
				default: break;
				}
			}
		}
		/*After we iterated trough one y-line, we have to std::endl for the next y-line*/
		std::cout << std::endl;
	}
}