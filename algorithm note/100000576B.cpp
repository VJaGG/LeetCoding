// http://codeup.cn/problem.php?cid=100000576&pid=1
// 问题 B: 找x

#include <stdio.h>
#include <iostream>
using namespace std;
const int maxn = 210;
int arr[maxn] = {0};
int main(){
    int n;
    int find;
    while (scanf("%d", &n) != EOF){
        bool flag = false;
        // fill(arr, arr+210, 0);
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        scanf("%d", &find);
        for (int i = 0; i < n; i++){
            if (arr[i] == find){
                flag = true;
                printf("%d\n", i);
                break;
            }
        }
        if (!flag){
            printf("-1\n");
        }
    }
}