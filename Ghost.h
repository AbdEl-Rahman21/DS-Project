#pragma once

#include "LevelMap.h"
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

class GhostNode {
public:
	int position;
	
	vector<int> parents;
public:
	GhostNode();
	GhostNode(int position);
	int traceParent();
	~GhostNode();
};

class Ghost {
public:
	int position;
public:
	Ghost();
	Ghost(int position);
	void getEasyMove();
	void getMediumMove();
	void getHardMove(int playerPosition, unordered_map<int, MapNode> map);
	bool isVisited(vector<int>,int);
	~Ghost();
};
