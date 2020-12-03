// 问题 D: 比较奇偶数个数
// http://codeup.cn/problem.php?cid=100000575&pid=3
#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        int num[2] = {0};
        for (int i = 0; i < n; i++){
            int temp;
            scanf("%d", &temp);
            num[temp % 2] += 1;
        }
        if (num[0] > num[1]){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}