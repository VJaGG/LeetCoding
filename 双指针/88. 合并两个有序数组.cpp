#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int ptr = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n>=0){
        nums1[ptr--] = nums1[m] > nums2[n]? nums1[m--]: nums2[n--];
    }
    while (m >= 0){
        nums1[ptr--] = nums1[m--];
    }
    while (n >= 0){
        nums1[ptr--] = nums2[n--];
    }
    
    
}


int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    for (auto i: nums1){
        printf("%d ", i);
    }
    return 0;
    
}