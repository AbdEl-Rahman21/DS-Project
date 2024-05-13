#include "Storage.h"

Storage::Storage() {
	loadScores();

	map0 = loadMap(0);
	map1 = loadMap(1);
	map2 = loadMap(2);
	map3 = loadMap(3);
}

void Storage::loadScores() {
	ifstream scoreFile;

	scoreFile.open("Scores.txt", ios::in);

	for (int i = 0; i < 3; ++i) {
		scoreFile >> highScores[i];
	}

	for (int i = 0; i < 3; ++i) {
		scoreFile >> latestScores[i];
	}

	scoreFile.close();
}

void Storage::saveScores() {
	ofstream scoreFile;

	scoreFile.open("Scores.txt", ios::out | ios::trunc);

	for (int i = 0; i < 3; ++i) {
		scoreFile << highScores[i] << endl;
	}

	for (int i = 0; i < 3; ++i) {
		scoreFile << latestScores[i] << endl;
	}

	scoreFile.close();
}

void Storage::updateScores(int newScore) {
	for (int i = 0; i < 3; ++i) {
		if (highScores[i] <= newScore) {
			for (int j = 2; j > i; --j) {
				highScores[j] = highScores[j - 1];
			}

			highScores[i] = newScore;

			break;
		}
	}

	for (int j = 2; j > 0; --j) {
		latestScores[j] = latestScores[j - 1];
	}

	latestScores[0] = newScore;
}

vector<int> Storage::loadMap(int mapNumber) {
	int node = 1;

	vector<int> map;

	ifstream mapFile;

	string row = "\0";
	string mapLocation = "\0";

	switch (mapNumber) {
	case 0:
		mapLocation = "Map0.txt";

		break;
	case 1:
		mapLocation = "Map1.txt";

		break;
	case 2:
		mapLocation = "Map2.txt";

		break;
	case 3:
		mapLocation = "Map3.txt";

		break;
	}

	mapFile.open(mapLocation, ios::in);

	while (getline(mapFile, row)) {
		for (int i = 0; i < row.length(); ++i) {
			if (row[i] == '.') {
				map.push_back(node);
			}

			++node;
		}
	}

	mapFile.clear();
	mapFile.seekg(ios::beg);

	getline(mapFile, row);

	map.push_back((int)row.length());

	mapFile.close();

	return map;
}

Storage::~Storage() {
	saveScores();

	map0.clear();
	map1.clear();
	map2.clear();
	map3.clear();
}
