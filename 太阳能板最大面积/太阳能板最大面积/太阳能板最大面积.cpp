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
int main()
{
	string input;
	while (cin >> input)
	{
		vector<int>nums;
		pre_input(input, nums);

		int res = 0;
		int len = nums.size();
		for (int i = 0; i < nums.size()-1; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				res = max(res, min(nums[i], nums[j]) * (j - i));
			}
		}

		cout << res << endl;
	}
	return 0;
}