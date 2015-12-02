#ifndef GAME_H
#define GAME_H
#include"SudokuBoard.h"
#include<string>
using namespace std;

class CGame
{
	CSudokuBoard* board;
public:
	CGame();
	~CGame();
	void createRandomBoard();
	void solve();
	void getKeyBoardEvent();
	void readFromFile(string filename);
	void writeToFile(string filename);
};

#endif