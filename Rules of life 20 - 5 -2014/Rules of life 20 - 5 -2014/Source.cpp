#include<iostream>
#include <random>
#include<vector>
#include<thread>
#include<chrono>

typedef std::vector<char> CHAR;
typedef std::vector<CHAR> CHAR2D;

int randInt(int beg, int end){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(beg, end);
	return dis(gen);
}

class cell{
	CHAR2D space;
public:
	cell();
	~cell();
	void initGen();
	void clearGen();
	void print();
};
cell::cell(){
	initGen();
}

cell::cell(){
	clearGen();
}

void cell::initGen(){
	space.resize(9);
	for (int i = 0; i < 9; ++i){
		space[i].resize(9);
		for (int j = 0; j < 9; ++j)
			space[i][j] = 0;
	}
	space[4][4] = 1;
	space[4][5] = 1;
}

void cell::clearGen(){
	for (int i = 0; i < space.size(); ++i){
		space[i].clear();
	}
	space.clear();
}

void cell::print(){
				
}