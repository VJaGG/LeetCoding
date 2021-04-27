#include <stack>
#include <vector>
#include <iostream>
using namespace std;


// 会超时
int largestRectangleArea1(vector<int>& heights) {
    int len = heights.size();
    int res = 0;
    for (int i = 0; i < len; i++){
        int min_height = heights[i];
        for(int j=i; j<len; j++){
            min_height = min(min_height, heights[j]);
            res = max(res, min_height * (j - i + 1));
        }
    }
    return res;
}

int largestRectangleArea(vector<int>& heights){
    stack<int> s;  //栈中元素始终单调递增，当插入元素i的时候，判断其是否满足单调栈的性质
    int res;
    heights.push_back(-1);  
    int len = heights.size();  // 类型size的类型不为int会报错
    for (int i = 0; i < len; i++){
        while (!s.empty() && heights[s.top()] >= heights[i]){
            int height_id = s.top();
            s.pop();
            int pre_id = s.empty()? -1: s.top(); 
            // 获得当前元素比其小的前一个元素的索引
            // 栈中存储的是数字的索引
            res = max(res, heights[height_id] * (i- pre_id -1));
            // heights[height_id] * (i- pre_id -1)
            // 为计算以heights[i]为顶的最大的矩形面积
        }
        s.push(i);
    }
    heights.pop_back();
    return res;
}


int main(){
    vector<int> heights = { 2, 1, 1, 1, 1, 1};
    int answer = largestRectangleArea(heights);
    printf("%d\n", answer);
}