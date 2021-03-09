#include <vector>
#include <iostream>
using namespace std;

// 输入: nums = [-1,0,3,5,9,12], target = 2
// 输出: -1
// 解释: 2 不存在 nums 中因此返回 -1

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low < high){
        int mid = (low + high) / 2;
        if (nums[mid]==target){
            return mid;
        }
        if (nums[mid] < target){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = -1;
    for(auto i: nums){
        printf("%d ", i);
    }
    printf("\n");
    int index = search(nums, target);


    printf("%d", index);
    return 0;

}