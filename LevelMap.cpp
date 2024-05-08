#include "LevelMap.h"

MapNode::MapNode() {
	status = true;
}

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

LevelMap::LevelMap() {
	rowLength = 0;
	columnLength = 0;
	eatenPoints = 0;
	remainingPoints = 0;
}

LevelMap::LevelMap(vector<int> mapData) {
	rowLength = *(--mapData.end());

	mapData.pop_back();

	columnLength = (int)ceil(*(--mapData.end()) / rowLength);

	eatenPoints = 0;
	remainingPoints = (int)mapData.size();

	createMap(mapData);
}

int LevelMap::getRowLength() {
	return rowLength;
}

int LevelMap::getRemainingPoints() {
	return remainingPoints;
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
	int right = (int)(mapData.size() - 1);

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
	const string backBlue = "\033[0;44m";
	const string reset = "\033[0m";

	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	cout << "\t\t";

	for (int i = 0; i < (3* rowLength + 4); ++i) {
		cout << blue << u8"\u2588" << reset;
	}

	cout << endl;

	for (int i = 0; i < columnLength; ++i) {
		cout << blue << u8"\t\t\u2588\u2588" << reset;

		for (int j = 0; j < rowLength; ++j) {
			if (map.find(currentNode) == map.end()) {
				cout << backBlue << u8"   " << reset;
			}
			else if (currentNode == playerPosition) {
				cout << yellow << u8" C " << reset;
			}
			else if (!printGhost(currentNode, ghostPositions)) {
				if (map[currentNode].getStatus()) {
					cout << u8" \u25CF ";
				}
				else {
					cout << u8" \u25CB ";
				}
			}

			++currentNode;
		}

		cout << blue << u8"\u2588\u2588" << reset << endl;
	}

	cout << "\t\t";

	for (int i = 0; i < (3 * rowLength + 4); ++i) {
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
				cout << red << " A " << reset;

				break;
			case 1:
				cout << green << " A " << reset;

				break;
			case 2:
				cout << magenta << " A " << reset;

				break;
			case 3:
				cout << cyan << " A " << reset;

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

int LevelMap::getNewPosition(int playerDirection, int playerPosition) {
	int newPosition = 0;

	switch (playerDirection) {
	case 72:	// Up
		newPosition = playerPosition - rowLength;

		if (validatePosition(newPosition, playerPosition)) {
			return newPosition;
		}

		break;
	case 77:	// Right
		newPosition = playerPosition + 1;

		if (validatePosition(newPosition, playerPosition)) {
			return newPosition;
		}

		break;
	case 80:	// Down
		newPosition = playerPosition + rowLength;

		if (validatePosition(newPosition, playerPosition)) {
			return newPosition;
		}

		break;
	case 75:	// Left
		newPosition = playerPosition - 1;

		if (validatePosition(newPosition, playerPosition)) {
			return newPosition;
		}

		break;
	default:
		break;
	}

	return -1;
}

bool LevelMap::validatePosition(int newPosition, int playerPosition) {
	for (auto child : map[playerPosition].getChildren()) {
		if (child == newPosition) {
			return true;
		}
	}

	return false;
}

LevelMap::~LevelMap() {
	map.clear();
}
