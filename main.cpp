#include"Snake.h"
#include"Console.h"
#include"Map.h"
#include<time.h>
int main()
{
	Nocursortype();		//hide pointer
	srand((unsigned)time(NULL));
	Snake snake;	//object to play
	Map::MainMenu(snake);	//Menu
	return 0;
}