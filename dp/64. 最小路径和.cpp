#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


// 没有空间压缩的版本
int minPathSum1(vector<vector<int>>& grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));  // dp表示在位置为i, j的地方路径和最小为多少
    dp[0][0] = grid[0][0];
    for (int i = 1; i < row; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < col; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < row; i++){
        for (int j = 1; j < col; j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[row-1][col-1];
}

// 空间压缩
int minPathSum(vector<vector<int>>& grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<int> dp(col, 0);  // 空间压缩为1维的，因为是从上到下从左到右遍历的。
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (i==0 && j==0){
                dp[j] = grid[i][j];
            }else if (i==0){
                dp[j] = grid[i][j] + dp[j-1];
            }else if (j==0){
                dp[j] = grid[i][j] + dp[j];
            }else{
                dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
            } 
        }
        
    }
    return dp[col-1];
}

int main(){
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};

    int answer = minPathSum(grid);
    printf("%d\n",answer);
}