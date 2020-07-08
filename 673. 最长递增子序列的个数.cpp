#include <vector>
#include <iostream>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = int(nums.size());
    if (n==0)
        return 0;
    vector<int> dp(n, 1); //以nums[i]结尾的序列长度
    vector<int> counts(n, 1);
    int maxLen = dp[0];
    for (int i = 1; i < n; i++) //以i结尾
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i]){
                if (dp[j] >= dp[i]){  //第一次碰到
                    dp[i]=dp[j]+1;
                    counts[i]=counts[j];
                }
                else if (dp[j]+1==dp[i])
                    counts[i]+=counts[j];
            }                
        }
        if(maxLen<dp[i])
            maxLen=dp[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i]==maxLen)
            count+=counts[i];
    }
    return count;
}

int main(){
    vector<int> arr;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    int res = findNumberOfLIS(arr);
    printf("%d", res);
    return 0;
}