#pragma once
#include<iostream>
#include"Snake.h"
using namespace std;
class Map {
public:
	static int PlayMode();
	static void WelcomeScreen();
	static void MainMenu(Snake& snake);
	static void MapClassic();
};


