#include "Menu.h"

Menu::Menu() {
	mapNumber = 0;
	difficulty = 0;
	game = nullptr;
	storage = new Storage();
}

void Menu::run() {
	int choice = 0;

	do {
		choice = printMenu();

		switch (choice) {
		case 1:
			createGame();

			startGame();

			break;
		case 2:
			displayScores();

			break;
		case 3:
			return;
		}

		while (game != nullptr) {
			storage->updateScores(game->getFinalScore());

			if (game->getGameState() == 1) {
				choice = printWinMenu();

				switch (choice) {
				case 1:
					delete game;

					game = nullptr;

					break;
				case 2:
					createGame();

					startGame();

					break;
				}
			}
			else {
				choice = printLoseMenu();

				switch (choice) {
				case 1:
					delete game;

					game = nullptr;

					break;
				case 2:
					startGame();

					break;
				}
			}
		}
	} while (true);
}

void Menu::displayScores() {
	system("CLS");

	cout << "\t\t\t===== High Scores =====" << endl;

	for (int i = 0; i < 3; ++i) {
		cout << i + 1 << "- " << storage->scores[i] << endl;
	}

	system("PAUSE");
}

int Menu::printMenu() {
	int choice = 0;

	do {
		system("CLS");

		cout << "\t\t\t===== Pac-Man =====\n1- New Game.\n2- High Scores.\n3- Exit.\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
		case 3:
			return choice;
		}

	} while (true);
}

void Menu::createGame() {
	selectMap();
	selectDifficulty();
}

void Menu::selectMap() {
	int choice = -1;

	do {
		system("CLS");

		cout << "\t\t\t===== Maps =====\n0- Map 0 (Tutorial)\n1- Map 1\n2- Map 2\n3- Map 3\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
		case 1:
		case 2:
		case 3:
			mapNumber = choice;

			return;
		}

	} while (true);
}

void Menu::selectDifficulty() {
	int choice = -1;

	do {
		system("CLS");

		cout << "\t\t\t===== Diffculty =====\n1- Easy\n2- Medium\n3- Hard\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
		case 3:
			difficulty = choice;

			return;
		}

	} while (true);
}

void Menu::startGame() {
	vector<int> mapData;

	switch (mapNumber) {
	case 0:
		mapData = storage->map0;

		break;
	case 1:
		mapData = storage->map1;

		break;
	case 2:
		mapData = storage->map2;

		break;
	case 3:
		mapData = storage->map3;

		break;
	}

	game = new Game(mapData, difficulty);

	game->start();
}

int Menu::printWinMenu() {
	int choice = -1;

	do {
		cout << "\t\t\t===== Win =====\n1- Return to main menu\n2- New game\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
			return choice;
		}

	} while (true);
}

int Menu::printLoseMenu() {
	int choice = -1;

	do {
		cout << "\t\t\t===== Lose =====\n1- Return to main menu\n2- Restart game\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
			return choice;
		}

	} while (true);
}

Menu::~Menu() {
	delete storage;
}
