#include<bits/stdc++.h>
using namespace std;
void pre_input(string s, vector<string>& nums)
{
	s = s + '#';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != '#' && j < s.size())
		{
			j++;
			if (s[j] == '#')
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(tmp);
				break;
			}
		}
		i = j;
	}
}
bool isvalid(vector<string>nums)
{
	if (nums.size() != 4) return false;

	int tmp = stoi(nums[0]);

	if (tmp < 1 || tmp>128) return false;

	for (int i = 1; i < nums.size(); i++)
	{
		if (stoi(nums[i]) < 0 || stoi(nums[i]) > 255)
		{
			return false;
		}
	}

	return true;
}

int solve(vector<string>nums)
{
	int res = 0;
	res += stoi(nums[0]) << 24;
	res += stoi(nums[1]) << 16;
	res += stoi(nums[2]) << 8;
	res += stoi(nums[3]);
	return res;
}
int main()
{
	string input;
	while (cin >> input)
	{
		vector<string>nums;
		pre_input(input,nums);

		if (isvalid(nums))
		{
			cout << solve(nums) << endl;
		}
		else
		{
			cout << "invalid IP" << endl;
		}
	}
	return 0;
}