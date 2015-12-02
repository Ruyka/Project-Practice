#include<iostream>
using namespace std;
#include<cstdlib>
#include <chrono>  
#include <thread> 
#include"Learning.h"
int main(){
	simpleGame Game;
	cout << "AI battle in rock, scissor, paper game.\n"
		<< "First round: 50 Games.\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for (int i = 0; i < 50; ++i){
		cout << "Game " << i + 1 << " : ";
		Game.play(Game.ranAI(), Game.ranAI());
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	Game.printStat();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	Game.clearStat();

	cout << "\nSecond round: 100 Games.\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for (int i = 0; i < 100; ++i){
		cout << "Game " << i + 1 << " : ";
		Game.play(Game.ranAI(), Game.ranAI());
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	Game.printStat();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	Game.clearStat();

	cout << "\nFinal round: 200 Games.\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for (int i = 0; i < 200; ++i){
		cout << "Game " << i + 1 << " : ";
		Game.play(Game.ranAI(), Game.ranAI());
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	Game.printStat();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	return 0;
}