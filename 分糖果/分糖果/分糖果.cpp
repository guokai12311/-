#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0,xor_sum=0,min_num=INT_MAX;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
			sum += nums[i];
			xor_sum ^= nums[i];
			min_num = min(min_num, nums[i]);
		}

		if (xor_sum == 0)
		{
			cout << sum - min_num;
		}
		else
		{
			cout << "NO";
		}
	}
	return 0;
}