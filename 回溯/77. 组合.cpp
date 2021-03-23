#include <vector>
#include <iostream>
using namespace std;


void backtracking(vector<vector<int>>& ans, vector<int>& comb, int n, int k, int pos){
    if (comb.size()==k){
        ans.push_back(comb);
        return;
    }
    for (int i = pos; i <= n; i++){
        comb.push_back(i);  // 将当前的节点值加入
        backtracking(ans, comb, n, k, i+1);  // 回溯下一层
        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb;
    backtracking(ans, comb, n, k, 1);
    return ans;
}


int main(){
    int n = 4, k=2;
    vector<vector<int>> ans = combine(4, 2);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j< ans[0].size(); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}