#include "LevelMap.h"

MapNode::MapNode(list<int> children) {
	status = true;
	this->children = children;
}

bool MapNode::getStatus() {
	return status;
}

void MapNode::setStatus(bool newStatus) {
	status = newStatus;
}

list<int> MapNode::getChildren() {
	return children;
}

MapNode::~MapNode() {
	children.clear();
}

LevelMap::LevelMap(vector<int> mapData) {
	rowLength = *(--mapData.end());

	mapData.pop_back();

	columnLength = ceil(*(--mapData.end()) / rowLength);

	eatenPoints = 0;
	remainingPoints = mapData.size();

	createMap(mapData);
}

void LevelMap::createMap(vector<int> mapData) {
	int currentNode = 0;

	for (int i = 0; i < mapData.size(); ++i) {
		currentNode = mapData[i];

		map[currentNode] = *(new MapNode(findChildren(currentNode, mapData)));
	}
}

list<int> LevelMap::findChildren(int currentNode, vector<int> mapData) {
	int child = 0;
	list<int> children;

	child = currentNode + 1;	// Right Child

	if (currentNode % rowLength != 0 && !isWall(child, mapData)) {
		children.push_back(child);
	}

	child = currentNode + rowLength;	// Bottom Child

	if (!isWall(child, mapData)) {
		children.push_back(child);
	}

	child = currentNode - 1;	// Left Child

	if (child % rowLength != 0 && !isWall(child, mapData)) {
		children.push_back(child);
	}

	child = currentNode - rowLength;	// Top Child

	if (!isWall(child, mapData)) {
		children.push_back(child);
	}

	return children;
}

bool LevelMap::isWall(int child, vector<int> mapData) {
	int left = 0;
	int middle = 0;
	int right = mapData.size() - 1;

	while (left <= right) {
		middle = left + (right - left) / 2;

		if (mapData[middle] == child) {
			return false;
		}
		else if (mapData[middle] < child) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}

	return true;
}

void LevelMap::printMap(int playerPosition, int ghostPositions[]) {
	int currentNode = 1;

	const string yellow = "\033[1;33m";
	const string blue = "\033[0;34m";
	const string reset = "\033[0m";

	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	for (int i = 0; i < (rowLength + 1); ++i) {
		cout << blue << u8"\u2588" << reset;
	}

	cout << endl;

	for (int i = 0; i < columnLength; ++i) {
		cout << blue << u8"\u2588" << reset;

		for (int j = 0; j < rowLength; ++j) {
			if (map.find(currentNode) == map.end()) {
				cout << blue << u8"\u2588" << reset;
			}
			else if (currentNode == playerPosition) {
				cout << yellow << "C" << reset;
			}
			else if (!printGhost(currentNode, ghostPositions)) {
				if (map[currentNode].getStatus()) {
					cout << u8"\u25CF";
				}
				else {
					cout << u8"\u25CB";
				}
			}

			++currentNode;
		}

		cout << blue << u8"\u2588" << reset << endl;
	}

	for (int i = 0; i < (rowLength + 1); ++i) {
		cout << blue << u8"\u2588" << reset;
	}

	cout << endl;
}

bool LevelMap::printGhost(int currentNode, int ghostPositions[]) {
	const string red = "\033[1;31m";
	const string green = "\033[1;32m";
	const string magenta = "\033[1;35m";
	const string cyan = "\033[1;36m";
	const string reset = "\033[0m";

	for (int i = 0; i < 4; ++i) {
		if (ghostPositions[i] == currentNode) {
			switch (i) {
			case 0:
				cout << red << "A" << reset;

				break;
			case 1:
				cout << green << "A" << reset;

				break;
			case 2:
				cout << magenta << "A" << reset;

				break;
			case 3:
				cout << cyan << "A" << reset;

				break;
			}

			return true;
		}
	}

	return false;
}

void LevelMap::updateMap(int playerPosition) {
	if (map[playerPosition].getStatus()) {
		map[playerPosition].setStatus(false);

		++eatenPoints;
		--remainingPoints;
	}
}

LevelMap::~LevelMap() {
	map.clear();
}
