#include <vector>
#include <iostream>
using namespace std;

// 左闭右开
void merge(vector<int>& nums, int lo, int mi, int hi){
    vector<int> temp((hi - lo), 0);
    int index = 0;
    int i = lo;
    int j = mi;
    while (i < mi && j < hi){
        if(nums[i] < nums[j]){
            temp[index] = nums[i];
            index++;
            i++;
        }else{
            temp[index] = nums[j];
            index++;
            j++;
        }
    }
    while (i < mi){
        temp[index] = nums[i];
        index++;
        i++;
    }
    while (j < hi){
        temp[index] = nums[j];
        index++;
        j++;
    }
    for (int k = 0; k < temp.size(); k++){
        // printf("%d\n", start);
        nums[lo + k] = temp[k];
    }   
}

void mergeSort(vector<int>& nums, int lo, int hi){
    if (hi - lo < 2){
        return;
    }
    int mi = (lo + hi) / 2;
    mergeSort(nums, lo, mi);
    mergeSort(nums, mi, hi);
    merge(nums, lo, mi, hi);
}

int main(){
    vector<int> nums1 = {1, 0};
    vector<int> nums2 = {1};
    vector<int> nums3 = {0, 8, 3, 9, 1, 2, 3, 1, 4};

    mergeSort(nums1, 0, nums1.size());
    for(auto i: nums1){
        printf("%d ", i);
    }
    printf("\n");

    mergeSort(nums2, 0, nums2.size());
    for(auto i: nums2){
        printf("%d ", i);
    }
    printf("\n");

    // for(auto i: nums3){
    //     printf("%d ", i);
    // }
    mergeSort(nums3, 0, nums3.size());
    for(auto i: nums3){
        printf("%d ", i);
    }
    printf("\n");


    return 0;
}
