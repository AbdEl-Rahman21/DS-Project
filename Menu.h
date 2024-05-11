#pragma once

#include "Game.h"
#include "Storage.h"

#include <iostream>

using namespace std;

class Menu {
private:
	int mapNumber;
	int difficulty;

	Game* game;
	Storage* storage;
public:
	Menu();
	void run();
	void displayScores();
	void startGame();
	void createGame();
	void selectMap();
	void selectDifficulty();
	int printWinMenu();
	int printLoseMenu();
	int printMenu();
	~Menu();
};
