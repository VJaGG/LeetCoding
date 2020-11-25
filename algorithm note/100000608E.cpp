// 问题 E: 【递归入门】出栈序列统计
// http://codeup.cn/problem.php?cid=100000608&pid=4

#include <iostream>
using namespace std;

int n;
int count = 0;
// num栈中数据的个数
void BFS(int num, int push, int pop){
    if(push == n && pop == n){
        count++;
        return;
    }
    if (push < n){ 
        BFS(num+1, push+1, pop);
    }
    if (pop < n && num > 0){
        BFS(num-1, push, pop+1);
    }
}

int main(){
    scanf("%d", &n);
    BFS(0, 0, 0);
    printf("%d\n", count);
    return 0;

}