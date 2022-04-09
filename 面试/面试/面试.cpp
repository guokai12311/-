#include<iostream>
#include<vector>

using namespace std;

int MinInterviewers(vector <vector<int>> intervals, int max_meets) {
    if (intervals.empty()) {
        return 0;
    }
    int end_time = intervals[0][1];
    int min_interviewers = 1;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < end_time) {
            min_interviewers++;
        }
        else {
            if ((i + 1) % max_meets == 0) {
                min_interviewers++;
            }
        }
    }
    return min_interviewers;
}

int main(int argc, char** argv) {
    vector <vector<int>> intervals;
    int max_meets = 0;
    int meets = 0;
    cin >> max_meets;
    cin >> meets;
    for (int i = 0; i < meets; i++) {
        int start, end;
        vector<int> vec;
        cin >> start >> end;
        vec.push_back(start);
        vec.push_back(end);
        intervals.push_back(vec);
    }
    cout << MinInterviewers(intervals, max_meets) << endl;
    return 0;
}
