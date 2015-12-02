#include <stdio.h>
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
#define forn(i,n) fori(i,0,n-1)

int main() {
	char c[1000005];
	int n[1000005];
	int ca = 1, len, sc, x, y;
	while (gets(c)) {
		len = strlen(c);
		if (len == 0)
			break;
		printf("Case %d:\n", ca++);
		n[0] = c[0] == '1' ? 1 : 0;
		fori(i, 1, len - 1)
			n[i] = c[i] == '1' ? n[i - 1] + 1 : n[i - 1];
		scanf("%d", sc);
		while (sc--) {
			scanf("%d %d", x, y);
			if (x > y)
				swap(x, y);
			if (c[x] == '0' && c[y] == '0' && n[y] - n[x] == 0) printf("Yes\n");
			else if (c[x] == '1' && c[y] == '1' && n[y] - n[x] == y - x) printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;
}
