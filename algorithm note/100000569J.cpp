// http://codeup.cn/problem.php?cid=100000569&pid=9
// 问题 J: 例题6-9 字符串求最大值

#include <string.h>
#include <stdio.h>

int main(){
    char str1[100], str2[100], str3[100];
    gets(str1);
    gets(str2);
    gets(str3);
    if(strcmp(str1, str2) > 0){
        if (strcmp(str1, str3) > 0){
            puts(str1);
        }else{
            puts(str3);
        }
    }else{
        if (strcmp(str2, str3) > 0){
            puts(str2);
        }else{
            puts(str3);
        }
    }
    return 0;
}