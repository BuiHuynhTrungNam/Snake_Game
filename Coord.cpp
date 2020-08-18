#include "Coord.h"
#include "Console.h"

Coord::Coord() {
	x = y = 10;
}
Coord::Coord(int x, int y) {
	this->x = x;
	this->y = y;
}
void Coord::setCoord(int x, int y) {
	this->x = x;
	this->y = y;
}
int Coord::getX() {
	return this->x;
}
int Coord::getY() {
	return this->y;
}
void Coord::moveUp() {
	y--;
	if (y < 1)	y = MAXFRAME_Y;

}
void Coord::moveDown() {
	y++;
	if (y > MAXFRAME_Y) y = 1;
}
void Coord::moveLeft() {
	x--;
	if (x < 1)	x = MAXFRAME_X;
}
void Coord::moveRight() {
	x++;
	if (x > MAXFRAME_X) x = 1;
}
void Coord::Draw(int color, char ch) {
	TextColor(color);
	gotoXY(x, y);
	cout << ch;
}
void Coord::Erase() {
	gotoXY(x, y);
	cout << " ";
}
void Coord::copyPos(Coord* p) {
	p->x = x;
	p->y = y;
}
bool Coord::IsEqual(Coord* p) {
	return p->x == x && p->y == y;
}
void Coord::Debug() {
	cout << " (" << x << ", " << y << ") ";
}

SnakeSegment::SnakeSegment() : Coord() {};

SnakeSegment::SnakeSegment(int x, int y) : Coord(x, y) {};

Wall::Wall() : Coord() {};
Wall::Wall(int x, int y) : Coord(x, y) {};