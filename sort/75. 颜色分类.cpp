#include <vector>
#include <iostream>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high){
        while (low < high && nums[high] == 2){
            high--;
        }
        while (low < high && nums[low] != 2){
            low++;
        }
        swap(nums[high], nums[low]);
    }
    low = 0;
    while (low < high){
        while (low < high && nums[high] == 1){
            high--;
        }
        while (low < high && nums[low] != 1){
            low++;
        }
        swap(nums[high], nums[low]);
    }  
}

int main(){
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (auto i: nums){
        printf("%d", i);
    }
    
}