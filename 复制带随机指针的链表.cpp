#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node* random;
	Node(){}
	Node(int _val) :val(_val), next(nullptr), random(nullptr) {}
	Node(int _val,Node*_next,Node*_random):val(_val),next(_next),random(_random){}
};
void printRandLinkedList(Node* head) {
	Node *cur = head;
	cout << "order: " << endl;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	cur = head;
	cout << "random: " << endl;
	while (cur) {
		if (cur->random == nullptr)
			cout << "_ ";
		else
			cout << cur->random->val << " ";

		cur = cur->next;
	}
	cout << endl;
}

//方法一
Node* copyRandomList(Node* head) {
	unordered_map<Node*, Node*> map;
	Node* cur = head;
	while (cur) {
		map[cur] =new Node(cur->val, nullptr, nullptr);
		cur = cur->next;
	}
	cur = head;
	while (cur) //再重新遍历一遍链表
	{
		if(cur->next)
			map[cur]->next = map[cur->next];
		if(cur->random)
			map[cur]->random = map[cur->random];
		cur = cur->next;
	}
	return map[head];
}
Node* copyRandomList1(Node *head) {
	unordered_map<Node*, Node*> map;
	Node* ptr = head;
	while (ptr)
	{
		Node* copy = new Node();
		copy->val = ptr->val;
		copy->next = nullptr;
		copy->random = nullptr;
		map[ptr] = copy;
		ptr = ptr->next;
	}

	for (auto iter = map.begin(); iter!=map.end(); iter++)
	{//遍历的是map
		Node* origin = iter->first;
		Node* copy = iter->second;
		Node* next = origin->next;
		Node* random = origin->random;
		if(next)  //边界条件考虑next和random为空的情况
			copy->next = map[next];
		if(random)
			copy->random = map[random];
	}
	return map[head];
}

//方法二
Node* copyRandomList2(Node *head) {
	if (head == nullptr)
		return nullptr;
	Node* cur = head;
	while (cur)
	{
		Node* copy = new Node(cur->val, nullptr, nullptr);
		Node* next = cur->next;
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	cur = head;
	head = cur->next;
	while (cur) {
		Node* copy = cur->next;
		copy->random = cur->random ? cur->random->next : nullptr;
		cur = copy->next;
		copy->next = cur ? cur->next : nullptr;

	}
	return head;
}
Node* copyRandomList3(Node *head) {//leetcode原题中因为是copy所以不可以修改原来链表的指针。
	if (head == nullptr)
		return nullptr;
	Node* cur = head;
	while (cur)
	{
		Node* copy = new Node(cur->val, nullptr, nullptr);
		Node* next = cur->next;
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	cur = head;
	while (cur) {
		Node* copy = cur->next;
		copy->random = cur->random ? cur->random->next : nullptr;
		cur = copy->next;
	}
	cur = head;
	head = cur->next;
	while (cur) {
		Node* copy = cur->next;
		cur->next = copy->next;
		cur = copy->next;
		copy->next = cur ? cur->next : nullptr;
	}
	return head;
}
/*{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
{"$id":"1","next":{"$id":"2","next":{"$id":"3","next":{"$id":"4","next":{"$id":"5","next":null,"random":{"$ref":"1"},"val":4},"random":null,"val":-3},"random":null,"val":7},"random":{"$ref":"4"},"val":8},"random":{"$ref":"5"},"val":-1}
*/
int main() {

	Node* head = nullptr;
	Node* res1 = nullptr;
	printRandLinkedList(head);
	res1 = copyRandomList2(head);
	printRandLinkedList(res1);


	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	
	head->random = head->next->next->next->next->next; //1->6
	head->next->random = head->next->next->next->next->next;//2->6
	head->next->next->random = head->next->next->next->next;//3->5
	head->next->next->next->random = head->next->next; // 4 -> 3
	head->next->next->next->next->random = nullptr; // 5 -> null
	head->next->next->next->next->next->random = head->next->next->next; // 6 -> 4
	printRandLinkedList(head);
	res1 = copyRandomList2(head);
	printRandLinkedList(res1);

	head = new Node(1); //1->2->3->4
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);

	head->random = head->next->next;  
	head->next->random = head->next->next;
	printRandLinkedList(head);
	res1 = copyRandomList2(head);
	printRandLinkedList(res1);

	head = new Node(1);
	head->next = new Node(2);
	head->random = head->next;
	head->next->random = head->next;
	printRandLinkedList(head);
	res1 = copyRandomList2(head);
	printRandLinkedList(res1);

	head = new Node(-1);
	head->next = new Node(8);
	head->next->next = new Node(7);
	head->next->next->next = new Node(-3);
	head->next->next->next->next = new Node(4);

	head->random = head->next->next->next->next; //-1->4
	head->next->random = head->next->next->next;//8->-3
	head->next->next->random = nullptr;//7->null
	head->next->next->next->random = nullptr; // -3 -> null
	head->next->next->next->next->random = head; // 4 -> null
	printRandLinkedList(head);
	res1 = copyRandomList3(head);
	printRandLinkedList(res1);


	system("pause");
	return 0;

}