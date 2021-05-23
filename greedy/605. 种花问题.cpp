#include <vector>
#include <iostream>
using namespace std;


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    if (flowerbed.size()==1){
        if (flowerbed[0]==0){
            count++;
        }
        return count >= n? true: false;
    }
    
    for (int i = 0; i < flowerbed.size(); i++){
        if (i==0){
            if(flowerbed[i+1]==0 && flowerbed[i]==0){
                flowerbed[i] = 1;
                count ++;
            }
        }else if (i==flowerbed.size()-1){
            if(flowerbed[i-1] == 0 && flowerbed[i]==0){
                flowerbed[i] = 1;
                count ++;
            }
        }else if (flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1] == 0){
            /* code */
            flowerbed[i] = 1;
            count ++;
        }
    }
    return count >= n? true: false;
}

int main(){
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 2;
    bool answer = canPlaceFlowers(flowerbed, n);
    printf("%d\n", answer);
    return 0;
}
