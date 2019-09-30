
//辅助空间，链表结构
//进阶：如果链表长度为N，时间复杂度达到O(N)，额外空间复杂度为O(1)
//coding能力
//快慢指针，慢指针一次走一次，快指针一次走两次，当快指针结尾的时候，慢指针在中间
//后面的反转链表的方向O(N),边界条件
//使用额外空间一种情况，不适用一种
/*
判断一个链表是否为回文结构
【题目】 给定一个链表的头节点head，请判断该链表是否为回 文结构。
例如： 1->2->1，返回true。 1->2->2->1，返回true。 15->6->15，返回true。 1->2->3，返回false。
进阶： 如果链表长度为N，时间复杂度达到O(N)，额外空间复杂 度达到O(1)。
*/
#include<stack>
#include<iostream>
using namespace std;
struct node
{
	int val;
	node* next;
	node(int x) :val(x), next(nullptr) {}
};
bool isPalindrome(node* head) {
	stack<int> help;
	node* ptr;
	ptr = head;
	while (ptr) {
		help.push(ptr->val);
		ptr = ptr->next;
	}
	while (!help.empty()) {
		if (help.top() != head->val)
			return false;
		help.pop();
		head = head->next;
	}
	return true;
}
bool isPalindrome1(node* head) {
	stack<int> help;
	node* fast=head;
	node* slow=head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = slow->next;
	while (slow) {
		help.push(slow->val);
		slow = slow->next;
	}
	while (!help.empty()) {
		if (help.top() != head->val)
			return false;
		help.pop();
		head = head->next;
	}
	return true;
}
int main() {
	node* head = new node(1);
	head->next = new node(2);
	head->next->next = new node(2);
	head->next->next->next = new node(1);
	bool res = isPalindrome1(head);
	cout << res << endl;
	system("pause");
	return 0;
}
