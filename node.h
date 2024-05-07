#pragma once
#include<iostream>
#include<vector>
#include"node.h"
using namespace std;
class node
{
public:
	int Position;
	node* Parent;
	node();
	node(int, node*);
};

class Node
{
public:
	int position;
	vector<int> child;
};