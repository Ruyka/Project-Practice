#include<iostream>
#include<Windows.h>

void txtColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main(){
	for (int i = 0; i < 255; ++i){
		txtColor(i);
		std::cout << "No." << i << std::endl;
	}
	return 0;
}