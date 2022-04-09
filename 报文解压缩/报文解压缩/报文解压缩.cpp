#include<bits/stdc++.h>
using namespace std;
void solve(string&s)
{
	stack<int>stk;
	string tmp1, tmp2;

	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]))
		{
			stk.push(i);
			while (s[i] != '[')
			{
				i++;
			}
			stk.push(i);
		}
		else if(s[i]==']')
		{
			int cur = stk.top(); stk.pop();
			int first_num = stk.top(); stk.pop();

			tmp1 = s.substr(cur + 1, i - cur - 1);
			int num = stoi(s.substr(first_num, cur - first_num));
			tmp2.clear();
			while (num--)
			{
				tmp2 += tmp1;
			}

			s.erase(first_num, i - first_num + 1);
			s.insert(first_num, tmp2);

			i = first_num + tmp2.size() - 1;
		}
	}
}
int main()
{

	string input;
	while (getline(cin,input))
	{
		solve(input);
		cout << input << endl;
	}
	return 0;
}