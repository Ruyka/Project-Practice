#include "game.h"
#define UP 72
#define DOWN 80
#define SHOOT 77

int frame = 1;

void game::begin(){
	isEnd = false;


	spaceShip = gameObjectFactory::createSpaceShip();
	int y = 0;
	for (int i = 0; i < 5; i++){
		y = rand() % 25;
		for (int j = 0; j < enemy.size(); j++){
			if (y == enemy[j]._co.Y){
				y = rand() % 80;
				j = 0;
			}
		}
		enemy.push_back(gameObjectFactory::createEnemySpaceShip(y));
	}

	drawScreen();
	move();
}

bool compareX(gameObject X, gameObject Y){ 
	return X._co.X < Y._co.X;
}
bool compareY(gameObject X, gameObject Y){
	return X._co.Y < Y._co.Y;
}

void game::update(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < bullet.size(); i++){
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet[i]._co);
		cout << " ";
	}
	for (int i = 0; i < enemy.size(); i++){
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), enemy[i]._co);
		cout << " ";
	}

	for (int i = 0; i < bullet.size(); i++){
		if (bullet[i]._di == 1){
			for (int j = 0; j < enemy.size(); j++){
				if (enemy[j]._co.Y == bullet[i]._co.Y && enemy[j]._co.X - bullet[i]._co.X <= 2){
					bullet.erase(bullet.begin() + i);
					enemy.erase(enemy.begin() + j);
					++_score;
					if (i != 0)
						--i;
					break;
				}
			}

			for (int j = 0; j < bullet.size(); j++)
			if (bullet[j]._di == -1 && bullet[i]._co.Y == bullet[j]._co.Y && bullet[j]._co.X - bullet[i]._co.X <= 3){
				bullet.erase(bullet.begin() + i);
				bullet.erase(bullet.begin() + j - 1);
				if (i != 0)
					--i;
				break;
			}
		}
		else {
			if (bullet[i]._co.Y == spaceShip._co.Y && bullet[i]._co.X >= spaceShip._co.X && bullet[i]._co.X - spaceShip._co.X <= 2){
				isEnd = true;
				return;
			}
		}
	}

	for (int i = 0; i < enemy.size(); i++){
		if (enemy[i]._co.X == 0){
			if (spaceShip._co.Y == enemy[i]._co.Y){
				isEnd = true;
				return;
			}
			enemy.erase(enemy.begin() + i);
		}
		else{
			enemy[i]._co.X += enemy[i]._di * enemy[i]._sp;
			if (frame % 10 == 0 && bullet.size() <= 20 &&rand() % 2)
				bullet.push_back(gameObjectFactory::createBullet(enemy[i]));
		}
	}

	for (int i = 0; i < bullet.size(); i++){
		if ((bullet[i]._co.X <= 1 && bullet[i]._di == -1) || (bullet[i]._co.X >= 78 && bullet[i]._di == 1))
			bullet.erase(bullet.begin() + i);
		else
			bullet[i]._co.X += bullet[i]._di * bullet[i]._sp;
	}

	if (frame % 30 == 0){
		int y = 0;
		for (int i = 0; i < 10 - enemy.size(); i++){
			y = rand() % 25;
			for (int j = 0; j < enemy.size(); j++){
				if (y == enemy[j]._co.Y){
					y = rand() % 80;
					j = 0;
				}
			}
			enemy.push_back(gameObjectFactory::createEnemySpaceShip(y));
		}
	}

	sort(bullet.begin(), bullet.end(), compareX);
	sort(bullet.begin(), bullet.end(), compareY);
}

void game::move(){
	while (!isEnd){
		do {
			update();
			drawScreen();
			++frame;
			Sleep(50);
		} while (!_kbhit() && !isEnd);


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), spaceShip._co);
		cout << " ";

		_getch();
		char key = _getch();
		if (key == UP && spaceShip._co.Y > 0)
			--spaceShip._co.Y;

		if (key == DOWN && spaceShip._co.Y < 24)
			++spaceShip._co.Y;

		if (key == SHOOT && bullet.size() <= 20)
			bullet.push_back(gameObjectFactory::createBullet(spaceShip));
	}
	end();
}

void game::drawScreen(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), spaceShip._co);
	cout << " ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	for (int i = 0; i < bullet.size(); i++){
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet[i]._co);
		cout << " ";
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 204);
	for (int i = 0; i < enemy.size(); i++){
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), enemy[i]._co);
		cout << " ";
	}

	COORD D;
	D.X = 0;
	D.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), D);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Score : " << _score;
}

void game::end(){
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "You Lose !!!!\n"
		"Score: " << _score << endl
		<< "Play again ? (y/n) ";

	_getch();
	char k = _getch();
	if (k == 'y'){
		system("CLS");
		bullet.clear();
		enemy.clear();
		begin();
	}
}