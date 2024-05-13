#pragma once
#pragma comment(lib, "Winmm.lib")

#include "Game.h"
#include "Storage.h"

#include <limits>
#include <string>
#include <iostream>
#include <Windows.h>

#undef max

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
	void displayHighScores();
	void displayLatestScores();
	void startGame();
	void createGame();
	void selectMap();
	void selectDifficulty();
	int printWinMenu();
	int printLoseMenu();
	int printMenu();
	~Menu();
};
