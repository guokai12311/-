#include<bits/stdc++.h>
#include<map>
using namespace std;

void pre_string(string s,vector<string>&nums)
{
	s = s + ',';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != ',' && j < s.size())
		{
			j++;
			if (s[j] == ',')
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(tmp);
				break;
			}
		}
		i = j;
	}
}

void pre_int(vector<string>strs, map<int, int>&word_set)
{
	for (string s : strs)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ':')
			{
				int tmp = stoi(s.substr(0, i));
				int num = stoi(s.substr(i+1));
				word_set[tmp] = num;
				break;
			}
		}
	}
}

int main()
{
	string s1,s2;
	while (cin>>s1>>s2)
	{
		vector<string>memory_pool;
		map<int, int>memeory_pool_nums;
		pre_string(s1, memory_pool);
	    pre_int(memory_pool, memeory_pool_nums);

		/*for (auto it : memeory_pool_nums)
		{
			cout << it.first << " " << it.second << endl;
		}*/
		
		
		vector<string>app;
		pre_string(s2, app);
		vector<int>app_nums;
		for (string s : app)
		{
			app_nums.push_back(stoi(s));
			//cout << stoi(s) << " ";
		}



		string res;
		for (auto app_num : app_nums)
		{
			bool flag = false;
			for (auto &it : memeory_pool_nums)//注意这里一定要加引用
			{
				if (it.first >= app_num && it.second > 0)
				{
					res += "true,";
					it.second--;
					flag = true;
					break;
				}
			}
			if (!flag) res += "false,";
		}
		res.pop_back();

		cout << res << endl;

	}
	return 0;
}