#include<bits/stdc++.h>
using namespace std;
int main()
{
	string input;
	cin >> input;
	stack<char>stk;
	for (char c : input)
	{
		if (c == '(')
		{
			stk.push(')');
		}
		else if (c == '[')
		{
			stk.push(']');
		}
		else if (c == '{')
		{
			stk.push('}');
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if (stk.empty())
			{
				cout << "false";
				return 0;
			}
			else if (stk.top() != c)
			{
				cout << "false";
				return 0;
			}
			else
			{
				stk.pop();
			}
		}
	}

	if (stk.empty())
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	return 0;
}