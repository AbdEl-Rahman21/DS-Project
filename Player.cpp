#include "Player.h"
#include<iostream>
#include<conio.h>
using namespace std;
int Player::get_direction()
{
    int c, direction;
    c = _getch();
    if (c && c != 224)
    {
        cout << endl << "Not arrow: " << (char)c << endl;
    }
    else
    {
        switch (direction = _getch())
        {
            //up
        case 72:
            return 72;
            break;
            //left
        case 75:
            return 75;
            break;
            //right
        case 77:
            return 77;
            break;
            //down
        case 80:
            return 80;
            break;
            //not arrow
        default:
            return -1;
            break;
        }
    }
}