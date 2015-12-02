//#include <algorithm>
//#include <iostream>
//#include <iomanip>
//#include <sstream>
//#include <string>
//#include <list>
//#include <bitset>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <deque>
//#include <set>
//#include <map>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cctype>
//#include <cmath>
//#include <cassert>
//#include <ctime>
//#include <numeric>
//#include <functional>
//#include <valarray>
//#include <complex>
//#include <utility>
//using namespace std;
//
//#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
//#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
//#define forn(i,n) fori(i,0,n-1)
//#define fora(i,a) forn(i,sz(a))
//
//int main() {
//	vector<long long> result;
//	long long biggest, sum;
//	int test, n, m, len, temp[600001];
//	cin >> test;
//	result.resize(test);
//	forn(i, test) {
//		cin >> n >> m;
//		biggest = -1000000001;
//		forn(j, n) {
//			cin >> temp[j];
//			temp[n + j] = temp[j];
//		}
//		forn(j, n) {
//			sum = 0;
//			fori(k, j, j + m - 1)
//				sum += temp[k];
//			biggest = biggest < sum ? sum : biggest;
//		}
//		result[i] = biggest;
//	}
//	forn(i, test)
//		cout << result[i] << endl;
//
//	return 0;
//}