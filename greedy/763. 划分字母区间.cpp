#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

vector<int> partitionLabels(string s) {
    vector<int> result;
    vector<vector<int>> points(26, vector<int>(2, 0));
    for (int i = 0; i < s.size(); i++){
        if(points[s[i] - 'a'][0] == 0){
            points[s[i] - 'a'][0] = i + 1;
            points[s[i] - 'a'][1] = i + 1;
        }else{
            points[s[i] - 'a'][1] = i + 1;
        }
    }
    int start = 0;
    int end = 0;
    sort(points.begin(), points.end(), cmp);
    for (int i = 0; i < points.size(); i++){
        if(points[i][0] == 0){
            continue;
        }
        if(start == 0){
            start = points[i][0];
            end = points[i][1];
        }else{
            if (points[i][0] > end){
                int len = end - start + 1;
                result.push_back(len);
                start = points[i][0];
                end = points[i][1];
            }else{
                end = max(end, points[i][1]);
            }
            
        }
    }
    result.push_back(end - start + 1);
    return result;
}

int main(){

    string s = "ababcbacadefegdehijhklij";
    vector<int> answer = partitionLabels(s);
    for (auto i: answer){
        printf("%d\n", i);
    }
    return 0;
}