#pragma once
#include "Object.h"
#include "Board.h"

#include <windows.h>

class Fruit : public Object {
public:
	Fruit(const COORD& coord) : Object(coord) {}
	void Draw();
};