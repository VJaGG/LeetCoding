#include <stack>
#include <iostream>
using namespace std;

class MinStack {
    stack<int> s, m;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        if (s.empty()){
            m.push(val);
        }else{
            if (m.top() <= val){
                m.push(m.top());
            }else{
                m.push(val);
            }
        }
        s.push(val);
    }
    
    void pop() {
        s.pop();
        m.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    int m = minStack->getMin();
    minStack->pop();
    int t = minStack->top();
    int m1 = minStack->getMin();
    printf("%d %d %d", m, t, m1);
    return 0;

}