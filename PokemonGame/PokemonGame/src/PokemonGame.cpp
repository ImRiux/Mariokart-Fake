#include "PokemonGame.h"
#include "Map.h"

#include <iostream>
#include <string>
#include <Windows.h>

int main() {
	PokemonGame *pkm_game = new PokemonGame();
	showConsoleCursor(false);
	pkm_game->runGame();
	std::cin.get();
	delete pkm_game;
	return 0;
}

void showConsoleCursor(bool showFlag) {
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

PokemonGame::PokemonGame() {
	
}
PokemonGame::~PokemonGame(){}

void PokemonGame::runGame() {
	beginningDialog();
	std::cin.get();
	system("cls");
	m_player.setXCoordinate(4);
	m_player.setYCoordinate(14);
	m_map.printMap(m_player);
}

void PokemonGame::beginningDialog() {
	printOakText("Hello and welcome to the world of pokemon!\n");
	printOakText("I'm going to tell you all about the basic sh.. stuff.\n");
	printOakText("But first, are you a boy or a girl?\n");
	unsigned char tempGender;
	std::cin >> tempGender;
	/*we wait until the user entered something valid*/
	while ((tempGender != 'B' && tempGender != 'b' && tempGender != 'G' && tempGender != 'g') || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "[Info]: Type \"b\" for boy or \"g\" for girl.\n";
		printOakText("But first, are you a boy or a girl?\n");
		std::cin >> tempGender;
	}

	/*and set then the gender of the player*/
	m_player.setGender(tempGender);

	printOakText("How are you called?\n");
	std::string tempName;
	std::cin.ignore(32767, '\n');
	std::getline(std::cin, tempName);
	/*we wait until the user entered a username which is shorter then 16 characters and longer than 2 characters*/
	while (tempName.length() <= 2 || tempName.length() > 15) {
		std::cout << "[Info]: Name must be longer than 2 characters and shorter than 16 characters!\n";
		printOakText("How are you called?\n");
		std::cout << "Your name: ";
		std::getline(std::cin, tempName);
	}

	/*and set then the username of the player*/
	m_player.setName(tempName);
	
	printOakText("Well ", m_player.getName().c_str(), " you will find me in my lab...cya later.\n");
}

void PokemonGame::print(const char *message) {
	int index = 0;
	/*we print each character with a specified sleep until we hit the null determinator*/
	while (1) {
		if (message[index] == '\0') {
			return;
		}
		std::cout << message[index];
		++index;
		Sleep(20);
	}
}

void PokemonGame::printOakText(const char *message) {
	std::cout << "Prof. Oak: ";
	print(message);
}

/*overloaded version of printOakText()*/
void PokemonGame::printOakText(const char *message1, const char *message2, const char *message3) {
	std::cout << "Prof. Oak: ";
	print(message1);
	print(message2);
	print(message3);
}