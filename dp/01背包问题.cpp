#include <vector>
#include <iostream>
using namespace std;


// 初始化二维的dp数组进行计算
int knapsack1(vector<int>& weights, vector<int>& values, int N, int W){
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));  //多增加一个维度便于初始化
    for (int i = 1; i <= N; i++){
        int w = weights[i-1];
        int v = values[i-1];
        for(int j = 1; j <= W; j++){
            if (j >= w){  // 判断背包的容量是否能容得下当前的物体
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);  // 对于第i个物品有两种情况，存放和不存放 
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}

// 空间压缩的dp数组
int knapsack(vector<int> weights, vector<int> values, int N, int W){
    vector<int> dp(W+1);  // 空间压缩为1维数组，因为dp数组再遍历的过程中，从上到下从左到右
                          // 当前层的状态只与上一层的有关系，所以这样操作
    for (int i = 1; i <=N; i++){
        int w = weights[i-1], v = values[i-1];
        for (int j = W; j >= 1; j++){  // 逆序遍历，不然前面的已经修改找不到上层的结果
            if (j >= w){
                dp[j] = max(dp[j], dp[j-w] + v);
            }else{
                dp[j] = dp[j-1];
            }
        }
    }
    return dp[W];
}


int main(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int maxvalue = knapsack(weight, value, 3, 4);
    printf("%d\n", maxvalue);
}
