#include "Storage.h"

Storage::Storage() {
	map0 = loadMap(0);
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

	map.push_back(row.length());

	mapFile.close();

	return map;
}

Storage::~Storage() {
	map0.clear();
	map1.clear();
	map2.clear();
	map3.clear();
}
