//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
//#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
//#define forn(i,n) fori(i,0,n-1)
//#define fora(i,a) forn(i,sz(a)
//
//int main() {
//	int count = 1, taskCount = 0, n, t, temp;
//	while (scanf("%d %d", &n, &t) != EOF) {
//		forn(i, n) {
//			scanf("%d", &temp);
//			t -= temp;
//			if (t >= 0)
//				++taskCount;
//			else {
//				cin.ignore(50, '\n');
//				break;
//			}
//		}
//		printf("Case %d: %d", count, taskCount);
//		taskCount = 0;
//	}
//	return 0;
//}