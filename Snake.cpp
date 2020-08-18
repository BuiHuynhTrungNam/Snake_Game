#include"Snake.h"
#include"Console.h"
#include"Board.h"

Food::Food(){
	food.setCoord((rand() % (MAXFRAME_X-1))+1, (rand() % (MAXFRAME_Y-1))+1);
}
Snake::Snake(){
	// Set snake default values
	cells.push_back(new Coord(15, 15));
	dir = Direction::dead_beat;
	dead = false;
}
void Snake::addCell(int x, int y){
	
	cells.push_back(new Coord(x, y));
}

void Snake::TurnUp() {
	if (dir != Direction::down) dir = Direction::up;
}
void Snake::TurnDown() {
	if (dir != Direction::up) dir = Direction::down;
}
void Snake::TurnLeft() {
	if (dir != Direction::right) dir = Direction::left;
}
void Snake::TurnRight() {
	if (dir != Direction::left) dir = Direction::right;
}

void Snake::EatFood() {
	if (fruit.food.getX() == cells[0]->getX() && fruit.food.getY() == cells[0]->getY()) {
		// Clear current food and set the new one
		addCell(fruit.food.getX(), fruit.food.getY());
		fruit.food.Erase();
		fruit.food.setCoord((rand() % (MAXFRAME_X - 1) + 1), (rand() % (MAXFRAME_Y - 1)) + 1);
	}
}

void Snake::handleHeadMove(){
	switch (dir) {
	case Direction::up:
		cells.front()->moveUp();
		break;
	case Direction::down:
		cells.front()->moveDown();
		break;
	case Direction::left:
		cells.front()->moveLeft();
		break;
	case Direction::right:
		cells.front()->moveRight();
		break;
	}
}
bool Snake::isBodyCollision(){
	if (cells.size() == 1) return false;
	for (int i = 1; i < cells.size(); i++)
		if (cells.front()->IsEqual(cells[i])) return true;

	return false;
}
void Snake::FreeLastSegment() {
	for (int i = cells.size() - 1; i > 0; i--) {
		cells[i - 1]->copyPos(cells[i]);
	}
}
void Snake::DrawObjects() {
	for (int i = 0; i < cells.size(); i++) {
		cells[i]->Draw(ColorCode_Green);
	}
	fruit.food.Draw(ColorCode_Red, '#');
}
void Snake::ResetAll() {
	// Set snake default values
	dir = Direction::dead_beat;
	dead = false;
	cells.clear();
	cells.push_back(new Coord(15, 15));
	fruit.food.setCoord((rand() % (MAXFRAME_X - 1) + 1), (rand() % (MAXFRAME_Y - 1)) + 1);
}
void Snake::EraseTailSnake() {
	gotoXY(cells.back()->getX(), cells.back()->getY());
	cout << " ";
}
void Snake::Move(){
	FreeLastSegment();				// Free last segment
	handleHeadMove();				// Turning head snake
	if (isBodyCollision()) {		//check dead
		dead = true;
		return;
	}
	EatFood();						//Check eat food
}
