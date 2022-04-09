#include<bits/stdc++.h>
using namespace std;

string solve(string s)
{
	string res;
	for (int i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]) && !isalpha(s[i])) return "!error";

		int j = i;
		while (isdigit(s[j]) && j < s.size())
		{
			j++;
			if (!isdigit(s[j]))
			{
				int cnt = stoi(s.substr(i, j - i));
				if (cnt <= 2) return "!error";

				for (int i = 0; i < cnt-1; i++)
				{
					res += s[j];
				}
			}
		}
		i = j;
		res += s[i];
	}
	return res;
}
int main()
{
	string input;
	while (cin >> input)
	{
		cout << solve(input) << endl;
	}
	return 0;
}