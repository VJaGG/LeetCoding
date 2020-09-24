#include <iostream>
using namespace std;

// 5
// 1 2 3 4 5
// 1 3

struct ListNode{
    int val;
    ListNode* next;
};

ListNode* input(int n){
    ListNode* head = new ListNode();
    ListNode* cur = head;
    int val;
    for (int i = 0; i < n; i++){
        scanf("%d", &val);
        if (i==0){
            cur->val = val;
            cur->next = nullptr;
        }else{
            ListNode* new_node = new ListNode();
            new_node->val = val;
            new_node->next = nullptr;
            cur->next = new_node;
            cur = cur->next;
        }
    }
    return head;
}

void traverse(ListNode* head){
    while (head){
        printf("%d ", head->val);
        head = head->next;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    ListNode* head = input(n);
    traverse(head);
}