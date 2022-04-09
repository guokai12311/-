#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum, n;
	while (cin >> sum >> n)
	{
		int tmp = sum - (n - 1) * n / 2;
		
		if (tmp < 0 || tmp % n != 0)
		{
			cout << -1 << endl;
		}
		else
		{
			int begin = tmp / n;
			for (int i = 0; i < n; i++)
			{
				cout << begin + i << " ";
			}
			cout << endl;
		}
	}
	return 0;
}