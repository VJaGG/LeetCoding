/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

// vector<int> reversePrint(ListNode* head) {
//     vector<int> reverse;
//     ListNode * ptr = head;
//     while (ptr!=NULL){
//         reverse.insert(reverse.begin() ,ptr->val);
//         ptr = ptr->next;
//     }
//     return reverse;
// }


int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode * ptr = head;
    while (ptr->next!=NULL){
        printf("%d-->", ptr->val);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->val);
    vector<int> reverse = reversePrint(head);
    for (int i = 0; i < reverse.size()-1; i++){
        printf("%d-->", reverse[i]);
    }
    printf("%d\n", reverse[reverse.size()-1]);
    
    return 0;
}


// 输入：head = [1,3,2]
// 输出：[2,3,1]