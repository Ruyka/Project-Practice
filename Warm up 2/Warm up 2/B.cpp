#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <numeric>
#include <functional>
#include <valarray>
#include <complex>
#include <utility>

using namespace std;

typedef vector<int> vi;
vi result;
vector<string> testIndex;

vi toBase(int B, int num) {
	vi rep;
	while (num != 0) {
		rep.push_back((num % B)%B);
		num /= B;
	}
	return rep;
}

int fromBase(int B, vi num) {
	int lenght = num.size(), re = 0;
	for (int i = 0; i < lenght; i++)
		re += num[i] * pow(B, i);

	return re;
}

int nimB(int B, int X, int Y) {
	vi x = toBase(B, X);
	vi y = toBase(B, Y);
	vi min = x.size() < y.size() ? x : y;
	vi max = x.size() == y.size() ? x : y;
	int Lenght = min.size();

	for (int i = 0; i < Lenght; i++) {
		int temp = max[i] + min[i];
		max[i] = temp >= B ? temp%B : temp;
	}

	return fromBase(B, max);
}

int main(){
	int n;
	cin >> n;

	int B, X, Y;

	result.resize(n);
	testIndex.resize(n);
	for (int i = 0; i < n; i++){
		cin >> testIndex[i] >> B >> X >> Y;
		result[i] = nimB(B, X, Y);
	}
	
	for (int i = 0; i < n; i++)
		cout << testIndex[i] << ' ' << result[i] << endl;

	return 0;
}

