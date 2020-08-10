#pragma once
#include"Map.h"
#include"Console.h"
#include"Control.h"
int Map::PlayMode(){
	int option;
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
void Map::WelcomeScreen(){
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
void Map::MapClassic() {
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
void Map::MainMenu(Snake &snake) {
	WelcomeScreen();
	int option = PlayMode();
	PlayGame::PlayMode_1(snake, option);
}
