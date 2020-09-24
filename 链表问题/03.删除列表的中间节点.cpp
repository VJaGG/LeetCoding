// 5 3
// 1 2 3 4 5

#include <iostream>
using namespace std;

struct  ListNode{
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
            cur->next = nullptr;
            cur->val = val;
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

void traverse(ListNode * head){
    while (head){
        printf("%d ", head->val);
        head = head->next;
    }
}

ListNode* remove_kth_node(ListNode* head, int k){
    ListNode* pre = head;
    ListNode* cur = head->next;
    if (k == 1){
        delete pre;
        return cur;
    }
    while (k-2 > 0){
        pre = cur;
        cur = cur->next;
        k--;
    }
    pre->next = cur->next;
    delete cur;
    return head;
}



int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    ListNode* head = input(n);
    head = remove_kth_node(head, k);
    traverse(head);


}