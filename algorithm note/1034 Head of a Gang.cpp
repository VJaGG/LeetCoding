#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main(){
    vector<vector<int>> graph;
    map<string, int> nameToId;
    int N, K;
    cin>>N>>K;
    int id = 0;
    while (N--)
    {
        string name1, name2;
        int id1, id2;
        int weight; 
        cin>>name1>>name2;
        cin>>weight;
        if(nameToId.count(name1) > 0){
            id1 = nameToId[name1];
        }
        else{
            nameToId.insert(pair<string, int>(name1, id));
            id++;
        }
        if (nameToId.count(name2) > 0){
            id2 = nameToId[name2];
        }
        else{
            nameToId.insert(pair<string, int>(name2, id));
            id++;
        }
        
        
        
        
        
    }
    

}
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10