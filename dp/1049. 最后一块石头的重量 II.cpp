#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int lastStoneWeightII(vector<int>& stones) {
    int total = accumulate(stones.begin(), stones.end(), 0);  // 石头尽量平均分成两份这样结果就比较准确
    int target = total / 2;  // 目标重量
    vector<int> dp(target + 1, 0);

    for (int i = 1; i <= stones.size(); i++){
        int value = stones[i-1];
        for (int j = target; j >= value; j--){
            dp[j] =  max(dp[j], dp[j-value] + value);
        }
    }

    return total - dp[target] - dp[target];
    
}

int main(){
    vector<int> stones = {2, 7, 4, 1, 8, 1};


    int answer = lastStoneWeightII(stones);
    printf("%d\n", answer);
    return 0;
}