#include <vector>
#include <numeric>
#include <iostream>
using namespace std;


// int numberOfArithmeticSlices(vector<int>& nums) {
//     int n = nums.size();
//     if (n < 3)
//         return 0;
//     vector<int> dp(n);  // 表示以nums[i]结尾的等差数列的个数
//     if(nums[2] + nums[0] == 2 * nums[1])
//         dp[2] = 1; 
//     for (int i = 3; i < n; i++){
//         if(nums[i] + nums[i-2] == 2 * nums[i-1]){
//             dp[i] = dp[i-1] + 1;
//         }
//     }
//     int number = 0;
//     for(auto i: dp){
//         number += i;
//     }
//     return number;
// }

int numberOfArithmeticSlices(vector<int>& nums){
    int n = nums.size();
    if(n < 3)
        return 0;
    vector<int> dp(n, 0);
    for (int i = 2; i < n; i++){
        if (nums[i] + nums[i-2] == 2 * nums[i-1]){
            dp[i] = dp[i-1] + 1;
        }
    }
    return accumulate(dp.begin(), dp.end(), 0);
    
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int number = numberOfArithmeticSlices(nums);
    printf("%d", number);
    return 0;

}