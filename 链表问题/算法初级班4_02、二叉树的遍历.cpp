#include<climits>
#include<stack>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
//C++中, 经常会使用, 某些类型的最大值, 
//如int的最大整数(INT_MAX), C的函数中, 包含了这些宏定义.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
void preorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return;
	cout << root->val << " " ;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

vector<int> preorderTraversalnorecursion(TreeNode*root) {
	vector<int> preorder;
	stack<TreeNode*> s;
	TreeNode*cur = nullptr;
	if (root != nullptr) {
		s.push(root);
		while (!s.empty()) {
			cur = s.top();
			preorder.push_back(cur->val);
			s.pop();
			if (cur->right)
				s.push(cur->right);
			if (cur->left)
				s.push(cur->left);
		}
	}
	return preorder;
}
void inorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return;//base case
	inorderTraversal(root->left);
	cout << root->val<<" ";
	inorderTraversal(root->right);
}
vector<int> inorderTraversalNorecursion(TreeNode* root) {
	vector<int> inorder;
	TreeNode* cur=root;
	if (cur == nullptr)
		return inorder;
	stack<TreeNode*> s;
	while (!s.empty() || cur!=nullptr) {
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		inorder.push_back(cur->val);
		s.pop();
		cur = cur->right;
	}
	return inorder;
}
vector<int> inorderTraversalNorecursion1(TreeNode* root) {
	vector<int> inorder;
	TreeNode* cur = root;
	if (cur == nullptr)
		return inorder;
	stack<TreeNode*> s;
	while (!s.empty() || cur != nullptr) {
		if(cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = s.top();
			inorder.push_back(cur->val);
			s.pop();
			cur = cur->right;
		}

	}
	return inorder;
}
void postorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->val << " ";
}
string getSpace(int num) {
	string space;
	for (int i = 0; i < num; i++)
		space.append(" ");
	return space;

}
void printInOrder(TreeNode* root,int height,string to,int len) {
	if (root == nullptr)
		return;
	printInOrder(root->right, height + 1, "v", len);
	string val = to+ to_string(root->val)+to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = getSpace(lenL) + val + getSpace(lenR);
	cout << getSpace(height*len) + val << endl;
	printInOrder(root->left, height + 1, "^", len);
}
void printTree(TreeNode* root) {
	cout << "Binary Tree:" << endl;
	printInOrder(root, 0, "H", 17);
	cout << endl;
}
vector<int> postorderTraversalNorecursion(TreeNode* root) {
	vector<int> postorder;
	stack<TreeNode*> s1, s2;
	TreeNode* cur = nullptr;
	if (root != nullptr) {
		s1.push(root);
		while (!s1.empty())
		{
			cur = s1.top();
			s1.pop();
			s2.push(cur);
			if (cur->left)
				s1.push(cur->left);
			if (cur->right)
				s1.push(cur->right);
		}
	}
	while (!s2.empty()) {
		cur = s2.top();
		postorder.push_back(cur->val);
		s2.pop();
	}
	return postorder;
}
vector<int> postorderTraversalNorecursion1(TreeNode* root) {
	vector<int> postorder;
	if (root) {
		stack<TreeNode *> s;
		s.push(root);
		TreeNode* cur = nullptr;
		TreeNode* last = root;
		while (!s.empty()) {

			cur = s.top();
			if (cur->left && cur->left!= last && cur->right!= last) {
				s.push(cur->left);
				cur = cur->left;
			}
			else if (cur->right!= last && cur->right) {
				s.push(cur->right);
			}
			else {
				postorder.push_back(cur->val);
				last = cur;
				s.pop();
			}

		}
	}
	return postorder;
}
int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(-2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(INT_MAX);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->left->left->right = new TreeNode(7);
	cout << "preorderTraversal" << endl;
	preorderTraversal(root);
	cout << endl;
	//printTree(root);
	vector<int> preorder = preorderTraversalnorecursion(root);
	for (auto i : preorder)
		cout << i << " ";
	cout << endl;
	cout << "inOrderTraversal" << endl;
	inorderTraversal(root);
	cout << endl;
 	vector<int> inorder = inorderTraversalNorecursion1(root);
	for (auto i : inorder) 
		cout << i << " ";
	cout << endl;
	cout << "postOrderTraversal" << endl;
	postorderTraversal(root);
	cout << endl;
	vector<int> postorder = postorderTraversalNorecursion1(root);
	for (auto i : postorder) 
		cout << i << " ";
	cout << endl;
	system("pause");


}