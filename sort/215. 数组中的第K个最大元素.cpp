#include <vector>
#include <iostream>
using namespace std;

int quickSelection(vector<int>& nums, int low, int high){
    int pivot = nums[low];
    while (low < high){
        while (low < high && pivot<=nums[high]){
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot){
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}   


int findKthLargest(vector<int>& nums, int k) {
    int low = 0, high = nums.size() - 1, target = nums.size() - k; 
    while (low < high){
        int mid = quickSelection(nums, low, high);
        if (mid == target){
            return nums[mid];
        }else if (mid < target){
            low = mid + 1;
        }else{
             high = mid - 1;
        }
    }
    return nums[low];
}

int main(){
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int answer = findKthLargest(nums, k);
    printf("%d", answer);
    return 0;
}