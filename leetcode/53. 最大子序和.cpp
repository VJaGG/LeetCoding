#include <vector>
#include <iostream>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = int(nums.size());
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int maxSub = nums[0];
    for (int i = 1; i < n; i++){
        if(dp[i-1]+nums[i] > nums[i])
            dp[i] = dp[i-1]+nums[i];
        else
            dp[i] = nums[i];
        if (maxSub<dp[i])
            maxSub=dp[i];
    }
    return maxSub;
}
int main(){
    vector<int> arr ={-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray(arr);
    printf("%d", res);
    return 0;
}