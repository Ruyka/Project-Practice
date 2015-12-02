#include<iostream>
using namespace std;

int main(){
	unsigned int n, pasTri[50], pasTemp[50];

	for (int i = 0; i < 50; i++)
		pasTri[i] = pasTemp[i] = 0;
	
	pasTri[0] = 1;
	pasTemp[0] = 1;

	cout << "Please enter number of row(s) : ";
	cin >> n;

	cout << "\nPascal Triangle : \n\n";

	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++)
			pasTri[j + 1] = pasTemp[j + 1] + pasTemp[j];


		for (int j = 0; pasTri[j]; j++){
			cout << pasTri[j] << " ";
			pasTemp[j] = pasTri[j];
		}
		cout << endl;
		system("PAUSE");
	}
}