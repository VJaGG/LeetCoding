// http://codeup.cn/problem.php?cid=100000575&pid=5
// 问题 F: A+B和C (15)

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    long long a, b, c;
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c){
            printf("Case #%d: true\n", i);
            }
        else{
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}

// int  (-2^31 ~ 2^31)
// long long  (-2^63 ~ 2^63)