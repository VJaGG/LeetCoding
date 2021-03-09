#include <iostream>
#include <vector>
using namespace std;


int upper_bound(vector<int> nums, int target){
    int low = 0;
    int high = nums.size();
    while (low < high){
        int mid = low + (high - low) / 2;
        if (nums[mid] > target){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return high;
}

int lower_bound(vector<int> nums, int target){
    int low = 0;
    int high = nums.size();
    while (low < high){
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return high;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()){
        return vector<int>{-1, -1};
    }
    
    vector<int> answer;
    int lower = lower_bound(nums, target);
    // 对于nums=[2, 2], target=3
    // 求其下界的时候，下界在nums.size()的位置
    
    // 对于nums=[8, 8], target=3
    // 求其下界的时候，下界在0的位置，因为不存在等于的位置，所以选出的为大于的位置
    if (lower == nums.size() || nums[lower] != target){
        return vector<int>{-1, -1};
    }
    int upper = upper_bound(nums, target) - 1;
    answer.push_back(lower);
    answer.push_back(upper);
    return answer;
}

int main(){
    vector<int> nums = {7, 7};
    int target = 3;
    vector<int> answer;
    answer = searchRange(nums, target);
    printf("%d %d\n", answer[0], answer[1]);
    return 0;
}