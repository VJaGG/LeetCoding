// http://codeup.cn/problem.php?cid=100000569&pid=1
// 问题 B: 习题6-5 数组元素逆置

#include <stdio.h>
int main(){
    int arr[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 5; i++){
        int temp = arr[i];
        arr[i] = arr[9 - i];
        arr[9 - i] = temp; 
    }
    for (int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}