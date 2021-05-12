#include <vector>
#include <iostream>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSub = nums[0];
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++){
        // 如果当前元素之前的和小于0，那么当前位置的最大和为当前位置的值
        // sum保存的是到当前位置的时候的最大值
        if(sum < 0){  
            // 如果当前之前的和为负数，相加的结果只能会更小
            sum = nums[i];
        }else{
            sum+=nums[i];
        }
        if(sum > maxSub){
            maxSub = sum;
        }
    }
    return maxSub;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int answer = maxSubArray(nums);
    printf("%d\n", answer);
}