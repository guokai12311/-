#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void pre_input(string s,vector<int>&nums)
{
	s = s + ' ';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != ' ' && j < s.size())
		{
			j++;
			if (s[j] == ' ')
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(stoi(tmp));
			}
		}
		i = j;
	}
}
void print(vector<int>nums1, vector<int>nums2, int max_sub)
{
	
}
void max_sub_que(vector<int>nums1,vector<int>nums2)
{
	unordered_map<int, int>cnt1;
	unordered_map<int, int>cnt2;

	for (int i = 0; i < nums1.size(); i++)
	{
		for (int j = i + 1; j < nums1.size(); j++)
		{
			cnt1[nums1[j] - nums1[i]]++;
		}
	}

	for (int i = 0; i < nums2.size(); i++)
	{
		for (int j = i + 1; j < nums2.size(); j++)
		{
			cnt2[nums2[j] - nums2[i]]++;
		}
	}

	int max_len = 0;
	int max_sub = 0;
	for (auto it1 : cnt1)
	{
		auto it2 = cnt2.find(it1.first);
		if (it2 != cnt2.end())
		{
			//一个指的是迭代器，一个指的是具体的map值
			//max_len = max(max_len, min(it1.second, it2->second));
			if (min(it1.second, it2->second) > max_len)
			{
				max_len = min(it1.second, it2->second);
				max_sub = it1.first;
			}
		}
	}

	if (max_len == 0)
	{
		cout << 0 << endl;
		return;
	}

	cout << max_len << endl;
	print(nums1, nums2, max_sub);
}

int main()
{
	string s1;
	while (getline(cin,s1))
	{
		string s2;
		getline(cin, s2);

		vector<int>nums1; pre_input(s1, nums1);
		vector<int>nums2; pre_input(s2, nums2);

		max_sub_que(nums1, nums2);
	}
	return 0;
}