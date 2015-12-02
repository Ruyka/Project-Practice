#include "Game.h"


Game::Game()
{
	for (int i = 0; i < Y_BORDER; i++)
	for (int j = 0; j < X_BORDER; j++)
		FrameA[i][j] = FrameB[i][j] = 0;

	for (int i = 0;i < 40;i++)
		FrameA[rand() % 25][rand() % 80] = FrameB[rand() % 25][rand() % 80] = 1;
}


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawCell(bool Frame[Y_BORDER][X_BORDER]){
	for (int i = 0; i < Y_BORDER; i++){
		for (int j = 0; j < X_BORDER; j++)
		if (Frame[i][j]){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 254);
			cout << " ";
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			cout << " ";
		}
		cout << endl;
	}
	gotoxy(0, 0);
}

int countNeighbour(bool Frame[Y_BORDER][X_BORDER], int x, int y){
	int count = 0;

	if (x == X_BORDER - 1 || x == 0 || y == Y_BORDER - 1 || y == 0){
		count += 4;
		return count;
	}

	if (Frame[x + 1][y])
		++count;

	if (Frame[x - 1][y])
		++count;

	if (Frame[x + 1][y + 1])
		++count;

	if (Frame[x - 1][y + 1])
		++count;

	if (Frame[x + 1][y - 1])
		++count;

	if (Frame[x - 1][y - 1])
		++count;

	if (Frame[x][y + 1])
		++count;

	if (Frame[x][y - 1])
		++count;

	return count;
}

void update(bool FrameA[Y_BORDER][X_BORDER], bool FrameB[Y_BORDER][X_BORDER]){
	int neighbour = 0;
	for (int i = 0; i < Y_BORDER;i++)
	for (int j = 0; j < X_BORDER;j++)
	if (FrameA[i][j]){
		neighbour = countNeighbour(FrameA, i, j);
		if (neighbour <= 1 || neighbour >= 4)
			FrameB[i][j] = 0;
		for (int k = i - 1; k < Y_BORDER && k <= i + 1;k++)
		for (int h = j - 1; h < X_BORDER && h <= j + 1; h++){
			if (k == i && h == j)
				continue;
			neighbour = countNeighbour(FrameA, k, h);
			if (neighbour == 3)
				FrameB[k][h] = 1;
		}
	}
	for (int i = 0; i < Y_BORDER; i++)
	for (int j = 0; j < X_BORDER; j++)
		FrameA[i][j] = FrameB[i][j];
}

void Game::Cycle(){
	char c;
	while (!_kbhit()) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		drawCell(FrameA);
		update(FrameA, FrameB);
		Sleep(200);
	}
	_getch();
	c = _getch();
	if (c == 'e')
		return;
		
	for (int i = 0; i < 40; i++)
		FrameA[rand() % 25][rand() % 80] = FrameB[rand() % 25][rand() % 80] = 1;
	Cycle();
}