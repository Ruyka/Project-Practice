//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//void displayPathtoPrincess(int n, vector <string> grid) {
//	int bxpos, bypos, pcorner;
//	if (bxpos = grid[bypos = n / 2 - 1].find('m'), bxpos != string::npos);
//	else { bxpos = grid[bypos = n / 2].find('m'); }
//
//	if (grid[0][0] == 'p') {
//		while (bypos-- > 0)
//			cout << "UP\n";
//		while (bxpos-- > 0) 
//			cout << "LEFT\n";
//	}
//	else if (grid[0][n - 1] == 'p') {
//		while (bypos-- > 0)
//			cout << "UP\n";
//		while (bxpos++ < n - 1)
//			cout << "RIGHT\n";
//	}
//	else if (grid[n - 1][0] == 'p') {
//		while (bypos++ < n - 1)
//			cout << "DOWN\n";
//		while (bxpos-- > 0)
//			cout << "LEFT\n";
//	}
//	else {
//		while (bypos++ < n - 1)
//			cout << "DOWN\n";
//		while (bxpos++ < n - 1)
//			cout << "RIGHT\n";
//	}
//}
//int main(void) {
//
//	int m;
//	vector <string> grid;
//
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		string s; cin >> s;
//		grid.push_back(s);
//	}
//
//	displayPathtoPrincess(m, grid);
//
//	return 0;
//}
