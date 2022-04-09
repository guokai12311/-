#include<bits/stdc++.h>
using namespace std;
void pre_input(string s, vector<string>& nums)
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
                nums.push_back(tmp);
                break;
            }
        }
        i = j;
    }
}

int compare(string a, string b)
{
    int m = a.size(), n = b.size();
    int len;
    len = m > n ? n : m;

    for (int i = 0; i < len;)
    {
        if (tolower(a[i]) == tolower(b[i]))
        {
            i++;
        }
        else if (tolower(a[i]) < tolower(b[i]))
        {
            return 1;
        }
        else return -1;
    }

    if (m < n) return 1;
    else if (n < m) return -1;
    else return 0;
}

void my_buble_sort(vector<string>& nums)
{
    for (int i = 0; i < nums.size()-1; i++)
    {
        bool flag = false;
        for (int j = 0; j < nums.size() - 1 - i; j++)
        {
            if (compare(nums[j], nums[j + 1]) == -1)
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

int main()
{
    string input;
    input = "world World Hel";
    vector<string>nums;
    pre_input(input, nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    my_buble_sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int i = 0;

    while (i < nums.size())
    {
        cout << nums[i] << " ";
        int j = i + 1;
        while (j < nums.size())
        {
            if (compare(nums[j], nums[i]) == 0) { j++; }
            else break;
        }
        i = j;
    }
    return 0;
}