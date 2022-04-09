#include<bits/stdc++.h>
using namespace std;
int main()
{
	string input;
	while (cin >> input)
	{
		stack<char>stk;
		int res = 0;
		for (char c : input)
		{
			if (!isalpha(c))
			{
				cout << 0 << endl;
				return 0;
			}

			if (stk.empty() || stk.top() != c)
			{
				stk.push(c);
			}
			else if (stk.top() == c)
			{
				res+=2;
				stk.pop();
			}
		}

		cout << input.size()-res << endl;
	}
	return 0;
}