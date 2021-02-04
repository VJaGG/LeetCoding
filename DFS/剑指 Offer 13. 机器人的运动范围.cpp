#include <vector>
#include <iostream>
using namespace std;


int count(int i, int j){
    int num = 0;
    while (i!=0){
        num = num + i % 10;
        i /= 10;
    }
    while (j!=0){
        num = num + j % 10;
        j /= 10;
    }
    return num;
}

int dfs(vector<vector<int>> &matrix, int i, int j, int k){  
    // 注意引用与不引用，如果不用引用没有对矩阵修改会错误
    if (i<0 || j <0 || i==matrix.size() || j==matrix[0].size() || k<matrix[i][j]){
        return 0;
    }
    int ans = 1;
    matrix[i][j] = k+1;
    ans = ans + dfs(matrix, i+1, j, k) + dfs(matrix, i-1, j, k) +
          dfs(matrix, i, j-1, k) + dfs(matrix, i, j+1, k);
    return ans;
}

int movingCount(int m, int n, int k) {
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = count(i, j);
        }
    }
    int count = dfs(matrix, 0, 0, k);
    return count;
}
int main(){
    int m=3, n=2, k=17;
    int count = movingCount(m, n, k);
    printf("%d", count);
    return 0;

}


// 机器人的运动范围与岛屿问题和矩阵路径的区别在于，机器人不用遍历整个矩阵
// 只是从(0, 0)位置开始深度优先搜索即可。