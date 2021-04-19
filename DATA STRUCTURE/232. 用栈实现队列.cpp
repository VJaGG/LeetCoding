#include <stack>
#include <iostream>
using namespace std;


class MyQueue {
    stack<int> in, out;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty()){
            while (!in.empty()){
                int top = in.top();
                out.push(top);
                in.pop();
            }
        }
        int top = out.top();
        out.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(out.empty()){
            while (!in.empty()){
                int top = in.top();
                out.push(top);
                in.pop();
            }
        }
        int top = out.top();
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(in.empty() && out.empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(2);
    int param_2 = myQueue->peek();
    int param_3 = myQueue->pop();
    bool param_4 = myQueue->empty();
    printf("%d %d %d", param_2, param_3, param_4);
    return 0;
}