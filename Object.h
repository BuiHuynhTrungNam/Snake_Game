#pragma once
#include <iostream>

class Board;

class Object {
protected:
	int x;
	int y;
	Board* _board;
public:
	Object(int x, int y);
	
	void setCoord(int x, int y);

	int getX();
	int getY();
	virtual void Draw() = 0;

	// Should be remove
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void Erase();	//go to (x,y) and erase it
	
	// TODO: Replace by copy constructor
	void copyPos(Object* p);

	bool operator==(const Object &p) {
		return x == p.x && y == p.y;
	}

	void Debug();						//show (x,y) on console to debug =))
};

