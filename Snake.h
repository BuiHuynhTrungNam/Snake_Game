#pragma once
#include <deque>

#include "Object.h"
#include "Board.h"
#include "Fruit.h"
#include "Console.h"

using namespace std;

enum class Direction {
	up = 'w',
	down = 's',
	left = 'a',
	right = 'd',
	dead_beat = '\0'
};

class SnakeSegment : public Object {
public:
	SnakeSegment();
	SnakeSegment(int x, int y);
};

class Snake {
private:
	Board* _board;
	deque<SnakeSegment*> cells;
	Direction dir;	//current director of snake
	bool dead;

public:
	Snake();

	void push_back(COORD coord);

	void linkBoard(Board *board);

	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();
	bool onFruitCollision(vector<Fruit*> fruits);
	void EatFood();

	void handleHeadMove();
	bool isBodyCollision();
	void FreeLastSegment();
	void DrawObjects();

	bool isDead() { return dead; }
	void Move();

	void setSnakeDead(bool status);

	void ResetAll();
	void EraseTailSnake();
};
