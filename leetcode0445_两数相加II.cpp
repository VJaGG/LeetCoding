#include<iostream>
#include<stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};
void printLinkedList(ListNode* head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	stack<int> s1, s2;
	ListNode* head = nullptr;
	ListNode* cur = nullptr;
	while (l1) {
		s1.push(l1->val);
		l1 = l1->next;
	}
	while (l2) {
		s2.push(l2->val);
		l2 = l2->next;
	}
	int carry = 0;
	int sum = 0;
	while (!s1.empty() && !s2.empty()) {

		sum = s1.top() + s2.top()+carry;
		carry = sum / 10; //调换错误，先求出进位，再计算当前位置
		sum = sum % 10;
		cur = new ListNode(sum);
		cur->next = head;
		head = cur;
		s1.pop();
		s2.pop();
	}
	while (!s1.empty())
	{
		sum = s1.top()  + carry;
		carry = sum / 10; //调换错误，先求出进位，再计算当前位置
		sum = sum % 10;
		cur = new ListNode(sum);
		s1.pop();
		cur->next = head;
		head = cur;

	}
	while (!s2.empty())
	{
		sum = s2.top() + carry;
		carry = sum / 10; //调换错误，先求出进位，再计算当前位置
		sum = sum % 10;
		cur = new ListNode(sum);
		s2.pop();
		cur->next = head;
		head = cur;

	}
	if (carry != 0) {
		cur = new ListNode(carry);
		cur->next = head;
		head = cur;

	}
	return head;

}
int main() {
	ListNode* head1 = new ListNode(7);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(4);
	head1->next->next->next = new ListNode(3);

	ListNode* head2 = new ListNode(5);
	head2->next = new ListNode(6);
	head2->next->next = new ListNode(4);

	printLinkedList(head1);
	printLinkedList(head2);
	ListNode* head = addTwoNumbers(head1, head2);
	printLinkedList(head);
	cout << "--------------------" << endl;
	head1 = new ListNode(7);
	head2 = new ListNode(5);
	printLinkedList(head1);
	printLinkedList(head2);
	head = addTwoNumbers(head1, head2);
	printLinkedList(head);
	cout << "--------------------" << endl;
	head2 = new ListNode(9);
	head2->next = new ListNode(9);
	head1 = new ListNode(1);
	printLinkedList(head1);
	printLinkedList(head2);
	head = addTwoNumbers(head1, head2);
	printLinkedList(head);
	system("pause");
	return 0;



}