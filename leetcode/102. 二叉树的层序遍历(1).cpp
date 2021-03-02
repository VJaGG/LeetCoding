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

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> answer;
    queue<TreeNode*> q;
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        int size = q.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode* cur = q.front();
            q.pop();
            vec.push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        answer.push_back(vec);
    }
    return answer;
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