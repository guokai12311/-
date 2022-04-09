#include<bits/stdc++.h>
using namespace std;
int main()
{
	string input;
	while (cin >> input)
	{
		int cur_len = 0, max_len = 0;
		char last = 'a';

		for (char c : input)
		{
			if (isdigit(c))
			{
				if (cur_len == 0)
				{
					cur_len++;
				}
				else if(c>=last)
				{
					cur_len++;
				}
				else
				{
					max_len = max(max_len, cur_len);
					cur_len = 1;
				}
				last = c;
			}
			else
			{
				max_len = max(max_len, cur_len);
				cur_len = 0;
				last = 'a';
			}
		}
		max_len = max(max_len, cur_len);
		cout << max_len << endl;
	}
	return 0;
}