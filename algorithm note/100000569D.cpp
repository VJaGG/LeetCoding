// http://codeup.cn/problem.php?cid=100000569&pid=3
// 问题 D: 习题6-12 解密

#include <string.h>
#include <stdio.h>
char str[100];
int main(){
    gets(str);
    for (int i = 0; i < strlen(str); i++){
        if (str[i]>=65 && str[i]<=90){
            str[i] = 155 - str[i];
        }else if (str[i]>=97 && str[i]<=122){
            str[i] = 219 - str[i];
        }
    }
    puts(str);
    return 0;
    
}