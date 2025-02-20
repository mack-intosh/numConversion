#include "binary.h"
#include <iostream>
#include <climits>
#include <iomanip>
#include <string>
using namespace std;

int bin2dec(string input2) {

	//input2[strcspn(input2, "\n")] = 0;

	int size = input2.length();

	int i = 0;
	int output = 0;

	char one[] = "1";
	for (i = 0;i < size;i++) {

		if (input2[i] == 49) {
			output = output + pow((double)2, (double)size - (i + 1));;

		}
	}
	
		//cout << "Decimal" << setfill('.') << setw(19) << output << endl;
	return output;
}

int bin2oct(string input2) { //think  00010110 as example
	
	int i = 0; int octput = 0;
	int size = input2.length();
	int size2 = (size / 3); 
	string ninput; 
	if (size % 3 != 0) {
		size2++;
		ninput.append((3-(size % 3)), '0');
	}
	ninput.append(input2);
	for (i = 0;i < size2;i++) {
		string substring = ninput.substr((i * 3), 3);
		string strg = quickConvert(substring);
		int num = std::stoi(strg);
		octput += (num * pow(10.0, (double)size2 - i - 1));
	}
	return octput;
}

string bin2hex(string input2) {
	int size = input2.length(); int size2 = size / 4;
	int i;
	string ninput; string hexput;
	if (size % 4 != 0) {
		size2++;
		ninput.append((4 - (size % 4)), '0');
	}
	ninput.append(input2);

	for (i = 0;i < size2;i++) {
		string substring = ninput.substr((i * 4), 4);
		string strg = quickConvert(substring);
		int num = std::stoi(strg);
		string newChar = to_string(num);
		if (num > 9) {
			switch (num) {
			case 10:
				newChar = 'A';
				break;
			case 11:
				newChar = 'B';
				break;
			case 12:
				newChar = 'C';
				break;
			case 13:
				newChar = 'D';
				break;
			case 14:
				newChar = 'E';
				break;
			case 15:
				newChar = 'F';
				break;
			default:
				cout << "that ain't right" << endl;

			}
		}
		hexput.append(newChar);
	}
	//cout << "Hexadecimal" << setfill('.') << setw(15) << hexput << endl;
	return hexput;
}

string quickConvert(string bloop) {
	int size = bloop.length();
	int i = 0;
	int output = 0;

	char one[] = "1";
	for (i = 0;i < size;i++) {

		if (bloop[i] == 49) {
			output = output + pow((double)2, (double)size - (i + 1));;

		}
	}
	string stri = to_string(output);
	return stri;
}