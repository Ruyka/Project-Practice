#include<iostream>
using namespace std;
bool checkSysmetric(int **a, int r, int c){
	for (int i = 0; i < r / 2; ++i){
		for (int j = 0; j < c; ++j){
			if (a[i][j] != a[r - i - 1][j])
				return false;
		}
	}
	return true;
}

void printMatrix(int **a, int r, int c){
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int R_minimumRow(int **a, int r, int c){
	if (r % 2 != 0) return r;
	unsigned int save = R_minimumRow(a, r / 2, c);
	if (checkSysmetric(a, r, c))
		return save;
	else
		return r;
}

int minimumRow(int **a, int r, int c){
	while (r % 2 == 0){
		if (checkSysmetric(a, r, c))
			r = r / 2;
		else break;
	}
	return r;
}

int** createMatrix(int **a, int Minr, int c){
	int**b;
	b = new int*[Minr];
	for (int i = 0; i < Minr; ++i){
		b[i] = new int[c];
		for (int j = 0; j < c; ++j)
			b[i][j] = a[i][j];
	}
	return b;
}
void clearMatrix(int **a, int r, int c){
	for (int i = 0; i < r; ++i)
		delete[]a[i];
	delete[]a;
}

int main(){
	int r, c, **a;
	cin >> r >> c;
	a = new int*[r];
	for (int i = 0; i < r; ++i){
		a[i] = new int[c];
		for (int j = 0; j < c; ++j){
			cin >> a[i][j];
		}
	}
	cout << endl;
	printMatrix(a, r, c);
	cout << endl;

	if (checkSysmetric(a, r, c))
		cout << "GOOD\n";
	else{
		cout << "Not sysmetrix.\n";
		return 0;
	}
	
	int Min = minimumRow(a, r, c);
	cout << "Row : " << Min << endl;

	int **b = createMatrix(a, Min, c);

	printMatrix(b, Min, c);

	clearMatrix(b, Min, c);

	clearMatrix(a, r, c);
	return 0;
}