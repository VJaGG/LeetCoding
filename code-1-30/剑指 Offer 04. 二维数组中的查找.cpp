#include <vector>
#include <iostream>
using namespace std;


bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if(row==0)
        return false;
    int col = matrix[0].size();
    int r = row-1;
    int c = 0;
    while (r>=0 && c<col)
    {
        if(matrix[r][c] == target){
            return true;
        }else if(matrix[r][c] > target){
            r--;
        }else{
            c++;
        }    
    }
    return false;
}


int main(){
    // vector<vector<int>> arr = { {1,   4,  7, 11, 15},
    //                             {2,   5,  8, 12, 19},
    //                             {3,   6,  9, 16, 22},
    //                             {10, 13, 14, 17, 24},
    //                             {18, 21, 23, 26, 30}};
    vector<vector<int>> arr = {{-5}};
    bool res = findNumberIn2DArray(arr, -5);
    printf("%d", res);
    return 0;
}