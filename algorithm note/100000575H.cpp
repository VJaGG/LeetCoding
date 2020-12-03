// http://codeup.cn/problem.php?cid=100000575&pid=7
// 问题 H: 部分A+B (15)
#include <stdio.h>

int num(int A, int D_A){
    int count = 0;
    while (A){
        if(A % 10 == D_A){
            count ++;
        }
        A /= 10;
    }
    return count;
}


int main(){
    int A, D_A;
    int B, D_B;
    while(scanf("%d%d%d%d", &A, &D_A, &B, &D_B) != EOF){
        int count1 = num(A, D_A);
        int count2 = num(B, D_B);
        int num1 = 0, num2 = 0;
        while (count1--){
            num1 = num1 * 10 + D_A;
        }
        while (count2--){
            num2 = num2 * 10 + D_B;
        }
        printf("%d\n", num1 + num2);
    }
}