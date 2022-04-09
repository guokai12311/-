#include<bits/stdc++.h>
using namespace std;
int main()
{
	string input;
	while (cin >> input)
	{
		string high = "bdfhkl"; // 6
		string mid = "aceimnorstuvwxz"; // 15
		string low = "gjqpy"; // 5

		set<char>p1, p2, p3;
		for (char c : input)
		{
			if (find(high.begin(),high.end(),c)!=high.end())
			{
				p1.insert(c);
			}
			else if (find(mid.begin(), mid.end(), c) != mid.end())
			{
				p2.insert(c);
			}
			else
			{
				p3.insert(c);
			}
		}

		for (auto it : p1)
		{
			cout << it;
		}
		cout << endl;
		for (auto it : p2)
		{
			cout << it;
		}
		cout << endl;
		for (auto it : p3)
		{
			cout << it;
		}
		cout << endl;
	}
	return 0;
}