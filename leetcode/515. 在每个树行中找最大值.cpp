#include <queue>
#include <climits>
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


vector<int> largestValues(TreeNode* root) {
    vector<int> answer;
    queue<TreeNode*> q;
    if(root!=NULL){
        q.push(root);
    }
    while (!q.empty()){
        int size = q.size();
        int max = INT_MIN;
        for (int i = 0; i < size; i++){
            TreeNode* cur = q.front();
            q.pop();
            max = max > cur->val? max: cur->val;
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        answer.push_back(max);
    }
    return answer;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    vector<int> answer = largestValues(root);
    for (auto i: answer){
        printf("%d ", i);
    }
    return 0;

}