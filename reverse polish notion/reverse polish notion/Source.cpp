#include<iostream>
#include<string>
using namespace std;

void pushBack(string &Out, string &Op, int &ocur, int &opcur){
	for (; opcur >= 0 && Op[opcur] != '('; opcur--)
		Out[ocur++] = Op[ocur];
	opcur++;
}

int main(){
	/* Your code goes here */
	string input, operand, output;
	int n, opcur = 0, ocur = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, input);
		int len = input.length();
		for (int j = 0; j < len; j++){
			if (input[j] == '+' || input[j] == '-'){
				if (opcur == 0 || (opcur > 0 && operand[opcur - 1] == '('))
					operand[opcur++] = input[j];
				else
					pushBack(output, operand, ocur, opcur);
			}
			else if (input[j] == ')')
				opcur--;
			else if (input[j] == '*' || input[j] == '/' || input[j] == '(')
				operand[opcur++] = input[j];
			else
				output[ocur++] = input[j];
			for (int j = 0; j < len; j++){
				cout << output[j];
			}
			cout << endl;
			input.clear();
			operand.clear();
			output.clear();
		}
	}
	return 0;
}