#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x==0){
        return 0;
    }
    int low = 1, high = x, mid, sqrt;
    while (low <= high){
        // mid = (low + high) / 2;  // mid * mid 溢出
        mid = low + (high - low) / 2;  // 防止溢出
        sqrt = x / mid;
        if (sqrt == mid){  // mid * mid 同样也会溢出
            return mid;
        }else if (sqrt < mid){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return high;
}



int main(){

    int x = 8;
    int answer = mySqrt(x);
    printf("%d ", answer);
    return 0;
}