#include<bits/stdc++.h>
using namespace std;

void pre_string(string s,vector<string>&vec)
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

int main()
{
	string s;
	while (cin >> s)
	{
		string input;
		cin >> input;

		vector<string>strs;
		pre_string(input, strs);

		/*for (int i = 0; i < strs.size(); i++)
		{
			cout << strs[i] << " ";
		}*/
		
		for(int i=0;i<strs.size();)
		{
			string tag = strs[i];
			i++;
			if (i > strs.size())break;

			int length = stoi(strs[i], nullptr, 16);
			i++;
			if (i > strs.size())break;

			string value;
			for (int j = 1; j <= length&&(i+2+j)<strs.size(); j++)
			{
				value += strs[i + 2 + j] + " ";
			}

			if (tag == s)
			{
				cout << value << endl;
				break;
			}

			i = i+(length + 1);
		}
	}
	return 0;
}