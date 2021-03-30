#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void backtracking(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& path, int& sum, int pos){
    if(sum > target){
        return;
    }
    if (sum == target){
        ans.push_back(path);
        return;
    }
    for (int i = pos; i < candidates.size(); i++){
        int value = candidates[i];
        if(i!=pos && value == candidates[i-1]){  // 在同一层的遍历过程中，相同的数字直接跳过
            continue;
        }
        
        sum += value;
        path.push_back(value);
        backtracking(candidates, target, ans, path, sum, i + 1);
        sum -= value;
        path.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> path;
    int sum = 0;
    backtracking(candidates, target, ans, path, sum, 0);
    return ans;
}

int main(){
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}