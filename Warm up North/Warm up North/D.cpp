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
//vector<int> result;
//
//int main() {
//	int t, chh, cmm, hh, mm, click;
//	char dump;
//	cin >> t;
//	result.resize(t);
//	forn(i, t) {
//		cin >> chh >> dump >> cmm >> hh >> dump >> mm;
//		click = abs(chh - hh) > 6 ? 12 - max(chh, hh) + min(chh, hh) : abs(chh - hh);
//		click += abs(cmm - mm) > 30 ? 60 - max(cmm, mm) + min(cmm, mm) : abs(cmm - mm);
//		result[i] = click;
//	}
//
//	forn(i, t)
//		cout << result[i] << endl;
//
//	return 0;
//}