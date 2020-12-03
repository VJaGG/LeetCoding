// http://codeup.cn/problem.php?cid=100000575&pid=2
// 问题 C: 特殊乘法

#include <stdio.h>
#include <string.h>

int main(){
    char str1[10];
    char str2[10];
    while(scanf("%s%s", str1, str2)!=EOF){
        int res = 0;
        for (int i = 0; i < strlen(str1); i++){
            for (int j = 0; j < strlen(str2); j++){
                res += (str1[i]-'0') * (str2[j] - '0');
            }
        }
        printf("%d\n", res);
    }
    return 0;
}