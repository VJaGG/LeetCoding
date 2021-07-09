#include <vector>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };



ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* l = new ListNode(0);
    ListNode* ptr = l;
    ListNode* ptr1 = l1;
    ListNode* ptr2 = l2;
    while (ptr1 && ptr2){
        if (ptr1->val > ptr2->val){
            ptr->next = ptr2;
            ptr2 = ptr2->next;
        }else{
            ptr->next = ptr1;
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
    if (ptr1){
        ptr->next = ptr1;
    }
    if (ptr2){
        ptr->next = ptr2;
    }
    return l->next;
}


int main(){
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l = mergeTwoLists(l1, l2);
    while (l){
        printf("%d\n", l->val);
        l = l->next;
    }
    return 0;

}