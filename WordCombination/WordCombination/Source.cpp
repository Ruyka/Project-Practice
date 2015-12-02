#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main() {
	//char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	ifstream file;
	string content, tokened;

	//open and reserve mem
	file.open("wordlist.txt");
	file.seekg(0, ios::end);
	content.reserve(file.tellg());
	file.seekg(0, ios::beg);

	//get all content
	content.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

	//close file
	file.close();

	int length = content.length(), A = 0, B = 0;
	while (A < length) {
		B = content.find('\n', A);
		if (B - A == 4)
			tokened += content.substr(A, 4) + '\n';
		A = B + 1;
	}

	ofstream out;
	out.open("outfile.txt");

	for (int i = 0; i < tokened.length(); i++)
		out << tokened[i];

	
}