// #include <cstdio>
// int main(){
//     int n;
//     char str[100] = "123";
//     sscanf(str, "%d", &n);
//     printf("%d\n", n);
//     return 0;
// }



// #include <cstdio>
// int main(){
//     int n = 233;
//     char str[100];
//     sprintf(str, "%d", n);
//     printf("%s\n", str);
//     return 0;
// }


// #include <cstdio>
// int main(){
//     int n;
//     double db;
//     char str[100] = "2048:3.14,hello", str2[100];
//     sscanf(str, "%d:%lf,%s", &n, &db, str);
//     printf("n = %d, db = %.2f, str2 = %s\n", n, db, str);
//     return 0;
// }

// #include <cstdio>
// int main(){
//     int n = 2048;
//     double db = 3.14;
//     char str2[100] = "hello";
//     char str1[100];
//     sprintf(str1, "%d:%lf,%s", n, db, str2);
//     printf("%s", str1);
//     return 0;
// }

#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    string str = "-12";
    long a;
    sscanf(str.c_str(), "%lld", &a);
    cout<<a<<endl;
}
