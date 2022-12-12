// Pacman-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Windows.h>
#define MAP_VERTICAL 30
#define MAP_HORIZONTAL 120
#define PERSONAJE 'O'
enum TILES { EMPTY = ' ', WALL = '#', POINT = '.' };
TILES map[MAP_VERTICAL][MAP_HORIZONTAL];
bool run = true;

enum INPUT { QUIT, UP, DOWN, LEFT, RIGHT, UNKNOW };
INPUT currentInput = INPUT::UNKNOW;

int personaje_x;
int personaje_y;
int puntuacion_actual = 0;
int puntuacion_total;

void Setup() {
	personaje_x = MAP_HORIZONTAL / 2;
	personaje_y = MAP_VERTICAL / 2;
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
	map[10][10] = TILES::POINT;
	map[10][12] = TILES::POINT;
	map[10][11] = TILES::POINT;
	map[10][18] = TILES::POINT;
	map[10][17] = TILES::POINT;
	map[10][16] = TILES::POINT;
	map[10][15] = TILES::POINT;
	map[17][11] = TILES::POINT;
	map[16][11] = TILES::POINT;
	map[15][11] = TILES::POINT;
	map[14][11] = TILES::POINT;
	map[13][11] = TILES::POINT;
	map[12][11] = TILES::POINT;
	map[11][11] = TILES::POINT;
	map[10][14] = TILES::POINT;
	map[10][13] = TILES::POINT;

	map[10][0] = TILES::EMPTY;
	map[11][0] = TILES::EMPTY;
	map[12][0] = TILES::EMPTY;
	map[13][0] = TILES::EMPTY;

	map[10][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[11][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[12][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[13][MAP_HORIZONTAL - 1] = TILES::EMPTY;

	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (map[i][j] == TILES::POINT) {
				puntuacion_total++;
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
	int personaje_y_new = personaje_y;
	int personaje_x_new = personaje_x;
	switch (currentInput)
	{
	case QUIT:
		run = false;
 break;
case UP:
	personaje_y_new--;
 break;
case DOWN:
	personaje_y_new++;
 break;
case LEFT:
	personaje_x_new--;
 break;
case RIGHT:
	personaje_x_new++;
 break;
	}
	if (personaje_x_new < 0) {
		personaje_x_new = MAP_HORIZONTAL - 1;
	}
	personaje_x_new = personaje_x_new % MAP_HORIZONTAL;


	switch (map[personaje_y_new][personaje_x_new])
	{
	case TILES::WALL:
		break;
	case TILES::POINT:
		puntuacion_actual++;
		map[personaje_y_new][personaje_x_new] = TILES::EMPTY;
	default:
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
		break;
	}

}

void Draw() {
	system("CLS");
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == personaje_y && j == personaje_x) {

				std::cout << PERSONAJE;
			}
			else {
				std::cout << (char)map[i][j];
			}
		}
		std::cout << std::endl;
	}
	std::cout << puntuacion_actual << '/' << puntuacion_total;
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
