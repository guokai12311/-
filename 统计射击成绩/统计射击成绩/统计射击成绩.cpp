#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct competitor
{
	int id;
	int score;
};
void input_id(string s, vector<competitor>& nums)
{
	s = s + ',';
	int k = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != ',' && j < s.size())
		{
			j++;
			if (s[j] == ',')
			{
				string tmp = s.substr(i, j - i);
				nums[k++].id = stoi(tmp);
			}
		}
		i = j;
	}
}
void input_score(string s, vector<competitor>& nums)
{
	s = s + ',';
	int k = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != ',' && j < s.size())
		{
			j++;
			if (s[j] == ',')
			{
				string tmp = s.substr(i, j - i);
				nums[k++].score = stoi(tmp);
			}
		}
		i = j;
	}
}
void my_buble_sort(vector<pair<int, int>>& nums)
{
	for (int i = 0; i < nums.size() - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < nums.size() - 1 - i; j++)
		{
			if (nums[j].second < nums[j + 1].second || (nums[j].second == nums[j + 1].second && nums[j].first < nums[j + 1].first))
			{
				flag = true;
				swap(nums[j], nums[j + 1]);
			}
		}
		if (!flag)break;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		//处理输入数据，，的处理
		//统计选手的分数之和，同时排除掉成绩少于三个
		//按成绩之和排序，相等则按照id排序
		string id_string;
		cin >> id_string;

		string score_string;
		cin >> score_string;

		vector<competitor>nums(n);
		input_id(id_string, nums);
		input_score(score_string, nums);


		unordered_map<int, vector<int>>map;
		for (int i = 0; i < nums.size(); i++)
		{
			map[nums[i].id].push_back(nums[i].score);
		}

		vector<pair<int, int>>map_score;
		for (auto it = map.begin(); it != map.end(); it++)
		{
			if ((*it).second.size() >= 3)
			{
				sort((*it).second.begin(), (*it).second.end(), [](int a, int b)
					{
						return a > b;
					});

				int x = (*it).first;
				int y = (*it).second[0] + (*it).second[1] + (*it).second[2];
				map_score.push_back({ x,y });
			}
		}

		/*sort(map_score.begin(), map_score.end(), [](pair<int, int>a, pair<int, int>b)
			{
					return a.second>b.second;
			});*/

		my_buble_sort(map_score);

		for (int i = 0; i < map_score.size(); i++)
		{
			if (i == map_score.size() - 1)
			{
				cout << map_score[i].first;
				break;
			}
			cout << map_score[i].first << ",";
		}

	}
	return 0;
}