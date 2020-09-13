#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

ListNode* input(int n){
    ListNode *head = new ListNode();
    ListNode *cur = head;
    int val;
    for (int i = 0; i < n; i++){
        scanf("%d", &val);
        if(i==0){
            cur->val = val;
            cur->next = nullptr;
        }
        else{
            ListNode* node = new ListNode();
            node->val = val;
            node->next = nullptr;
            cur->next = node;
            cur = node;        
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


ListNode * remove_last_kth_node(ListNode * head, int k){
    ListNode* cur = head;
    ListNode* lastk = head;  
    int nums = k;
    while (nums){
        cur = cur->next;
        nums--;
    }
    while (cur->next != nullptr)
    {
        cur = cur->next;
        lastk = lastk->next;
    }
    ListNode* tmp = lastk->next;
    lastk->next = tmp->next;
    delete tmp;
    return head;
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    ListNode* head = input(n);
    ListNode* rhead = remove_last_kth_node(head, k);
    traverse(rhead);
    return 0;
}