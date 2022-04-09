#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>matrix;
vector<int>cost;
vector<int>in_dgree;
vector<bool>visited;

void pre_input(string s,vector<string>&vec)
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
				vec.push_back(tmp);
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
	for (int i = 0; i < matrix[index].size(); i++)
	{
		int next = matrix[index][i];
		if (!visited[next])
		{
			res = max(res, dfs(next));
		}
	}
	visited[index] = false;
	return res + cost[index];
}

int main()
{

	int n;
	while (cin >> n)
	{
		matrix = vector<vector<int>>(n);
		cost = vector<int>(n, 0);
		in_dgree = vector<int>(n, 0);
		visited = vector<bool>(n, false);
		//数据预处理
		for (int i = 0; i < n; i++)
		{
			string s; 
			getline(cin, s);

			vector<string>vec;
			pre_input(s,vec);

			/*for (int i = 0; i < vec.size(); i++)
			{
				cout << vec[i] << " ";
			}*/

			cost[i] = stoi(vec[1]);
			if (vec.size() > 2)
			{
				for (int j = 2; j < vec.size(); j++)
				{
					matrix[i].push_back(stoi(vec[j]) - 1);
					in_dgree[stoi(vec[j])]++;
				}
			}
		}


		//bfs，入度为0的进队
		queue<int>que;
		for (int i = 0; i < n; i++)
		{
			if (in_dgree[i] == 0)
			{
				que.push(i);
			}
		}

		int res = 0;
		while (!que.empty())
		{
			int i = que.front();
			//dfs，搜索最短时间
			res = max(res, dfs(i));
			que.pop();
		}

		cout << res << endl;
	}
	return 0;
}