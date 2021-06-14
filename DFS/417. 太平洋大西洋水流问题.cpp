#include <vector>
#include <iostream>
using namespace std;


vector<int> derections = {-1, 0, 1, 0, -1};
void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reach, int r, int c){
    int row = heights.size();
    int col = heights[0].size();
    if (reach[r][c]){ // 递归结束的标志，节点访问过的标记
        return;
    }
    
    reach[r][c] = true;
    for (int i = 0; i < 4; i++){
        int x = r + derections[i];
        int y = c + derections[i+1];
        if (0<=x && x < row && 0<=y && y<col && heights[r][c]<=heights[x][y]){
            dfs(heights, reach, x, y);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;
    int row = heights.size(), col = heights[0].size();
    vector<vector<bool>> reach_a(row, vector<bool>(col, false));
    vector<vector<bool>> reach_b(row, vector<bool>(col, false));
    for (int i = 0; i < col; i++){
        dfs(heights, reach_a, 0, i);
        dfs(heights, reach_b, row-1, i);

    }
    for (int i = 0; i < row; i++){
        dfs(heights, reach_a, i, 0);
        dfs(heights, reach_b, i, col-1);
    }
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (reach_a[i][j] && reach_b[i][j]){
                 ans.push_back({i, j});
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> heights = 
    {{1, 2, 2, 3, 5},
     {3, 2, 3, 4, 4},
     {2, 4, 5, 3, 1},
     {6, 7, 1, 4, 5},
     {5, 1, 1, 2, 4}
     };
     vector<vector<int>> ans = pacificAtlantic(heights);
     for (int i = 0; i < ans.size(); i++){
         printf("%d %d\n", ans[i][0], ans[i][1]);
     }
     return 0;
}