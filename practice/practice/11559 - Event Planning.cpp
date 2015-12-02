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
//#define MAX_PRICE 11000
//#define NOPE -1
//
//int main() {
//	int p, b, h, w, hPrice, prevPrice, hAvailable, bestPrice;
//	while (scanf("%ld %ld %ld %ld", &p, &b, &h, &w) != EOF) {
//		hPrice = 0;
//		hAvailable = bestPrice = NOPE;
//		prevPrice = MAX_PRICE;
//		for (int i = 0; i < h; i++) {
//			scanf("%d", &hPrice);
//			if (hPrice < prevPrice || bestPrice == -1) {
//				for (int j = 0; j < w; j++) {
//					scanf("%d", &hAvailable);
//					if (hAvailable >= p) {
//						bestPrice = hPrice * p <= b? hPrice * p : NOPE;
//						cin.ignore(1000, '\n');
//						break;
//					}
//				}
//				prevPrice = hPrice;
//			}
//			else {
//				cin.ignore(1000, '\n');
//				cin.ignore(1000, '\n');
//			}
//		}
//		printf(bestPrice != -1 ? "%d\n" : "stay home\n", bestPrice);
//	}
//	return 0;
//}