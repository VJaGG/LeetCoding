#include <vector>
#include <iostream>
using namespace std;


vector<int> twoSum(vector<int>& numbers, int target) {
    int low = 0, high = numbers.size() - 1;
    while(low < high){
        if (target == numbers[low] + numbers[high]){
            break;
        }else if (target < numbers[low] + numbers[high]){
            high--;
        }else{
            low++;
        }
    }
    return vector<int>{low + 1, high + 1};
}

int main(){

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> answer = twoSum(numbers, target);
    for (auto i: answer){
        printf("%d\n", i);
    }
    return 0;
}