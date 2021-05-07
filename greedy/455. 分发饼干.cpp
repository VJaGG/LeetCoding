#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


// 超时
// int findContentChildren(vector<int>& g, vector<int>& s) {
//     sort(g.begin(), g.end());
//     sort(s.begin(), s.end());
//     int num = 0;
//     for (int i = 0; i < s.size(); i++){
//         for (int j = 0; j < g.size(); j++){
//             if (g[i] > 0 && s[i]>=g[i]){
//                 num ++ ;
//                 g[j] =-g[j];
//                 s[i] =-s[i];
//             }
//         }
//     }
//     return num;
// }


int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int num = 0;
    for (int i=s.size()-1, j=g.size()-1; i>=0 && j>=0;){
        if (s[i]>=g[j]){
            num++;
            i--;
            j--;
        }else{
            j--;
        }
    }
    return num;
}


int main(){
    vector<int> g = {1, 2, 3}, s = {3};
    int answer = findContentChildren(g, s);
    printf("%d\n", answer);


    return 0;

}