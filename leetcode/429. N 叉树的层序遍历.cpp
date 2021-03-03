#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;
    Node(){}
    Node(int _val){
        val = _val;
    }
    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> answer;
    queue<Node*> q;
    if(root!=NULL){
        q.push(root);
    }
    while (!q.empty()){
        vector<int> vec;
        int size = q.size();
        for (int i = 0; i < size; i++){
            Node* cur = q.front();
            vec.push_back(cur->val);
            q.pop();
            for(auto j: cur->children){
                q.push(j);
            }
            
        }
        answer.push_back(vec);
    }
    return answer;
}

int main(){
    Node* root = new Node(1);
    Node* temp = new Node(3);
    root->children.push_back(temp);
    temp = new Node(2);
    root->children.push_back(temp);
    temp = new Node(4);
    root->children.push_back(temp);
    temp = new Node(5);
    // root.children[0].push_back(temp4);
    // Node* temp5 = new Node(6);
    // root.children[0].push_back(temp5);
    root->children[0]->children.push_back(temp);
    temp = new Node(6);
    root->children[0]->children.push_back(temp);

    vector<vector<int>> answer = levelOrder(root);
    for (int i = 0; i < answer.size(); i++){
        for (int j = 0; j < answer[i].size(); j++){
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;


}