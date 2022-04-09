#include<bits/stdc++.h>
using namespace std;
int depth = 0;
bool valid_max_depth(string s)
{
	stack<char>stk;

	for (char c : s)
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
				return false;
			}
			else if (stk.top() == c)
			{
				depth = max(depth, (int)stk.size());
				stk.pop();
			}
			else if (stk.top()!=c)
			{
				return false;
			}
		}
	}

	return stk.empty();
}
int main()
{
	string s;
	while (cin >> s)
	{
		if (valid_max_depth(s))
		{
			cout << depth << endl;
		}
		else
		{
			cout << 0 << endl;
		}

	}
	return 0;
}