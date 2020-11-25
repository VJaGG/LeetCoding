// // http://codeup.cn/problem.php?cid=100000598&pid=0
// // 问题 A: 字符串处理
// #include <math.h>
// #include <string>
// #include <iostream>
// using namespace std;

// double digits(string str){
//     double pos = 1.0;
//     if (str[0] == '-'){
//         pos = -1.0;
//         str.erase(str.begin());
//     }
    
//     string integer;
//     string fraction;
//     string power;
//     int num = 0;
//     int e = 0;
//     for (int i = 0; i < str.length(); i++){
//         if (str[i] == '.'){
//             num = i;
//         }
//         if (str[i]=='e' || str[i] =='E'){
//             e = i;
//             break;
//         }
//     }
//     if(num){
//         integer = str.substr(0, num);
//     }
//     if (num){
//         if (e){
//             fraction = str.substr(num+1, e-num-1);
//         }else{
//             fraction = str.substr(num+1, str.length());
//         }
//     }
//     if (e){
//         power = str.substr(e+1, str.length());
//     }
    
//     double integers = 0.0;
//     for (int i = 0; i < integer.length(); i++){
//         integers = integers * 10 + int(integer[i]-'0');
//     }
//     double fractions = 0.0;
//     for (int i = fraction.length()-1; i >= 0; i--){
//         fractions = fractions * 0.1 + int(fraction[i]-'0');
//     }
//     double powers = 0.0;
//     for (int i = 0; i < power.length(); i++){
//         powers = powers * 10 + int(power[i]-'0');
//     }
    
//     double res = (integers + fractions * 0.1) * pos * pow(10, powers);
//     cout<<res<<endl;
//     return res;
// }

// int main(){
//     string str1, str2;
//     cin>>str1>>str2;
//     double num1 = digits(str1);
//     double num2 = digits(str2);
//     double res = num1 + num2;
//     double temp = res;
//     int n = 0;
//     while (temp >= 10){
//         temp /= 10;
//         n++;
//     }
//     cout<<temp << "e" << n <<endl;
// }
#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


double digits(string str){
    double ints = 0.0;
    double points = 0.0;
    double powers = 0.0;
    double npos = 1.0;
    if(str[0]=='-'){
        npos = -1.0;
        str.erase(str.begin());
    }
    if (str.find(".")!=string::npos){
        int point_pos = str.find(".");
        string int_str= str.substr(0, point_pos);
        sscanf(int_str.c_str(), "%lf", &ints);
        if (str.find("e")!=string::npos || str.find("E")!=string::npos){
            int e_pos = str.find("e")!=string::npos? str.find("e"): str.find("E");
            string point_str = str.substr(point_pos+1, e_pos-point_pos-1);
            sscanf(point_str.c_str(), "%lf", &points);
            points *= pow(10, int(point_str.length())*(-1));
            string e = str.substr(e_pos+1, str.length());
            sscanf(e.c_str(), "%lf", &powers);
        }
        else{
            string point_str = str.substr(point_pos+1, str.length());
            sscanf(point_str.c_str(), "%lf", &points);
            points *= pow(10, int(point_str.length())*(-1));
        }
    }else{
        if (str.find("e")!=string::npos || str.find("E")!=string::npos){
            int e_pos = str.find("e")!=string::npos? str.find("e"): str.find("E");
            string int_str = str.substr(0, e_pos);
            sscanf(int_str.c_str(), "%lf", &ints);
            string e = str.substr(e_pos+1, str.length());
            sscanf(e.c_str(), "%lf", &powers);
        }
        else{
            sscanf(str.c_str(), "%lf", &ints);
        }
    }
    double res = (ints + points) * pow(10, int(powers)) * npos;
    return res;
}
int main(){
    string str1, str2;
    while(cin>>str1>>str2){
        bool interger = true;
        if (str1.find(".")!=string::npos ||str2.find(".")!=string::npos){
            interger = false;
        }
        
        double num1 = digits(str1);
        double num2 = digits(str2);
        double res = num1 + num2;
        if(interger==true){
            cout.precision(10);
            cout<<int(res)<<endl;
        }else{
            int num = 0;
            while (res>=10){
                res /= 10;
                num++;
            }
            cout.precision(10);
            cout<<res<<"e"<<num<<endl;
        }

    }
    return 0;
}










