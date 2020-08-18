#pragma once
#include "Coord.h"
#include <conio.h>
#include <deque>
#include "Board.h"

using namespace std;

#define MAXSIZESNAKE 100

class Snake;

class Food{
	friend class Snake;
private:
	Coord food;
public:
	Food();
};

enum class Direction {
	up = 'w',
	down = 's',
	left = 'a',
	right = 'd',
	dead_beat = '\0'
};


class Snake {			//1 snake create form many points
private:

	std::deque<Coord*> cells;
	//vector<SnakeSegment*> cells;
	Direction dir;	//current director of snake
	Food fruit;	//food 
	bool dead;
	
public:
	Snake();
	void addCell(int x, int y);	//add 1 point if snake eat food (size +1 )
	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();
	void EatFood();

	void handleHeadMove();
	bool isBodyCollision();
	void FreeLastSegment();
	void DrawObjects();

	bool isDead() { return dead; }
	void Move();

	void ResetAll();
	void EraseTailSnake();
};
