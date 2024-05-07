#pragma once

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Storage {
public:
	vector<int> map1;
	vector<int> map2;
	vector<int> map3;
public:
	Storage();
	vector<int> loadMap(int mapNumber);
	~Storage();
};
