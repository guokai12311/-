#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>strs)
{
	map<char, int>nums;
	for (string s : strs)
	{
		nums[s[0]] += s[4] - '0';
		nums[s[2]] += s[6] - '0';
	}

	vector<pair<char, int>>res;
	for (auto it : nums)
	{
		res.push_back(make_pair(it.first, it.second));
	}

	sort(res.begin(), res.end(), [](pair<char, int>a, pair<char, int>b)
		{
			return a.second > b.second;
		});

	for (int i = 0; i < res.size(); i++)
	{
		if (i == res.size() - 1)
		{
			cout << res[i].first << " " << res[i].second;
			break;
		}
		cout << res[i].first << " " << res[i].second << ",";
	}
}
int main()
{
	string s;
	vector<string>strs;
	while (getline(cin, s))
	{
		if (s == "\0")
		{
			break;
		}
		strs.push_back(s);
	}

	solve(strs);
	
	return 0;
}