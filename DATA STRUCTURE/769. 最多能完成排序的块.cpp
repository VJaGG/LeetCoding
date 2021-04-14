#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0, cur_max = 0;
    for (int i = 0; i < arr.size(); i++){
        cur_max = max(cur_max, arr[i]);
        // 如果当前最大值大于数组位置，则说明右边一定有小于数组位置的数字。
        // 需要把它也加入待排序的数组
        if (cur_max == i){
            chunks ++;
        }
    }
    return chunks;
}

int main(){
    vector<int> arr = {1, 0, 2, 3, 4};

    int chunks = maxChunksToSorted(arr);
    printf("%d\n", chunks);
    return 0;
}