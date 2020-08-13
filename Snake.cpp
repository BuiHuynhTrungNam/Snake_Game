#pragma once
#include"Snake.h"
#include"Console.h"
#include"Map.h"
Food::Food(){
	food.setPoint((rand() % (MAXFRAME_X-1))+1, (rand() % (MAXFRAME_Y-1))+1);
}
Snake::Snake(){
	size = 1;	//default size
	Cell[0] = new Point(15, 15);	//default x, y
	for (int i = 1; i < MAXSIZESNAKE; i++){
		Cell[i] = NULL;
	}
	state = 1;
	blink = 1;
	dir = 1;
	isUpdateSize = false;
}
void Snake::addCell(int x, int y){
	Cell[size++] = new Point(x, y);
	isUpdateSize = true;
}
void Snake::TurnUp() {
	if (dir != 's')
		dir = 'w';
}
void Snake::TurnDown() {
	if (dir != 'w')
		dir = 's';
}
void Snake::TurnLeft() {
	if (dir != 'd')
		dir = 'a';
}
void Snake::TurnRight() {
	if (dir != 'a')
		dir = 'd';
}
void Snake::CheckDir() {
	switch (dir) {
	case 'w':
		Cell[0]->moveUp();
		break;
	case 's':
		Cell[0]->moveDown();
		break;
	case 'a':
		Cell[0]->moveLeft();
		break;
	case 'd':
		Cell[0]->moveRight();
		break;
	}
}
bool Snake::isDead(){
	for (int i = 1; i < size; i++)
		if (Cell[0]->IsEqual(Cell[i]))	return true;
	return false;
}
void Snake::DrawSnake() {
	for (int i = 0; i < size; i++) {
		if ((i == size - 1) && isUpdateSize) {
			isUpdateSize = false;
			continue;
		}
		Cell[i]->Draw();
	}
}
void Snake::ResetDir() {
	dir = '\0';
}
void Snake::clearPoint(int x, int y) {
	gotoXY(x,y);
	cout << " ";
}
void Snake::clearAll() {
	for (int i = 0; i < size; i++) {
		clearPoint(Cell[i]->getX(), Cell[i]->getY());
	}
	clearPoint(fruit.food.getX(), fruit.food.getY());
}
void Snake::Move(){
	if (state == 0) {  //if snake die
		clearAll();
		gotoXY(51, 21);
			cout << "\nGame Over";
			cout << "\nPress any key to start again";
			_getch();
			ResetDir();
			state = 1;
			size = 1;
	}
	//making snake body follow head snake
	for (int i = size - 1; i > 0; i--) {
		Cell[i - 1]->copyPos(Cell[i]);
	}
	//turning head snake
	CheckDir();
	//check Dead
	if (isDead()) {
		state = 0;
	}
	//Check eat food
	if (fruit.food.getX() == Cell[0]->getX() && fruit.food.getY() == Cell[0]->getY()){
		addCell(51, 21);
		clearPoint(fruit.food.getX(), fruit.food.getY());
		fruit.food.setPoint((rand() % (MAXFRAME_X - 1) + 1), (rand() % (MAXFRAME_Y - 1)) + 1);
	}
	//draw snake
	TextColor(ColorCode_Green);
	DrawSnake();
	//make color fruit
	TextColor(ColorCode_Red);
	//Draw food
	if (!blink)	fruit.food.Draw('#');
	//Blink
	blink = !blink;
	Sleep(100);
	clearPoint(Cell[size-1]->getX(),Cell[size-1]->getY());
	
}
