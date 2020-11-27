// http://codeup.cn/problem.php?cid=100000569&pid=2
// 问题 C: 习题6-6 杨辉三角

#include <stdio.h>

int arr[11][11] = {};
int main(){
    arr[1][1] = 1;
    int num;
    scanf("%d", &num);
    for (int i = 2; i < 11; i++){
        for (int j = 1; j <= i; j++){
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }
    for (int i = 1; i <= num; i++){
        for (int j = 1; j <= i; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");        
    }   
}