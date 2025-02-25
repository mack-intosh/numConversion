//created by mack-intosh
//nine files total

//Header files
#include "binary.h"
#include "decimal.h"
#include "octal.h"
#include "hexadecimal.h"
//C++ libraries
#include <iostream>
#include <climits>
#include <iomanip>


using namespace std;

//main function
int main() {
	int choice = 1;
	bool running = true;
	while (running == true) {
		printf("Choose your type of input\n");
		printf("1 - Binary\n2 - Decimal\n3 - Octal\n4 - Hexadecimal\n0 - Exit\n");
		printf("Enter: ");

		cin >> choice;
		//checking if cin was a char
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			choice = 100; //to have it go to default
		}
		//int and string inputs(since i compute stuff different ways)
		int input; string input2;

		//these vars are just to store outputs, whether they be ints or strings for each set of funcs.
		string s1,s2,s3; int i1,i2;

		//vars to help error checking for each of the inputs
		bool err = false; int i = 0;
		switch (choice) {
		case 1:
			b:
			cout << "Enter your BINARY number: ";
			cin >> input2;
			/********************Error Checkinng*****************************/
			err = false; i = 0;
			while(err == false && i < input2.length()) {
				if ((input2[i] != '0') && input2[i] != '1') {
					err = true;
					cout << "0s and 1s only :)\n";
					goto b; //yes i use gotos, i like them(in moderation and not too far apart from each other)
				}
				i++;
			}
			/****************************************************************/
			cout << "***********************************************" << endl;
			i1 = bin2dec(input2);
			i2 = bin2oct(input2);
			s3 = bin2hex(input2);
			cout << "Decimal" << setfill('.') << setw(19) << i1 << endl;
			cout << "Octal" << setfill('.') << setw(21) << i2 << endl;
			cout << "Hexadecimal" << setfill('.') << setw(15) << s3 << endl;
			cout << "***********************************************" << endl;
			break;
		case 2:
			d:
			cout << "Enter your DECIMAL number: ";
			cin >> input;
			/********************Error Checkinng*****************************/
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				goto d;
			}
			/****************************************************************/
			cout << "***********************************************" << endl;
			s1 = dec2bin(input);
			s2 = dec2oct(input);
			s3 = dec2hx(input);
			cout << "Binary" << setfill('.') << setw(19) << s1 << endl;
			cout << "Octal" << setfill('.') << setw(21) << s2 << endl;
			cout << "Hexadecimal" << setfill('.') << setw(15) << s3 << endl;
			cout << "***********************************************" << endl;
			break;
		case 3:
		o:
			cout << "Enter your OCTAL number: ";
			cin >> input2;
			/********************Error Checkinng*****************************/
			err = false; i = 0;
			while (err == false && i < input2.length()) {
				if (input2[i] == '8' || input2[i] == '9') {
					err = true;
					cout << "Octal contains the digits \"01234567\" only :)\n";
					goto o; 
				}
				i++;
			}
			/****************************************************************/
			
			cout << "***********************************************" << endl;
			s1 = oct2bin(input2);
			i2 = o2d(input2);
			s3 = oct2hx(input2);
			cout << "Binary" << setfill('.') << setw(19) << s1 << endl;
			cout << "Decimal" << setfill('.') << setw(21) << i2 << endl;
			cout << "Hexadecimal" << setfill('.') << setw(15) << s3 << endl;
			cout << "***********************************************" << endl;
			break;
		case 4:
		h:
			/********************Error Checkinng*****************************/
			err = false; i = 0;
			while (err == false && i < input2.length()) {
				if (input2[i] != '0' || input2[i] != '1' || input2[i] != '2' || input2[i] != '3' || input2[i] != '4' || input2[i] != '5' || input2[i] != '6' || 
					input2[i] != '7' || input2[i] != '8' || input2[i] != '9' || input2[i] != 'A' || input2[i] != 'B' || input2[i] != 'C' || input2[i] != 'D' || 
					input2[i] != 'E' || input2[i] != 'F' ) {
					err = true;
					cout << "Hex contains the digits \"0123456789ABCDEF\" only :)\n";
					goto h;
				}
				i++;
			}
			/****************************************************************/
			cout << "Enter your HEXIDECIMAL number: ";
			cin >> input2;
			cout << "***********************************************" << endl;
			s1 = hex2bin(input2);
			i2 = hex2dec(input2);
			s3 = hex2oct(input2);
			cout << "Binary" << setfill('.') << setw(19) << s1 << endl;
			cout << "Decimal" << setfill('.') << setw(21) << i2 << endl;
			cout << "Octal" << setfill('.') << setw(15) << s3 << endl;
			cout << "***********************************************" << endl;
			break;
		case 0:
			running = false;
			printf("Exiting program\n");
			break;
		
		default:
			printf("\n\n\nthat wasnt an option. try again. \n\n\n\n");
			break;



		}


	}
	return 0;
}
