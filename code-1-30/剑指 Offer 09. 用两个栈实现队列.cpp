#include <stack>
#include <iostream>
using namespace std;


class CQueue {
    stack<int> input;
    stack<int> output;
    public:
        CQueue() {
        }
        
        void appendTail(int value) {
            input.push(value);
        }
        
        int deleteHead() {
            if (!output.empty()){
                int top = output.top();
                output.pop();
                return top;
            }
            while (!input.empty()){
                int top = input.top();
                input.pop();
                output.push(top);
            }
            if (output.empty()){
                return -1;
            }else{
                int top = output.top();
                output.pop();
                return top;
            }
        }
};

// 输入：
// ["CQueue","appendTail","deleteHead","deleteHead"]
// [[],[3],[],[]]
// 输出：[null,null,3,-1]

int main(){
      CQueue* obj = new CQueue();
        obj->appendTail(3);
        int param_2 = obj->deleteHead();

}