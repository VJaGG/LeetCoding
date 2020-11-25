#include <vector>
#include <iostream>
using namespace std;
const int maxn = 15;
int graph[maxn][maxn];
int global_x, global_y;
int px[] = {0, -1, 0, 1};
int py[] = {-1, 0, 1, 0}; 
int flag = 0;
struct point
{
    int x;
    int y;
    point(int x_, int y_): x(x_), y(y_){}
};
vector<point> path;


void search(int x, int y){
    if (x==global_x && y==global_y){
        printf("(%d,%d)", path[0].x, path[0].y);
        for (int i = 1; i < path.size(); i++){
            printf("->(%d,%d)", path[i].x, path[i].y);
        }
        flag = 1;
        printf("\n");
        return;
    }
    for (int i = 0; i < 4; i++){  //判断当前层的节点，上一层的已经处理完毕
        if (graph[x+px[i]][y+py[i]] == 1){
            /* code */
            path.push_back(point(x+px[i], y+py[i]));
            graph[x+px[i]][y+py[i]] = 0;
            search(x+px[i], y+py[i]);
            path.pop_back();
            graph[x+px[i]][y+py[i]] = 1;
        }
    }
}

int main(){
    int m, n;
    int start_x, start_y;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    scanf("%d%d", &start_x, &start_y);
    scanf("%d%d", &global_x, &global_y);
    graph[start_x][start_y] = 0;
    path.push_back(point(start_x, start_y));
    search(start_x, start_y);
    if (flag == 0){
        printf("%d", -1);
    }
    
    return 0;
}