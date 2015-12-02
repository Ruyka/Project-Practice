#include<iostream>
#include<random>
#include<vector>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include"2048.h"

game::game(){
	initGame();
}

void game::initGame(){
	diem = 0;
	for (int i = 0; i < BLOCK_SIZE; ++i){
		for (int j = 0; j < BLOCK_SIZE; ++j)
			player[i][j] = 0;
	}
	int X = randInt(BLOCK_SIZE - 1, 0), Y = randInt(BLOCK_SIZE - 1, 0);
	player[X][Y] = randInt(2, 1) * 2;
	int Xs = randInt(BLOCK_SIZE - 1, 0), Ys = randInt(BLOCK_SIZE - 1, 0);
	while (Xs == X && Ys == Y){
		Xs = randInt(BLOCK_SIZE - 1, 0); Ys = randInt(BLOCK_SIZE - 1, 0);
	}
	player[Xs][Ys] = randInt(2, 1) * 2;
	
}

int game::checkFull(){
	int count = 0;
	for (int i = 0; i < BLOCK_SIZE; ++i){
		for (int j = 0; j < BLOCK_SIZE; ++j){
			if (!player[i][j])
				++count;
			if (player[i][j] == 2048)
				return 2;
		}
	}
	if (checkMoveable('\0'))
		return true;
	if (!count)
		return 0;
	return 1;
}

bool game::checkMoveable(char k){
	int check = 0;
	switch (k){
	case UP: case DOWN:		
		for (int i = 0; i < BLOCK_SIZE; ++i){
			for (int j = 0; j < BLOCK_SIZE; ++j){
				if (player[i][j]){
					int countUp = 0, countDown = 0;
					for (int k = 0; k < BLOCK_SIZE; ++k){
						if (j == k)
							continue;
						if (player[i][k] == player[i][j] && abs(k - j) == 1)
							++check;
						else if (player[i][k] == player[i][j] && abs(k - j) > 1){
							int count = 0, min, max;
							if (j > k){
								min = k;
								max = j;
							}
							else{
								min = j;
								max = k;
							}
							for (min + 1; min < max; ++min){
								if (player[i][min])
									++count;
							}
							if (!count)
								++check;
						}

						if (!player[i][k] && k < j)
							++countUp;
						else if (!player[i][k] && k > j)
							++countDown;
					}
					if (k == UP && countUp)
						++check;
					else if (k == DOWN && countDown)
						++check;
				}
			}
		}
		break;
	case LEFT:case RIGHT:
		for (int j = 0; j < BLOCK_SIZE; ++j){
			for (int i = 0; i < BLOCK_SIZE; ++i){
				if (player[i][j]){
					int countLeft = 0, countRight = 0;
					for (int k = 0; k < BLOCK_SIZE; ++k){
						if (i == k)
							continue;
						if (player[k][j] == player[i][j] && abs(k - i) == 1)
							++check;
						else if (player[k][j] == player[i][j] && abs(k - j) > 1){
							int count = 0, min, max;
							if (i > k){
								min = k;
								max = i;
							}
							else{
								min = i;
								max = k;
							}
							for (min + 1; min < max; ++min){
								if (player[i][min])
									++count;
							}
							if (!count)
								++check;
						}
						if (!player[k][j] && k < i)
							++countLeft;
						else if (!player[k][j] && k > i)
							++countRight;
					}

					if (k == LEFT && countLeft != 0)
						++check;
					else if (k == RIGHT && countRight != 0)
						++check;
				}
			}
		}
		break;
	default:
		for (int i = 0; i < BLOCK_SIZE; ++i){
			for (int j = 0; j < BLOCK_SIZE; ++j){
				if (player[i][j]){
					int countUp = 0, countDown = 0;
					for (int k = 0; k < BLOCK_SIZE; ++k){
						if (j == k)
							continue;
						if (player[i][k] == player[i][j] && abs(k - j) == 1)
							++check;
						else if (player[i][k] == player[i][j] && abs(k - j) > 1){
							int count = 0, min, max;
							if (j > k){
								min = k;
								max = j;
							}
							else{
								min = j;
								max = k;
							}
							for (min + 1; min < max; ++min){
								if (player[i][min])
									++count;
							}
							if (!count)
								++check;
						}

						if (!player[i][k] && k < j)
							++countUp;
						else if (!player[i][k] && k > j)
							++countDown;
					}
					if (countUp)
						++check;
					if (countDown)
						++check;
				}
			}
		}
		for (int j = 0; j < BLOCK_SIZE; ++j){
			for (int i = 0; i < BLOCK_SIZE; ++i){
				if (player[i][j]){
					int countLeft = 0, countRight = 0;
					for (int k = 0; k < BLOCK_SIZE; ++k){
						if (i == k)
							continue;
						if (player[k][j] == player[i][j] && abs(k - i) == 1)
							++check;
						else if (player[k][j] == player[i][j] && abs(k - j) > 1){
							int count = 0, min, max;
							if (i > k){
								min = k;
								max = i;
							}
							else{
								min = i;
								max = k;
							}
							for (min + 1; min < max; ++min){
								if (player[i][min])
									++count;
							}
							if (!count)
								++check;
						}
						if (!player[k][j] && k < i)
							++countLeft;
						else if (!player[k][j] && k > i)
							++countRight;
					}

					if (countLeft != 0)
						++check;
					if (countRight != 0)
						++check;
				}
			}
		}
	}
	if (check)
		return true;
	return false;
}

void game::nextBlock(){
	int X = randInt(BLOCK_SIZE - 1, 0), Y = randInt(BLOCK_SIZE - 1, 0);
	while (player[X][Y]){
		X = randInt(BLOCK_SIZE - 1, 0); Y = randInt(BLOCK_SIZE - 1, 0);
	}
	player[X][Y] = randInt(2, 1) * 2;
}

void game::printBlock(){
	for (int i = 0; i < BLOCK_SIZE; ++i){
		for (int j = 0; j < BLOCK_SIZE; ++j){
			if (player[i][j] == 2 || player[i][j] == 4 || player[i][j] == 8)
				printNumber(player[i][j], i*BLOCK_AREA + 5, j*BLOCK_AREA + 7);

			else if (player[i][j] == 16 || player[i][j] == 32 || player[i][j] == 64){
				int save = player[i][j];
				std::vector<int> seque;
				while (save){
					seque.push_back(save % 10);
					save = save / 10;
				}
				int total = seque.size();
				for (int k = 0; k < seque.size(); ++k)
					printNumber(seque[total - 1 - k], i*BLOCK_AREA + 3 + 5 * k, j*BLOCK_AREA + 7);
				while (seque.size())
					seque.pop_back();
			}
			else if (player[i][j] == 128 || player[i][j] == 256 || player[i][j] == 512){
				int save = player[i][j];
				std::vector<int> seque;
				while (save){
					seque.push_back(save % 10);
					save = save / 10;
				}
				int total = seque.size();
				for (int k = 0; k < seque.size(); ++k)
					printNumber(seque[total - 1 - k], i*BLOCK_AREA + 1 + 5 * k, j*BLOCK_AREA + 7);
				while (seque.size())
					seque.pop_back();
			}
			else if (player[i][j] == 1024 || player[i][j] == 2048){
				int save = player[i][j];
				std::vector<int> seque;
				while (save){
					seque.push_back(save % 10);
					save = save / 10;
				}
				int total = seque.size();
				for (int k = 0; k < seque.size(); ++k){
					if (seque[total - 1 - k] == 0)
						printNumber(seque[total - 1 - k], i*BLOCK_AREA + 4 * k, j*BLOCK_AREA + 7);
					else
						printNumber(seque[total - 1 - k], i*BLOCK_AREA + 5 * k, j*BLOCK_AREA + 7);					
				}
				while (seque.size())
					seque.pop_back();
			}
		}
	}
	toPos(0, 1);
	txtColor(DEFAULT_COLOR);
}

void game::printBoard(){
	txtColor(BOARD_COLOR);
	for (int i = 0; i <= BLOCK_SIZE; ++i){
		toPos(0, 2 + i * BLOCK_AREA);
		for (int j = 0; j <= BLOCK_AREA * 4; ++j)
			std::cout << " ";
	}
	for (int i = 0; i <= BLOCK_SIZE; ++i){
		toPos(0 + i * BLOCK_AREA, 2);
		for (int j = 0; j < BLOCK_AREA * 4; ++j){
			toPos(0 + i * BLOCK_AREA, 2 + j);
			std::cout << " ";
		}
	}
	toPos(0, 1);
	txtColor(DEFAULT_COLOR);
}

void game::printDiem(){
	toPos(0, 0);
	std::cout << "DIEM : " << diem;
}

void game::CLS(){
	txtColor(DEFAULT_COLOR);
	for (int i = 0; i < BLOCK_SIZE; ++i){
		for (int j = 0; j < BLOCK_SIZE; ++j){
			for (int k = 0; k < 5; ++k){
				toPos(i*BLOCK_AREA, j*BLOCK_AREA + 7 + k);
				for (int k = 0; k < 19; ++k)
					std::cout << " ";
			}
			for (int k = 0; k < 5; ++k){
				toPos(i*BLOCK_AREA, j*BLOCK_AREA + 7 + k);
				txtColor(BOARD_COLOR);
				std::cout << " ";
			}
			txtColor(DEFAULT_COLOR);
		}
	}
}

int game::move(char key){
	switch (key){
	case UP:
		for (int k = 0; k < 2; ++k){
			for (int i = 0; i < BLOCK_SIZE; ++i){
				for (int j = 1; j < BLOCK_SIZE; ++j){
					if (!player[i][j - 1]){
						player[i][j - 1] = player[i][j];
						player[i][j] = 0;
					}
				}
			}
		}
		for (int i = 0; i < BLOCK_SIZE; ++i){
			for (int j = 1; j < BLOCK_SIZE; ++j){
				if (!player[i][j - 1]){
					player[i][j - 1] = player[i][j];
					player[i][j] = 0;
				}
				else if (player[i][j - 1] == player[i][j]){
					player[i][j - 1] += player[i][j];
					diem += player[i][j - 1];
					player[i][j] = 0;
					++j;
				}
			}
		}
		for (int k = 0; k < 2; ++k){
			for (int i = 0; i < BLOCK_SIZE; ++i){
				for (int j = 1; j < BLOCK_SIZE; ++j){
					if (!player[i][j - 1]){
						player[i][j - 1] = player[i][j];
						player[i][j] = 0;
					}
				}
			}
		}
		break;
	case DOWN:
		for (int k = 0; k < 2; ++k){
			for (int i = 0; i < BLOCK_SIZE; ++i){
				for (int j = BLOCK_SIZE - 1; j > 0; --j){
					if (!player[i][j]){
						player[i][j] = player[i][j - 1];
						player[i][j - 1] = 0;
					}
				}
			}
		}
		for (int i = 0; i < BLOCK_SIZE; ++i){
			for (int j = BLOCK_SIZE - 1; j > 0; --j){
				if (!player[i][j]){
					player[i][j] = player[i][j - 1];
					player[i][j - 1] = 0;
				}
				else if (player[i][j] == player[i][j - 1]){
					player[i][j] += player[i][j - 1];
					diem += player[i][j];
					player[i][j - 1] = 0;
					--j;
				}
			}
		}
		for (int k = 0; k < 2; ++k){
			for (int i = 0; i < BLOCK_SIZE; ++i){
				for (int j = BLOCK_SIZE - 1; j > 0; --j){
					if (!player[i][j]){
						player[i][j] = player[i][j - 1];
						player[i][j - 1] = 0;
					}
				}
			}
		}
		break;
	case LEFT:
		for (int k = 0; k < 2; ++k){
			for (int j = 0; j < BLOCK_SIZE; ++j){
				for (int i = 1; i < BLOCK_SIZE; ++i){
					if (!player[i - 1][j]){
						player[i - 1][j] = player[i][j];
						player[i][j] = 0;
					}
				}
			}
		}
		for (int j = 0; j < BLOCK_SIZE; ++j){
			for (int i = 1; i < BLOCK_SIZE; ++i){
				if (!player[i - 1][j]){
					player[i - 1][j] = player[i][j];
					player[i][j] = 0;
				}
				else if (player[i - 1][j] == player[i][j]){
					player[i - 1][j] += player[i][j];
					diem += player[i - 1][j];
					player[i][j] = 0;
					++i;
				}
			}
		}
		for (int k = 0; k < 2; ++k){
			for (int j = 0; j < BLOCK_SIZE; ++j){
				for (int i = 1; i < BLOCK_SIZE; ++i){
					if (!player[i - 1][j]){
						player[i - 1][j] = player[i][j];
						player[i][j] = 0;
					}
				}
			}
		}
		break;
	case RIGHT:
		for (int k = 0; k < 2; ++k){
			for (int j = 0; j < BLOCK_SIZE; ++j){
				for (int i = BLOCK_SIZE - 1; i > 0; --i){
					if (!player[i][j]){
						player[i][j] = player[i - 1][j];
						player[i - 1][j] = 0;
					}
				}
			}
		}
		for (int j = 0; j < BLOCK_SIZE; ++j){
			for (int i = BLOCK_SIZE - 1; i > 0; --i){
				if (!player[i][j]){
					player[i][j] = player[i - 1][j];
					player[i - 1][j] = 0;
				}
				else if (player[i][j] == player[i - 1][j]){
					player[i][j] += player[i - 1][j];
					diem += player[i][j];
					player[i - 1][j] = 0;
					--i;
				}
			}
		}
		for (int k = 0; k < 2; ++k){
			for (int j = 0; j < BLOCK_SIZE; ++j){
				for (int i = BLOCK_SIZE - 1; i > 0; --i){
					if (!player[i][j]){
						player[i][j] = player[i - 1][j];
						player[i - 1][j] = 0;
					}
				}
			}
		}
	}
	return 1;
}

void game::play(){
	printDiem();
	printBoard();
	printBlock();
	int check = true;
	while (check == 1){
		while (check == 1){
			printDiem();
			CLS();
			printBlock();
			_getch();
			char key = _getch();
			if (checkMoveable(key) && (key == UP || key == DOWN || key == LEFT || key == RIGHT)){
				check = move(key);
				nextBlock();
			}
			int save = checkFull();
			if (!save){
				CLS();
				printBlock();
				toPos(0, 1);
				std::cout << "You Lose.";
				Sleep(5000);
				check = 0;
			}
			else if (save == 2){
				CLS();
				printBlock();
				toPos(0, 1);
				std::cout << "You Win.";
				Sleep(5000);
				check = 2;
			}
		}
		toPos(0, 1);
		flush(std::cout);
		std::cout << "DO YOU WANT TO TRY AGAIN ? (Y/N) ";
		char k;
		std::cin >> k;
		if (k == 'Y' || k == 'y'){
			initGame();
			system("CLS");
			printBoard();
			check = 1;
		}
		else
			break;
	}
}

void txtColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void toPos(int X, int Y){
	COORD temp;
	temp.X = X;
	temp.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
}

int randInt(int max, int min){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

void printNumber(int val, int X, int Y){
	switch (val){
	case 0:
		toPos(X, Y);
		std::cout << "  *";
		toPos(X, Y + 1);
		std::cout << " * *";
		toPos(X, Y + 2);
		std::cout << "* * *";
		toPos(X, Y + 3);
		std::cout << " * *";
		toPos(X, Y + 4);
		std::cout << "  *";
		break;
	case 1:
		toPos(X, Y);
		std::cout << "  *";
		toPos(X, Y + 1);
		std::cout << " **";
		toPos(X, Y + 2);
		std::cout << "* *";
		toPos(X, Y + 3);
		std::cout << "  *";
		toPos(X, Y + 4);
		std::cout << "  *";
		break;
	case 2:
		toPos(X, Y);
		std::cout << " **";
		toPos(X, Y + 1);
		std::cout << "*  *";
		toPos(X, Y + 2);
		std::cout << "  *";
		toPos(X, Y + 3);
		std::cout << " *";
		toPos(X, Y + 4);
		std::cout << "****";
		break;
	case 3:
		toPos(X, Y);
		std::cout << "****";
		toPos(X, Y + 1);
		std::cout << "   *";
		toPos(X, Y + 2);
		std::cout << "***";
		toPos(X, Y + 3);
		std::cout << "   *";
		toPos(X, Y + 4);
		std::cout << "****";
		break;
	case 4:
		toPos(X, Y);
		std::cout << "   *";
		toPos(X, Y + 1);
		std::cout << "  **";
		toPos(X, Y + 2);
		std::cout << " * *";
		toPos(X, Y + 3);
		std::cout << "****";
		toPos(X, Y + 4);
		std::cout << "   *";
		break;
	case 5:
		toPos(X, Y);
		std::cout << "****";
		toPos(X, Y + 1);
		std::cout << "*";
		toPos(X, Y + 2);
		std::cout << "***";
		toPos(X, Y + 3);
		std::cout << "   *";
		toPos(X, Y + 4);
		std::cout << "***";
		break;
	case 6:
		toPos(X, Y);
		std::cout << "  *";
		toPos(X, Y + 1);
		std::cout << " * ";
		toPos(X, Y + 2);
		std::cout << "* *";
		toPos(X, Y + 3);
		std::cout << "*  *";
		toPos(X, Y + 4);
		std::cout << " **";
		break;
	case 8:
		toPos(X, Y);
		std::cout << " **";
		toPos(X, Y + 1);
		std::cout << "*  *";
		toPos(X, Y + 2);
		std::cout << " **";
		toPos(X, Y + 3);
		std::cout << "*  *";
		toPos(X, Y + 4);
		std::cout << " **";
		break;
	}
}