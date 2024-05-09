#pragma once

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <unordered_map>

using namespace std;

class MapNode {
private:
	bool status;

	list<int> children;
public:
	MapNode();
	MapNode(list<int> children);
	bool getStatus();
	void setStatus(bool newStatus);
	list<int> getChildren();
	~MapNode();
};

class LevelMap {
private:
	int rowLength;
	int columnLength;

	int eatenPoints;
	int remainingPoints;

	unordered_map<int, MapNode> map;
public:
	LevelMap();
	LevelMap(vector<int> mapData);
	int getRowLength();
	int getRemainingPoints();
	int getEatenPoints();
	unordered_map<int, MapNode> getMap();
	void printMap(int playerPosition, list<int> ghostPositions);
	void updateMap(int playerPosition);
	int getNewPosition(int playerDirection, int playerPosition);
	~LevelMap();
private:
	void createMap(vector<int> mapData);
	list<int> findChildren(int currentNode, vector<int> mapData);
	bool isWall(int child, vector<int> mapData);
	bool printGhost(int currentNode, list<int> ghostPositions);
	bool validatePosition(int newPosition, int playerPosition);
};
