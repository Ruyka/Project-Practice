#include<iostream>
using namespace std;
struct Point{
	int r, c;
};

void sortPoint(Point *&p,int n){
	for (int i = 0; i < n; ++i){
		for (int j = i; j < n; ++j){
			if (p[i].c > p[j].c){
				Point temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
			if (p[i].c == p[j].c && p[i].r > p[j].r){
				Point temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

int countSquare(Point *p, int n){
	int count = 0;
	for (int i = 0; i < n - 1; ++i){
		if (p[i].c != p[i + 1].c)
			continue;
		int lenght = 0;
		for (int j = i + 1; j < n && p[i].c ==p[j].c ; ++j){
			lenght = abs(p[i].r - p[j].r);
			for (int k = j; k < n; ++k){
				if (p[i].c == p[k].c || p[i].r != p[k].r)
					continue;
				for (int e = k; e < n && p[i].r == p[e].r; ++e){
					if (lenght != abs(p[i].c - p[j].c))
						continue;
					for (int f = e; f < n; ++f){
						if (p[j].r == p[f].r && p[e].c == p[f].c){
							++count;
							break;
						}
					}
				}
			}
			
		}
	}
	return count;
}

int main(){
	int n;
	Point *p;
	cin >> n;
	p = new Point[n];
	for (int i = 0; i < n; ++i)
		cin >> p[i].c >> p[i].r;

	sortPoint(p, n);
	for (int i = 0; i < n; ++i)
		cout << "(" << p[i].c << "," << p[i].r << ")\n";
	
	cout << "There are : " << countSquare(p, n) << " square(s) in the plane.\n";

	delete[]p;
	return 0;
}