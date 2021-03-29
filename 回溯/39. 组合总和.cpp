#include <vector>
#include <iostream>
using namespace std;


void backtracking(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& path, int &sum, int pos){
    if (sum > target){
        return;
    }
    
    if (sum==target){
        ans.push_back(path);
        return;
    }
    for (int i = pos; i < candidates.size(); i++){
        int value = candidates[i];
        sum += value;
        path.push_back(value);
        backtracking(candidates, target, ans, path, sum, i);
        sum -= value;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    int sum = 0;
    backtracking(candidates, target, ans, path, sum, 0);
    return ans;
}


int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");        
    }
    return 0;

}