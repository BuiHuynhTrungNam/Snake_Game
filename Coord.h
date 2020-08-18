#pragma once
#include <iostream>

using namespace std;

#define MAXFRAME_X 50
#define MAXFRAME_Y 20

class Coord {					//1 point has (x,y) on console
protected:
	int x;
	int y;
public:
	Coord();
	Coord(int x, int y);
	void setCoord(int x, int y);		//set x, y for new point
	int getX();
	int getY();
	void moveUp();						// y--
	void moveDown();					//y++
	void moveLeft();					//x--
	void moveRight();					//x++
	void Draw(int color, char ch = 'O');			//go to (x,y) of 1 point and draw it
	void Erase();						//go to (x,y) of 1 point and erase it
	void copyPos(Coord* p);				//trace
	bool IsEqual(Coord* p);				//compare 2 point 
	void Debug();						//show (x,y) on console to debug =))
};

class SnakeSegment : public Coord {
public:
	SnakeSegment();
	SnakeSegment(int x, int y);
};

class Wall : public Coord {
public:
	Wall();
	Wall(int x, int y);
};