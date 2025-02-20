#include "octal.h"
#include "binary.h"
#include <iostream>
#include <climits>
#include <iomanip>
#include <string>
using namespace std;
string oct2bin(string octInput) {
	int size = octInput.length(); string cset; string output;
	for (int i = 0; i < size; i++) {
		switch (octInput[i]) {
		case '0':
			cset = "000";
			break;
		case '1':
			cset = "001";
			break;
		case '2':
			cset = "010";
			break;
		case '3':
			cset = "011";
			break;
		case '4':
			cset = "100";
			break;
		case '5':
			cset = "101";
			break;
		case '6':
			cset = "110";
			break;
		case '7':
			cset = "111";
			break;
		default:
			cout << "welp that wasnt an actual thing(octal.cpp o2b switch case)\n";
			break;
		}
		output.append(cset);
	}
		return output;
	}


int o2d(string octInput) {
	int output = 0; int size = octInput.length() - 1; //string oc = octInput;
	/*cout << "checking octInput: " << octInput << "length : " << size  << endl;*/
	for (int i = 0; i <= size; i++) {
		string c(1,octInput[i]);
	int x = std::stoi(c);
	output += x * pow(8.0, (double)size - i);
}
	return output;
}



string oct2hx(string octInput) {
	string o = oct2bin(octInput);
	string output = bin2hex(o);

	return output;
}