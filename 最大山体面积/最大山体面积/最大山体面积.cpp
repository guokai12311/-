#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& matrix,int x,int y)
{
	int m = matrix.size(), n = matrix[0].size();
	if (x < 0 || x > m - 1 || y<0 || y>n - 1 || matrix[x][y] == 0)
	{
		return 0;
	}

	int cnt = matrix[x][y];
	matrix[x][y] = 0;

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		cnt+=dfs(matrix, xx, yy);
	}

	return cnt;
}

int main()
{
	int l, w;
	cin >> l >> w;
	vector<vector<int>>matrix(l, vector<int>(w, 0));
	vector<vector<bool>>visited(l, vector<bool>(w, false));

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int res = 0;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (matrix[i][j] != 0)
			{
				res = max(res, dfs(matrix,i,j));
			}
			//cout << matrix[i][j] << endl;
		}
	}

	cout << res << endl;


	return 0;
}