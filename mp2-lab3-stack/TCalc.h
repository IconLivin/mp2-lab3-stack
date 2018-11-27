#pragma once
#include "TStack.h"
#include <string>
using namespace std;

class TCalc {
	string infix;
	TStack<char> stop;
	string postfix;
	TStack<double> stnum;
	int GetPriority(char m);
public:
	void ToPostFix();
	void SetInfix();
	string GetPostfix();
	double Calc();
};