#include<iostream>
#include<fstream>
#include<chrono>  
#include<thread> 
#include<string>
#include"PLAYER.h"
using namespace std;

player* player::moveNext(){ return next; }

void player::changeNext(player*P){ next = P; }

void player::optiCombo(){

}

void player::printStat(){
	cout << "Player : " << ID << endl
		<< "Total  : " << win + lose + draw << " game(s)"
		<< "Win    : " << win << " time(s).\n"
		<< "Lose   : " << lose << " time(s).\n"
		<< "Draw   : " << draw << " time(s).\n";
}

void read(fstream& Data, player*& cur) {

}

playerData::playerData(){
	fstream Data;
	Data.open("PlayerData", ios::in);

	head = new player;

	cout << "Initializing player data";
	for (int i = 0; i < 3; ++i){
		cout << ".";
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	if (!Data.is_open()){
		cout << "\nNo former data found.\nInitializing new player data";
		for (int i = 0; i < 3; ++i){
			cout << ".";
			this_thread::sleep_for(chrono::milliseconds(500));
		}
		pList = NULL;
		cout << "DONE.\n";
		return;
	}

	player*cur = new player; head->changeNext(cur);

	while (cur != NULL){
		read(Data, cur);
		
	}
}

void write(fstream&Data, player*cur){
	Data << "\t<Player>\n"
		<< "\t\t<Player ID>"<<cur->
}

playerData::~playerData(){
	fstream Data;
	Data.open("PlayerData", ios::out);

	cout << "Saving player data";
	for (int i = 0; i < 3; ++i){
		cout << ".";
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	if (!Data.is_open()){
		cout << "\nProblem opening file.\n*Warning*Program will log out unsave.\n";
		return;
	}

	Data << "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n"
		<< "<Player List>\n"
		<< "\t<Total>" << total << "</Total>\n";

	player*cur = head->moveNext();

	for (int i = 0; i < total&& cur != NULL; ++i){
		write(Data, cur);
		cur = cur->moveNext();
	}

	Data << "</Player List>\n";
}