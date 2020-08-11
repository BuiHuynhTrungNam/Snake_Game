#pragma once
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

	bool running();

private:
	bool isRunning;

};

