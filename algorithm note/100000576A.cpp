// http://codeup.cn/problem.php?cid=100000576&pid=0
// 问题 A: 统计同成绩学生人数

#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const int maxn = 100;
int grad[maxn] = {0};
int main(){
    int N;
    int find;
    while (scanf("%d", &N)!=EOF && N!=0){
        int temp;
        memset(grad, 0, sizeof(grad));
        // fill(grad, grad+100, 0);
        for (int i = 0; i < N; i++){    
            scanf("%d", &temp);
            grad[temp]++;
        }
        scanf("%d", &find);
        printf("%d\n", grad[find]);
    }
    return 0;    
}