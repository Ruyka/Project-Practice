#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string default_insert = "INSERT ";
string default_value = "VALUES (";
string table = "";

// generate script
void generateScript(int dataNum, int* type);
// user defined function
void special(string& input, int& cur);

void main(){

	int dataNum;
	cout << "Num : ";
	cin >> dataNum;

	/*
	1 int
	2 string
	3 date
	*/
	int* type = new int[dataNum * 2] {};
	for (int i = 0; i < dataNum; i++){
		cout << i + 1 << "Type : ";
		cin >> type[i*2];
		if (type[i * 2] == 2){
			cout << i + 1 << "Special : ";
			cin >> type[i * 2 + 1];
		}
	}

	generateScript(dataNum, type);
	delete[]type;
}

void special(string& input, int& cur){
	// cur: current pointer position on the input string
	// input: current processed input string
	// ex:
	// raw: ABCS ASDF
	// current processed might be: "ABCS", |A|SDF
	// |A| is the current pointer position

	// Your code here
	input.insert(input.begin() + cur, '\'');
	if (input.find_first_of("0123456789", cur + 6) != -1){
		cur = input.find_first_of("0123456789", cur + 6);
		input.insert(input.begin() + cur - 1, '\'');
		input.insert(input.begin() + cur, ',');
		cur += 3;
	}
	else{
		cur = input.find("NULL", cur);
		input.insert(input.begin() + cur - 1, '\'');
		input.insert(input.begin() + cur, ',');
		cur += 3;
	}

}

void strProcess(string& input, int dataNum, int* type){
	int cur = 0;
	for (int i = 0; i < dataNum - 1; i++){
		switch (type[i * 2]){
		case 1:
			input.insert(input.begin() + input.find(' ', cur), ',');
			cur = input.find(' ', cur) + 1;
			break;
		case 2:
			if (type[i * 2 + 1]){
				special(input, cur);
			}
			else{
				input.insert(input.begin() + cur, '\'');
				cur = input.find(' ', cur);
				input.insert(input.begin() + cur, '\'');
				input.insert(input.begin() + cur + 1, ',');
				cur += 3;
			}
			break;
		case 3:
			input.insert(input.begin() + cur, '\'');
			cur = input.find(' ', cur);
			input.insert(input.begin() + cur, '\'');
			input.insert(input.begin() + cur + 1, ',');
			cur += 3;
			break;
		}
	}

	if (type[(dataNum - 1) * 2] > 1){
		input.insert(input.begin() + cur, '\'');
		input += "\')";
	}
	else
		input += ")";

}

void generateCmt(string& cmt, string input, string typeName, int dataNum, int* type){
	cmt = "/*\nValues : \n";
	int typeCur = 0, valueCur = 0;
	for (int i = 0; i < dataNum - 1; i++){
		cmt += "- " + typeName.substr(typeCur, typeName.find(' ', typeCur) - typeCur) + " : ";
		typeCur = typeName.find(' ', typeCur) + 1;

		if (type[i * 2] > 1){
			cmt += input.substr(valueCur + 1, input.find('\'', valueCur + 1) - valueCur - 1) + "\n";
			valueCur = input.find('\'', valueCur + 1) + 3;
		}
		else{
			cmt += input.substr(valueCur, input.find(',', valueCur) - valueCur) + "\n";
			valueCur = input.find(',', valueCur) + 2;
		}
	}
	cmt += "- " + typeName.substr(typeCur, typeName.length() - typeCur) + " : ";

	if (type[(dataNum - 1)*2] > 1)
		cmt += input.substr(valueCur + 1, input.find('\'', valueCur + 1) - valueCur - 1) + "\n";
	else
		cmt += input.substr(valueCur, input.find(')', valueCur) - valueCur) + "\n";

	cmt += "*/\n";
}

void generateScript(int dataNum, int* type){
	ifstream in("input.txt");
	if (in.is_open()){
		ofstream out("output.sql");
		string input, typeName, cmt;
		getline(in, table);
		out << "-- Insert into table " + table + "\n";
		out << default_insert + table + '\n';
		getline(in, typeName);
		while (!in.eof()){
			getline(in, input);
			strProcess(input, dataNum, type);
			generateCmt(cmt, input, typeName, dataNum, type);
			out << cmt << default_value << input << ",\n\n";
			input.clear();
		}
		out.close();
		in.close();
	}
	else{
		cout << "ERROR: FILE NOT FOUND!";
	}
}