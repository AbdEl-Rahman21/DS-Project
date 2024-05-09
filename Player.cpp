#include "Player.h"

Player::Player() {
    position = 0;
}

Player::Player(int position) {
    this->position = position;
}

int Player::getMove() {
    int choice = 0;
    int direction = 0;

    while (true) {
        choice = _getch();  // The first of two values

        if (choice && choice != 224) {  // Check that the input is an arrow key
            cout << "Invalid Input!" << endl << "Only use arrow keys!" << endl;
        }
        else {
            switch (choice = _getch()) { // The second of two values
            case 72:    // Up
            case 77:    // Left
            case 80:    // Down
            case 75:    // Right
                return choice;
            default:    // Function Key
                break;
            }
        }
    }
}
