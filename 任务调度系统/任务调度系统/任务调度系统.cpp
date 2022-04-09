#include<bits/stdc++.h>
using namespace std;
void pre_input(string s, vector<string>& nums,char pattern)
{
	s += pattern;
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (j < s.size() && s[j] != pattern)
		{
			j++;
			if (s[j] == pattern)
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(tmp);
				break;
			}
		}
		i = j;
	}
}
int bfs(vector<int>times, vector<vector<int>>matrix,int n)
{
	vector<int>in_dgree(n, 0);
	for (auto it : matrix)
	{
		for (int i:it)
		{
			in_dgree[i]++;
		}
	}

	queue<int>que;
	vector<int>dp(n, 0);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (in_dgree[i] == 0)
		{
			dp[i] = times[i];
			que.push(i);
		}
	}

	while (!que.empty())
	{
		int cur = que.front(); que.pop();
		cnt++;
		for (int i : matrix[cur])
		{
			in_dgree[i]--;
			dp[i] = max(dp[i], dp[cur] + times[i]);
			if (in_dgree[i] == 0)
			{
				que.push(i);
			}
		}
	}

	if (cnt != n) return -1;
	int res = 0;
	for (int j : dp)
	{
		res = max(res, j);
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
		string s;
		vector<int>times(n);
		vector<vector<int>>matrix(n, vector<int>{});

		for (int i = 0; i < n; i++)
		{
			vector<string>tmp1;
			string s;
			getline(cin, s);
			pre_input(s, tmp1, ',');
			for (int j = 0; j < tmp1.size() - 1; j++)
			{
				int a = stoi(tmp1[j]);
				matrix[a].push_back(i);
			}

			vector<string>tmp2;
			pre_input(tmp1.back(), tmp2, ' ');
			if (tmp2[0] != "-1")
			{
				int a = stoi(tmp1[0]);
				matrix[a].push_back(i);
			}

			int t = stoi(tmp2[1]);
			times[i] = t;
		}
		cout << bfs(times, matrix, n)<<endl;
		/*for (int i = 0; i < times.size(); i++)
		{
			cout << times[i] << " ";
		}
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				cout << matrix[i][j] << " ";
			}
		}*/

	return 0;
}