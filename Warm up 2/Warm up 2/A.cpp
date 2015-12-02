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
//typedef vector<vi> vii;
//
//string patterns[8] = { "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };
//vector<string> testIndex;
//vii result;
//
//int main() {
//	string input;
//	vi resultCase;
//	int n, A = 0, count = 0;
//
//	resultCase.resize(8);
//
//	cin >> n;
//	cin.get();
//	result.resize(n);
//	testIndex.resize(n);
//	for (int i = 0; i < n; i++) {
//		cin >> testIndex[i] >> input;
//
//		for (int j = 0; j < 8; j++) {
//			bool flag = true;
//			count = A = 0;
//			A = input.find(patterns[j], A);
//			while (A != string::npos) {
//				++count;
//				++A;
//				A = input.find(patterns[j], A);
//			}
//			resultCase[j] = count;
//		}
//
//		result[i] = resultCase;
//
//		input.clear();
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << testIndex[i] << ' ';
//		for (int j = 0; j < 8; j++)
//			cout << result[i][j] << ' ' ;
//		cout << endl;
//	}
//
//	return 0;
//}