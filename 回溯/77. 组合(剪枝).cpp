#include <vector>
#include <iostream>
using namespace std;

void backtracking(vector<vector<int>>& ans, vector<int> &path, int n, int k, int pos){
    if (path.size() == k){
        ans.push_back(path);
        return;
    }
    for (int i = pos; i <= (n - (k - path.size())) + 1; i++){
        // 剪枝操作，k是组合的元素的个数，path.size()是已经选出来的元素的个数，(k-path.size())还需要多少个元素
        // 这边i理解为第一个元素的范围，[pos, (n-(k-path.size())) + 1]
        // 例如当n=4, k=2时候，第一个元素的范围只能为[1, 2, 3], 当起始元素为4的时候不能选出两个元素了。
        path.push_back(i);
        backtracking(ans, path, n, k, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    backtracking(ans, path, n, k, 1);
    return ans;
}

int main(){
    int n = 4, k=2;
    vector<vector<int>> ans = combine(n, k);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[0].size(); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;   
}