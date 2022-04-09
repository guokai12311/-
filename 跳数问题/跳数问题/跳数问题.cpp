#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;

	vector<int>nums;
	for (int i = 1; i < 2 * n; i++)
	{
		string tmp = to_string(i);
		if (find(tmp.begin(), tmp.end(), '7') == tmp.end())
		{
			nums.push_back(i);
		}
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == n)
		{
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}