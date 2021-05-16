#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++){
        int curProfit = prices[i] - prices[i-1];
        if (curProfit > 0){
            profit += curProfit;
        }
    }
    return profit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int answer = maxProfit(prices);
    printf("%d\n", answer);
    return 0;
}