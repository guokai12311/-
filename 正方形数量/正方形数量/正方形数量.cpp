#include<bits/stdc++.h>
using namespace std;
struct  point
{
	int x;
	int y;
};
int solve(vector<point>nums)
{
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i+1; j < nums.size(); j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				for (int l = k + 1; l < nums.size(); l++)
				{
					int tmp1 = (nums[j].x - nums[i].x) * (nums[l].x - nums[i].x) +
						(nums[j].y - nums[i].y) * (nums[l].y - nums[i].y);
					int tmp2= (nums[j].x - nums[k].x) * (nums[l].x - nums[k].x) +
						(nums[j].y - nums[k].y) * (nums[l].y - nums[k].y);
					if (tmp1 == 0 && tmp2 == 0)
					{
						res++;
					}
				}
			}
		}
	}
	return res;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<point>nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i].x >> nums[i].y;
		}

		if (n < 4) cout << 0 << endl;
		cout << solve(nums) << endl;
	}
	return 0;
}