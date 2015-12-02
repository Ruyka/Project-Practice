#include<iostream>
#include<random>
#include<windows.h>
#include<vector>
#include<time.h>
#include<conio.h>
#include <stdio.h>
#include"snake.h"

game::game(){
	initGame(100);
}

game::game(int Speed){
	initGame(Speed);
}


game::~game(){
	clear();
}

void game::initGame(int Speed){
	speed = Speed;
	diem = 0;
	alive = true;
	COORD temp = createPos(10, 10);
	snake.push_back(temp);
	for (int i = 1; i < 5; ++i){
		snake.push_back(createPos(snake[0].X - i, snake[0].Y));
	}
	while (!checkFood()){
		foodPos = randPos(BOARD_MAX_X - 20, 20, BOARD_MAX_Y - 3, 6);
	}
}

void game::clear(){
	alive = false;
	diem = 0;
	while (snake.size())
		snake.pop_back();
}

bool game::checkSnake(){
	if (snake[0].X >= BOARD_MAX_X - 1 || snake[0].X <= 0 || snake[0].Y >= BOARD_MAX_Y - 1 || snake[0].Y <= 2)
		return false;

	for (int i = 1; i < snake.size(); ++i){
		if (snake[0].X == snake[i].X && snake[0].Y == snake[i].Y)
			return false;
	}

	return true;
}

bool game::checkFood(){
	for (int i = 0; i < snake.size(); ++i){
		if (foodPos.X == snake[i].X && foodPos.Y == snake[i].Y)
			return false;
	}

	if (foodPos.X >= BOARD_MAX_X - 1 || foodPos.X <= 0 || foodPos.Y >= BOARD_MAX_Y - 1 || foodPos.Y <= 1)
		return false;

	return true;
}

bool game::checkEat(){
	return (snake[0].X == foodPos.X && snake[0].Y == foodPos.Y);
}

void game::updateSnake(){
	for (int i = snake.size() - 1; i > 0; --i)
		copy(snake[i], snake[i - 1]);
}

bool game::move(){
	printDiem();
	printBoard();
	printFood();
	while (alive){
		do {
			printFood();
			printSnake();
			COORD tail; copy(tail, snake[snake.size() - 1]);
			if (!checkSnake()){
				alive = false;
				break;
			}
			if (checkEat()){
				while (!checkFood())
					foodPos = randPos(BOARD_MAX_X - 20, 20, BOARD_MAX_Y - 3, 6);
				++diem;
				printDiem();
				printFood();
				snake.push_back(tail);
			}
			if (!_kbhit()){
				CLS();
				int X = snake[0].X - snake[1].X, Y = snake[0].Y - snake[1].Y;
				updateSnake();
				snake[0].X += X; snake[0].Y += Y;
				printSnake();
			}
			Sleep(speed);
		} while (!_kbhit());

		if (alive){
			COORD tail; 
			_getch();
			char k = _getch();
			if (k == PAUSE){
				_getch();
				char k = _getch();
			}
			switch (k){
			case UP:
				if (snake[0].Y <= snake[1].Y){
					copy(tail, snake[snake.size() - 1]);
					CLS();
					updateSnake();
					--snake[0].Y;
				}
				break;
			case DOWN:
				if (snake[0].Y >= snake[1].Y){
					copy(tail, snake[snake.size() - 1]);
					CLS();
					updateSnake();
					++snake[0].Y;
				}
				break;
			case LEFT:
				if (snake[0].X <= snake[1].X){
					copy(tail, snake[snake.size() - 1]);
					CLS();
					updateSnake();
					--snake[0].X;
				}
				break;
			case RIGHT:
				if (snake[0].X >= snake[1].X){
					copy(tail, snake[snake.size() - 1]);
					CLS();
					updateSnake();
					++snake[0].X;
				}			
			}
			if (!checkSnake()){
				alive = false;
				break;
			}
			if (checkEat()){
				while (!checkFood())
					foodPos = randPos(BOARD_MAX_X - 20, 20, BOARD_MAX_Y - 3, 6);
				++diem;
				printDiem();
				printFood();
				snake.push_back(tail);
			}
			printSnake();
			Sleep(speed);
		}
	}
	return false;
}

void game::printBoard(){
	txtColor(BOARD_COLOR);
	toPos(0, 1);
	for (int i = 0; i < BOARD_MAX_X; ++i)
		std::cout << " ";
	for (int i = 0; i < BOARD_MAX_Y - 3; ++i)
		std::cout << " " << std::endl;
	for (int i = 0; i < BOARD_MAX_X; ++i)
		std::cout << " ";
	for (int i = 2; i < BOARD_MAX_Y; ++i){
		toPos(BOARD_MAX_X - 1, i);
		std::cout << " ";
	}
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

void game::printFood(){
	txtColor(FOOD_COLOR);
	toPos(foodPos);
	std::cout << " ";
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

void game::printDiem(){
	toPos(0, 0);
	std::cout << "DIEM : " << diem;
}

void game::printSnake(){
	txtColor(SNAKE_COLOR);
	for (int i = 0; i < snake.size(); ++i){
		toPos(snake[i]);
		std::cout << " ";
	}
	toPos(0, BOARD_MAX_Y + 1);
	txtColor(DEFAULT_COLOR);
}

void game::CLS(){
	txtColor(0);
	for (int i = 0; i < snake.size(); ++i){
		toPos(snake[i]);
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

void copy(COORD& A, COORD& B){
	A.X = B.X;
	A.Y = B.Y;
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