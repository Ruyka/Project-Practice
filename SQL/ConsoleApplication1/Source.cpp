#include<iostream>
#include<string>
using namespace std;

void main(){
	string a = "1001 Huong 8 Dien Bien Phu 8330733 500000 1";
	int cur = a.length();
	string b = a.substr(0, a.find(' '));
	cout << b << endl;
	cout << a << endl;
	b = "Hello";
	cout << b << endl;
}