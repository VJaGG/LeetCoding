#include <vector>
#include <string>
#include <iostream>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = matrix.size() - 1, j=0;
    int n = matrix[0].size() - 1;
    while (i>=0 && j<=n){
        if(matrix[i][j] == target){
            return true;
        }else if(matrix[i][j] > target){
            i--;
        }else{
            j++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 4, 7, 11 ,15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}; 
    int target = 5;
    bool answer = searchMatrix(matrix, target);
    printf("%d", answer);
    return 0;
}