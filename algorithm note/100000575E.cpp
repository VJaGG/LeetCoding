// http://codeup.cn/problem.php?cid=100000575&pid=4
// 问题 E: Shortest Distance (20)


#include <stdio.h>

int arr[100000] = {0};
int main(){
    int n;
    int length = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        length += arr[i];
    }
    int num;
    scanf("%d", &num);
    while (num--)
    {
        int start, end;
        scanf("%d%d", &start, &end);
        int shortest = 0;
        if (start > end){
            int temp;
            temp = start;
            start = end;
            end = temp;
        }
        for (int i = start; i < end; i++){
            shortest += arr[i];
        }
        shortest = length-shortest > shortest? shortest: length-shortest;
        printf("%d\n", shortest);
    }
    return 0;
}