#pragma once

#include "Ghost.h"
#include "Player.h"
#include "LevelMap.h"

#include <vector>
#include <iostream>

using namespace std;

class Game {
private:
	LevelMap* map;
	Player* player;
	int difficulty;
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
