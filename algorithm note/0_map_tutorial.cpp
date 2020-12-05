// #include <map>
// #include <stdio.h>
// using namespace std;


// // 通过下标的方式访问
// int main(){
//     map<char, int> mp;
//     mp['c'] = 20;
//     mp['c'] = 30;  // 20被覆盖
//     printf("%d\n", mp['c']);  // 输出30
//     return 0;
// }

// // 通过迭代器来访问
// #include <map>
// #include <stdio.h>
// using namespace std;
// int main(){
//     map<char, int> mp;

//     mp['m'] = 20;
//     mp['r'] = 30;
//     mp['a'] = 40;
//     for (map<char, int>:: iterator it=mp.begin(); it!=mp.end(); it++){
//         printf("%c %d\n", it->first, it->second);
//     }
//     return 0;
// }
// // map会以键从小到大的顺序自动的排序，这是因为map内部是使用红黑树实现的(set也是)，
// // 在建立映射的过程中就会自动的实现从小到大排序的功能


// find(key)函数
#include <stdio.h>
#include <map>
using namespace std;

int main(){
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    map<char, int>:: iterator it = mp.find('b');
    printf("%c %d\n", it->first, it->second);
    return 0;
}




























