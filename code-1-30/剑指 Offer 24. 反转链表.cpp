/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* reverseList(ListNode* head) {
    if (head==NULL){
        return NULL;
    }
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur->next!=NULL){
        ListNode* n = cur->next;
        cur->next = pre;
        pre = cur;
        cur = n;   
    }
    cur->next = pre;
    return cur;
}

void traverse(ListNode* root){
    while (root!=NULL){
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}

int main(){
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    traverse(root);
    ListNode* reverse = reverseList(root);
    traverse(reverse);
    
    return 0;
}
