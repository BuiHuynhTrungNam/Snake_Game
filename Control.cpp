#include"Control.h"
void PlayGame::PlayMode_1(Snake& snake){
	char op;
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
			snake.Move();
		}
		else {
			snake.Move();
		}
		if (snake.isDead()) break;
	} while (true); 
}