/*
	1  2  3  4
	5  6  7  8
 	9  10 11 12
	13 14 15 16

	1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

	宏观调度能力
*/
#include<vector>
#include<iostream>
using namespace std;
void printEdge1(vector<vector<int>> &matrix, vector<int> &result, int tR, int tC, int dR, int dC) {
	if (tR == dR) { //只有一行的情况
		for (int i = tC; i <= dC; i++)
		{
			result.push_back(matrix[tR][i]);
		}
	}else if (tC == dC) { //只有一列的情况
		for (int i = tR; i <= dR; i++) {
			result.push_back(matrix[i][tC]);
		}
	}
	else
	{
		//一般的情况下
		int curC = tC;
		int curR = tR;
		while (curC!=dC)
		{
			result.push_back(matrix[tR][curC]);
			curC++;
		}
		while (curR!=dR)
		{
			result.push_back(matrix[curR][dC]);
			curR++;
		}
		while (curC!=tC)
		{
			result.push_back(matrix[dR][curC]);
			curC--;
		}
		while (curR != tR) {
			result.push_back(matrix[curR][tC]);
			curR--;
		}
	}
}
void printEdge(vector<vector<int>> &arr, vector<int> &result, int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		for (int i = y1; i <=y2 ; i++)
		{
			result.push_back(arr[x1][i]);
		}
	}
	else if(y1==y2){
		for (int i = x1; i <= x2; i++) {
			result.push_back(arr[i][y1]);
		}

	}
	else{
		for (int i = y1; i <= y2 - 1; i++)
			result.push_back(arr[x1][i]);
		for (int j = x1; j <= x2 - 1; j++)
			result.push_back(arr[j][y2]);
		for (int i = y2; i >= y1 + 1; i--)
			result.push_back(arr[x2][i]);
		for (int j = x2; j >= x1 + 1; j--)
			result.push_back(arr[j][y1]);

	}


}
vector<int> spiralOrder(vector<vector<int>> &arr) {
	vector<int> result;
	int rows = arr.size();
	if (rows <= 0)
		return result;
	int cols = arr[0].size();
	
	int x1 = 0, y1 = 0;
	int x2 = rows-1, y2 = cols-1;
	while (x1<=x2 && y1<=y2 ) {
		printEdge1(arr, result,x1, y1, x2, y2);
		x1++;
		y1++;
		x2--;
		y2--;
	}
	return result;
}

int main() {
	//vector<vector<int>> arr = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<vector<int>> arr = { {1,2,3},{4,5,6},{7,8,9} };
	//vector<vector<int>>arr = {};
 	vector<int> result = spiralOrder(arr);
	for (auto i : result) {
		cout << i << " ";
	}
	system("pause");
	return 0;

}