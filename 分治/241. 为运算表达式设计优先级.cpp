#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> diffWaysToCompute(string expression) {
    vector<int> ways;
    for (int i = 0; i < expression.size(); i++){  // 考虑极端的情况，当输入只为一个数字时候
        char c = expression[i];
        if (c=='+' || c=='-' || c=='*'){
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i+1));
            for (int l: left){
                for (int r: right){
                    if (expression[i]=='+'){
                        ways.push_back(l + r);
                    }else if(expression[i]=='-'){
                        ways.push_back(l - r);
                    }else{
                        ways.push_back(l * r);
                    }
                }
            }
        }
    }
    if(ways.empty()){ //当ways为空的时候只有一个数字
        ways.push_back(stoi(expression));
    }
    return ways; 
}

int main(){
    string expression = "2*3-4*5";
    vector<int> ans = diffWaysToCompute(expression);
    for (auto i: ans){
        printf("%d\n", i);
    }
    return 0;
}