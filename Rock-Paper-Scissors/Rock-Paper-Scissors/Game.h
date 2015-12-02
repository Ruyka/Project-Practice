#ifndef GAME_H
#define GAME_H
#include<string>
#include<iostream>



typedef class Game{
public:
	std::string AIPlayer, Player;
	unsigned int Count, pWin, draw;
	Game();
};

typedef class AI{
	std::string Pattern;
	int itr, count, status;
	char sPrev;
	bool Pattern_Discovered, mode;
	char Default_Play();
	char Pattern_Play();
public:
	AI();
	void Game_Update(int status, char optPrev);
	char Play(void);
};

#endif /* AI_H */