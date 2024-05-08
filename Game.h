#pragma once

#include "Ghost.h"
#include "Player.h"
#include "LevelMap.h"

#include <vector>
#include <iostream>

using namespace std;

class Game {
private:
	int gameState;
	int difficulty;
	int finalScore;

	LevelMap* map;
	Player* player;

	vector<Ghost*> ghosts;
public:
	Game();
	Game(vector<int> mapData, int difficulty);
	int getGameState();
	int getFinalScore();
	void setStartingPositions();
	bool win();
	bool lose();
	void movePlayer();
	void moveGhosts();
	void start();
	int endGame();
	~Game();
};
