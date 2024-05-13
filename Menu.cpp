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
			displayHighScores();

			break;
		case 3:
			displayLatestScores();

			break;
		case 4:
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

void Menu::displayHighScores() {
	system("CLS");

	cout << "\t\t\t===== High Scores =====" << endl;

	for (int i = 0; i < 3; ++i) {
		cout << i + 1 << "- " << storage->highScores[i] << endl;
	}

	system("PAUSE");
}

void Menu::displayLatestScores() {
	system("CLS");

	cout << "\t\t\t===== Latest Scores =====" << endl;

	for (int i = 0; i < 3; ++i) {
		cout << i + 1 << "- " << storage->latestScores[i] << endl;
	}

	system("PAUSE");
}

int Menu::printMenu() {
	int choice = 0;

	do {
		system("CLS");

		cout << "\t\t\t===== Pac-Man =====\n1- New Game.\n2- High Scores.\n3- Latest Scores\n4- Exit.\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
		case 3:
		case 4:
			return choice;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (true);
}

void Menu::createGame() {
	selectMap();
	selectDifficulty();
}

void Menu::selectMap() {
	string choice = "\0";	// Choice is string because one of the inputs is 0

	do {
		system("CLS");

		cout << "\t\t\t===== Maps =====\n0- Map 0 (Tutorial)\n1- Map 1\n2- Map 2\n3- Map 3\nEnter your choice: ";
		getline(cin, choice);

		if (choice.size() != 1) {
			continue;
		}

		switch (choice[0]) {
		case '0':
			mapNumber = 0;

			return;
		case '1':
			mapNumber = 1;

			return;
		case '2':
			mapNumber = 2;

			return;
		case '3':
			mapNumber = 3;

			return;
		}
	} while (true);
}

void Menu::selectDifficulty() {
	int choice = -1;

	do {
		system("CLS");

		cout << "\t\t\t===== Diffculty =====\n1- Easy\n2- Medium\n3- Hard\n4- Randomizer\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
		case 3:
		case 4:
			difficulty = choice;

			return;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

	PlaySound(TEXT("./Sound Files/loop.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	game->start();
}

int Menu::printWinMenu() {
	int choice = -1;

	PlaySound(TEXT("./Sound Files/win.wav"), NULL, SND_FILENAME | SND_ASYNC);

	do {
		cout << "\t\t\t===== Win =====\n1- Return to main menu\n2- New game\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
			return choice;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (true);
}

int Menu::printLoseMenu() {
	int choice = -1;

	PlaySound(TEXT("./Sound Files/lose.wav"), NULL, SND_FILENAME | SND_ASYNC);

	do {
		cout << "\t\t\t===== Lose =====\n1- Return to main menu\n2- Restart game\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		case 2:
			return choice;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (true);
}

Menu::~Menu() {
	delete storage;
}
