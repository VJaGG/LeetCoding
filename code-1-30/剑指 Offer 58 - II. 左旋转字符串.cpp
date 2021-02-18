#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// substr(pos, len)返回从pos号位开始、长度为len的子串
// string reverseLeftWords(string s, int n) {
//     string head = s.substr(0, n);
//     for (int i = 0; i < s.length() - n; i++){
//         s[i] = s[i + n];
//     }
//     for (int i = 0; i < head.size(); i++){
//         s[i+s.length()-n] = head[i];
//     }
//     return s;

// }

string reverseLeftWords(string s, int n){
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin()+n, s.end());
    reverse(s.begin(), s.end());
    return s;
}


int main(){
    string s = "lrloseumgh";
    int k = 6;
    cout<<s<<endl;
    string res = reverseLeftWords(s, k);
    cout<<res<<endl;

}
