#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    int steps = 0;
    while (n != 1)
    {
        if(n % 2 != 0){
            n = 3 * n + 1;
        }
        n /= 2;
        steps++;
    }
    printf("%d", steps);
    return 0;
}