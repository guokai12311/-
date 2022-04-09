#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    string str;
    while (getline(cin, str)) {
        vector<char> ve_num;
        string str_num = "123456";
        for (char& i : str_num) {
            ve_num.push_back(i);
        }
        for (char i : str) {
            if (i == 'L') {
                swap(ve_num[0], ve_num[5]);
                swap(ve_num[0], ve_num[1]);
                swap(ve_num[0], ve_num[4]);
            }
            else if (i == 'R') {
                swap(ve_num[0], ve_num[5]);
                swap(ve_num[1], ve_num[4]);
                swap(ve_num[4], ve_num[5]);
            }
            else if (i == 'F') {
                swap(ve_num[4], ve_num[2]);
                swap(ve_num[3], ve_num[5]);
                swap(ve_num[4], ve_num[5]);
            }
            else if (i == 'B') {
                swap(ve_num[5], ve_num[2]);
                swap(ve_num[4], ve_num[3]);
                swap(ve_num[4], ve_num[5]);
            }
            else if (i == 'A') {
                swap(ve_num[0], ve_num[3]);
                swap(ve_num[1], ve_num[2]);
                swap(ve_num[2], ve_num[3]);
            }
            else if (i == 'C') {
                swap(ve_num[2], ve_num[0]);
                swap(ve_num[1], ve_num[3]);
                swap(ve_num[2], ve_num[3]);
            }
        }
        for (char i : ve_num) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
