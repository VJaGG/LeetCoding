#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


int cuttingRope(int n) {
    vector<int> dp(n+1);
    dp[2] = 1;
    for (int i = 3; i <= n; i++){
        for (int j = 1; j <= i-1; j++){ // 切分出j的长度
            dp[i] = max(dp[i], max(j * dp[i-j], j * (i-j)));
        }
    }
    return dp[n];
}

int main(){
    int n = 10;
    int answer = cuttingRope(n);
    printf("%d\n", answer);
    return 0;
}