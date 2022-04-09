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
		int k;
		cin >> k;

		sort(nums.begin(), nums.end());

		int res = 0;
		vector<bool>visited(nums.size(), false);

		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] >= k)
			{
				res++;
				visited[i] = true;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] >= k&&visited[j]==false&&visited[i]==false)
				{
					res++;
					visited[j] = true;
					visited[j] = true;
					break;
				}
			}
		}

		cout << res << endl;
	}
	return 0;
}