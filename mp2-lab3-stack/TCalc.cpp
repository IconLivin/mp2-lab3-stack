#include "TCalc.h"
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int TCalc::GetPriority(char m) {
	switch (m)
	{
	case '(':return 0;
	case '+':return 1;
	case '-':return 1;
	case '*':return 2;
	case '/':return 2;
	case '^':return 3;
	}
	throw -1;
}

void TCalc::ToPostFix() {
	postfix = "";
	stop.clear();
	string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '(') stop.Push(tmp[i]);
		if (tmp[i] >= '0'&&tmp[i] <= '9') postfix += tmp[i];
		if (tmp[i] == ')') {
			while (stop.Top() != '(')postfix += stop.Pop();
			stop.Pop();
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^')
		{
			postfix += ' ';
			while (GetPriority(tmp[i]) <= GetPriority(stop.Top()))postfix += stop.Pop();
			stop.Push(tmp[i]);
		}
		if (tmp[i] == 's' || tmp[i] == 'c' || tmp[i] == 't')
		{
			if (i == tmp.find("sin") || i == tmp.find("cos") || i == tmp.find("tg"))
			{
				stop.Push(tmp[i]);
				if (tmp[i] == 's' || tmp[i] == 'c')
					i += 2;
				else
					i++;
			}
			else
				throw "Error symbol";
		}
	}
}

void TCalc::SetInfix(string inf) {
	infix = inf;
}

string TCalc::GetPostfix() {
	this->ToPostFix();
	return postfix;
}

bool TCalc::CheckBrackets()
{
	TStack <char> bracket(infix.length());
	if (infix == "")
		throw 'a';
	else
	{
		for (int i = 0; i < infix.length(); i++)
			if (infix[i] == '(')
				bracket.Push(infix[i]);
			else if (infix[i] == ')')
			{
				if (bracket.IsEmpty())
					return false;
				else
					bracket.Pop();
			}
		if (bracket.IsEmpty())
			return true;
		else
			return false;
	}
}

double TCalc::Calc() {
	double num1, num2, res;
	stnum.clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			num2 = stnum.Pop();
			num1 = stnum.Pop();
			switch (postfix[i])
			{
			case '+':res = num1 + num2;
				break;
			case '-':res = num1 - num2;
				break;
			case '*':res = num1 * num2;
				break;
			case '/':res = num1 / num2;
				break;
			case '^':res = pow(num1, num2);
				break;
			}
			stnum.Push(res);
		}
		if (postfix[i] >= '0'&&postfix[i] <= '9') {
			char *p;
			double x;
			x = strtod(&postfix[i], &p);
			stnum.Push(x);
			int l = p - &postfix[i];
			i += l - 1;
		}
		if (postfix[i] == 's' || postfix[i] == 'c' || postfix[i] == 't')
		{
			switch (postfix[i])
			{
			case 's':
				res = sin(stnum.Pop()*M_PI / 180);
				stnum.Push(res);
				break;
			case 'c':
				res = cos(stnum.Pop()*M_PI / 180);
				stnum.Push(res);
				break;
			case 't':
				res = tan(stnum.Pop()*M_PI / 180);
				stnum.Push(res);
				break;
			}
		}
	}
	TStack<double> tmp(stnum);
	tmp.Pop();
	if (tmp.IsEmpty())
		return stnum.Top();
	else
		throw - 1;
}