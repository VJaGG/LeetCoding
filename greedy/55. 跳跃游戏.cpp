#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


bool canJump(vector<int>& nums){
    int cover = 0;
    for(int i=0; i<=cover; i++){
        cover = max(cover, nums[i] + i);
        if (cover >= nums.size()-1){
            return true;
        }
    }
    return false;
}


int main(){
    vector<int> nums = {0};
    bool answer = canJump(nums);
    printf("%d", answer);
    return 0;
}
