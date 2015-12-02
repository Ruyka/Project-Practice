#include<iostream>
#include<windows.h>
#include<vector>
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include"snake.h"

int main(){
	std::cout << "Speed : ";
	int s;
	std::cin >> s;
	game demo(s);
	bool check = true;
	while (check){
		check = demo.move();
		system("CLS");
		demo.printDiem();
		std::cout << "\nDO YOU WANT TO CONTINUE? (Y/N) ";
		char k;
		std::cin >> k;
		if (k == 'Y' || k == 'y'){
			std::cout << "Speed : ";
			int s;
			std::cin >> s;
			demo.clear();
			demo.initGame(s);
			check = true;
			system("CLS");
		}
	}
	return 0;
}