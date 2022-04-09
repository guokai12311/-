#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int>memory_pool_nums;
		int num=0, size=0;
		for (int i = 0; i < n; i++)
		{
			cin >> num >> size;
			memory_pool_nums[size] = num;
		}

		int k;
		cin >> k;
		vector<int>apps(k);
		for (int i = 0; i < k; i++)
		{
			cin >> apps[i];
		}

		
	}
	return 0;
}