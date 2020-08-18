#pragma once
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Coord.h"

using namespace std;

class Board {
private:
	//There are points in a board
	vector<Coord> _points;
public:
	Coord createObject(Coord object, int x, int y);
	int PlayMode();
	bool isOccupied();
	void WelcomeScreen();
	//void MainMenu(Snake& snake);
	void GameOverScreeen();
	void drawLines();
	void MapClassic();
};