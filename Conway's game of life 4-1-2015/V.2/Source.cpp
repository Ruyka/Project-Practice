#include<iostream>
#include<windows.h>
using namespace std;

// source

typedef struct cell{
	bool _alive;
	int neighbour;
	cell(){ _alive = 0; neighbour = 0; }
};

// variables
int init_cells = 50;
const int screen_x = 80;
const int screen_y = 25;
cell board[screen_y][screen_x];

void updateCell(int x, int y, bool alive){
	if (alive)
		alive = 1;
	else alive = -1;

	for (int i = y - 1; i < y + 2 && i < screen_y;i++)
	for (int j = x - 1; j < x + 2 && j < screen_x;j++)
	if (i != y && j != x)
		board[i][j].neighbour += alive;
}

void drawScreen(){
	for (int i = 0; i < screen_y; i++){
		for (int j = 0; j < screen_x; j++)
		if (board[i][j]._alive){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 254);
			cout << " ";
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			cout << " ";
		}
		cout << endl;
	}
}

void updateBoard(){
	for (int i = 0; i < screen_y; i++){
		for (int j = 0; j < screen_x; j++)
		if (board[i][j]._alive && (board[i][j].neighbour < 2 || board[i][j].neighbour > 3)) {
			board[i][j]._alive = 0;
			updateCell(i, j, 0);
		}
		else if (!board[i][j]._alive && board[i][j].neighbour == 3){
			board[i][j]._alive = 1;
			updateCell(i, j, 1);
		}
	}
}

void init(){
	for (int i = 0; i < init_cells; i++){
		int x = rand() % screen_y, y = rand() % screen_x;
		board[y][x]._alive = 1;
		updateCell(x, y, 1);
	}
}


int main(){
	// Underconstruction
	return 0;
}