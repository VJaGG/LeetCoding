#include <vector>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode *detectCycle(ListNode *head){
    ListNode *slow = head, *fast = head;
    if (!fast){
        return NULL;
    }
    
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            fast = head;
            while (fast!=slow){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return NULL;

}


int main(){
    ListNode* head = new ListNode(3);
    ListNode* cycle = new ListNode(2);
    head->next = cycle;
    head->next->next = new ListNode(0);
    head->next->next = new ListNode(-4);
    head->next->next->next = cycle;
    ListNode* answer = detectCycle(head);
    bool result = (cycle == answer);
    printf("%d", result);
    return 0;
}