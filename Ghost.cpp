#include "Ghost.h"

GhostNode::GhostNode() {
	position = 0;
	parent = nullptr;
}

GhostNode::GhostNode(int position, GhostNode* parent) {
	this->position = position;
	this->parent = parent;
}

int GhostNode::traceParent() {
    GhostNode* currentNode = this;

    while (currentNode->parent->parent != nullptr) {
        currentNode = currentNode->parent;
    }

    return currentNode->position;
}

GhostNode::~GhostNode() {
   // if (parent != nullptr)
    //delete parent;
}

Ghost::Ghost() {
	position = 0;
}

Ghost::Ghost(int position) {
	this->position = position;
}
bool Ghost::isVisited(vector<int> VisitedNodes , int child)
{
    for (int i = 0; i < VisitedNodes.size(); i++)
    {
        if (VisitedNodes[i] == child)
            return true;
    }
    return false;
}

// Hard Mode Using BFS Algorithm
void Ghost::getHardMove(int playerPosition, unordered_map<int, MapNode> map) {
    queue<GhostNode> nodes;
    GhostNode* currentNode = nullptr;
    vector<int>VisitedNodes;
    nodes.push(GhostNode(position, nullptr));
 
    currentNode = &nodes.front();
  //  nodes.pop();
    while (!nodes.empty()) {
        // Children of each node insertion in the queue
        VisitedNodes.push_back(currentNode->position);
        for (auto child : map[currentNode->position].getChildren()) {
            if(!isVisited(VisitedNodes,child))
                nodes.push(GhostNode(child, currentNode));  
        }
        nodes.pop();

        currentNode = &nodes.front();   // Update currentNode

        // Pac-Man Postionition is found
        if (playerPosition == currentNode->position) {
            position = currentNode->traceParent();  // Set position to first move in shortest path

            break;
        }
    }
}

Ghost::~Ghost() {
	position = 0;
}
