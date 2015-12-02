#include<iostream>
using namespace std;
#include<cstdlib>
#include"Learning.h"
simpleGame::simpleGame(){ P1win = 0;  draw = 0; totalGame = 0; }
unsigned char simpleGame::juge(unsigned char P1, unsigned char P2){
	switch (P1){
	case 0:
		switch (P2){
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		}
	case 1:
		switch (P2){
		case 0:
			return 2;
		case 1:
			return 0;
		case 2:
			return 1;
		}
	case 2:
		switch (P2){
		case 0:
			return 1;
		case 1:
			return 2;
		case 2:
			return 0;
		}
	}
}
void simpleGame::play(unsigned char P1, unsigned char P2){
	unsigned char result = juge(P1, P2);
	if (result == 0){
		cout << "It's a Draw.\n\n";
		++draw;
	}
	else if (result == 1){
		cout << "P1 : Win.  P2 : Lose.\n\n";
		++P1win;
	}
	else{
		cout << "P1 : Lose. P2 : Win.\n\n";
	}
	++totalGame;
}
unsigned char simpleGame::ranAI(){
	return unsigned char(rand() % 3 + 0);
}
void simpleGame::printStat(){
	cout << "P1 win : " << P1win << " time(s).\n"
		<< "P2 win : " << totalGame - draw - P1win << " time(s).\n"
		<< "Total draw : " << draw << " time(s).\n"
		<< "Total game(s) : " << totalGame << " game(s).\n";
}
void simpleGame::clearStat(){P1win = 0;  draw = 0; totalGame = 0;}