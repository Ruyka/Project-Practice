//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//int main() {
//	int t, R, C, r, c;
//	vector<string> input, search;
//	bool flag;
//	cin >> t;
//	while (t--) {
//		cin >> R >> C;
//		cin.get();
//		input.resize(R);
//		for (int i = 0; i < R; i++)
//			getline(cin, input[i]);
//
//		cin >> r >> c;
//		cin.get();
//		search.resize(r);
//		for (int i = 0; i < r; i++)
//			getline(cin, search[i]);
//		
//		int maxR = R - r, maxC = C - c;
//		flag = false;
//		for (int i = 0; i <= maxR && !flag; i++) {
//			for (int j = 0; j <= maxC && !flag; j++)
//				if (input[i][j] == search[0][0]) {
//					flag = true;
//					for (int k = 0; k < r && flag; k++)
//						for (int t = 0; t < c; t++)
//							if (input[i + k][j + t] != search[k][t]) {
//								flag = false;
//								break;
//							}
//				}
//		}
//		if (flag)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
//}
