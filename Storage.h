#pragma once

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Storage {
public:
	int highScores[3];
	int latestScores[3];

	vector<int> map0;
	vector<int> map1;
	vector<int> map2;
	vector<int> map3;
public:
	Storage();
	void loadScores();
	void saveScores();
	void updateScores(int newScore);
	vector<int> loadMap(int mapNumber);
	~Storage();
};
