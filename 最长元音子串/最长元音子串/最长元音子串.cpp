#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;

	string yuanyin = "aeiouAEIOU";

	int cnt = 0, res = 0;

	for (char c : s)
	{
		if (find(yuanyin.begin(), yuanyin.end(), c) != yuanyin.end())
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
		res = max(res, cnt);
	}
	cout << res << endl;
	
	return 0;
}