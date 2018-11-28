
#include <iostream>
#include "TStack.h"
#include "TCalc.h"
using namespace std;

bool Check(string str)
{
	TStack <char> st(10);

	for (int i = 0; i < str.length(); i++)
		if (str[i] == '(')
			st.Push(str[i]);
		else if (str[i] == ')')
		{
			if (st.IsEmpty())
				return false;
			else
				st.Pop();
		}
	if (st.IsEmpty())
		return true;
	else
		return false;
}

void main()
{
	TCalc tcal;
	string exp = "2+2*2-4/2";
	tcal.SetInfix(exp);
	cout << tcal.GetPostfix() << endl;;
	cout << tcal.Calc() << endl;
	system("pause");
}
