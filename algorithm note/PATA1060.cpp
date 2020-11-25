// // https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872
// // 1060 Are They Equal (25分)

// #include <string>
// #include <iostream>
// using namespace std;
// int n;
// string deal(string s, int &e){
//     int k = 0;
//     while (s[0] == '0'){  //去除前导的0
//         s.erase(s.begin());
//     }
//     // 计算指数，去除小数点
//     if (s[0] == '.')
//     {
//         s.erase(s.begin());
//         while (s[0] == '0'){
//             s.erase(s.begin());
//             e--;
//         }    
//     }else
//     {
//         while (k < s.length() && s[k] != '.'){
//             k++;
//             e++;
//         }
//         if (k < s.length()){
//             s.erase(s.begin() + k);
//         }
//     }
//     if (s.length() == 0){
//         e = 0;  //去除前导0后的长度变为0，说明这个数是0
//     }
//     int num = 0;
//     k = 0;
//     string res;
//     while (num < n){
//         if (k < s.length()){
//             res += s[k++];
//         }else{
//             res += '0';
//         }
//         num++;
//     }
//     return res;
// }
// int main(){
//     string s1, s2, s3, s4;
//     cin>>n>>s1>>s2;
//     int e1 = 0, e2 = 0;
//     s3 = deal(s1, e1);
//     s4 = deal(s2, e2);
//     if(s3==s4 && e1==e2){
//         cout<<"YES 0."<<s3<<"*10^"<<e1;
//     }else
//     {
//         cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2;
//     }
// }


#include <string>
#include <iostream>
using namespace std;

int n;
string deal(string str, int& e){
    while (str[0]=='0'){  //去除前面的0
        str.erase(str.begin());
    }
    if (str[0]=='.'){  //如果当前是小数点则删除
        str.erase(str.begin());
        while (str[0]=='0'){
            str.erase(str.begin());
            e--;  //判断后面几个小数点
        }
    }else{
        while (e < str.length() && str[e]!='.' ){
            e++;
        }
        if(str[e]=='.'){
            str.erase(str.begin()+e);
        }  
    }
    if (str.length()==0)  //当为0的时候特殊处理
        e = 0;
    
    string res;
    int num = 0;
    while (num < str.length() && num < n){
        res += str[num];
        num++;
    }
    while (num<n){
        res += '0';
        num++;
    }
    return res;
}

// 3 12300 12358.9
// 3 120 128
int main(){
    string str1, str2, str3, str4;
    cin>>n>>str1>>str2;
    int e1 = 0, e2 = 0;
    str3 = deal(str1, e1);
    str4 = deal(str2, e2);
    if (str3==str4 && e1==e2){
        cout<<"YES 0."<<str3<<"*10^"<<e1;
    }else{
        cout<<"NO 0."<<str3<<"*10^"<<e1<<" 0."<<str4<<"*10^"<<e2;
    }
    return 0;    
}