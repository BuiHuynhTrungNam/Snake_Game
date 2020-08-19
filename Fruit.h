#pragma once
#include "Object.h"
#include "Board.h"

#include <windows.h>

class Fruit : public Object {
public:
	Fruit(COORD coord);
	void Draw();
};