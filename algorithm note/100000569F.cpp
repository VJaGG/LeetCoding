// http://codeup.cn/problem.php?cid=100000569&pid=5
// 问题 F: 例题6-1 逆序输出数组元素

#include <stdio.h>
int main(){
    int arr[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 9; i >= 0; i--){
        printf("%d\n", arr[i]);
    }
    return 0;
}