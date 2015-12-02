#include<iostream>
using namespace std;

void main(){
	int n;
	cin >> n;

	char *board = new char[n*n];

	// Input board game into array
	for (int i = 0; i < n*n; i++){
		char k;
		cin >> k;
		if (k != '\n')
			board[i] = k;
		else
			i--;
	}

	// Find all the tower and save their position
	int 
	for (int i = 0; i < n*n; i++)

	delete board;
}