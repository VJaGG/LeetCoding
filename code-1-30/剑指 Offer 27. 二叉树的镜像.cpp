#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* mirrorTree(TreeNode* root){
    if (root==NULL){
        return root;
    }
    TreeNode* temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);
    return root;
}

vector<int> levelOrder(TreeNode* root){
    vector<int> result;
    queue<TreeNode*> q;
    if (root!=NULL){
        q.push(root);
    }
    while (!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        result.push_back(cur->val);
        if (cur->left!=NULL){
            q.push(cur->left);
        }
        if (cur->right!=NULL){
            q.push(cur->right);
        }
    }
    return result;
}

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9

//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1


int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    vector<int> result = levelOrder(root);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
    TreeNode* min = mirrorTree(root);
    vector<int> result1 = levelOrder(min);
    for (int i = 0; i < result1.size(); i++){
        cout<<result1[i]<<" ";
    }
    cout<<endl;
    

}