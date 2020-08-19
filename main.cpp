#include "Game.h"

int main()
{
	Game *game = new Game();

	game->init();
	while (game->isRunning()) {
		game->handleEvents();
		game->update();
	}

	game->clean();
	return 0;
}