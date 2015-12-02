
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define UP 72

typedef struct toado
{
	int x, y;
}toado;
toado than[10], tam, cot, t[20];

int a[100][100], diem = 0;
void begin();
void gotoxy(int x, int y);
void txtColor(int color);
void bird();
void move();
void khung();
void cls();
void ongkhoi();
void start();
void lef();
void day();
void score();
void died();
void main()
{

	begin();
}
void move()
{
	int i, j;
	char c;
	do
	{
		cls();
		khung();
		score();
		bird();
		died();
		if (a[tam.x][tam.y] == 0 && a[tam.x][11] == 1)
			diem++;
		day();
		if (a[1][11] == 1)
		{
			for (i = 0; i <= 1; i++)
			for (j = 11; j <= 29; j++)
			{
				a[i][j] = 0;
				gotoxy(i, j);
				printf(" ");
				gotoxy(i + 1, j);
				printf(" ");
				gotoxy(i + 2, j);
				printf(" ");
			}
		}
		else
			lef();
		if (a[50][11] == 1)
			ongkhoi();
		tam.y++;
		Sleep(250);
	} while (!_kbhit());
	_getch();
	c = _getch();
	if (c == UP)
	{
		tam.y -= 2;
		move();
	}
	else
	{
		gotoxy(0, 32);
		system("pause");
		system("cls");
		move();
	}
}

void ongkhoi()
{
	int i, x;
	cot.x = 78;
	cot.y = 11;
	srand(time(NULL));
	x = rand() % 3 + 8;
	for (i = 1; i < x; i++)
	{
		t[i].x = cot.x;
		t[i].y = cot.y + (i - 1);
		a[t[i].x][t[i].y] = 1;
	}
	for (i = x; i < 2 * x - 1; i++)
	{
		t[i].x = cot.x + 1;
		t[i].y = cot.y + (i - x);
		a[t[i].x][t[i].y] = 1;
	}

	cot.y = 29;
	srand(time(NULL));
	x = rand() % 5 + 4;
	for (i = 1; i <= x; i++)
	{
		t[i].x = cot.x;
		t[i].y = cot.y - (i - 1);
		a[t[i].x][t[i].y] = 1;
	}
	for (i = x; i <= 2 * x - 1; i++)
	{
		t[i].x = cot.x + 1;
		t[i].y = cot.y - (i - x);
		a[t[i].x][t[i].y] = 1;
	}
}
void cls()
{
	int j;
	for (j = 9; j <= 29; j++)
	{
		gotoxy(28, j);
		printf("     ");
	}
}
void khung()
{
	txtColor(11);
	int i;
	for (i = 0; i<80; i++)
	{
		gotoxy(i, 10);
		printf("*");
		gotoxy(i, 30);
		printf("*");
	}
}

void bird()
{
	int i;
	txtColor(12);
	for (i = 0; i <= 1; i++)
	{
		than[i].x = tam.x;
		than[i].y = tam.y - i;
		gotoxy(than[i].x, than[i].y);
		printf("%c", 3);
	}
	for (i = 1; i <= 2; i++)
	{
		than[i].x = tam.x + 1;
		than[i].y = tam.y - (i - 1);
		gotoxy(than[i].x, than[i].y);
		printf("%c", 3);
	}
}
void txtColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void day()
{
	int i, j;
	txtColor(10);
	for (i = 0; i < 80; i++)
	for (j = 11; j <= 29; j++)
	{
		if (a[i][j] == 1)
		{
			gotoxy(i, j);
			printf("%c", 2);
		}
	}
}

void start()
{
	int i, j;
	for (i = 0; i <= 80; i++)
	for (j = 11; j <= 29; j++)
	{
		a[i][j] = 0;
	}
}

void lef()
{
	int i, j;
	for (i = 0; i <= 80; i++)
	for (j = 11; j <= 29; j++)
	{
		if ((a[i][j] == 1) && (a[i + 1][j] == 1) && i != 1 && i != 0)
		{
			a[i - 1][j] = a[i][j];
			a[i][j] = 0;
			gotoxy(i + 2, j);
			printf(" ");
			a[i - 2][j] = a[i + 1][j];
			a[i + 1][j] = 0;
			gotoxy(i + 3, j);
			printf(" ");
		}
	}
}

void score()
{
	txtColor(14);
	gotoxy(10, 9);
	printf("DIEM : %d", diem);
}

void died()
{
	int i;
	char c;
	if (a[tam.x][tam.y] == 1 || tam.y == 30)
	{
		system("cls");
		gotoxy(28, 10);
		txtColor(12);
		printf("\a");
		printf("GAME OVER !!!");
		txtColor(8);
		for (i = 25; i<50; i++)
		{
			gotoxy(i, 13);
			printf("*");
			gotoxy(i, 17);
			printf("*");
		}
		for (i = 13; i <= 17; i++)
		{
			gotoxy(25, i);
			printf("*");
			gotoxy(49, i);
			printf("*");
		}
		gotoxy(30, 15);
		txtColor(10);
		printf("Diem cua ban: %d ", diem);

		_getch();
		system("cls");
		gotoxy(30, 12);
		printf("Ban muon choi lai khong (y/n) ?");
		c = _getch();
		if (c == 'y' || c == 'Y')
		{
			diem = 0;
			system("cls");
			begin();
		}
		else
			exit(1);
	}
}

void begin()
{
	start();
	tam.x = 30;
	tam.y = 15;
	ongkhoi();
	move();
}