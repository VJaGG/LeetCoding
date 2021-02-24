#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* kth = head;
    ListNode* cur = head;
    while (k!=1){
        kth = kth->next;
        k--;
    }
    while (kth->next!=NULL){
        kth = kth->next;
        cur = cur->next;
    }
    return cur;
}
void traverse(ListNode* head){
    while (head!=NULL){
        printf("%d ", head->val);
        head = head->next;
    }    
}


int main(){
    ListNode* head= new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* answer = getKthFromEnd(head, 4);
    traverse(answer);
    return 0;
}
