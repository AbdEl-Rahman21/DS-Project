#pragma once
#include "Game.h"
#include<iostream> 
#include<queue>
#include<vector>
#include<unordered_map>
#include"node.h"
using namespace std;
class Game
{
	int findParent(node*);
	int Hard_Mode(int, int, unordered_map <int, Node>& map);
	bool win(int food);
	bool lose(int playerPosition, int ghostPosition[4]);
	void move_player();
};

