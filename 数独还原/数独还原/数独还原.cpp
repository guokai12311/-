#include<bits/stdc++.h>
using namespace std;
//判断数独是否有效
bool is_valid(vector<vector<int>>matrix,int row,int col,int val)
{
	//行重复
	for (int i = 0; i < 9; i++)
	{
		if (matrix[row][i] == val)
		{
			return false;
		}
	}
	//列重复
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i][col] == val)
		{
			return false;
		}
	}
	//所在的格子重复
	int start_row = (row / 3) * 3;
	int start_col = (col / 3) * 3;
	for (int i = start_row; i < start_row + 3; i++)
	{
		for (int j = start_col; j < start_col + 3; j++)
		{
			if (matrix[i][j] == val)
			{
				return false;
			}
		}
	}
}
//处理输入数据
void pre_input(string s, vector<int>& nums)
{
	s += ',';
	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (j < s.size() && s[j] != ',')
		{
			j++;
			if (s[j] == ',')
			{
				string tmp = s.substr(i, j - i);
				nums.push_back(stoi(tmp));
				break;
			}
		}
		i = j;
	}
}

//递归解数独
bool recur(vector<vector<int>>&matrix)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 0)
			{
				for (int k = 1; k <= 9; k++)
				{
					if (is_valid(matrix, i, j, k))
					{
						matrix[i][j] = k;
						if (recur(matrix))
						{
							return true;
						}
						matrix[i][j] = 0;
					}
				}
				return false;
			}
		}
	}

	return true;
}
void print(vector<vector<int>>matrix)
{
	for (int i = 0; i < 9; i++)
	{
		cout << "{";
		for (int j = 0; j < 9; j++)
		{
			if (j == 8)
			{
				cout << matrix[i][j] << "}";
				break;
			}
			cout << matrix[i][j] << ",";
		}
		cout << endl;
	}
}
int main()
{
	//输入数据
	vector<vector<int>>matrix(9);
	for (int i = 0; i < 9; i++)
	{
		string s;
		getline(cin, s);
		vector<int>nums;

		//预处理数据
		pre_input(s.substr(1, s.size() - 2), nums);
		for (auto it : nums)
		{
			matrix[i].push_back(it);
		}
	}
	//测试输入数据
	/*for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/

	/*测试输入代码
	matrix = {{5,0,0,6,0,2,0,0,0},
{0,0,8,0,7,0,2,0,0},
{7,0,0,8,1,0,5,4,6},
{2,0,1,3,0,0,9,8,5},
{3,4,0,0,8,0,0,0,0},
{0,0,9,0,0,7,0,1,4},
{1,5,6,0,2,0,0,0,3},
{4,0,2,0,9,6,0,0,7},
{9,0,0,0,0,3,0,0,1} };*/
	
	//解数独
	recur(matrix);

	//输出
	print(matrix);

	return 0;
}