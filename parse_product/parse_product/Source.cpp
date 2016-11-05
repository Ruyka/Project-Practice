#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class scanner {
private:
	string input;
	int A, B;
public:
	scanner(string input) {
		this->input = input;
		A = B = 0;
	}

	bool hasNext() {
		int t1 = input.find("%", A), t2 = input.find("%", t1 + 1);
		if (t1 != string::npos && t2 != string::npos)
			return true;
		return false;
	}

	string getNext() {
		A = input.find("%", A) + 1;
		B = input.find("%", A);
		if (A != string::npos && B != string::npos) {
			string temp = input.substr(A, B - A);
			A = B + 1;
			return temp;
		}
		return "";
	}
};

class json_encoder {
public:
	static string encode_all(vector<string> input, string brand = "") {
		string result = "{\"product\":[";
		int size = input.size();
		if (brand != "") {
			for (int i = 0; i < size; i += 5) {
				if (input[i] == brand) {
					result += "{\"brand\":\"" + input[i]
						+ "\",\"name\":\"" + input[i + 1]
						+ "\",\"price\":\"" + input[i + 2]
						+ "\",\"description\":\"" + input[i + 3]
						+ "\",\"image\":\"" + input[i + 4]+"\"},";
						
				}
			}
		}
		else {

			for (int i = 0; i < size; i += 5) {
				result += "{\"brand\":\"" + input[i]
					+ "\",\"name\":\"" + input[i + 1]
					+ "\",\"price\":\"" + input[i + 2]
					+ "\",\"description\":\"" + input[i + 3]
					+ "\",\"image\":\"" + input[i + 4] + "\"},";
			}
		}
		result[result.length() - 1] = ']';
		result += "}";
		return result;
	}
};


int main() {
	ifstream file;
	string input;

	file.open("input.txt", ifstream::in);
	file.seekg(0, ios::end);
	input.reserve(file.tellg());
	file.seekg(0, ios::beg);

	input.assign((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());

	file.close();

	scanner scan(input);
	vector<string> rawData;

	while (scan.hasNext()) {
		rawData.push_back(scan.getNext());
	}

	ofstream out;
	
	out.open("NIKE", ofstream::out);
	out << json_encoder::encode_all(rawData, "NIKE");

	out.close();
	

	out.open("ADDIDAS", ofstream::out);
	out << json_encoder::encode_all(rawData, "ADDIDAS");

	out.close();
	

	out.open("PUMA", ofstream::out);
	out << json_encoder::encode_all(rawData, "PUMA");

	out.close();
	

	out.open("PRODUCT", ofstream::out);
	out << json_encoder::encode_all(rawData);
	out.close();

	return 0;
}