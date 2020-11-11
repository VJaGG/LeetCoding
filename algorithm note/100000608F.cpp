//http://codeup.cn/problem.php?cid=100000608&pid=5
//问题 F: 【递归入门】走迷宫
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 15;
int matirx[maxn][maxn];
// bool used[maxn][maxn]={false};  可以直接用地图的矩阵这一步可以省去
int n, m;
int start_x, start_y;
int goal_x, goal_y;
int px[4] = {0, -1, 0, 1};
int py[4] = {-1, 0, 1, 0};
vector<pair<int, int>> path;


void search(int x, int y){
    if (x == goal_x && y == goal_y){
        printf("(%d,%d)", start_x, start_y);
        for(unsigned int i=1; i < path.size(); i++){
            printf("->(%d, %d)", path[i].first, path[i].second);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + px[i];
        int new_y = y + py[i];
        if (matirx[new_x][new_y]==1){
            path.push_back(pair<int, int>(new_x, new_y));
            matirx[new_x][new_y] = 0;
            search(new_x, new_y);
            path.pop_back();
            matirx[new_x][new_y] = 1;
        }
    }
}


int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
                scanf("%d", &matirx[i][j]);
        }
    }
    scanf("%d%d", &start_x, &start_y);
    scanf("%d%d", &goal_x, &goal_y);
    path.push_back(pair<int, int>(start_x, start_y));
    search(start_x, start_y);

}


// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// struct dot {
// 	int x, y;
// };
// int a[20][20], n, m, flag = 0;
// int movex[4] = { 0,-1,0,1 }, movey[4] = { -1,0,1,0 };
// dot start, endd;
// vector<dot> route;
// void dfs(int x, int y) {
// 	if(x == endd.x && y == endd.y) {
// 		printf("(%d,%d)", route[0].x, route[0].y);
	
 
// 		for(int i = 1; i < route.size(); i++) {
// 			printf("->(%d,%d)", route[i].x, route[i].y);
// 		}
// 		printf("\n");
// 		flag = 1;
// 		return;
// 	}
 
// 	for(int i = 0; i < 4; i++) {
// 		if(a[x+movex[i]][y + movey[i]] == 1) {
// 			dot d;
// 			d.x = x + movex[i];
// 			d.y = y + movey[i];
// 			route.push_back(d);
// //			cout << "push:" << d.x << " " << d.y << endl; 
// 			a[x+movex[i]][y + movey[i]] = 0;
// 			dfs(x + movex[i], y + movey[i]);
// 			route.pop_back();
// //			cout << "pop:" << d.x << " " << d.y << endl; 
// 			a[x+movex[i]][y + movey[i]] = 1;
// 		}
// 	}
// }
// int main(int argc, char** argv) {
// 	while(cin >> n >> m) {
// 		for(int i = 1; i <= n; i++) {
// 			for(int j = 1; j <= m; j++) {
// 				cin >> a[i][j];
// 			}
// 		}
// 		cin >> start.x >> start.y;
// 		cin >> endd.x >> endd.y;
// 		a[start.x][start.y] = 0;//把起点设为0
// 		route.push_back(start);//把起点添加进最终路径
// 		dfs(start.x, start.y);
// 		if(!flag){
// 			cout << "-1" << endl;
// 		}
// 	}
// 	return 0;
// }