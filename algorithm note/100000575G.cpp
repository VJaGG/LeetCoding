#include <stdio.h>


int main(){
    int n;
    while (scanf("%d", &n)!=EOF){

        int temp;
        bool a = false, aa = false, aaa = false, aaaa = false, aaaaa = false;
        int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, pos = 1, num = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &temp);
            int remainder = temp % 5;
            if (remainder == 0 && temp % 2 == 0){
                a = true;
                a1 += temp;
            }else if (remainder == 1){
                aa = true;
                temp = pos * temp;
                pos = pos * -1;
                a2 += temp;
            }else if (remainder == 2){
                a3 ++;
                aaa = true;
            }    
            else if (remainder == 3){
                aaaa = true;
                a4 += temp;
                num ++;
            }else if (remainder == 4){
                aaaaa = true;
                a5 = a5 > temp? a5: temp;
            }      
        }
        if (a){
            printf("%d ", a1);
        }else{
            printf("N ");
        }
        if (aa){
            printf("%d ", a2);
        }else{
            printf("N ");
        }
        if (aaa){
            printf("%d ", a3);
        }else{
            printf("N ");
        }
        if (aaaa){
            printf("%0.1f ", a4 * 1.0 / num);
        }else{
            printf("N ");
        }
        if (aaaaa){
            printf("%d ", a5);
        }else{
            printf("N\n");
        }
    }
}