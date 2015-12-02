#include<iostream>
#include<fstream>
using namespace std;
struct Hang
{
	char Ten[1000];
	double GiaTien;
	double GiaBan;
};
void InputData(Hang& a);
int main()
{
	Hang t[1000];
	int n,a;
	ifstream fin;
	ofstream fout;

	cout << "Chon hanh dong ban muon thuc hien : " << endl
		<< "1.Nhap du lieu." << endl
		<< "2.Xuat du lieu." << endl;
	cin >> n;
	while (n<1 || n>2)
	{
		cout << "Xin vui long nhap lai : ";
		cin >> n;
	}
	cout << "Xin vui long nhap so luong du lieu muon nhap : ";
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		InputData(t[i]);
	}
	fout.open("Gia Hang.text");
	if (fout.open != NULL)
	{
		for (int i = 0; i < a; ++i)
		{

		}
	}
}
void InputData(Hang& a)
{
	cout << "Vui long nhap ten hang : ";
	cin.ignore();
	cin.get(a.Ten, 1000, '\n');
	cout << "Vui long nhap gia tien cua hang : ";
	cin >> a.GiaTien;
	cout << "Vui long nhap gia ban cua hang : ";
	cin >> a.GiaBan;
}