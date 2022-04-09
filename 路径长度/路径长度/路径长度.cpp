#include<bits/stdc++.h>
using namespace std;
int main()
{
	string source_s, path_s;
	cin >> source_s >> path_s;

	vector<char>points;
	for (char c : path_s)
	{
		points.push_back(c);
	}

	int res = 0;
	int start = source_s.find(points[0]);
	for (int i = 0; i < points.size() - 1; i++)
	{
		int end = source_s.find(points[i + 1]);
		int len = abs(end - start);
		start = end;
		res += len;
	}
	cout << res << endl;

	return 0;
}