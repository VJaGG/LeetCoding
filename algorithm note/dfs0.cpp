#include <iostream>
using namespace std;
const int maxn = 30;
int n, v, maxValue=0;
int w[maxn], c[maxn];  //w[i]为每件物品的重量，c[i]为每件物品的价值

//暴力递归遍历了整棵树
void DFS(int index, int sumW, int sumC){
    if (index == n){ //已经完成对n件物品的选择,到了树的底部才做决策
        if(sumW <= v  && sumC > maxValue){
            maxValue = sumC;
        }
        return;
    }
    DFS(index+1, sumW, sumC);
    DFS(index+1, sumW+w[index], sumC+c[index]);
}

void DFS2(int index, int sumW, int sumC){
    if (index == n){  //递归退出的条件
        return;
    }
    DFS2(index+1, sumW, sumC);  //当不包含当前物品的时候
    if (sumW+w[index] <= v){  //当加入当前的物品不超过maxValue的时候才继续递归
        if(sumC+c[index] > maxValue){
            maxValue = sumC+c[index];
        }
        DFS2(index+1, sumW+w[index], sumC+c[index]);        
    }
}

int main(){
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; i++){
        scanf("%d", &w[i]);  //每件物品的重量
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    DFS2(0, 0, 0);  //当前的索引，当前的重量，当前的价值
    printf("%d\n", maxValue);
    return 0;
}


// 5 8
// 3 5 1 2 2
// 4 5 2 1 3