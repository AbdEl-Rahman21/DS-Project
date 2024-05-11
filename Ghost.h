#pragma once

#include "LevelMap.h"

#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

class Ghost {
public:
	int position;
public:
	Ghost();
	Ghost(int position);
	int getRandomMove(list<int> possibleMoves);
	void getEasyMove(unordered_map<int, MapNode> map);
	void getMediumMove(unordered_map<int, MapNode> map);
	void getHardMove(int playerPosition, unordered_map<int, MapNode> map);
	bool isVisited(list<int> visitedNodes, int node);
};
