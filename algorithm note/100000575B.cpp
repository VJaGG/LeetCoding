// 问题 B: A+B
// http://codeup.cn/problem.php?cid=100000575&pid=1
#include <string>
#include <iostream>
using namespace std;

// -234,567,890 123,456,789
// 1,234 2,345,678


int digit(string str){
    int res = 0.0;
    int pos = 1.0;
    if (str[0] == '-'){
        pos = -1.0;
        str.erase(str.begin());
    }
    for (int i = 0; i < str.size(); i++){
        if (str[i] == ',')
            continue;
        res = res * 10 + (str[i] - '0');
    }
    return res * pos;
}

int main(){
    string str1, str2;
    int num1, num2;
    while(cin>>str1>>str2){
        num1 = digit(str1);
        num2 = digit(str2);
        // cout<<num1<<endl<<num2;
        cout<<num2 + num1<< endl;
    }
    return 0;
    
}

