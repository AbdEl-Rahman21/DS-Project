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
    delete parent;
}

Ghost::Ghost() {
	position = 0;
}

Ghost::Ghost(int position) {
	this->position = position;
}

// Hard Mode Using BFS Algorithm
void Ghost::getHardMove(int playerPosition, unordered_map<int, MapNode> map) {
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
            position = currentNode->traceParent();  // Set position to first move in shortest path

            break;
        }
    }
}

Ghost::~Ghost() {
	position = 0;
}
