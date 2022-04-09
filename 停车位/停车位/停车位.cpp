#include<bits/stdc++.h>
using namespace std;
void input_string(string s, vector<int>&nums)
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
	nums.push_back(1);

	for (int i = 0; i < nums.size(); i++)
	{
		int j = i;
		while (nums[j] == 0 && j < nums.size()-1)
		{
			j++;
			if (nums[j] != 0)
			{
				res = max(res, j - i);
			}
		}
		i = j;
	}

	if (res % 2 == 0)
	{
		return res / 2;
	}
	else
	{
		return res / 2 + 1;
	}
}
int main()
{
	string input;
	while (cin >> input)
	{
		vector<int>nums;

		input_string(input,nums);

		/*for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << endl;
		}*/
		cout << solve(nums) << endl;
	}
	return 0;
}