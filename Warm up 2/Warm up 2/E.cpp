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
//int inputSize , length , i , j;
//string number;
//vector<string> result;
//vector<string> testIndex;
//
//int main()
//{
//	cin >> inputSize;
//	cin.ignore();
//	int t;
//	testIndex.resize(inputSize);
//	for (int x = 0; x < inputSize; ++x)
//	{
//		cin >> testIndex[x] >> number;
//		length = number.size();
//		for (i = length - 2; i >= 0; --i)
//			if (number[i] < number[i + 1])
//				break;
//		if (i == -1)
//			number = "BIGGEST";
//		else
//		{
//			for (j = length - 1; j > i; --j)
//				if (number[j] > number[i])
//					break;
//			swap(number[i], number[j]);
//			int swapLength = (length - i) / 2 + (length - i) % 2;
//			for (int k = 1; k < swapLength; ++k)
//				swap(number[i + k], number[length - k]);
//		}
//		for (int u = 0; u < length; ++u)
//			if (number[u] == '0')
//				continue;
//			else
//			{
//				if (u > 0)
//					number = number.substr(u);
//				break;
//			}
//		result.push_back(number);
//	}
//	for (int i = 0; i < inputSize; ++i)
//	{
//		cout << testIndex[i] << ' ' << result[i];
//		if (i != inputSize - 1)
//			cout << endl;
//	}
//	return 0;
//}