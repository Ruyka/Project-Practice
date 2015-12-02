#include<iostream>
#include<random>
#include<windows.h>
#include<vector>
#include<time.h>
#include<conio.h>
#include <stdio.h>
#define BOARD_MAX_X 80
#define BOARD_MAX_Y 23
#define BOARD_BLOCK_AREA 19
#define BOARD_COLOR 170
#define DEFAULT_COLOR 7
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
typedef std::vector<int> int2D;
typedef std::vector<int2D> block;
void txtColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void toPos(COORD pos){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void toPos(int X, int Y){
	COORD temp;
	temp.X = X;
	temp.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
}

int main(){

	for (int i = 0; i < 255; ++i){
		txtColor(i);
		std::cout << i << std::endl;
	}
	return 0;
}