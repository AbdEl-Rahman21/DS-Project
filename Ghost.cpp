#include "Ghost.h"

GhostNode::GhostNode() {
	position = 0;
}

GhostNode::GhostNode(int position) {
	this->position = position;
}

int GhostNode::traceParent() {
    return parents.at(1);
}

GhostNode::~GhostNode() {
    parents.clear();
}

Ghost::Ghost() {
	position = 0;
}

Ghost::Ghost(int position) {
	this->position = position;
}

bool Ghost::isVisited(vector<int> VisitedNodes , int child) {
    for (int i = 0; i < VisitedNodes.size(); ++i) {
        if (VisitedNodes[i] == child) {
            return true;
        }
    }

    return false;
}

// Hard Mode Using BFS Algorithm
void Ghost::getHardMove(int playerPosition, unordered_map<int, MapNode> map) {
    queue<GhostNode> nodes;
    GhostNode* currentNode = nullptr;
    vector<int> VisitedNodes;
    nodes.push(GhostNode(position));
 
    currentNode = &nodes.front();

    VisitedNodes.push_back(currentNode->position);

    while (!nodes.empty()) {
        // Children of each node insertion in the queue
        for (int child : map[currentNode->position].getChildren()) {
            if (!isVisited(VisitedNodes, child)) {
                VisitedNodes.push_back(child);
                nodes.push(GhostNode(child));
                nodes.back().parents = currentNode->parents;
                nodes.back().parents.push_back(currentNode->position);
            }
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
