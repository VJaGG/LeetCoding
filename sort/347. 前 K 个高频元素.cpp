#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    int max_counts = 0;
    for (auto num: nums){
        max_counts = max(max_counts, ++counts[num]);
    }
    vector<vector<int>> buckets(max_counts + 1);
    for (auto i: counts){
        buckets[i.second].push_back(i.first);
    }
    
    vector<int> answer;
    for (int i = max_counts; i >=0; i--){
        for (auto num: buckets[i]){
            if(answer.size() == k){
                break;
            }
            answer.push_back(num);
        }
    }
    return answer;
}

int main(){
    vector<int> nums = {1, 1, 1, 1, 2, 2, 3, 4};
    int k = 2;
    vector<int> answer = topKFrequent(nums, k);
    for (auto i: answer){
        cout<<i<<endl;
    }
    return 0;

}