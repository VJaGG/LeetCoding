#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    int size = nums.size();
    for (int fast = 0; fast < nums.size(); fast++){
        if (nums[fast] != val){
            // swap(nums[fast], nums[slow]);
            nums[slow++] = nums[fast];
        }else{
            size--;
        }
    }
    return size;
}


int main(){
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int ans = removeElement(nums, val);
    printf("%d\n", ans);
    return 0;
}