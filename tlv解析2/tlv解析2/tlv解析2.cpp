#include<bits/stdc++.h>
using namespace std;

void pre_string(string s,vector<int>&nums)
{
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (s[j] != ',' && j < s.size())
		{
			j++;
			if (s[j] == ',')
			{
				int tmp = stoi(s.substr(i, j - i));
				nums.push_back(tmp);
				break;
			}
		}
		i = j;
	}
}
int check(vector<vector<int>>matrix)
{
	int res = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			res += matrix[i][j];
		}
	}
	return res;
}

int bfs(vector<vector<int>>& matrix)
{
	int m = matrix.size();

	if (check(matrix) == m * m || check(matrix) == 0) return -1;

	bool needcontinue = true;
	int cnt = 0;

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	while (needcontinue)
	{
		needcontinue = false;
		int cur_diffusion = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 1)
				{
					for (int k = 0; k < 4; k++)
					{
						int x = i + dx[k], y = j + dy[k];
						if (x >= 0 && x <= m - 1 && y >= 0 && y <= m - 1 && matrix[x][y] == 0)
						{
							matrix[x][y] = 2;
							cur_diffusion = 1;
						}
					}
				}
			}
		}

		cnt += cur_diffusion;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 2)
				{
					matrix[i][j] = 1;
				}

				if (matrix[i][j] == 0)
				{
					needcontinue = true;
				}
			}
		}
	}

	return cnt;
}
int main()
{
	string input;
	while (cin >> input)
	{
		vector<int>nums;
		pre_string(input, nums);

		int n = sqrt(nums.size())+1;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		
		//for (int i = 0; i < nums.size(); i++) cout << nums[i];
		
		//cout << n << endl;
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = nums[k];
				k++;
				if (k == nums.size()) break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j];
			}
		}

		cout<<bfs(matrix)<<endl;
	}
	return 0;
}