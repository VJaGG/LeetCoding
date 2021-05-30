#include <algorithm>
#include <iostream>
using namespace std;

bool judgeSquareSum(int c) {
    long low = 0;
    long high = int(sqrt(c));  // high 初始化为sqrt(c), 这样 low=0 这样 low*low + high*high = c
    while (low <=high){
        int sum = low * low + high * high; 
        if (sum == c){
            return true;
        }else if (sum < c){
            low++;
        }else{
            high--;
        }
    }
    return false;
}

int main(){
    int c = 5;
    bool answer = judgeSquareSum(c);
    printf("%d\n", answer);
    return 0;
}
