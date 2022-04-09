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
	string s;
	cin >> s;
	cin.ignore();

	vector<int>nums;
	pre_input(s, nums);

	int sum = 0;
	cin >> sum;

	/*for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
	}*/
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int tmp = 0;
		for (int j = i; j < nums.size(); j++)
		{
			tmp += nums[j];
			if (tmp == sum)
			{
				res = max(res, j - i+1);
			}
		}
	}
	cout << res << endl;

	return 0;
}