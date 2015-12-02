#include "SudokuBoard.h"
#include<iostream>
#include<conio.h>
using namespace std;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

CSudokuBoard::CSudokuBoard(){
	for (int i = 0; i < 9;i++)
	for (int j = 0; j < 9; j++)
		board[i][j] = 0;
}

void CSudokuBoard::drawBoard(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (board[i][j])
				cout << " " << board[i][j] << " ";
			if (j == 3 || j == 5)
				cout << " ";
		}
		if (i == 3 || i == 5)
			cout << "\n\n";
		else
			cout << "\n";
	}
}

CSudokuBoard::PointerIterator::PointerIterator(int (&board)[9][9]){
	x = y = 0;
	pBoard = board;
}

void CSudokuBoard::PointerIterator::moveUP(){
	if (x > 0)
		--x;
}

void CSudokuBoard::PointerIterator::moveDOWN(){
	if (x < 8)
		++x;
}
void CSudokuBoard::PointerIterator::moveLEFT(){
	if (y > 0)
		--y;
}
void CSudokuBoard::PointerIterator::moveRIGHT(){
	if (y < 8)
		++y;
}

int CSudokuBoard::PointerIterator::getValue(){
	return pBoard[x][y];
}

void CSudokuBoard::PointerIterator::changeValue(int value){
	if (value >= 1 && value <= 9)
		pBoard[x][y] = value;
}

void CSudokuBoard::PointerIterator::changePosition(int x, int y){
	if (x >= 0 && x <= 8 && y >= 0 && y <= 8){
		this->x = x;
		this->y = y;
	}
}