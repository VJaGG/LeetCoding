#include <vector>
#include <iostream>
using namespace std;
/*
void backtrack(int n, vector<int>& nums, vector<vector<int>> &res, int first) {
	if (first == n)
		res.push_back(nums);
	for (int i = first; i <= n; i++) {
		swap(nums[first], nums[i]); 
		backtrack(n, nums, res, first + 1);
		swap(nums[first], nums[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	backtrack(nums.size() - 1, nums, res, 0);
	return res;
}
*/
void backtrack(vector<vector<int>>& res,vector<int>& nums, vector<int>& perm, int depth, vector<bool>& used) {
	if (depth == nums.size())
		res.push_back(perm);
	for (int i = 0; i < nums.size(); i++) {
		if (used[i])
			continue;
		used[i] = true;
		perm[depth] = nums[i];
		backtrack(res, nums, perm, depth + 1, used);
		used[i] = false;
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> perm(nums.size());
	vector<bool> used(nums.size(), false);
	backtrack(res, nums, perm, 0, used);
	return res;
}
int main() {
	vector<int> nums = { 1, 2, 3, 4 };
	vector<vector<int>> res = permute(nums);
	for (auto i : res) {
		for (int j = 0; j < i.size(); j++)
			cout << i[j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}