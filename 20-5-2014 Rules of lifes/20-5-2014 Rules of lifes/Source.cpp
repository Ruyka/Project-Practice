#include<iostream>
#include <random>
#include<thread>
#include<chrono>
using namespace std;

struct cell{
	int col, row;
	cell(){ col = 0; row = 0; }
};

int randInt(int beg,int end){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(beg, end);
	return dis(gen);
}

void animated(vector<cell> live){
	for (int i = 0; i < live.size(); ++i){
		
		for (int j = 0; j < live[i].col; ++j)
			cout << " ";
		cout << "*";		

		if (live[i].row != live[i + 1].row){
			for (int k = 0; i < abs(live[i].row - live[i + 1].row); ++k)
				cout << endl;
		}
	}
}

void delPosition(vector<int> &illPos,int pos){
	for (int i = pos; i < illPos.size() - 1; ++i)
		swap(illPos[i], illPos[i + 1]);
	illPos.pop_back();
}

void eliCell(vector<cell>&live, vector<int>delPos){
	vector<cell> saveLive;
	int i = 0, j = 0, k = 0;
	for (i,j,k; j < live.size(); ++j, ++k){
		if (j == delPos[i]){
			++j;
			++i;
		}
		saveLive[k] = live[j];
	}
	live.resize(saveLive.size());
	for (int i = 0; i < saveLive.size(); ++i)
		live[i] = saveLive[i];
}

void natureSelection(vector<cell>&live){
	vector<int> illPos;
	for (int i = 0; i < live.size(); ++i){
		int neighbour = 0;
		for (int j = i + 1; j < live.size(); ++j){
			int x = abs(live[i].col - live[j].col), y = abs(live[i].row - live[j].row);
			if ((x == 1 || x == 0) && (y == 1 || y == 0))
				++neighbour;
		}
		if (neighbour >= 4 || neighbour == 0)
			illPos.push_back(i);
	}
	vector<int>delPos;
	for (int i = 0; i < illPos.size(); ++i){
		int neighbour = 0, pos;
		for (int j = i + 1; j < illPos.size(); ++j){
			int x = abs(live[illPos[i]].col - live[illPos[j]].col), y = abs(live[illPos[i]].row - live[illPos[j]].row);
			if ((x == 1 || x == 0) && (y == 1 || y == 0)){
				++neighbour;
				pos = j;
			}
		}
		if (neighbour >= 4 || neighbour == 0){
			int temp = randInt(i, pos);
			delPos.push_back(illPos[temp]);
			delPosition(illPos, temp);
		}
	}
	eliCell(live, delPos);
}

void updateCell(vector<cell>&live){
	for (int i = 0; i < live.size(); ++i){
		for (int j = i; j < live.size(); ++j){
			if (live[i].row < live[i].row)
				swap(live[i], live[j]);
			else if (live[i].col > live[j].col && live[i].row == live[i].row)
				swap(live[i], live[j]);
		}
	}
}

void swap(cell &A, cell &B){
	cell temp = A;
	A = B;
	B = temp;
}

cell bornNew(int growNext, cell pos){
	cell temp;
	switch (growNext){
	case 1 :
		temp.col = pos.col - 1;
		temp.row = pos.row + 1;
	case 2:
		temp.col = pos.col;
		temp.row = pos.row + 1;
	case 3:
		temp.col = pos.col + 1;
		temp.row = pos.row + 1;
	case 4:
		temp.col = pos.col + 1;
		temp.row = pos.row ;
	case 5:
		temp.col = pos.col + 1;
		temp.row = pos.row - 1;
	case 6:
		temp.col = pos.col;
		temp.row = pos.row - 1;
	case 7:
		temp.col = pos.col - 1;
		temp.row = pos.row - 1;
	case 8:
		temp.col = pos.col - 1;
		temp.row = pos.row ;
	}
	return temp;
}

bool checkValid(int pos, int growNext, vector<cell>live) {

	cell temp = bornNew(growNext, live[pos]);

	for (int i = 0; i < live.size(); ++i){
		if (live[i].col == temp.col && live[i].row == temp.row)
			return false;
	}
	return true;
}

void grow(int &celNum,int yearNum){
	vector<cell> live;
	live.resize(celNum);
	int celNumTemp = celNum;
	for (int i = 0; i < yearNum; ++i){
		cout << "Year : " << i + 1 << endl;
		int pos = randInt(0, celNumTemp - 1), growNext = randInt(1, 8);

		while (!checkValid(pos, growNext, live)){
			growNext = randInt(1, 8);
		}

		live.push_back(bornNew(growNext, live[pos]));

		updateCell(live);
		
		natureSelection(live);
		celNumTemp = live.size();
		cout << "Number of cell : " << celNumTemp << endl;
		animated(live);
		this_thread::sleep_for(chrono::milliseconds(500));
		system("CLS");
	}
	celNum = celNumTemp;
}

int main(){
	int celNum, yearNum;
	cin >> celNum >> yearNum;
	grow(celNum, yearNum);
	return 0;
}