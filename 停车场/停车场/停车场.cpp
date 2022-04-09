#include<bits/stdc++.h>
using namespace std;

void input_string(string s,vector<int>&nums)
{
	s = s + ',';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != ',' && j < s.size())
		{
			j++;
			if (s[j] == ',')
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(stoi(tmp));
			}
		}
		i = j;
	}
}
int solve(vector<int>nums)
{
	int res = 0;
	nums.push_back(0);

	for (int i = 0; i < nums.size(); i++)
	{
		int j = i;
		while (nums[j] != 0 && j < nums.size())
		{
			j++;
			if (nums[j] == 0)
			{
				int sum = (j - i >= 1 && j - i <= 3) ? 1 : ceil((j - i) / 3.0);
				res+=sum;
			}
		}
		i = j;
	}
	return res;
}
int main()
{
	string input;
	while (cin >> input)
	{
		vector<int>nums;
		input_string(input, nums);

		cout << solve(nums)<<endl;
	}
	return 0;
}