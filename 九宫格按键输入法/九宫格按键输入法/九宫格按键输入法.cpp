#include<bits/stdc++.h>
using namespace std;

string solve(string input)
{
	
	vector<string> hashTable = { ",.", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	bool isdigit = true;

	string res;
	int i = 0;
	while (i < input.size())
	{
		if (input[i] == '#')
		{
			isdigit = false;
		}
		else if (input[i] != '/' && isdigit)
		{
			res.push_back(input[i]);
		}
		else if (input[i] == '0')
		{
			res.push_back(' ');
		}
		else
		{
			int cnt = 0;
			while (i < input.size() - 1&&input[i] == input[i + 1])
			{
				i++;
				cnt++;
			}

			if (input[i] != '/')
			{
				res.push_back(hashTable[input[i] - '1'][cnt % (hashTable[input[i] - '1'].size())]);
			}
		}
		i++;
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