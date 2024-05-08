#include "Game.h"

Game::Game() {
    difficulty = 0;
    map = nullptr;
    player = nullptr;
}

Game::Game(vector<int> mapData, int difficulty) {
    this->difficulty = difficulty;
    map = new LevelMap(mapData);

    setStartingPositions();
}

void Game::setStartingPositions() {
    if (map->getRowLength() == 26) {    // Maps 1, 2, 3
        player = new Player(273);

        ghosts.push_back(new Ghost(1));
        ghosts.push_back(new Ghost(26));
        ghosts.push_back(new Ghost(729));
        ghosts.push_back(new Ghost(754));
    }
    else {  // Map 0
        player = new Player(13);

        ghosts.push_back(new Ghost(1));
        ghosts.push_back(new Ghost(25));
    }
}

bool Game::lose() {
    for (int i = 0; i < ghosts.size(); i++) {
        if (player->position == ghosts[i]->position) {
            return true;
        }
    }

    return false;
}

bool Game::win() {
    if (map->getRemainingPoints() == 0) {
        return true;
    }

    return false;
}

void Game::movePlayer() {
    int newPosition = 0;
    
    while (true) {
        newPosition = map->getNewPosition(player->getMove(), player->position);

        if (newPosition != -1) {
            player->position = newPosition;

            break;
        }

        cout << "Invaild Move!" << endl;
    }
}
