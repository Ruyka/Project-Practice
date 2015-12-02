#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;

#define X_BORDER 80
#define Y_BORDER 25

class Game
{
	bool FrameA[Y_BORDER][X_BORDER], FrameB[Y_BORDER][X_BORDER];
public:
	Game();
	void Cycle();
};

#endif