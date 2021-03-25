#include <vector>
#include <iostream>
using namespace std;

// 输入: k = 3, n = 7
// 输出: [[1,2,4]]

void backtracking(vector<vector<int>>& ans, vector<int>& path, int k, int n, int pos, int sum){
    if (sum > n || (path.size() >= k & sum != n)){
        return;
    }

    if (sum==n & path.size() == k){
        ans.push_back(path);  // 找到结果直接返回，没有必要继续往下遍历
        return;
    }
    // for (int i = pos; i <= 9; i++){
    for (int i = pos; i <= (9 - (k - path.size()) + 1); i++){
        sum += i;
        path.push_back(i);
        backtracking(ans, path, k, n, i+1, sum);
        sum -= i;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;
    backtracking(ans, path, k, n, 1, 0);
    return ans;
}

int main(){
    int k = 1, n = 9;
    vector<vector<int>> ans = combinationSum3(k, n);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[0].size(); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}