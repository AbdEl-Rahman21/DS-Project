#pragma once

#include "Ghost.h"
#include "Player.h"
#include "LevelMap.h"

#include <vector>
#include <iostream>

using namespace std;

class Game {
private:
	int difficulty;

	LevelMap* map;
	Player* player;

	vector<Ghost*> ghosts;
public:
	Game();
	Game(vector<int> mapData, int difficulty);
	void setStartingPositions();
	bool win();
	bool lose();
	void movePlayer();
	~Game();
};
