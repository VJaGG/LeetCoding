#include <iostream>
using namespace std;
// int fib(int n){
//     if(n==0)
//         return 0;
//     if(n==1)
//         return 1;
//     return fib(n-1) + fib(n-2);
// }

int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int n1 = 0;
    int n2 = 1;
    for (int i = 2; i <= n ; i++){
        int temp = n2;
        n2 = (n1 + n2) % 1000000007;  // 这里为什么
        n1 = temp;
    }
    return n2 % 1000000007;
}


int main(){
    int n = 2;
    int res = fib(2);
    printf("%d", res);
    return 0;
}