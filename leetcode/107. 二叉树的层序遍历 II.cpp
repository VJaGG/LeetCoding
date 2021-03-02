#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> answer;
    queue<TreeNode*> q;
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        int size = q.size();
        vector<int> vec;
        for(int i=0; i<size; i++){
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
        answer.insert(answer.begin(), vec);
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
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    vector<vector<int>> answer = levelOrderBottom(root);
    for(int i=0; i<answer.size(); i++){
        for(int j=0; j<answer[i].size(); j++){
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    return 0;
}