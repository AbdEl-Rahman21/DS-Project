#pragma once

#include "LevelMap.h"

#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

class GhostNode {
public:
	int position;

	GhostNode* parent;
public:
	GhostNode();
	GhostNode(int position, GhostNode* parent);
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
	~Ghost();
};
