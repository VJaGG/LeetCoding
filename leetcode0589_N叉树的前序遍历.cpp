#include<vector>
#include<stack>
#include<iostream>
using namespace std;
struct Node
{
	int val;
	vector<Node *> children;
	Node(int _val, vector<Node *> _children = {}) :val(_val), children(_children) {}
};
void preorder(Node* root) {
	if (root == nullptr)
		return;
	cout << root->val << " ";
	for (auto i : root->children)
		preorder(i);

}
void postorder(Node *root) {
	if (root == nullptr)
		return;
	for (auto i : root->children)
		postorder(i);
	cout << root->val << " ";
}
vector<int> preorderno(Node* root) {
	vector<int> pre;
	if (root) {
		stack<Node *> s;
		s.push(root);
		while (!s.empty()){
			Node* cur = s.top();
			s.pop();
			pre.push_back(cur->val);
			if (cur->children.size()!=0) {
				for (auto i = cur->children.rbegin(); i != cur->children.rend(); i++){
					s.push(*i);
				}
			}

		}
	}
	return pre;

}
vector<int> postorderno(Node* root) {
	vector<int> post;

	stack<int> val;
	if (root) {

		stack<Node*> s;
		s.push(root);
		while (!s.empty()) {
			Node* cur = s.top();
			s.pop();
			val.push(cur->val);
			for (auto i = cur->children.begin(); i != cur->children.end(); i++)
				s.push(*i);
		}
	}
	while (!val.empty())
	{
		post.push_back(val.top());
		val.pop();
	}
	return post;
}

int main() {
	Node *root = new Node(1);
	root->children.push_back(new Node(3));
	root->children.push_back(new Node(2));
	root->children.push_back(new Node(4));
	root->children[0]->children.push_back(new Node(5));
	root->children[0]->children.push_back(new Node(6));
	
	cout << "preorderTraversal: " << endl;
	preorder(root);
	cout << endl;
	vector<int> pre = preorderno(root);
	for (auto i : pre)
		cout << i << " ";
	cout << endl;
	cout << "inorderTraversal: " << endl;
	postorder(root);
	cout << endl;
	vector<int> post = postorderno(root);
	for (auto i : post)
		cout << i << " ";
	system("pause");
}