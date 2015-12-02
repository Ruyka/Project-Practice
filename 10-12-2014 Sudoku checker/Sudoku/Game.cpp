#include "Game.h"


CGame::CGame(){
	board = new CSudokuBoard;
}

CGame::~CGame(){
	delete board;
}

void CGame::createRandomBoard(){
	CSudokuBoard::PointerIterator* gameIterator = board->getIterator();
	CSudokuBoard::PointerIterator* iterator1 = board->getIterator();
	CSudokuBoard::PointerIterator* iterator2 = board->getIterator();
	int eleNum = rand() % 64 + 17;
	int x, y;
	for (int i = 0; i < eleNum; i++){
		x = rand() % 9;
		y = rand() % 9;
		gameIterator->changePosition(x, y);
		gameIterator->changeValue(rand() % 9 + 1);
		for (int i = 0; i < 9;i++)
		for (int j = 0; j < 9; j++){
			iterator1->changePosition(i, j);
			iterator2->changePosition(j, i);
			if (gameIterator->getValue() == iterator1->getValue() || gameIterator->getValue() == iterator2->getValue()){
				i = j = 0;
				gameIterator->changeValue(rand() % 9 + 1);
			}
		}
		int a = (x / 3) * 3, b = (y / 3) * 3;
		for (int i = a; i < a + 3; i++)
		for (int j = b; j < b + 3; j++){
			iterator1->changePosition(i, j);
			iterator2->changePosition(j, i);
			if (gameIterator->getValue() == iterator1->getValue() || gameIterator->getValue() == iterator2->getValue()){
				i = a;
				j = b;
				gameIterator->changeValue(rand() % 9 + 1);
			}
		}
	}
	delete gameIterator;
	delete iterator1;
	delete iterator2;
}

void 