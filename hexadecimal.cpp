#include "hexadecimal.h"
#include "binary.h"
#include <iostream>
#include <climits>
#include <iomanip>
#include <string>
using namespace std;

string hex2bin(string hexInput) {
	int size = hexInput.length(); string cset; string output;
	for (int i = 0; i < size; i++) {
		switch (hexInput[i]) {
		case '0':
			cset = "0000";
			break;
		case '1':
			cset = "0001";
			break;
		case '2':
			cset = "0010";
			break;
		case '3':
			cset = "0011";
			break;
		case '4':
			cset = "0100";
			break;
		case '5':
			cset = "0101";
			break;
		case '6':
			cset = "0110";
			break;
		case '7':
			cset = "0111";
			break;
		case '8':
			cset = "1000";
			break;
		case '9':
			cset = "1001";
			break;
		case 'A':
			cset = "1010";
			break;
		case 'B':
			cset = "1011";
			break;
		case 'C':
			cset = "1100";
			break;
		case 'D':
			cset = "1101";
			break;
		case 'E':
			cset = "1110";
			break;
		case 'F':
			cset = "1111";
			break;
		default:
			cout << "Error in h2b switch" << endl;
			break;
		}
		output.append(cset);
	}
	return output;
}

int hex2dec(string hexInput) {
	int output = 0; int size = hexInput.length() - 1; int x;//string oc = octInput;
	//cout << "checking octInput: " << hexInput << "length : " << size << endl;
	for (int i = 0; i <= size; i++) {
		string c(1, hexInput[i]);
		if ((c == "A") || c == "B" || c == "C" || c == "D" || c == "E" || c == "F") {
			switch (hexInput[i]) {
			case 'A':
				x = 10;
				break;
			case 'B':
				x = 11;
				break;
			case 'C':
				x = 12;
				break;
			case 'D':
				x = 13;
				break;
			case 'E':
				x = 14;
				break;
			case 'F':
				x = 15;
				break;
			default:
				std::cout << "that ain't right" << endl;

			}
		} else {
			 x = std::stoi(c);
		}
		
		output += x * pow(16.0, (double)size - i);
	}
	return output;
}

string hex2oct(string hexInput) {
	string h = hex2bin(hexInput);
	string output = to_string(bin2oct(h));

	return output;
}