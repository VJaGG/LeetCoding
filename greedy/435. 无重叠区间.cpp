#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static bool cmp(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() == 0)
        return 0;
    sort(intervals.begin(), intervals.end(), cmp);
    int end = intervals[0][1];
    int count = 1;
    for (int i = 1; i < intervals.size(); i++){
        if (end <= intervals[i][0]){
            end = intervals[i][1];
            count ++;
        }
    }
    return intervals.size() - count;
}

int main(){
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };
    int answer = eraseOverlapIntervals(intervals);
    printf("%d\n", answer);
    return 0;
}