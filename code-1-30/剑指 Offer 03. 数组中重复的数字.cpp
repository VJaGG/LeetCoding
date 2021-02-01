#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


// [2, 3, 1, 0, 2, 5, 3]
// int findRepeatNumber(vector<int>& nums){
//     vector<int> counts(nums.size(), 0);
//     for (int i = 0; i < nums.size(); i++){
//         counts[nums[i]] ++;
//         if(counts[nums[i]] == 2){
//             return nums[i];
//         }
//     }
//     return -1;
// }

// int findRepeatNumber(vector<int>& nums){
//     int repeat = -1;
//     set<int> numbers;
//     for (auto number: nums){
//         if (numbers.find(number) != numbers.end()){
//             return number;
//         }
//         numbers.insert(number);
//     }
//     return repeat;
// }

int findRepeatNumber(vector<int> &nums){
    unordered_map<int, int> mp;
    for (auto num: nums){
        if (mp.find(num) != mp.end()){
            return num;
        }else{
            mp[num]++;
        }       
    }
    return -1;
}



int main(){
    vector<int> arr = {2, 3, 1, 0, 2, 5, 3};
    int number = findRepeatNumber(arr);
    printf("%d\n", number);
    
    return 0;
}