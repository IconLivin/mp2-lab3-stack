
#include <iostream>
#include "TStack.h"
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
	TStack<int> k(3);
	k.Push(1);
	k.Push(2);
	k.Push(3);
	cout << k.Top() << endl;
	k.Pop();
	cout << k.Top() << endl;
	k.Pop();
	cout << k.Top() << endl;
	system("pause");
}
