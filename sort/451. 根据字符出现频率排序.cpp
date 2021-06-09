#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


string frequencySort(string s) {
    unordered_map<char, int> counts;
    int max_counts = 0;
    for (auto i: s){
        max_counts = max(max_counts, ++counts[i]);
    }

    vector<vector<char>> buckets(max_counts + 1);
    for (auto i: counts){
        buckets[i.second].push_back(i.first);
    }
    string answer;
    for (int i = max_counts; i >=0; i--){
        for (auto c: buckets[i]){
            while (counts[c]--){
                answer.push_back(c);
            }
            
        }
        
    }
    return answer;
}

int main(){
    string s = "tree";
    string answer = frequencySort(s);
    cout<<answer<<endl;
    return 0;
}