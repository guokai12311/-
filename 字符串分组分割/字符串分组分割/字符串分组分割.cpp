#include<bits/stdc++.h>
using namespace std;
int judge_lower_cap(string s)
{
	int cnt_lower = 0, cnt_cap = 0;
	for (char c : s)
	{
		if(islower(c))
		{
			cnt_lower++;
		}
		if (isupper(c))
		{
			cnt_cap++;
		}
	}

	if (cnt_lower > cnt_cap)
	{
		return 1;
	}
	else if (cnt_lower == cnt_cap)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void pre_string(string& s)
{
	if (judge_lower_cap(s)==1)
	{
		for (char c : s)
		{
			if (isupper(c))
			{
				c = c - 'A' + 'a';
			}
		}
	}
	else if(judge_lower_cap(s)==-1)
	{
		for (char c : s)
		{
			if (islower(c))
			{
				c = c - 'a' + 'A';
			}
		}
	}
}
string remove_extra_(string s)
{
	string res;
	for (char c : s)
	{
		if (c != '-')
		{
			res += c;
		}
	}
	return res;
}
string solve(string s, int k)
{
	string res;
	string new_s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i] == '-')
		{
			new_s = s.substr(i);
			break;
		}
		res += s[i];
	}

	string new_new_s = remove_extra_(new_s);
	for (int i = 0; i < new_new_s.size(); i+=k)
	{
		res += '-'+new_new_s.substr(i, k);
	}

	return res;
}
int main()
{
	int k; string s;
	while (cin >> k >> s)
	{
		pre_string(s);

		cout << solve(s,k) << endl;
	}
	return 0;
}