#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool isPalindrome(string s){
    int low = 0;
    int high = s.size() - 1;
    // while (low <= high){
    while (low < high){ 
        // 小于等于存在问题，当low==high的时候一定成立，当s为空的时候""存在bug 
        // while (low <= high && !(isdigit(s[low]) || isalpha(s[low]))){
        while (low < high && !(isdigit(s[low]) || isalpha(s[low]))){
            low++;
        }
        // while (low <= high && !(isdigit(s[high]) || isalpha(s[high]))){
        // 这里都写成low < high
        while (low < high && !(isdigit(s[high]) || isalpha(s[high]))){
            high--;
        }
        if (toupper(s[low]) != toupper(s[high])){
            return false;
        }
        low ++;
        high -- ;    
    }
    return true;
}


int main(){
    string s = "A man, a plan, a canal: Panama";
    bool answer = isPalindrome(s);
    printf("%d\n", answer);
    return 0;
}