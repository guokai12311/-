#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		sort(s.begin(), s.end());
		int res = 0;

		do
		{
			res++;
		} while (next_permutation(s.begin(), s.end()));

		cout << res << endl;
	}
	return 0;
}