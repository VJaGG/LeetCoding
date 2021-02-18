#include <vector>
#include <iostream>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = int(nums.size());
    if (n==0)
        return 0;
    
    vector<int> dp(n, 1);
    int maxLen = dp[0];

    for (int i = 1; i < nums.size(); i++)
    { 
        for (int j = 0; j < i; j++)
        {
            if(nums[j] <= nums[i] && dp[j]+1 > dp[i])
                dp[i] = dp[j] + 1;
        }  
        if (dp[i]>maxLen)
            maxLen = dp[i];      
    }
    return maxLen;
    
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
    int res = lengthOfLIS(arr);
    printf("%d", res);
    return 0;
    

}