#pragma once
#include <deque>
#include <vector>
#include "Object.h"
#include "Fruit.h"
#include "Console.h"

using namespace std;

class Fruit;

enum class Direction {
	up = 'w',
	down = 's',
	left = 'a',
	right = 'd',
	dead_beat = '\0'
};

class SnakeSegment : public Object {
public:
	SnakeSegment(int x, int y);
	SnakeSegment(COORD coord);

	void Draw();
};

class Snake { // Only snake head
private:
	deque<SnakeSegment*> cells;
	Direction dir;	//current director of snake
	bool dead;
	Board* _board;

public:
	Snake();

	void push_back(COORD coord);

	void linkBoard(Board* board) {
		_board = board;
	}
	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();
	bool onFruitCollision(vector<Fruit*> fruits);
	void EatFood();

	void handleHeadMove();
	bool isBodyCollision();
	void FreeLastSegment();

	bool isDead() { return dead; }
	void Move();

	void setSnakeDead(bool status);

	void ResetAll();
	void EraseTailSnake();
};
