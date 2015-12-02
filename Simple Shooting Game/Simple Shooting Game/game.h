#ifndef GAME_H
#define GAME_H
#include<windows.h>
#include<iostream>
#include<vector>
#include<conio.h>
#include<algorithm>
#include"gameObject.h"
using namespace std;

class game
{
private:
	bool isEnd;
	int _upY, _downY, _upX, _downX, _score;
	gameObject*spaceShip;
public:
	void begin();
	void update();
	void move();
	void drawScreen();
	void end();
};

#endif