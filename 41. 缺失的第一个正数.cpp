#include <vector>
#include <iostream>
using namespace std;
int firstMissingPositive(vector<int> &nums){
    int high = int(nums.size());  //最大的可能的正整数
    int low = 0; //当前最小的正整数
    while (low < high){
        // nums[0] = 1, nums[1] = 2;
        if (nums[low] == low+1){
            low++;
        }else if(nums[low] > high || nums[low] <=low){ //不合法
            nums[low] = nums[--high];
        }else
        {   //合法但是不在正确的位置，交换到正确的位置
            swap(nums[low], nums[nums[low] - 1]);
        }
    }   
    return low+1;
}
int main(){
    vector<int> nums{2, 2};
    int missingPositive = firstMissingPositive(nums);
    printf("missing positive: %d\n", missingPositive);
    return 0;
}