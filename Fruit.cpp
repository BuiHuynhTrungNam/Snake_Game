#include "Fruit.h"

void Fruit::Draw() {
	TextColor(ColorCode_Red);
	gotoXY(x, y);
	cout << '#';
}