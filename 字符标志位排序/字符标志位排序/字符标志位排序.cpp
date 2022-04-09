#include<bits/stdc++.h>
using namespace std;
void sort(string s)
{
	map<char, int>char_map;
	for (char c : s)
	{
		char_map[c]++;
	}

	vector<pair<char, int>>nums;
	for (auto it : char_map)
	{
		nums.push_back(make_pair(it.first, it.second));
	}

	sort(nums.begin(), nums.end(), [](pair<char, int>a, pair<char, int>b)
		{
			return a.second == b.second ? a.first<b.first : a.second>b.second;
		});

	cout << nums[0].first << " " << nums[0].second;
}
int main()
{
	string input;
	while (getline(cin,input))
	{
		input += ' ';
		string flag = input.substr(input.find_first_of(' '));
		string tmp = " false ";

		string s = input.substr(0, input.find_first_of(' '));
		if (flag == tmp)
		{
			for (char &c : s)
			{
				if (isupper(c))
				{
					c = c - 'A' + 'a';
				}
			}
			sort(s);
		}
		else
		{
			sort(s);
		}
	}
	return 0;
}