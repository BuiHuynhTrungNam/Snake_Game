#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

#include "Snake.h"
#include "Object.h"

using namespace std;

enum class ObjectType {
	snake,
	wall,
	fruit
};

class Board {
private:
	int _width;
	int _height;

	//There are points in a board
	vector<Object *> _points;
public:
	Board(int width, int height) : _width(width), _height(height) {}

	Object* createObject(ObjectType type, COORD coord);
	void destroyObject(COORD coord);

	void drawObjects();

	int PlayMode();
	bool isOccupied(const Object& point);

	void WelcomeScreen();
	void GameOverScreeen();
	void MapClassic();

	int getWidth() { return _width; }
	int getHeight() { return _height; }
};