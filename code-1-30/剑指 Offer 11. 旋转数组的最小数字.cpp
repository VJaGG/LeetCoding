#include <vector>
#include <iostream>
using namespace std;

int minArray(vector<int>& numbers){
    int len = numbers.size();
    int low = len - 2;
    int high = len - 1;
    while (high > 0 && numbers[high] >= numbers[low]){
        high -- ;
        low --;
    }
    return numbers[++low];
}

int main(){
    // vector<int> numbers = {2, 2, 2, 0, 1};
    vector<int> numbers = {1, 3, 3};
    int min = minArray(numbers);
    printf("%d", min);

}