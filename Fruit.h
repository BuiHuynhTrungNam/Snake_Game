#pragma once
#include "Object.h"
#include "Board.h"

#include <windows.h>

class Fruit : public Object {
private:
	Board* _board;
public:
	Fruit(COORD coord);
	void linkBoard(Board* board);
	void Draw();
};