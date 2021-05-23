#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size()==0){
        return 0;
    }
    sort(points.begin(), points.end(), cmp);
    int start = points[0][0];
    int end = points[0][1];
    int count = 1;
    for (int i = 1; i < points.size(); i++){
        if (points[i][0] > end){
            start = points[i][0];
            end = points[i][1];
            count ++;
        }else{
            start = points[i][0];
            end = min(end, points[i][1]);
        } 
    }
    return count;
}

int main(){
    vector<vector<int>> points ={
        {10,16},
        {2,8},
        {1,6},
        {7,12}
    };
    int answer = findMinArrowShots(points);
    printf("%d\n", answer);
    return 0;
}