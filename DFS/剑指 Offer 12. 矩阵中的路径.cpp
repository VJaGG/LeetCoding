#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool exist(vector<vector<char>>& board, string word, int i, int j, int index){
    if(i<0|| i>=board.size() || j<0 || j>=board[0].size() || word[index]!=board[i][j])
        return false;
    if (index==word.size()-1){
        return true;
    }

    board[i][j] = ' ';  // 赋值
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    bool flag = false;
    for (int k = 0; k < 4; k++){
        int next_i = i + di[k];
        int next_j = j + dj[k];
        // flag = flag || exists(board, word, next_i, next_j, ++index);  // 错误的原因
        flag = flag || exist(board, word, next_i, next_j, index+1);
    }
    // bool flag = exists(board, word, i-1, j, index+1) || exists(board, word, i+1, j, index+1)
    //             || exists(board, word, i, j-1, index+1) || exists(board, word, i, j+1, index+1);
    board[i][j] = word[index];  //还原 与岛屿问题的区别
    return flag;
}


bool exist(vector<vector<char>>& board, string word){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            bool flag = exist(board, word, i, j, 0);
            if(flag)
                return true;
        } 
    }
    return false;
}

int main(){
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool flag = exist(board, word);
    printf("%d", flag);            
}