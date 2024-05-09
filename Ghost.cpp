#include "Ghost.h"

Ghost::Ghost() {
	position = 0;
}

Ghost::Ghost(int position) {
	this->position = position;
}

bool Ghost::isVisited(list<int> visitedNodes , int node) {
    for (int visitedNode : visitedNodes) {
        if (visitedNode == node) {
            return true;
        }
    }

    return false;
}

void Ghost::getHardMove(int playerPosition, unordered_map<int, MapNode> map) {  // Hard Mode Using BFS Algorithm
    list<int> visitedNodes;
    queue<pair<int, int>> nodes;    // First value is the position, Second value is the first move in the path

    pair<int, int> currentNode;

    nodes.push(make_pair(position, 0)); // Current position of ghost
 
    currentNode = nodes.front();

    visitedNodes.push_back(currentNode.first);

    for (int child : map[currentNode.first].getChildren()) {
        visitedNodes.push_back(child);

        nodes.push(make_pair(child, child));    // Set the first move in the path
    }

    while (!nodes.empty()) {
        nodes.pop();

        currentNode = nodes.front();

        if (playerPosition == currentNode.first) {  // Pac-Man Postionition is found
            position = currentNode.second;  // Set position to first move in shortest path

            break;
        }

        for (int child : map[currentNode.first].getChildren()) {    // Children of each node insertion in the queue
            if (!isVisited(visitedNodes, child)) {
                visitedNodes.push_back(child);

                nodes.push(make_pair(child, currentNode.second));
            }
        }
    }
}
