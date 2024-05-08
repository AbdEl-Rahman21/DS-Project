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
	parent = nullptr;
}

Ghost::Ghost() {
	position = 0;
}

Ghost::Ghost(int position) {
	this->position = position;
}

// Hard Mode Using BFS Algorithm
int Ghost::getHardMove(int playerPosition, unordered_map<int, MapNode>& map) {
    queue<GhostNode> nodes;
    GhostNode* currentNode = nullptr;

    nodes.push(GhostNode(position, nullptr));

    currentNode = &nodes.front();

    while (!nodes.empty()) {
        // Children of each node insertion in the queue
        for (auto child : map[currentNode->position].getChildren()) {
            nodes.push(GhostNode(child, currentNode));
        }

        nodes.pop();

        currentNode = &nodes.front();   // Update currentNode

        // Pac-Man Postionition is found
        if (playerPosition == currentNode->position) {
            return currentNode->traceParent();  // Return first move in shortest path
        }
    }

    // Pac-Man position is not found
    return -1;
}

Ghost::~Ghost() {
	position = 0;
}
