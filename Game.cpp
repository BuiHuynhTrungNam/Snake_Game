#include "Game.h"

void Game::init()
{
	// Initialize interface
	Nocursortype();
	srand((unsigned)time(NULL));

	// Create objects
	board = new Board(50, 20);
	snake = new Snake();

	//board->WelcomeScreen();

	// Set game state
	running = true;
}

Game::Game()
{
	board = nullptr;
	snake = nullptr;
	running = false;
}

Game::~Game()
{
	if (snake) delete snake;
	if (board) delete board;
}

void Game::handleEvents()
{
	int playAgain = 0;

	do
	{
		system("cls");
		//board->drawLines();

		// Play scene
		char op;

		do
		{
			// Handle key
			if (_kbhit())
			{
				op = _getch();
				switch (op)
				{
				case 'w':
				case 'W':
					snake->TurnUp();
					break;
				case 's':
				case 'S':
					snake->TurnDown();
					break;
				case 'a':
				case 'A':
					snake->TurnLeft();
					break;
				case 'd':
				case 'D':
					snake->TurnRight();
					break;
				}
			}

			snake->Move();

			// Handle collision
			if (snake->onFruitCollision(fruits)) 
			{
				snake->EatFood();
			}
			else if (snake->isBodyCollision())
			{
				snake->setSnakeDead(true);
			}
			// TODO: handle wall collision

			render();
		} 
		while (!snake->isDead());

		// Game over scene
		board->GameOverScreeen();
		std::cin >> playAgain;

		board->clearObjects();
		snake->ResetAll();
	} 
	while (playAgain == 1);
}

void Game::update()
{
	// Update snake position
}

void Game::render()
{
	// Render on the screen
	board->drawObjects();

	Sleep(100);						//mot cho nay cho them tham so, chinh clear tao ra level
	snake->EraseTailSnake();		//Ben class Coord co ham Erase r, nen lam ham Erase tail dung cho tien
}

void Game::clean()
{
}

bool Game::isRunning()
{
	return running;
}
