#pragma once

#include <conio.h>
#include <iostream>

using namespace std;

class Player {
public:
	int position;
public:
	Player();
	Player(int position);
	int getMove();
};
