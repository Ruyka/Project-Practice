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

typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define forin(i,a,b,n) for(int i(a),_b(b),_n(n);i<=_b;i+=n)
#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define fordn(i,a,b,n) for(int i(a),_b(b),_n(n);i>=_b;i-=n)
#define forn(i,n) fori(i,0,n-1)
#define fora(i,a) forn(i,sz(a))

void init();
pii calSaving(int*orderList);
vpii change;

int main() {
	init();
	int i;

	forn(i, 7)
	{
		cout << get<0>(change[i]) << endl;
	}

	return 0;
}

void init() {
	int seed = 1;
	int i;
	change.resize(7);

	change[0] = pii(seed, 0);

	forin(i,1,5,2)
	{
		change[i] = pii(seed * 5, 0);
		if(5-i!=1)
			change[i + 1] = pii(seed *= 10, 0);
	}
}