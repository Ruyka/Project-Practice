#pragma once;
class player{
private:
	string ID, Password;
	player*next;
protected:
	unsigned char *combo;
	unsigned int Rock[2], Scissor[2], Paper[2], win, lose, draw,Length;
public:
	player(){ next = NULL; }
	player* moveNext();
	void changeNext(player*P);
	void optiCombo();
	void printStat();
	string pID();
	string pPassword();
	unsigned char* pCombo();
	unsigned int pRock();
};

struct linkPlayer{
	player*linkNext, *linkPrev;
	linkPlayer*next;
};

class playerData{
private:
	int total;
	player*head;
protected:
	linkPlayer*pList;
public:
	playerData();
	~playerData();
};