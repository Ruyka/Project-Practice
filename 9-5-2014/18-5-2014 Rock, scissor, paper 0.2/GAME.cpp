#include<iostream>
#include<fstream>
#include<chrono>  
#include<thread> 
#include"GAME.h"
using namespace std;

unsigned char game::juge(unsigned char P1, unsigned char P2){
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

void game::play(unsigned char P1, unsigned char P2)){
	unsigned char result = juge(P1, P2);
	if (result == 0){
		cout << "It's a Draw.\n\n";
	}
	else if (result == 1){
		cout << "P1 : Win.  P2 : Lose.\n\n";
		++P1;
	}
	else{
		cout << "P1 : Lose. P2 : Win.\n\n";
		++P2;
	}
	++total;
}