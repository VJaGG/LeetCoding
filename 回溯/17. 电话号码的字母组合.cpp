#include <string>
#include <vector>
#include <iostream>
using namespace std;


// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
const string letterMap[10] = {
    "",  //0
    "",  //1
    "abc",  //2
    "def",  //3
    "ghi",  //4,
    "jkl",  //5,
    "mno",  //6
    "pqrs", //7
    "tuv",  //8
    "wxyz"  //9
};

void backtracking(vector<string> &ans, string &path, string digits, int n, int pos){
    if(path.size() == n){
        ans.push_back(path);
        return;
    }
    int num = digits[pos] - '0';
    string str = letterMap[num];
    for (int i = 0; i < str.size(); i++){
        // char ch = (char)(96 + (num - 2) * 3 + i);
        char ch = str[i];
        path.insert(path.end(), ch);
        backtracking(ans, path, digits, n, pos+1);  // 注意pos的增加
        path.pop_back();
    }
}


vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string path = "";
    int n = digits.size();
    if(n==0){
        return ans;
    }
    backtracking(ans, path, digits, n, 0);
    return ans;
}


int main(){
    string digits = "7";
    // 考虑空的情况，一个字符
    vector<string> ans = letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;

}

