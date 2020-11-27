// http://codeup.cn/problem.php?cid=100000569&pid=6
// 问题 G: 例题6-2 数组求解Fibonacci数列问题

#include <stdio.h>

int main(){
    int arr[20];
    arr[0] = 1, arr[1] = 1;
    for (int i = 2; i < 20; i++){
        arr[i] = arr[i-1] + arr[i-2]; 
    }
    for (int i = 0; i < 20; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
    
}