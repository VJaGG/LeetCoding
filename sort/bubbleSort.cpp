#include <vector>
#include <iostream>
using namespace std;

// 左闭右开
void bubbleSort(vector<int>& nums, int lo, int hi){
    for (int i = lo; i < hi - 1; i++){
        bool sorted = true;
        for (int j = lo; j < hi- (i - lo) - 1; j++){
            if (nums[j] > nums[j + 1]){
                sorted = false;
                swap(nums[j], nums[j + 1]);
            }
        }
        if(sorted){
            return;
        }
    }
}


int main(){
    vector<int> nums1 = {1, 0};
    vector<int> nums2 = {1};
    vector<int> nums3 = {0, 8, 3, 9, 1, 2, 3, 1, 4};

    bubbleSort(nums1, 0, nums1.size());
    for(auto i: nums1){
        printf("%d ", i);
    }
    printf("\n");

    bubbleSort(nums2, 0, nums2.size());
    for(auto i: nums2){
        printf("%d ", i);
    }
    printf("\n");

    // for(auto i: nums3){
    //     printf("%d ", i);
    // }
    bubbleSort(nums3, 0, nums3.size());
    for(auto i: nums3){
        printf("%d ", i);
    }
    printf("\n");


    return 0;
}
