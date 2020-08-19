
#include "Board.h"
#include "Console.h"
#include "Control.h"
#include "Object.h"

Object* Board::createObject(ObjectType type, COORD coord)
{
	Object* object;
	
	switch (type) {
	case ObjectType::fruit: {
		object = new Fruit(coord);
		break;
	}
	case ObjectType::snake: {
		object = new SnakeSegment(coord);
		break;
	}
	//case ObjectType::wall: {
	//	object = new Wall(coord);
	//}
	}

	_points.push_back(object);

	return object;
}
void Board::destroyObject(COORD coord)
{
	for(auto i: _points) {
		if (i->getX() == coord.X && i->getY() == coord.Y) {
			i->Erase();
			break;
		}
	}
}
void Board::clearObjects() {
	_points.clear();
}
void Board::drawObjects()
{
	for (auto i : _points) {
		i->Draw();
	}
}
int Board::PlayMode()
{
	int option;
	//TODO: store menu in a string array
	TextColor(ColorCode_Blue);
	cout<<	"1.New Game (1 player)" << endl;
	TextColor(ColorCode_Red);
	cout << "2.New Game (2 players)  //chua lam" << endl;
	TextColor(ColorCode_White);
	cout << "3.High Score  //chua lam" << endl;
	TextColor(ColorCode_Pink);
	cout << "4.Exit  //chua lam" << endl;
	TextColor(ColorCode_Cyan);
	cout << "Enter your choose: ";
	cin >> option;
	return option;
}
bool Board::isOccupied(const Object& point)
{
	for (auto i : _points) {
		if (*i == point) return true;
	}
	return false;
}
void Board::WelcomeScreen(){
	cout << "_________________     __                      __           _        _____________" << endl;
	cout << "|                     | |          |         /  |          |    /   |" << endl;
	cout << "|                     |  |         |        /    |         |   /    |" << endl;
	cout << "|                     |   |        |       /      |        |  /     |" << endl;
	cout << "|________________     |    |       |      /        |       | /      |" << endl;
	cout << "                 |    |     |      |     / ======== |      |/       |============" << endl;
	cout << "                 |    |      |     |    /            |     ||       |" << endl;
	cout << "                 |    |       |    |   /              |    | |      |" << endl;
	cout << "                 |    |        |   |  /                |   |  |     |" << endl;
	cout << "=================     |         |__| /                  |  |   |    |_____________" << endl;
	cout << endl;
}
void Board::GameOverScreeen() {
	TextColor(ColorCode_Cyan);
	gotoXY(15, 8);
	cout << "GAME OVER !!!";
	gotoXY(15, 9);
	cout << "Do you want to play again ?";
	gotoXY(15, 10);
	cout << "1. Yes";
	gotoXY(15, 11);
	cout << "2. No";
	gotoXY(15, 12);
	cout << "Your Chose: ";
}

void Board::MapClassic() 
{	
	TextColor(ColorCode_Cyan);
	cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "A                                                 A" << endl;
	cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
}