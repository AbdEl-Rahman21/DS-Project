#include "Game.h"

Game::Game() {
    gameState = -1;
    finalScore = 0;
    difficulty = 0;
    map = nullptr;
    player = nullptr;
}

Game::Game(vector<int> mapData, int difficulty) {
    gameState = -1;
    finalScore = 0;

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

int Game::getGameState() {
    return gameState;
}

int Game::getFinalScore() {
    return finalScore;
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

void Game::moveGhosts() {
    for (int i = 0; i < ghosts.size(); ++i) {
        switch (difficulty) {
        case 1:
            //ghosts[i]->getEasyMove();

            break;
        case 2:
            //ghosts[i]->getMediumMove();

            break;
        case 3:
            ghosts[i]->getHardMove(player->position, map->getMap());

            break;
        }
    }
}

void Game::start() {
    int *ghostPositions = new int[ghosts.size()];

    map->updateMap(player->position);

    while (true) {
        for (int i = 0; i < ghosts.size(); ++i) {
            ghostPositions[i] = ghosts[i]->position;
        }

        map->printMap(player->position, ghostPositions);

        if (endGame() != -1) {
            break;
        }

        movePlayer();

        map->updateMap(player->position);
        map->printMap(player->position, ghostPositions);

        if (endGame() != -1) {
            break;
        }

        moveGhosts();
    }
}

int Game::endGame() {
    if (lose()) {
        gameState = 0;
    }
    else if (win()) {
        gameState = 1;
    }

    return gameState;
}

Game::~Game() {
    map = nullptr;
    player = nullptr;

    ghosts.clear();
}
