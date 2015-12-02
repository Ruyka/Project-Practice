#include<iostream>
using namespace std;
bool check(int *m, int n, int v){
	for (int i = 0; i < n; ++i){
		for (int j = i; j < n; ++j){
			if (m[i] > m[j]){
				int temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < n - 1; ++i){
		sum = sum + m[i];
		if (sum > v)
			return false;
	}
	return true;
}
int main(){
	int n, v, *m;
	cin >> n >> v;
	m = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> m[i];
	if (check(m, n, v))
		cout << "YES\n";
	else
		cout << "NO\n";
	delete[]m;
	return 0;
}