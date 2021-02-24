#include <iostream>
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): left(NULL), right(NULL), val(x){}
};


int maxdepth(TreeNode * root){

}


//    3
//    / \
//   9  20
//     /  \
//    15   7
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int depth = maxdepth(root);
}
