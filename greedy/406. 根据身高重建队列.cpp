#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


static bool cmp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }else{
        return a[0] > b[0];
    } 
}


vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> q;
    sort(people.begin(), people.end(), cmp);
    q.push_back(people[0]);
    for (int i = 1; i < people.size(); i++){
        q.insert(q.begin() + people[i][1], people[i]);
    }
    return q;
}

int main(){
    vector<vector<int>> people = {
        {9, 0},
        {7, 0},
        {1, 9},
        {3, 0},
        {2, 7},
        {5, 3},
        {6, 0},
        {3, 4},
        {6, 2},
        {5, 2}
    };

    vector<vector<int>> answer = reconstructQueue(people);
    for (int i = 0; i < answer.size(); i++){
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }
    return 0;
}