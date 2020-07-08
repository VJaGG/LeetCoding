#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10010;
int dp[maxn];
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int len = triangle[n-1].size();
    for (int i = 0; i < len; i++){
        dp[i] = triangle[n-1][i];
    }
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 0; j <= i;j++)
            dp[j] = dp[j] > dp[j+1] ? dp[j] + triangle[i][j] :  dp[j+1] + triangle[i][j];
    }
    return dp[0];
}

int main(){
    int n;
    scanf("%d", &n);
    int temp;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++){
            int temp;
            scanf("%d", &temp);
            arr[i][j] = temp;
        }
    }
    int res = minimumTotal(arr);
    printf("%d\n", res);
    return 0;

}