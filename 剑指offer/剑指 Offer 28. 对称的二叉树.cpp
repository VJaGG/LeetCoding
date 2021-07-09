#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* left, TreeNode* right){
    if (left==NULL && right==NULL){
        return true;
    }
    if (left==NULL || right==NULL){
        return false;
    }
    if (left->val == right->val){
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    return false;  
}


bool isSymmetric(TreeNode* root) {
    if (root==NULL){
        return true;
    }
    return isSymmetric(root->left, root->right);
}
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    bool ans = isSymmetric(root);
    printf("%d\n", ans);
    return 0; 
}































