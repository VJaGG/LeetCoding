#include <vector>
#include <iostream>
using namespace std;


// 000000000000000
// 边界条件仔细考虑
int wiggleMaxLength(vector<int>& nums) {
    if(nums.size()==1){
        return nums.size();
    }
    int pre = 0;
    int length = 1;
    for (int i = 1; i < nums.size(); i++){
        int cur = nums[i] - nums[i-1];
        if ((pre>=0 && cur<0) || (pre<=0 && cur>0)){
            length++;
            pre = cur;
        }  
    }
    return length;
}


int main(){
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    int answer = wiggleMaxLength(nums);
    printf("%d\n", answer);
    return 0;
}