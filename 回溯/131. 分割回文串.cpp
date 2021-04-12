#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool isPlalindrome(const string &str, int start, int end){
    for (int i = start, j=end; i <= j; i++, j--){
        if (str[i]!=str[j]){
            return false;
        }
    }
    return true;
}

void backtracking(string s, vector<vector<string>>& ans, vector<string>& path, int pos){
    if (pos == s.size()){
        ans.push_back(path);
        return;
    }
    for (int i = pos; i < s.size(); i++){
        if (isPlalindrome(s, pos, i)){
            string str = s.substr(pos, i-pos+1);
            path.push_back(str);
        }else{
            continue;
        }
        backtracking(s, ans, path, i+1);
        path.pop_back();
    }
    

}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    backtracking(s, ans, path, 0);
    return ans;
}

// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
int main(){
    string s = "abbab";
    vector<vector<string>> ans = partition(s);
    for (int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}