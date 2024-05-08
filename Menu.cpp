#include "Menu.h"
void Menu::startgame() {
	game = new Game(map,diff);
}
void Menu::printmenu()
{
	cout << "Welcome to Pac-Man game\nMain Menu\nChoose from below:\n1)New Game\n2)Score History ";
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:
		gamesett();
		startgame();
		break;
	case 2:
		//storage;
		break;
	default:
		break;
	}
}
void Menu::aftergamew()
{
	cout << "Choose from below:\n1)Main menu\n2)New game\n";
	int choice4 = 0;
	cin >> choice4;
	switch (choice4)
	{
	case 1:
		printmenu();
		break;
	case 2:
		gamesett();
		startgame();
		break;
	default:
		break;
	}
}
void Menu::aftergamel()
{
	cout << "Choose from below:\n1)Main menu\n2)Restart game\n";
	int choice4 = 0;
	cin >> choice4;
	switch (choice4)
	{
	case 1:
		printmenu();
		break;
	case 2:
		startgame();
		break;
	default:
		break;
	}
}
void Menu::gamesett()
{
	cout << "Choose your Map:\n1)Map1\n2)Map2\n3)Map3\n4)Map4(practice)";
	int choice2 = 0;
	cin >> choice2;
	switch (choice2)
	{
	case 1:
		map = 1;
		break;
	case 2:
		map = 2;
		break;
	case 3:
		map = 3;
		break;
	case 4:
		map = 4;
		break;
	default:
		break;

	}
	cout << "Choose your diffculty:\n1)easy\n2)Medium\n3)Hard";
	int choice3 = 0;
	cin >> choice3;
	switch (choice3)
	{
	case 1:
		diff = 1;
		break;
	case 2:
		diff = 2;
		break;
	case 3:
		diff = 3;
		break;
	default:
		break;

	}
}
Menu::Menu()
{
	 map = 0, diff = 0;
}
/*int main()
{
	menu();
	cout << map << "\n " << diff;
	system("pause");
	return 0;
}*/