#ifndef SNAKE_H
#define SNAKE_H

#define BOARD_MAX_X 80
#define BOARD_MAX_Y 23
#define BOARD_COLOR 170
#define SNAKE_COLOR 255
#define DEFAULT_COLOR 7
#define FOOD_COLOR 85
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define PAUSE 0


typedef class game{
	std::vector<COORD> snake;
	COORD foodPos;
	bool alive;
	int speed;
	int diem;
public:
	game(void);
	game(int);
	~game(void);
	void clear(void);
	void initGame(int Speed);
	bool checkSnake(void);
	bool checkFood(void);
	bool checkEat(void);
	bool move(void);
	void updateSnake(void);
	void printBoard(void);
	void printFood(void);
	void printDiem(void);
	void printSnake(void);
	void CLS();
};

void txtColor(int);
void toPos(COORD);
void toPos(int, int);
void copy(COORD&, COORD&);
COORD randPos(int, int, int, int);
COORD createPos(int, int);

#endif /* SNAKE_H */