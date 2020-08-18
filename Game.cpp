#include "Game.h"

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

void Game::init()
{
	// Initialize interface
	Nocursortype();
	srand((unsigned)time(NULL));
	
	// Create objects
	snake = new Snake();
	board->WelcomeScreen();

	// Set game state
	running = true;
}

void Game::handleEvents()
{
	int playAgain = 0;

	do
	{
		system("cls");
		board->drawLines();
		
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
			render();
		} while (!snake->isDead());

		board->GameOverScreeen();
		std::cin >> playAgain;
		snake->ResetAll();			//Reset o ngoai nay, do mac cong ham move cu chay if else
	} while (playAgain == 1);
}

void Game::update()
{
	// Update snake position
}

void Game::render()
{
	// Render on the screen
	snake->DrawObjects();
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
