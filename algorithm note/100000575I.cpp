// http://codeup.cn/problem.php?cid=100000575&pid=8
// 问题 I: 锤子剪刀布 (20)
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    int all=n;
    int win1 = 0, win2 = 0;
    int draw = 0;
    char dict[4] = {'B', 'C', 'J'};
    int num1[3] = {0};
    int num2[3] = {0};
    while (n--){
        char a, b, c;
        scanf("%c%c%c", &a, &c, &b);
        if (a=='B' && b=='J'){
            win2 ++;
            num2[2] ++;
        }else if (a=='B' && b=='C'){
            win1 ++;
            num1[0] ++;
        }else if (a=='C' && b=='J'){
            win1++;
            num1[1]++;
        }else if (a=='C' && b=='B'){
            win2++;
            num2[0]++;
        }else if (a=='J' && b=='C'){
            win2++;
            num2[1]++;
        }else if (a=='J' && b=='B'){
            win1++;
            num1[2]++;
        }else{
            draw++;
        }
        getchar();
    }
    printf("%d %d %d\n", win1, draw, all-win1-draw);
    printf("%d %d %d\n", win2, draw, all-win2-draw);
    int index = num1[0] >= num1[1]? 0: 1;
    index = num1[index] >= num1[2]? index: 2;
    
    int index1 = num2[0] >= num2[1]? 0: 1;
    index1 = num2[index1] >= num2[2]? index1: 2;
    printf("%c %c\n", dict[index], dict[index1]);
    return 0;
}