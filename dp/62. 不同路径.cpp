#include <vector>
#include <iostream>
using namespace std;


//--------------------------------------------------
// 深度优先搜索的方式来计算
int dfs(int i, int j, int m, int n){
    if (i >= m || j >= n){ //如果遍历超出范围，返回0
        return 0;
    }
    if (i==(m-1) && j==(n-1)){  // 如果遍历的终点，返回一条路径
        return 1;
    }
    
    // 在两个方向上进行深度优先搜索。
    return dfs(i+1, j, m, n) + dfs(i, j+1, m, n);
}
int uniquePaths1(int m, int n) {
    return dfs(0, 0, m, n);
}

//--------------------------------------------------
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++){
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++){
        dp[0][j] = 1;
    }
    
    
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
    
}

int main(){
    int m = 7, n=3;
    int answer = uniquePaths(7, 3);
    printf("%d", answer);
    return 0;
}
