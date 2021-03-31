#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int pos){

    for (int i = pos; i < nums.size(); i++){
        int val = nums[i];
        if (i!=pos && val==nums[i-1]){  // 同层遍历中已经遍历到的数字直接略过
            continue;
        }
        path.push_back(val);
        ans.push_back(path);
        backtracking(nums, ans, path, i + 1);
        path.pop_back();
    }
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // 先对数组排序，遍历的时候方便控制同层重复的数字
    vector<vector<int>> ans;
    vector<int> path;
    ans.push_back({});
    backtracking(nums, ans, path, 0);
    return ans;
}
int main(){
    // vector<int> nums = {1, 2, 2};
    // vector<int> nums = {0};
    vector<int> nums = {4, 4, 4, 1, 4};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}