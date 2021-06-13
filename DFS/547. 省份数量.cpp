#include <vector>
#include <iostream>
using namespace std;


// 深度优先搜索
void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
    visited[i] = false;  // 深度优先搜索对当前节点访问
    for (int j = 0; j < isConnected[i].size(); j++){
        if (isConnected[i][j]==1 && visited[j]){
            dfs(isConnected, visited, j);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected){
    int n = isConnected.size();
    int ans = 0;
    vector<bool> visited(n, true);
    for (int i = 0; i < n; i++){  // 对多有的节点进行访问
        if (visited[i]){  
            // 如果节点没有被访问，对当前节点深度优先搜索
            ans++;
            dfs(isConnected, visited, i);
        }
        
    }
    return ans;
}


int main(){
    // vector<vector<int>> isConnected = {{1, 0, 0},{0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> isConnected = {{1}};
    int ans = findCircleNum(isConnected);
    printf("%d\n", ans);
    return 0;

}