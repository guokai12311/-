#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solve(int n,int res)
{
	if (n <= 1) return res;

	if (n % 2 == 0)
	{
		return solve(n / 2, res + 1);
	}
	else
	{
		return min(solve(n + 1, res + 1), solve(n - 1, res + 1));
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << solve(n,0) << endl;
	}
	return 0;
}