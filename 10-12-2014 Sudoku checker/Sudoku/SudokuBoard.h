#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

class CSudokuBoard
{
	int board[9][9];
public:
	CSudokuBoard();
	class PointerIterator{
		int x, y;
		int (*pBoard)[9];
	public:
		PointerIterator(int (&board)[9][9]);
		void moveUP();
		void moveDOWN();
		void moveLEFT();
		void moveRIGHT();
		int getValue();
		void changeValue(int value);
		void changePosition(int x, int y);
	}*getIterator(){
		PointerIterator* newIterator = new PointerIterator(board);
		return newIterator;
	}

	void drawBoard();
};
#endif 