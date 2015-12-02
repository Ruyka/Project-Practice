#ifndef GAME_H
#define GAME_H

#define BLOCK_SIZE 4
#define BLOCK_AREA 19
#define BLOCK_START_COLOR 2
#define BOARD_COLOR 170
#define DEFAULT_COLOR 7
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75

typedef class game{
	int player[4][4];
	int diem;
	void initGame(void);
	int checkFull(void);
	bool checkMoveable(char);
	void nextBlock(void);
	void printBlock(void);
	void printBoard(void);
	void printDiem(void);
	int move(char);
	void CLS(void);
public:
	game(void);	
	void play(void);
};

void txtColor(int);
void toPos(int, int);
int randInt(int, int);
void printNumber(int, int, int);

#endif /* GAME_H */