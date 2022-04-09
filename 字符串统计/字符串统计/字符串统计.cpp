#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<char, int>word_map;

void solve(string s,string t)
{
	for (int i = 0; i < s.size(); i += 4)
	{
		word_map[s[i]] = s[2] - '0';
	}

	for (int i = 0; i < t.size(); i += 4)
	{
		word_map[s[i]] = t[2] - '0';
	}

	vector<pair<char, int>>res;
	for (auto it = word_map.begin(); it != word_map.end(); it++)
	{

		if ((*it).second != 0)
		{
			res.push_back({ (*it).first,(*it).second });
		}
	}

	for (int i = 0; i < res.size()-1; i++)
	{
		cout << res[i].first << ":" << res[i].second << ",";
	}
	cout << res[res.size() - 1].first << ":" << res[res.size() - 1].second;
}

int main()
{
	string input;
	while (cin >> input)
	{
		string all_string;
		string used_string;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '@')
			{
				all_string = input.substr(0, i);
				used_string = input.substr(i + 1);
				break;
			}
		}

		solve(all_string, used_string);
	}
	return 0;
}