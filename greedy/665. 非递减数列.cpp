#include <vector>
#include <iostream>
using namespace std;


bool checkPossibility(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++){
        if(i == 0 && nums[i] > nums[i+1]){  // 为0的时候需要分开考虑
            nums[i] = nums[i+1];
            count++;
        }
        if(nums[i] > nums[i+1]){
            if (nums[i-1] > nums[i+1]){
                nums[i+1] = nums[i];
            }else{
                nums[i] = nums[i-1];
            }
            count++;
        }
    }
    return count > 1?false: true;
}

int main(){
    vector<int> nums = {-1, 4, 2, 3};
    bool answer = checkPossibility(nums);
    printf("%d", answer);
    return 0;
}