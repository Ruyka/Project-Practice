#pragma once
class simpleGame{
private:
	int P1win, draw, totalGame;
public:
	simpleGame();
	void play(unsigned char P1, unsigned char P2);
	unsigned char juge(unsigned char P1, unsigned char P2);
	unsigned char ranAI();
	void printStat();
	void clearStat();
};