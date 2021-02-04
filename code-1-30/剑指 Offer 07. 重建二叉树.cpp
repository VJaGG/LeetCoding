/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
    if(preright <= preleft)
        return NULL;
    int val = preorder[preleft];
    TreeNode* root = new TreeNode(val);
    if((preright - preleft) == 1)
        return root;

    int num = 0;
    for (int i = inleft; i < inright; i++){
        if (inorder[i] == val){
           num = i - inleft + 1;
           break; 
        }
    }

    root->left = buildTree(preorder, inorder, preleft + 1, preleft + num, inleft, inleft + num - 1);
    root->right = buildTree(preorder, inorder, preleft + num, preright, inleft + num, inright);

    return root;    
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0)
        return NULL;
    TreeNode* root = buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    return root; 

}

void traverse(TreeNode* root){
    if(root==NULL)
        return;
    traverse(root->left);
    traverse(root->right);
    printf("%d ", root->val);
}
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
int main(){
    // vector<int> preorder = {3, 9, 20, 15, 7};
    // vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {1, 2};
    vector<int> inorder = {2, 1};

    TreeNode* root = buildTree(preorder, inorder);
    traverse(root);
    return 0;
}