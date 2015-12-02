#include<iostream>
#include<string>
using namespace std;
void printReverse(string a, int pos){
	if (pos == a.length()) return;
	printReverse(a, pos + 1);
	cout << a[pos];
}
int main(){
	string a;
	cout << "Input  : ";
	getline (cin, a);
	cout << "Output : ";
	printReverse(a, 0);
	cout << endl;
	return 0;
}