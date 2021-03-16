#include <vector>
#include <iostream>
using namespace std;

struct  ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){
    } 
};




bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }   
    }
    return false;
}

int main(){
    ListNode* head = new ListNode(3);
    ListNode* cycle = new ListNode(2);
    head->next = cycle;
    head->next->next = new ListNode(0);
    head->next->next = new ListNode(-4);
    head->next->next->next = cycle;

    bool answer = hasCycle(head);
    printf("%d\n", answer);
    return 0;

}