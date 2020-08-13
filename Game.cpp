#include "Game.h"

Game::Game()
{
	board = nullptr;
	snake = nullptr;
	running = false;
}

Game::~Game()
{
}

void Game::init()
{
	Nocursortype();		//hide pointer
	srand((unsigned)time(NULL));

	snake = new Snake();	//object to play

	running = true;

	board->WelcomeScreen();
	int option = board->PlayMode();

	int PlayAgain;
	if (option == 1) {
		do {
			system("cls");
			board->drawLines();
			//Map::MapClassic();
			// PlayGame::PlayMode_1(snake);
			board->GameOverScreeen();
			cin >> PlayAgain;
		} while (PlayAgain == 1);
	}


	system("cls");
}

void Game::handleEvents()
{


	char op = 's'; //s = start
	do {
		if (_kbhit()) {
			op = _getch();
			switch (op)
			{
			case'w':
			case'W':
				snake->TurnUp();
				break;
			case's':
			case'S':
				snake->TurnDown();
				break;
			case'a':
			case'A':
				snake->TurnLeft();
				break;
			case'd':
			case'D':
				snake->TurnRight();
				break;
			}
		}
		snake->Move();
	} while (op != 'q'); //q = quit

}

void Game::update()
{
}

void Game::render()
{
}

void Game::clean()
{
}

bool Game::isRunning()
{
	return running;
}
