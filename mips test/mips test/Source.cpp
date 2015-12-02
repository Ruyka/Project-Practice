#include<iostream>
using namespace std;

void  main(){
	cout << 5 / 2 << endl;
	for (int i = 0; i < 100; i++){
		int k = rand();
		if (k % 50 == k - 50 * (k / 50))
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}
}