
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

	tcal.SetInfix();
	cout << tcal.GetPostfix() << endl;;
	cout << tcal.Calc() << endl;
	system("pause");
}
