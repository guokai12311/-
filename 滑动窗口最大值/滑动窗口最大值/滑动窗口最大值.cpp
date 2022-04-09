#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		int m;
		cin >> m;

		int l = 0;
		int res = INT_MIN;
		int cnt = 0;
		for (int r = 0; r < nums.size(); r++)
		{
			cnt += nums[r];

			if (r - l + 1 == m)
			{
				res = max(res, cnt);
				cnt -= nums[l++];
			}
		}

		cout << res << endl;
	}
	return 0;
}