#include "Fruit.h"

Fruit::Fruit(COORD coord)
{
	x = coord.X;
	y = coord.Y;
}

void Fruit::Draw() {
	TextColor(ColorCode_Red);
	gotoXY(x, y);
	cout << '#';
}