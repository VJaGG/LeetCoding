#include <vector>
#include <string>
#include <climits>
#include <iostream>
using namespace std;


string minWindow(string s, string t) {
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    for (int i = 0; i < t.size(); i++){
        flag[t[i]] = true;
        chars[t[i]] += 1;
    }
    int cnt = 0, low = 0;
    int min_size = INT_MAX;
    int min_low = 0;
    for (int high = 0; high < s.size(); high++){
        if (flag[s[high]]){
            if(--chars[s[high]] >= 0){
                cnt ++;
            }
    
        }
        while (cnt == t.size()){
            if (high - low + 1 < min_size){
                min_size = high - low + 1;
                min_low = low;
            }
            if (flag[s[low]] && ++chars[s[low]] > 0){ //
                --cnt;
            }
            ++low;
        }
    }
    return min_size > s.size()?"": s.substr(min_low, min_size);
}

int main(){

    // string s = "ADOBECODEBANC";
    // string t = "ABC";

    string s = "acbbaca";
    string t = "aba";
    string answer = minWindow(s, t);
    cout<<answer<<endl;
    return 0;
}