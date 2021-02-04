#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int IslandDFS(vector<vector<int>>& grid, int i, int j){
    // 当前位置(i, j)没有超出地图范围
    if (i>=0 && i<grid.size() && j>=0 && j<grid[0].size()){
        if (grid[i][j]==0){  // 当前位置是否为岛屿
            return 0;
        }else{
            grid[i][j] = 0;  // 标记为已经访问过
            return 1 + IslandDFS(grid, i-1, j) + IslandDFS(grid, i+1, j) 
                   + IslandDFS(grid, i, j-1) + IslandDFS(grid, i, j+1);
        }
    }else{
        return 0;
    }
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