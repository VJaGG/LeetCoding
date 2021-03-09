#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (nums[mid] == target){ 
            return mid;
        }
        if (nums[mid] == nums[start]){
            start ++;
            continue;
        }

        if (nums[start] < nums[mid]){
            if (nums[start] <= target && target < nums[mid]){
                end = mid;
            }else{
                start = mid;
            }
        }else{
            if (nums[mid] < target && target <= nums[end]){
                start = mid;
            }else{
                end = mid;
            }
        }    
    }
    return -1;
    
}

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    int index = search(nums, target);
    printf("%d\n", index);
    return 0;
}