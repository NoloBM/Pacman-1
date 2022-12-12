// Pacman-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAP_VERTICAL 30
#define MAP_HORIZONTAL 120
enum TILES { EMPTY = ' ', WALL = '#', POINT = '.' };
TILES map[MAP_VERTICAL][MAP_HORIZONTAL];
bool run = true;

enum INPUT { QUIT, UP, DOWN, LEFT, RIGHT, UNKNOW };
INPUT currentInput = INPUT::UNKNOW;

void Setup() {
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == 0 || j == 0 || i == MAP_VERTICAL - 1 || j == MAP_HORIZONTAL - 1) {
				map[i][j] = TILES::WALL;
			}
			else {
				map[i][j] = TILES::EMPTY;
			}
		}

	}

}

void Input() {
	char input;
	std::cin >> input;
	switch (input)
	{
	case 'w':
	case 'W':
		currentInput = INPUT::UP;
		break;
	case 'q':
	case 'Q':
		currentInput = INPUT::QUIT;
		break;
	case 's':
	case 'S':
		currentInput = INPUT::DOWN;
		break;
	case 'a':
	case 'A':
		currentInput = INPUT::LEFT;
		break;
	case 'd':
	case 'D':
		currentInput = INPUT::RIGHT;
		break;
	default:
		currentInput = INPUT::UNKNOW;
		break;
	}

}

void Logic(){
	switch (currentInput)
	{
	case QUIT:
		run = false;
 break;
case UP:
 break;
case DOWN:
 break;
case LEFT:
 break;
case RIGHT:
 break;
	}
}

void Draw() {
	system("CLS");
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			std::cout << (char)map[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	Setup();
	Draw();
	while (run)
	{
		Input();
		Logic();
		Draw();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
