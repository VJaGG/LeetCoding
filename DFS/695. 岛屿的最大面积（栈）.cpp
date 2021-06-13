#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int IslandDFS(vector<vector<int>>& grid, int i, int j){
    stack<int> stacki;
    stack<int> stackj;
    stacki.push(i);
    stackj.push(j);

    int ans = 0;
    while (!stacki.empty()){
        int cur_i = stacki.top();
        stacki.pop();
        int cur_j = stackj.top();
        stackj.pop();
        if (cur_i<0 || cur_i==grid.size() || cur_j<0 || cur_j==grid[0].size() || grid[cur_i][cur_j]!=1){
            continue;
        }
        ans++;
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++){
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];
            stacki.push(next_i);
            stackj.push(next_j);
        }
    }
    return ans;
    
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int ans = 0;
    // 遍历每一个点来判断是否为岛屿
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            ans = max(ans, IslandDFS(grid, i, j));
        }
    }
    return ans;
}
// ===============================================
// vector<int> direction{-1, 0, 1, 0, -1};
// int dfs(vector<vector<int>>& grid, int x, int y){
//     int ans = 0;
//     int row = grid.size(), col = grid[0].size();
//     stack<pair<int, int>> island;
//     island.push({x, y});
//     grid[x][y] = 0;
//     ans++;
//     while (!island.empty()){
//         int r = island.top().first, c = island.top().second;
//         island.pop();
//         for (int k = 0; k < 4; k++){
//             x = r + direction[k], y = c + direction[k+1];
//             if (x >=0 && x < row && y >=0 && y < col && grid[x][y]==1){
//                 island.push({x, y});
//                 grid[x][y] = 0;
//                 ans ++;
//             }
            
//         }
        
//     }
//     return ans;
    
// }

// int maxAreaOfIsland(vector<vector<int>>& grid) {
//     int row = grid.size(), col = grid[0].size();
//     int ans = 0;
//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < col; j++){
//             if (grid[i][j]){
//                 ans = max(ans, dfs(grid, i, j));
//             }   
//         }
//     }
//     return ans;
// }



int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int ans = maxAreaOfIsland(grid);
    printf("%d", ans);
    return 0;
    
}
