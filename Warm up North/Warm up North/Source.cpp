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

#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define forn(i,n) fori(i,0,n-1)
#define fora(i,a) forn(i,sz(a))
#define MIN -1000000001
#define MAX 1000000001

int main() {
	vector<long long> result;
	long long biggest, min, sum;
	int test, n, m, len, *temp, *check;
	temp = new int[600001];
	check = new int[600001];

	cin >> test;
	result.resize(test);
	forn(i, test) {
		cin >> n >> m;
		min = MAX;
		forn(j, n) {
			cin >> temp[j];
			temp[n + j] = temp[j]; 
			min = min > temp[j] ? temp[j] : min;
		}
		forn(j, n)
			check[j] = check[n + j] = temp[j] > min ? true : false;
		biggest = MIN;
		forn(j, n) {
			sum = 0;
			for (int k = j; k < j + m && check[k]; ++k)
				sum += temp[k];
			biggest = biggest < sum ? sum : biggest;
		}

		result[i] = biggest;
	}
	forn(i, test)
		cout << result[i] << endl;

	delete[]temp;
	delete[]check;
	return 0;
}