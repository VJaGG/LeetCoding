// http://codeup.cn/problem.php?cid=100000569&pid=7
// 问题 H: 例题6-3 冒泡排序

#include <stdio.h>

int main(){
    int arr[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9 - i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    }
    for (int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }
}