//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <utility>
//using namespace std;
//
//#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
//#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
//#define forn(i,n) fori(i,0,n-1)
//#define fora(i,a) forn(i,sz(a))
//
//int main() {
//	string input;
//	getline(cin, input);
//	vector<int> automaton, check;
//
//	int len = input.size();
//	automaton.resize(len);
//	check.resize(len);
//	check[0] = 0;
//	forn(i, len - 1)
//		check[i + 1] = input[i] == input[i + 1] ? check[i] : check[i] + 1;
//
//	automaton[0] = 0;
//	int front, back, seed = -1;
//
//	//forn(i, len - 1) {
//	//	if (seed == -1 && input[i] == input[0])
//	//		seed = i;
//	//	else if(input[i] != input[i + 1])
//	//	if (check[i] == check[i + 1])
//	//		if (input[i] == input[0]) {
//	//			front = 0; back = i;
//	//			while (front < len - 1 && input[front] == input[front + 1])
//	//				++front;
//	//			while (back > 0 && input[back] == input[back - 1])
//	//				--back;
//	//			back = i - back;
//	//			automaton[i + 1] = back >= front ? i - front - 1: i + 1;
//	//		}
//	//		else
//	//			automaton[i + 1] = i;
//	//	else
//	//		if (check[i] == check[0])
//	//			automaton[i + 1] = 0;
//	//		else if (input[i] != input[0])
//	//			automaton[i + 1] = i + 1;
//	//		else {
//	//			front = 0; back = i;
//	//			while (input[front] == input[front + 1])
//	//				++front;
//	//			while (input[back] == input[back - 1])
//	//				--back;
//	//			back = i - back + 1;
//	//			automaton[i + 1] = back >= front ? i - front : i - back;
//	//		}
//	//}
//
//	forn(i, len - 1) {
//
//	}
//
//	/*for (int i = 0; i < len; i++) {
//		cout << "STATE_" << i;
//		if (input[i] == '1')
//			cout << " IF 0 THEN";
//		else
//			cout << " IF 1 THEN";
//		cout << " STATE_" << i - automaton[i] << endl << endl;
//		cout << input[i] << endl << endl;
//	}
//	cout << "FINAL" << endl;*/
//	for (int i = 0; i < len; i++) {
//		cout << "Node " << i << ": ";
//		if (input[i] == '1')
//			cout << i + 1 << ", " << i - automaton[i] << endl;
//		else
//			cout << i - automaton[i] << ", " << i + 1 << endl;
//	}
//	return 0;
//}