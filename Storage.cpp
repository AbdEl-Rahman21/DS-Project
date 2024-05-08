#include "Storage.h"

Storage::Storage() {
	map1 = loadMap(1);
	map2 = loadMap(2);
	map3 = loadMap(3);
}

vector<int> Storage::loadMap(int mapNumber) {
	int node = 1;

	vector<int> map;

	ifstream mapFile;

	string row = "\0";
	string mapLocation = "\0";

	if (mapNumber == 1) {
		mapLocation = "Map1.txt";
	}
	else if(mapNumber == 2) {
		mapLocation = "Map2.txt";
	}
	else {
		mapLocation = "Map3.txt";
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

	map.push_back(row.length());

	mapFile.close();

	return map;
}

Storage::~Storage() {
	map1.clear();
	map2.clear();
	map3.clear();
}
