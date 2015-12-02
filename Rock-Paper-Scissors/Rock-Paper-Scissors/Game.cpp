#include"Game.h"
#include<string>
#include<stdio.h>
#include<conio.h>

AI::AI(){
	Pattern_Discovered = 0;
	mode = 0;
	status = 0;
	count = 0;
	sPrev = 1;
	itr = 0;
}

bool mode;
int count;

char AI::Default_Play(){
	if (!status || mode){
		if (!sPrev)
			return 1;
		if (sPrev == 1)
			return 2;
		else
			return 0;
	}
	else{
		if (!sPrev)
			return 2;
		if (sPrev == 1)
			return 0;
		else
			return 1;
	}
}

void AI::Game_Update(int Status, char OptPrev){
	if (OptPrev == -1)
		return;

	status = Status;

	if (!Pattern_Discovered && Status){
		if (count == 3){
			count = 0;
			if (mode)
				mode = 0;
			else mode = 1;
		}
	}

	if (Status && Pattern_Discovered){
		Pattern_Discovered = 0;
		Pattern.clear();
		itr = 0;
	}

	if (!Pattern_Discovered)
		Pattern += std::to_string(OptPrev);

	if (!Pattern_Discovered && Pattern.length() % 2 == 0){
		unsigned int i = Pattern.length() - 1, j = Pattern.length() / 2 - 1;
		for (i, j; j != -1;i--,j--)
		if (Pattern[i] != Pattern[j])
			return;
		Pattern_Discovered = 1;
		Pattern = Pattern.substr(0, i);
		itr = 0;
		count = 0;
	}
}

char AI::Pattern_Play(){
	if (itr == Pattern.length()) itr = 0;

	if (Pattern[itr] == 0)
		return 2;
	else if (Pattern[itr] == 1)
		return 0;
	else
		return 1;
}

char AI::Play(){
	if (!Pattern_Discovered){
		return Default_Play();
	}
	else{
		return Pattern_Play();
	}
}

Game::Game(){
	AI Machine;
	int match;
	Count = pWin = draw = 0;
	std::cout << "\tWelcome to rock - scissors - paper game.\n\n"
		"Play ? \t";
	system("PAUSE");
	std::cin.clear();
	std::fflush(stdin);
	char psave = 0, msave, time = 0;
	while (psave != -35){
		msave = Machine.Play();
		AIPlayer += msave;

		std::cout << "1 : rock, 2 : scissors , 3 : paper.\n\n"
			"Input : ";
		psave = _getch() - '0' - 1;
		Player += psave;

		std::cout << char(psave + '0' + 1) <<"\n\n";
	
		++count;

		if (psave == -35) break;

		if (psave > 2 || psave < 0){
			std::cout << "Invalid input.\n\n";
			match = 0;
		}
		else{
			if (msave == psave){
				++draw;
				match = -1;
			}
			else if (psave - msave == -1 || psave - msave == 2){
				++pWin;
				match = 1;
			}
			else
				match = 0;
		}

		if (!match)
			std::cout << "You Lose.\n\n";
		else if (match == -1)
			std::cout << "It's Draw,\n\n";
		else
			std::cout << "You Win.\n\n";
		Machine.Game_Update(match, psave - 1);
	}

	std::cout << "\tSumary.\n\n"
		"Total : " << count
		<< "Win : " << pWin << "\tDraw : " << draw << "\tLose : " << count - pWin << "\n\n";

	system("PAUSE");
}