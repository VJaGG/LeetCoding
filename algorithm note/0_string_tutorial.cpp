// #include <stdio.h>
// #include <string>
// using namespace std;
// int main(){
//     string str = "abcd";
//     for (int i = 0; i < str.length(); i++){
//         printf("%c", str[i]);
//     }
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     string str;
//     cin>>str;
//     cout<<str;
//     return 0;
// }



// #include <stdio.h>
// #include <string>
// using namespace std;
// int main(){
//     string str = "abcd";
//     printf("%s\n", str.c_str());  //将string型str使用c_str()变为字符数组
//     return 0;
// }



// #include <stdio.h>
// #include <string>
// using namespace std;
// int main(){
//     string str = "abcd";
//     for (string::iterator it = str.begin(); it != str.end(); it++){
//         printf("%c", *it);
//     }
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     string str1 = "abc", str2 = "xyz", str3;
//     str3 = str1 + str2;  //将str1和str2拼接，赋值给str3
//     str1 += str2;  //将str2直接拼接到str1上
//     cout<<str1<<endl;
//     cout<<str3<<endl;
//     return 0;
// }



// #include <stdio.h>
// #include <string>
// using namespace std;
// int main(){
//     string str1 = "aa", str2 = "aaa", str3 = "abc", str4 = "xyz";
//     if (str1 < str2){
//         printf("ok\n");  //如果str1字典序小于str2，输出ok1
//     }
//     if (str1 != str3){
//         printf("ok\n");
//     }
//     if (str4 > str3){
//         printf("ok\n");
//     }
// }




// #include <string>
// using namespace std;
// int main(){
//     string str1 = "abcdefghi";
//     printf("%d %d\n", str1.size(), str1.length());
//     return 0;
// }


// #include <string>
// #include <iostream>
// using namespace std;

// int main(){
//     string str1 = "abcxyz";
//     string str2 = "opq";
//     str1.insert(0, str2);
//     cout<<str1<<endl;
//     str1.insert(str1.begin(), str1.begin()+3, str1.end());
//     cout<<str1<<endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main(){
//     string str = "abcdefg";
//     str.erase(str.begin() + 4);  //删除4号位（即e）
//     cout<<str<<endl;
//     return 0;
// }


// #include <string>
// #include <iostream>
// using namespace std;

// int main(){
//     string str = "abcdefg";
//     // 删除区间内的元素
//     // 左闭右开
//     str.erase(str.begin()+2, str.end()-1);
//     cout<<str<<endl;
//     return 0;
// }

// #include <string>
// #include <iostream>
// using namespace std;

// int main(){
//     string str = "abcdefg";
//     str.erase(3, 2);  // 删除从3号位开始的2个字符
//     cout<<str<<endl;
//     return 0;
// }

// #include <stdio.h>
// #include <string>
// using namespace std;

// int main(){
//     string str = "abcd";
//     printf("%d\n", str.length());
//     str.clear();
//     printf("%d\n", str.length());
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     string str = "Thank you for your smile";
//     cout<<str.substr(0, 5)<<endl;
//     cout<<str.substr(14, 4)<<endl;
//     cout<<str.substr(19, 5)<<endl;
//     return 0;
// }

//  #include <iostream>
//  using namespace std;
//  int main(){
//      if (string::npos == -1){
//          cout<<"-1 is true."<<endl;
//      }
//      if (string::npos == 4294967295){
//          cout<<"4294967295 is also true."<<endl;
//      }
//      return 0;
//  }



// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     string str = "Thank you for your smile.";
//     string str2 = "you";
//     string str3 = "me";
//     if (str.find(str2) != string::npos){
//         cout<<str.find(str2)<<endl;
//     }
//     if (str.find(str3) != string::npos){
//         cout<<str.find(str3)<<endl;
//     }else
//     {
//         cout<<"I knowe there is no position for me."<<endl;
//     }
    
//     if (str.find(str2, 7) != string::npos){
//         cout<<str.find(str2, 7)<<endl;
//     }
// }


#include <iostream>
#include <string>
using namespace std;
int main(){
    string str = "Maybe you will turn around.";
    string str2 = "will not";
    string str3 = "surely";
    cout<<str.replace(10, 4, str2)<<endl; //将str从pos开始，长度为len的字符串替换为str2
    cout<<str.replace(str.begin(), str.begin() + 5, str3)<<endl;
    return 0;
}

