#include<bits/stdc++.h>
using namespace std;
void pre_input(string s, vector<string>& nums)
{
	s = s + "},";
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (j < s.size() && s.substr(j,2) != "},")
		{
			j++;
			if (s[j] == '}')
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(tmp);
				j++;
				break;
			}
		}
		i = j;
	}
}
void pre_input2(string s, vector<int>& nums)
{
	s = s + ',';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (j < s.size() && s[j] !=',')
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
	while (getline(cin, input))
	{
		vector<string>nums;
		pre_input(input, nums);

		vector<int>numsa, numsb;
		pre_input2(nums[0].substr(nums[0].find('{') + 1), numsa);
		pre_input2(nums[1].substr(nums[1].find('{') + 1), numsb);

		int r = stoi(input.substr(input.find_last_of('=') + 1));

		//for (int i : numsa) cout << i << " ";
		//for (int i : numsb) cout << i << " ";

		bool flag = true;
		for (int i : numsa)
		{
			for (int j : numsb)
			{
				if (i > j) continue;

				if (j - i <= r)
				{
					cout << '(' << i << ',' << j << ')';
					flag = false;
					continue;
				}

				if (flag)
				{
					cout << '(' << i << ',' << j << ')';
				}
				break;
			}
		}
	}
	return 0;
}