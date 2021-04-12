#include <vector>
#include <iostream>
using namespace std;


vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (auto num: nums){
        int pos = abs(num) - 1;  //获得位置，数字存在
        if (nums[pos] > 0){
            nums[pos] = -nums[pos];
        }
    }
    for (int i = 1; i <= nums.size(); i++){
        if (nums[i-1] > 0){
            ans.push_back(i);
        }
    }
    return ans;
}
// [4,3,2,7,8,2,3,1]
// [5,6]
int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDisappearedNumbers(nums);
    for (auto i: ans){
        printf("%d ", i);
    }
    return 0;
}
