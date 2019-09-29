#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	while (l1 && l2)
	{
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
			cur = cur->next;
			cur->next = nullptr;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
			cur = cur->next;
			cur->next = nullptr;
		}
	}
	if (l1) {
		cur->next = l1;
	}
	if (l2) {
		cur->next = l2;
	}
	cur = head;
	head = head->next;
	delete cur;
	return head;
}
void printLinkedList(ListNode *head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(4);

	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(3);
	head2->next->next = new ListNode(4);

	printLinkedList(head1);
	printLinkedList(head2);
	ListNode* head = mergeTwoLists(head1, head2);
	printLinkedList(head);
	system("pause");
	return 0;
}