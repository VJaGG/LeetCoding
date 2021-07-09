#include <vector>
#include <iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

bool isEquelAB(TreeNode* A, TreeNode* B){
    if (B==NULL){
        return true;
    }
    if (A==NULL){
        return false;
    }
    if (A->val != B->val){
        return false;
    }
    return isEquelAB(A->left, B->left) && isEquelAB(A->right, B->right);
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
    
    bool result = false;
    if (A!=NULL && B!=NULL)
    {
            
        if (A->val == B->val){
            result = isEquelAB(A, B);
        }
        if(!result){
            result = isSubStructure(A->left, B);
        }
        if (!result)
        {
            result = isSubStructure(A->right, B);
        }
        
    }
    return result;
}


void traverse(TreeNode* A){
    if (A==NULL){
        return;
    }
    traverse(A->left);
    printf("%d ", A->val);
    traverse(A->right);
}

int main(){
    TreeNode* A = new TreeNode(3);
    A->left = new TreeNode(4);
    A->right = new TreeNode(5);

    A->left->left = new TreeNode(1);
    A->left->right = new TreeNode(2);

    TreeNode* B = new TreeNode(4);
    B->left = new TreeNode(1);

    traverse(A);
    bool ans = isSubStructure(A, B);
    printf("%d\n", ans);
    return 0;


}