#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    // ListNode(int x): val(x), next(nullptr){}
};

ListNode* input(void){
    int n, val;
    ListNode* head = new ListNode();
    ListNode* cur = head;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
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

void solution(ListNode* a_head, ListNode* b_head){
    while (a_head!=nullptr & b_head!=nullptr){
        if (a_head->val==b_head->val){
            printf("%d ", a_head->val);
            a_head = a_head->next;
            b_head = b_head->next;
        }
        else if(a_head->val > b_head->val){
            b_head = b_head->next;
        }
        else{
            a_head = a_head->next;
        }
    }
}

int main(){
    ListNode* a = input();
    ListNode* b = input();
    solution(a, b);
    return 0;
}