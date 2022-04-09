#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>intersection(vector<pair<int,int>>nums)
{
	vector<pair<int,int>>res;
	if (nums.empty()) return res;
	int left = nums[0].first;
	int right = nums[0].second;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i].first < right)
		{
			left = max(nums[i].first, left);
			right = min(nums[i].second, right);
			res.push_back(make_pair(left, right));
		}
		else
		{
			left = nums[i].first;
			right = nums[i].second;
		}
	}

	return res;

}

void solve(vector<pair<int, int>>nums)
{
	sort(nums.begin(), nums.end(), [](pair<int, int>a, pair<int, int>b)
		{
			return a.first < b.first;
		});

	vector<pair<int, int>>res;
	res.push_back(nums[0]);

	for (int i = 1; i < nums.size(); i++)
	{
		if (res.back().second >= nums[i].first)
		{
			res.back().second = max(res.back().second, nums[i].second);
		}
		else
		{
			res.push_back(nums[i]);
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		if (i == res.size() - 1)
		{
			cout << res[i].first << " " << res[i].second;
			break;
		}
		cout << res[i].first << " " << res[i].second << " ";
	}
}
void pre_input(string s, vector<int>& vec)
{
	s = s + ' ';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (j < s.size() && s[j] != ' ')
		{
			j++;
			if (s[j] == ' ')
			{
				string tmp = s.substr(i, j - i);
				vec.push_back(stoi(tmp));
				break;
			}
		}
		i = j;
	}
}
int main()
{
	string input;
	vector<pair<int,int>>nums;
	while (getline(cin,input)&&input!="0 0")
	{
		if (!input.empty())
		{
			vector<int>tmp;
			pre_input(input, tmp);
			nums.push_back(make_pair(tmp[0], tmp[1]));
		}
		else
		{
			break;
		}
	}

	solve(intersection(nums));

	return 0;
}