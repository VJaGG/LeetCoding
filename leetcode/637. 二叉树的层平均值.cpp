#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x): val(x), left(NULL), right(NULL){
    }
};

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> answer;
    queue<TreeNode*> q;
    if(root!=NULL){
        q.push(root);
    }
    while (!q.empty()){
        int size = q.size();
        double count = 0;
        for (int i=0; i < size; i++){
            TreeNode* cur = q.front();
            q.pop();
            count += cur->val;
            if (cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
            
        }
        double avg = count / size;
        answer.push_back(avg);
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
    vector<double> answer = averageOfLevels(root);
    for(auto i: answer){
        printf("%.2f ", i);
    }
    printf("\n");
    return 0;
}
