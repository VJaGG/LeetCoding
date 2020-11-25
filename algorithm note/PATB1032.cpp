// https://pintia.cn/problem-sets/994805260223102976/problems/994805289432236032
#include <cstdio>
const int maxn = 100010;
int schools[maxn] = {0};
int main(){
    int n, schID, score;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &schID, &score);
        schools[schID] += score;
    }
    int k = 1, MAX = -1;  //最高总分的学校以及
    for (int i = 1; i <= n; i++)
    {
        if (schools[i] > MAX)
        {
            MAX = schools[i];
            k = i; 
        }
        
    }
    printf("%d %d\n", k, MAX);
    return 0;
}