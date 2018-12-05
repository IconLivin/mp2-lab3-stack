#pragma once
#include "TStack.h"
#include <string>
#include <math.h>
#define _USE_MATH_DEFINES

class TCalc {
	std::string infix;
	TStack<char> stop;
	std::string postfix;
	TStack<double> stnum;
	int GetPriority(char m);
public:
	void ToPostFix();
	void SetInfix(std::string inf);
	std::string GetPostfix();
	double Calc();
	bool CheckBrackets();
};