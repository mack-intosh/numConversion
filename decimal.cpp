#include "decimal.h"
#include "binary.h"
#include <iostream>
#include <climits>
#include <iomanip>
#include <string>
using namespace std;

string dec2bin(int decInput) {
    string binary; bool pwr =false; int x = 0; int pw;
    
    while (pwr == false) {
        if (decInput < pow(2.0, double(x))) {
            pw = x;
            pwr = true;
        } else {
            x++;
        }
    }
    while (decInput >= 0) {
        if (decInput >= 0) {
            int i = pw;
            
            for (i = (pw-1);i >= 0;i--) {
                int x = pow((double)2, (double)i);
                if ((decInput - x) >= 0) {
                    binary[(pw-1) - i] = '1';
                    decInput -= x;
                }
                else {
                    binary[(pw-1) - i] = '0';
                }
                
            }

            break;
        }
        
    }
    return binary;
}


int dec2oct(int decInput) {
    
    
    int i = 0; int output = 0;
    
    int remainder; int quotient = 1;
    while(quotient != 0) {
        remainder = decInput % 8;
        quotient = decInput / 8;
        decInput = quotient;
        output += remainder * pow((double)10, (double)i);
        i++;
    }
    //std::cout << "Octal" << setfill('.') << setw(41) << output << endl;
    return output;
}

string dec2hx(int decInput) {
    string output;
    string newChar;
    int remainder; int quotient = 1;
    while (quotient != 0) {
        remainder = decInput % 16;
        quotient = decInput / 16;
        decInput = quotient;
        newChar = to_string(remainder);
        
        if (remainder > 9) {
            switch (remainder) {
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
                std::cout << "that ain't right" << endl;

            }
        }
            output.insert(0,newChar);
        
    }
    return output;

}