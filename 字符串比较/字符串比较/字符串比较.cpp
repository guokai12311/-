#include<bits/stdc++.h>
using namespace std;
int solve(string a, string b,int v)
{
	int sum = 0;
	int max_len = 0;
	//int cur_len = 0;
	int left = 0;
	for (int right = 0; right < a.size(); right++)
	{
		sum += abs(a[right] - b[right]);
		
		while (sum > v && left < right)
		{
			sum -= abs(a[left] - b[left]);
			left++;
		}

		max_len = max(max_len, right - left+1);
	}

	return max_len;
}
int main()
{
	string a;
	while (cin >> a)
	{
		string b;
		cin >> b;
		int v;
		cin >> v;

		cout << solve(a, b, v) << endl;
	}
	return 0;
}