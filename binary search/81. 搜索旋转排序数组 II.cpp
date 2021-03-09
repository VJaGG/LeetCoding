#include <vector>
#include <iostream>
using namespace std;


bool search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end){  // 极端情况下nums中只有一个数字所以这里有等于
        int mid = start + (end - start) / 2;
        if (nums[mid] == target){
            return true;
        }

        if(nums[mid] == nums[start]){
            start++;
            continue;
        }

        if (nums[start] < nums[mid]){  // 前半部分有序
            // 如果在前半部分有序部分
            if (nums[start] <= target && target < nums[mid]){  
                end = mid;
            }else{
                start = mid;
            }
        }else{  // 否则后半部分有序
            if (nums[mid] < target && target <= nums[end]){
                start = mid;
            }else{
                end = mid;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool result = search(nums, target);
    printf("%d", result);
    return 0;

}