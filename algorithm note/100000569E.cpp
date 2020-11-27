// http://codeup.cn/problem.php?cid=100000569&pid=4
// 问题 E: 习题6-13 字符串比较

#include <stdio.h>
#include <string.h>
int main(){
    char str1[100], str2[100];
    gets(str1);
    gets(str2);
    int len = strlen(str1) > strlen(str2)? strlen(str2) : strlen(str1);
    for (int i = 0; i < len; i++){
        if (str1[i] != str2[i]){
            printf("%d", str1[i] - str2[i]);
            break;
        }
    }
    return 0;
}