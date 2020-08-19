#include "Object.h"

Object::Object(COORD coord) {
	x = coord.X;
	y = coord.Y;
	_board = nullptr;
}
void Object::setCoord(int x, int y) {
	this->x = x;
	this->y = y;
}
int Object::getX() {
	return this->x;
}
int Object::getY() {
	return this->y;
}
void Object::moveUp() {
	y--;
	if (y < 1) y = _board->getHeight();
}
void Object::moveDown() {
	y++;
	if (y > _board->getHeight()) y = 1;
}
void Object::moveLeft() {
	x--;
	if (x < 1)	x = _board->getWidth();
}
void Object::moveRight() {
	x++;
	if (x > _board->getWidth()) x = 1;
}
void Object::Erase() {
	gotoXY(x, y);
	std::cout << " ";
}
void Object::copyPos(Object* p) {
	p->x = x;
	p->y = y;
}

void Object::Debug() {
	std::cout << " (" << x << ", " << y << ") ";
}
