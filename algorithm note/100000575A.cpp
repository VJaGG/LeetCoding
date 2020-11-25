// 问题 A: 剩下的树
// http://codeup.cn/problem.php?cid=100000575&pid=0

#include <cstdio>
#include <iostream>
using namespace std;
// const int maxn = 10010;
// int istree[maxn] = {0};
// int main(){
//     int L, M;
//     while (scanf("%d%d", &L, &M) != EOF){
//         if (L == 0 && M == 0){
//             break;
//         }
//         while (M--)
//         {
//             int left, right;
//             scanf("%d%d", &left, &right);
//             for (int j = left; j <= right; j++){
//                 istree[j] = 1;
//             }
//         }
//         int count = 0;
//         for (int i = 0; i <= L; i++){
//             if (istree[i] == 0){
//                 count ++;
//             }else
//             {
//                 istree[i] = 0;
//             }
//         }
//         printf("%d\n", count);
        
//     }
//     return 0;
    
// }


int main(){
    int L, M;
    while (scanf("%d%d", &L, &M) != EOF)
    {   if (L==0)
            return 0;
    
        int tree[10010];
        fill(tree, tree+10010, 1);
        for (int i = 0; i < M; i++)
        {
            int low, high;
            scanf("%d%d", &low, &high);
            while (low <= high)
            {
                if (tree[low])
                    tree[low] = 0;
                low++;
            }
        }
        int count = 0;
        for (int i = 0; i <= L; i++)
            if(tree[i])
                count++;
        printf("%d\n", count);
    }
    return 0;
    
}