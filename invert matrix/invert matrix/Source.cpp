#include<iostream>
using namespace std;

void Gaussian(double**matrix, int*index, int n){
	double*c = new double[n];

	for (int i = 0; i < n; i++){
		index[i] = i;
	}

	for (int i = 0; i < n; i++){
		double c1 = 0;
		for (int j = 0; j < n; j++){
			double c0 = abs(matrix[i][j]);
			c1 = c0 > c1 ? c0 : c1;
		}
		c[i] = c1;
	}

	int k = 0;
	for (int j = 0; j < n - 1; j++){
		double pi1 = 0;
		for (int i = j; i < n; i++){
			double pi0 = abs(matrix[index[i]][j]);
			pi0 /= c[index[i]];
			if (pi0 > pi1){
				pi1 = pi0;
				k = i;
			}
		}

		int itmp = index[j];
		index[j] = index[k];
		index[k] = itmp;
		for (int i = j + 1; i < n; i++){
			double pj = matrix[index[i]][j] / matrix[index[j]][i];
			matrix[index[i]][j] = pj;
			for (int l = j + 1; l < n; l++)
				matrix[index[i]][l] -= pj*matrix[index[j]][l];
		}
	}
	delete[]c;
}

double** Invert(double**matrix, int n){
	double **b = new double*[n];
	for (int i = 0; i < n; i++){
		b[i] = new double[n];
		for (int j = 0; j < n; j++)
			b[i][j] = i == j ? 1 : 0;
	}
	
	double **x = new double*[n];
	for (int i = 0; i < n; i++)
		x[i] = new double[n];

	int*index = new int[n];

	Gaussian(matrix, index, n);

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = 0; k < n; k++)
				b[index[j]][k] -= matrix[index[j]][i] * b[index[i]][k];

	for (int i = 0; i < n; i++){
		x[n - 1][i] = b[index[n - 1]][i] / matrix[index[n - 1]][n - 1];
		for (int j = n - 2; j >= 0; j--){
			x[j][i] = b[index[j]][i];
			for (int k = j + 1; k < n; k++)
				x[j][i] -= matrix[index[j]][k] * x[k][i];
			x[j][i] /= matrix[index[j]][j];
		}
	}

	for (int i = 0; i < n; i++)
		delete[]b[i];
	delete[]b;
	delete[]index;
	
	return x;
}

 void main(){
	cout << "Matrix dimension : ";
	int n;
	cin >> n;

	double**matrix = new double*[n];
	for (int i = 0; i < n; i++){
		matrix[i] = new double[n];
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << "\n\n";
	double **d = Invert(matrix, n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < n; i++){
		delete[]matrix[i];
		delete[]d[i];
	}
	delete[]matrix;
	delete[]d;
}