#include<iostream>
#include<windows.h>
#include<conio.h>
#define BOARD_MAX_X 80
#define BOARD_MAX_Y 24
#define BOARD_COLOR 170
#define SNAKE_COLOR 255
#define DEFAULT_COLOR 7
#define FOOD_COLOR 85

void txtColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
		std::cout << "No." << i << std::endl;
	}
	return 0;
}