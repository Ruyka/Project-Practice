#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <conio.h>
using namespace std;

void getT(int(*board)[9][9]){
	int (*p)[9][9] = board;
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++){
		cout << (*p)[i][j] << " ";
		++(*p)[i][j];
	}
}

int main()
{
	int board[9][9];
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
		board[i][j] = j;
	getT(&board);
	cout << endl;

	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++){
		cout << board[i][j] << " ";
	}
}