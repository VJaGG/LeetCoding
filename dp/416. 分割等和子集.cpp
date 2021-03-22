#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canPartition1(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2){
        return false;
    }
    int target = sum / 2, n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    for (int i = 1; i <= n; i++){
        int value = nums[i-1];
        for (int j = 1; j <= target; j++){
            if(j >= value){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-value] + value);
            }else{
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    return dp[n][target] == target ? true : false;
}

bool canPartition(vector<int>& nums){
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2){
        return false;
    }

    int target = sum / 2;
    vector<int> dp(20001, 0);
    for (int i = 1; i <= nums.size(); i++){
        int value = nums[i-1];
        for (int j = target; j >= value; j--){
            dp[j] = max(dp[j], dp[j-value] + value);
        }
    }
    return dp[target] == target ? true : false;
}

int main(){
    vector<int> nums = {1, 5, 11, 5};
    bool answer = canPartition(nums);
    printf("%d", answer);
    return 0;

}