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
//#include <unordered_map>
//#include <unordered_set>
//using namespace std;
//
//typedef long long LL;
//typedef unsigned long long uLL;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//typedef vector<vi> vgraph;
//typedef vector<pii> vpii;
//typedef vector<LL> vLL;
//typedef vector<string> vs;
//
//#define sz(a) (int)a.size()
//#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
//#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
//#define forn(i,n) fori(i,0,n-1)
//#define fora(i,a) forn(i,sz(a))
//#define fore(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
//
//string words, brand;
//
//int main() {
//	int p, r, pr, bestCompPR, test = 1;
//	double  pp;
//	string bestComp;
//	double bestCompPP;
//	cin >> r >> p;
//	cin.get();
//	while (r || p) {
//		bestCompPR = 0;
//		bestCompPP = 1000000000;
//		forn(i, r) 
//			getline(cin, words);
//		
//		forn(j, p) {
//			getline(cin, brand);
//			cin >> pp >> pr;
//			cin.get();
//			if (bestCompPR < pr) {
//				bestComp = brand;
//				bestCompPP = pp;
//				bestCompPR = pr;
//			}
//			else if (bestCompPR == pr && bestCompPP < pp) {
//				bestComp = brand;
//				bestCompPP = pp;
//			}
//			forn(i, pr) 
//				getline(cin, words);
//			
//		}
//		if (test > 1)
//			cout << endl;
//		cout << "RFP #" << test++ << endl << bestComp << endl;
//		cin >> r >> p;
//		cin.get();
//	}
//	return 0;
//}