#pragma once

#include "Ghost.h"
#include "Player.h"
#include "LevelMap.h"

#include <list>
#include <iostream>

using namespace std;

class Game {
private:
	int gameState;
	int difficulty;
	int finalScore;

	LevelMap* map;
	Player* player;

	list<Ghost*> ghosts;
public:
	Game();
	Game(vector<int> mapData, int difficulty);
	int getGameState();
	int getFinalScore();
	void start();
	~Game();
private:
	void setStartingPositions();
	void printBoard();
	bool win();
	bool lose();
	void movePlayer();
	void moveGhosts();
	int endGame();
};
