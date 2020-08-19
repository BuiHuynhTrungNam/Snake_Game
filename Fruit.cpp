#include "Fruit.h"

Fruit::Fruit(COORD coord)
{
	x = coord.X;
	y = coord.Y;
}

void Fruit::linkBoard(Board* board)
{
	_board = board;
}

void Fruit::drawObject()
{

}
