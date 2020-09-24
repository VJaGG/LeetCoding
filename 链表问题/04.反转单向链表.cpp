#include <iostream>
using namespace std;

// 3
// 1 2 3
// 4
// 1 2 3 4
struct ListNode{
    int val;
    ListNode *next;
};

struct DoubleList
{
    int val;
    DoubleList* pre;
    DoubleList* next;
};

ListNode* input(int n){
    ListNode* head = new ListNode();
    ListNode* cur = head;
    int val;
    for (int i = 0; i < n; i++){
        scanf("%d", &val);
        if(i==0){
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

DoubleList* input_double(int n){
    DoubleList *head = new DoubleList();
    DoubleList *cur = head;
    int val;
    for (int i = 0; i < n; i++){
        scanf("%d", &val);
        if (i==0){
            cur->val = val;
            cur->next = nullptr;
            cur->pre = nullptr;
        }else{
            DoubleList* new_node = new DoubleList();
            new_node->val = val;
            new_node->pre = cur;
            new_node->next = nullptr;
            cur->next = new_node;
            cur = cur->next;
        }      
    }
    return head;
}

ListNode* reverse(ListNode* head){
    ListNode* pre = head;
    ListNode* cur = head->next;
    while (cur){
        ListNode* succ = cur->next;
        cur->next = pre;
        if (pre==head){
            pre->next = nullptr;
        }
        pre = cur;
        cur = succ;
    }
    return pre;
}

DoubleList* reverse_double(DoubleList* head){
    DoubleList* cur = head;
    while (cur){
        DoubleList* succ = cur->next;
        if(succ == nullptr)
            head = cur;
        cur->next = cur->pre;
        cur->pre = succ;
        cur = succ;
    }
    return head;
}

void traverse(ListNode *head){
    while (head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void traverse(DoubleList* head){
    while (head){
        printf("%d ", head->val);
        head = head->next;
    }
}

int main(){
    int m;
    scanf("%d", &m);
    ListNode* head = input(m);
    head = reverse(head);
    traverse(head);
    int n;
    scanf("%d", &n);
    DoubleList* dhead = input_double(n);
    dhead = reverse_double(dhead);
    traverse(dhead);
}

