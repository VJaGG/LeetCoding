#include <string>
#include <iostream>
using namespace std;

bool isPalindrome(string s, int low, int high) {
    while (low <= high){
        if (s[low]!=s[high]){
            return false;
        }
        low ++;
        high--;
    }
    return true;  
} 


bool validPalindrome(string s){
    int low = 0;
    int high = s.size() - 1;
    while (low <= high){
        if (s[low] == s[high]){
            low ++;
            high --;
        }else{
            return isPalindrome(s, low+1, high) || isPalindrome(s, low, high-1);
        }
        
    }
    return true;
}



// bool validPalindrome(string s) {
//     int low = 0;
//     int high = s.size() - 1;
//     int count = 0;
//     bool flag = true;
//     while (low <= high){
//         if (s[low] == s[high]){
//             low ++;
//             high --;
//         }else{
//             /* code */
//             if (s[low + 1] == s[high] && flag){
//                 low = low + 2;
//                 high = high - 1;
//                 flag = false;
//             }else if (s[low] == s[high-1] && flag){
//                 low = low + 1;
//                 high = high - 2;
//                 flag = false;
//             }else{
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// cupuuuupucu 上述的算法对于这个测试用例不能通过
// 只有s[low] == s[high-1]时候成立

int main(){
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    bool answer = validPalindrome(s);
    printf("%d\n", answer);
    return 0;
}