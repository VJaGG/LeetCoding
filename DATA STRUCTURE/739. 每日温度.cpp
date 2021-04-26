#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> answer = vector<int>(T.size(), 0);
    stack<int> s;
    for (int i = 0; i < T.size(); i++){
        while (!s.empty() && T[s.top()] < T[i]){  // 单调栈中存储的元素始终是从小到大的
                                                  // 栈顶元素为最小元素，栈底元素为最大元素
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return answer;
}

int main(){
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> answer = dailyTemperatures(temperatures);
    for (int i = 0; i < answer.size(); i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}