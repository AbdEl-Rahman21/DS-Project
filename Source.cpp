#include <iostream>
#include "Storage.h"
#include "LevelMap.h"

using namespace std;

int main() {
	int a[] = {1, 26,729,754};
	Storage s;

	LevelMap m(s.map3);
	m.updateMap(273);
	m.printMap(274, a);

	return 0;
}