#ifndef RACE_H
#define RACE_H

#define BOARD_MAX_X 80
#define BOARD_MAX_Y 23
#define YOU_COLOR 255
#define ENEMY_COLOR 170
#define BOARD_COLOR 204
#define DEFAULT_COLOR 7
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define PAUSE 0
#define SHOOT 32

typedef class game{
	std::vector<COORD> enemy;
	std::vector<COORD> yshoot;
	std::vector<COORD> eshoot;
	COORD you;
	int live, diem;
public:
	game(void);
	~game(void);
	bool checkYou(void);
	bool checkEnemy(void);
	void move();
	void printDiem();
	void printBoard();
	void printYou();
	void printEnemy();
	void printYShoot();
	void printEShoot();
};

void txtColor(int);
void toPos(COORD);
void toPos(int, int);
int randInt(int, int);
COORD randPos(int, int, int, int);
COORD createPos(int, int);

#endif /* RACE_H */