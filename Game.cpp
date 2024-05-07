#include "Game.h"
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include"node.h"
using namespace std;
int Game::findParent(node* x)
{
    while (x->Parent->Parent != NULL)
        x = x->Parent;
    return x->Position;
}
int Game::Hard_Mode(int PacMan_Pos, int Ghost_Pos, unordered_map<int, Node>& map)
{
//Hard Mode using BFS Algorithm 
    queue<node> Ghost_Q;
    Ghost_Q.push(node(Ghost_Pos, nullptr));

    vector<int>::iterator itr;

while (!Ghost_Q.empty())
{
    //Children of each node insertion in the queue
    itr = map[Ghost_Q.front().Position].child.begin();
    while (itr != map[Ghost_Q.front().Position].child.end())
    {
        Ghost_Q.push(node(*itr, Ghost_Q.front().Parent));
        itr++;
    }
    Ghost_Q.pop();
    //Pac-Man Postionition is found
    if (PacMan_Pos == Ghost_Q.front().Position)
    {
        int Best_Move = findParent(Ghost_Q.front().Parent);
        return Best_Move;
    }
}
//Pac-Man position is not found
return -1;
}
