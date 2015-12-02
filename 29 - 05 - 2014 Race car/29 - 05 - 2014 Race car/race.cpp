#include<iostream>
#include<random>
#include<windows.h>
#include<vector>
#include<time.h>
#include<conio.h>
#include <stdio.h>
#include"race.h"

void game::printDiem(){
	toPos(0, 0);
	std::cout << "DIEM : " << diem;
}

void game::printBoard(){
	txtColor(BOARD_COLOR);
	toPos(0, 1);
	for (int i = 0; i < BOARD_MAX_X; ++i)
		std::cout << " ";
	toPos(0, BOARD_MAX_Y);
	for (int i = 0; i < BOARD_MAX_X; ++i)
		std::cout << " ";
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

void game::printYou(){
	txtColor(YOU_COLOR);
	toPos(you);
	std::cout << " ";
	for (int i = 0; i < 3; ++i){
		toPos(you.X - 1, you.Y + 1 - i);
		std::cout << " ";
	}
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

void game::printEnemy(){
	txtColor(ENEMY_COLOR);
	for (int i = 0; i < enemy.size(); ++i){
		toPos(enemy[i]);
		std::cout << " ";
		for (int i = 0; i < 3; ++i){
			toPos(enemy[i].X + 1, enemy[i].Y + 1 - i);
			std::cout << " ";
		}
	}
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

void game::printYShoot(){
	txtColor(YOU_COLOR);
	for (int i = 0; i < yshoot.size(); ++i){
		toPos(yshoot[i]);
		std::cout << " ";		
	}
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

void game::printEShoot(){
	txtColor(ENEMY_COLOR);
	for (int i = 0; i < eshoot.size(); ++i){
		toPos(eshoot[i]);
		std::cout << " ";
	}
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

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

int randInt(int max, int min){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

COORD randPos(int max_X, int min_X, int max_Y, int min_Y){
	COORD temp;
	temp.X = randInt(max_X, min_X);
	temp.Y = randInt(max_Y, min_Y);
	return temp;
}

COORD createPos(int X, int Y){
	COORD temp;
	temp.X = X;
	temp.Y = Y;
	return temp;
}