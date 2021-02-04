#include <vector>
#include <iostream>
using namespace std;

// int numWays(int n){
//     if(n==1 || n==0)
//         return 1;
//     if(n==2)
//         return 2;
    
//     return (numWays(n-1) + numWays(n-2)) % 1000000007;
// }

int numWays(int n){
    if (n==1 || n==0){
        return 1;
    }
    vector<int> num(n+1, 0);
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <=n ; i++){
        num[i] = (num[i-1] + num[i-2]) %  1000000007;
    }
    return num[n];
}

int main(){
    int n = 43;
    int res = numWays(n);
    printf("%d", res);
    return 0;
}