#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


vector<int> printNumbers(int n) {
    int max = pow(10, n) - 1;
    vector<int> answer;
    for (int i = 1; i <= max; i++){
        answer.push_back(i);
    }
    return answer;
}
int main(){
    int n = 3;
    vector<int> answer = printNumbers(n);
    for (auto i: answer){
        printf("%d\n", i);
    }
    return 0;
    

}