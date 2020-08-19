#include"Snake.h"

void SnakeSegment::Draw() {
	TextColor(ColorCode_Green);
	gotoXY(x, y);
	cout << 'O';
}

Snake::Snake(){
	// Set snake default values
	push_back({ 15, 15 });

	dir = Direction::dead_beat;
	dead = false;
}
void Snake::push_back(COORD coord)
{
	auto segment = _board->createObject(ObjectType::snake, coord);
	cells.push_back((SnakeSegment*) segment); //TODO: use C++ pointer type cast
}
void Snake::linkBoard(Board* board)
{
	_board = board;
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

bool Snake::onFruitCollision(vector<Fruit*> fruits) {
	for (auto fruit : fruits) {
		if (fruit->getX() == cells[0]->getX() || fruit->getY() == cells[0]->getY()) return true;
	}
	return false;
}
void Snake::EatFood() {
	// Clear current food and set the new one
	push_back({ cells[0]->getX(), cells[0]->getY() });
		
	// Destroy fruit
	_board->destroyObject({ cells[0]->getX(), cells[0]->getY() });
			
	// Create new fruit
	COORD coord = { rand() % (_board->getWidth() - 1) + 1, rand() % (_board->getHeight() - 1) + 1 } ;
	_board->createObject(ObjectType::fruit, coord);
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
		if (cells.front() == cells[i]) return true;

	return false;
}
void Snake::FreeLastSegment() {
	for (int i = cells.size() - 1; i > 0; i--) {
		cells[i - 1]->copyPos(cells[i]);
	}
}
void Snake::ResetAll() {
	// Set snake default values
	dir = Direction::dead_beat;
	dead = false;
	cells.clear();
	push_back({ 15, 15 });
	fruit.food.setCoord((rand() % (_board->getWidth() - 1) + 1), (rand() % (_board->getHeight() - 1)) + 1);
}
void Snake::EraseTailSnake() {
	gotoXY(cells.back()->getX(), cells.back()->getY());
	cout << " ";
}
void Snake::Move(){
	// When snake moves, all of its body follow the new head, free its last segment
	FreeLastSegment();
	
	// Turning head snake
	handleHeadMove();
}

void Snake::setSnakeDead(bool status) {
	dead = status;
}