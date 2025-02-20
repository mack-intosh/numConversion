#pragma once
#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#include "binary.h"
#include <iostream>
#include <climits>
#include <iomanip>
#include <string>
using namespace std;

string hex2bin(string hexInput);
int hex2dec(string hexInput);
string hex2oct(string hexInput);
#endif
#pragma once
