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
//typedef vector<int> vi;
//
//#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
//#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
//#define forn(i,n) fori(i,0,n-1)
//#define fora(i,a) forn(i,sz(a))
//
//int main() {
//	int h, d, l, f, Dis;
//	int i;
//	cin >> h >> d >> l >> f;
//	while (h != 0) {
//		f *= d;
//		h *= 100;
//		d *= 100;
//		l *= 100;
//		Dis = 0;
//		for (i = 0;; i++) {
//			if (i == 25)
//				i = i;
//			Dis += d;
//			if (Dis > h) {
//				printf("success on day "); 
//				break;
//			}
//			Dis -= l;
//			if (Dis < 0) {
//				printf("failure on day "); 
//				break; 
//			}
//			d = d > f ? d - f : 0;
//		}
//		printf("%d\n", i + 1);
//		cin >> h >> d >> l >> f;
//	}
//	return 0;
//}