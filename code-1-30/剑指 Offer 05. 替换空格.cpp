#include <string>
#include <iostream>
using namespace std;

// 输入：s = "We are happy."
// 输出："We%20are%20happy."
string replaceSpace(string s) {
    string res;
    for (auto ch: s){
       if(ch==' '){
           res+= "%20";
        }else{
            res+=ch;
        }
    }
    return res;

}


// 1.printf函数输出字符串是针对char *的，即printf只能输出c语言的内置数据类型，而string不是c语言的内置数据类型。
// 2.string类型的对象不止包含字符串，还包含了许多用于操作的函数，所以&str并非字符串的首地址。
// 3.如需输出string对象中的字符串，可以使用string的成员函数c_str()，该函数返回字符串的首字符的地址。

int main(){
    string str;
    getline(cin, str);
    printf("%d\n", str.length());
    string res = replaceSpace(str);
    printf("%s\n", "%20");
    printf("%s", res.c_str());
    return 0;
}