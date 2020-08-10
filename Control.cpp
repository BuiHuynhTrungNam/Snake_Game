#pragma once
#include"Control.h"
void PlayGame::PlayMode_1(Snake& snake, int option){
	char op = 's'; //s = start
	do {
		if (_kbhit()) {
			op = _getch();
			switch (op)
			{
			case'w':
			case'W':
				snake.TurnUp();
				break;
			case's':
			case'S':
				snake.TurnDown();
				break;
			case'a':
			case'A':
				snake.TurnLeft();
				break;
			case'd':
			case'D':
				snake.TurnRight();
				break;
			}
			snake.Move(option);
		}
		else {
			snake.Move(option);
		}
	} while (op != 'q'); //q = quit
}