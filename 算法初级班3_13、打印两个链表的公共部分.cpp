/*
打印两个有序链表的公共部分 
	【题目】 给定两个有序链表的头指针head1和head2，打印两个链表的公共部分
*/
#include<iostream>
using namespace std;
struct node
{
	int val;
	node* next;
	node(int value) :val(value), next(nullptr){}
};
void printLinkedList(node *head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
void printCommonPart(node*head1, node*head2) {
	cout << "Common Part: " << endl;
	while (head1 && head2) {
		if (head1->val == head2->val) {
			cout << head1->val << " ";
			head1 = head1->next;
			head2 = head2->next;
		}
		else if (head1->val < head2->val) {
			head1 = head1->next;
		}
		else {
			head2 = head2->next;
		}

	}
}
//struct 与 class struct默认为public,class默认为private
int main() {
	node *head1 = new node(2);
	head1->next = new node(3);
	head1->next->next = new node(5);
	head1->next->next->next = new node(6);

	node* head2 = new node(1);
	head2->next = new node(2);
	head2->next->next = new node(5);
	head2->next->next->next = new node(7);
	head2->next->next->next->next = new node(8);

	printLinkedList(head1);
	printLinkedList(head2);
	printCommonPart(head1, head2);
	system("pause");
	return 0;



}