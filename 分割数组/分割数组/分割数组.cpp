#include<bits/stdc++.h>
using namespace std;
const int n=10;

void recur(vector<int>nums, vector<bool>visited, int depth,int&res)
{
	int tmp = 0,sum=0;
	if (depth == n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
			tmp += visited[i] ? nums[i] : 0;
		}
		res = (res == -1) ? (abs(sum - 2 * tmp)) : min(abs(sum - 2 * tmp), res);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			visited[i] = true;
			recur(nums, visited, depth + 1, res);
			visited[i] = false;
		}
	}
}
int main()
{
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	
	int res = -1;
	vector<bool>visited(n, false);
	recur(nums, visited, 0, res);

	cout << res << endl;
	return 0;
}