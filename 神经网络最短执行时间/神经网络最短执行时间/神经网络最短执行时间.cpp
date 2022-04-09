#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>matrix;
vector<int>times;
vector<int>indgree;
vector<bool>visited;

void pre_input(string s, vector<string>& nums)
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
				nums.push_back(tmp);
				break;
			}
		}
		i = j;
	}
}

int dfs(int index)
{
	int res = 0;
	visited[index] = true;
	for (int j = 0; j < matrix[index].size(); j++)
	{
		int next = matrix[index][j];
		if (!visited[next])
		{
			res = max(res, dfs(matrix[index][j]));
		}
	}
	visited[index] = false;
	return res + times[index];
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	
	matrix = vector<vector<int>>(n);
	times = vector<int>(n);
	indgree = vector<int>(n);
	visited = vector<bool>(n, false);

	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);

		vector<string>nums;
		pre_input(s, nums);
		
		times[i] = stoi(nums[1]);

		if (nums.size() > 2)
		{
			for (int j = 2; j < nums.size(); j++)
			{
				matrix[i].push_back(stoi(nums[j]));
				indgree[stoi(nums[j])]++;
			}
		}
	}

	int res = 0;
	queue<int>que;
	for (int i = 0; i < n; i++)
	{
		if (indgree[i] == 0)
		{
			que.push(i);
		}
	}
	while (!que.empty())
	{
		int i = que.front();
		res = max(res, dfs(i));
		que.pop();
	}
	cout << res << endl;

	return 0;
}