#include<bits/stdc++.h>
using namespace std;
void pre_input(string s, vector<int>& nums)
{
	s = s + ',';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (j < s.size() && s[j] != ',')
		{
			j++;
			if (s[j] == ',')
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(stoi(tmp));
				break;
			}
		}
		i = j;
	}
}
int max_expence(vector<int>& nums, int r)
{
	int len = nums.size();
	if (len < 3) return -1;

	vector<int>res;
	int left, right;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < len - 2; i++)
	{
		left = i + 1;
		right = len-1;
		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] <= r)
			{
				res.push_back(nums[i] + nums[left] + nums[right]);
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	sort(res.begin(), res.end());
	return res.empty() ? -1 : res.back();
}
int main()
{
	string input;
	while (cin >> input)
	{
		vector<int>nums;
		pre_input(input, nums);

		int r;
		cin >> r;

		cout << max_expence(nums, r)<<endl;
	}
	return 0;
}