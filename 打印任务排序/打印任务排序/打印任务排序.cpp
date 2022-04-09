#include<bits/stdc++.h>
using namespace std;

void pre_input(string s, queue<int>& nums)
{
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != ',' && j < s.size())
		{
			j++;
			if (s[j] == ',')
			{
				string tmp = s.substr(i, j - i);
				nums.push(stoi(tmp));
				break;
			}
		}
		i = j;
	}
}

void solve(queue<int>nums)
{
	string res;
	int k = 0;
	while (!nums.empty())
	{
		int tmp = nums.front(); nums.pop();
		bool flag = false;
		vector<int>vec;
		while (!nums.empty())
		{
			vec.push_back(nums.front());
			nums.pop();
		}

		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] > tmp)
			{
				flag = true;
			}
		}

		if (flag)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				nums.push(vec[i]);
			}
			nums.push(tmp);
		}
		else
		{
			cout<<;
		}
		k++;
	}
}

int main()
{
	string input;
	while (cin >> input)
	{
		queue<int>nums;
		pre_input(input, nums);

		
	}
	return 0;
}