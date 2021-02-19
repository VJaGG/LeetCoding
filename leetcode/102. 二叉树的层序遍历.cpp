#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
    /* data */
};

vector<int> levelOrder0(TreeNode* root) {
    vector<int> vec;
    queue<TreeNode*> q;
    if (root!=NULL){
        q.push(root);
    }
    while (!q.empty()){
        TreeNode * node = q.front();
        q.pop();
        if (node->left!=NULL){
            q.push(node->left);
        }
        if(node->right!=NULL){
            q.push(node->right);
        }
        vec.push_back(node->val);
    }
    return vec;
}

// https://blog.csdn.net/u013040591/article/details/80329066?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&dist_request_id=89e201cd-6209-43e7-ade8-586bdd16f198&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> traverse(0, vector<int> (0));
    TreeNode *right = NULL;
    queue< pair<TreeNode*, int>> q;
    if (root!=NULL){
        pair<TreeNode*, int> first = {root, 0};
        q.push(first);
    }
    int level = -1;
    while (!q.empty()){
        pair<TreeNode*, int> cur = q.front();
        q.pop();
        TreeNode* node = cur.first;
        if(cur.second > level){
            level = cur.second;
            traverse.resize(level + 1);
        }
        traverse[level].push_back(node->val);
      
        if (node->left!=NULL){
            q.push(make_pair(node->left, cur.second+1));
        }
        if (node->right!=NULL){
            q.push(make_pair(node->right, cur.second+1));
        }
    }
    return traverse;
}

//     3
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
    // vector<int> res = levelOrder0(root);
    // for (int i = 0; i < res.size(); i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;
    vector<vector<int>> result = levelOrder(root);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}