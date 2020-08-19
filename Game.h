#pragma once

#include "Console.h"
#include "Object.h"
#include "Board.h"
#include "Snake.h"
#include "Fruit.h"
#include <ctime>
#include <conio.h>

class Game
{
public:
	Game();
	~Game();

	void init();

	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning();

private:
	bool running;
	
	Snake* snake;
	Board* board;
	vector<Fruit*> fruits;
};

