#include <vector>
#include <iostream>
using namespace std;


// [lo, hi) 左闭有开
int patition(vector<int>& nums, int lo, int hi){
    int pivot = nums[lo];
    while (lo < hi){
        while ((lo < hi) && (pivot <= nums[hi])){
            hi--;
        }
        nums[lo] = nums[hi];
        while ((lo < hi) && (nums[lo] <= pivot)){
            lo++;
        }
        nums[hi] = nums[lo];
    }
    nums[lo] = pivot;
    return lo;
}


// [lo, hi) 左闭有开
void quickSort(vector<int>& nums, int lo, int hi){
    if (hi - lo < 2){
        return;
    }
    int mi = patition(nums, lo, hi - 1);
    quickSort(nums, lo, mi);
    quickSort(nums, mi + 1, hi);
}

int main(){
    vector<int> nums1 = {1, 0};
    vector<int> nums2 = {1};
    vector<int> nums3 = {0, 8, 3, 9, 1, 2, 3, 1, 4};

    quickSort(nums1, 0, nums1.size());
    for(auto i: nums1){
        printf("%d ", i);
    }
    printf("\n");

    quickSort(nums2, 0, nums2.size());
    for(auto i: nums2){
        printf("%d ", i);
    }
    printf("\n");

    quickSort(nums3, 0, nums3.size());
    for(auto i: nums3){
        printf("%d ", i);
    }
    printf("\n");


    return 0;
}
