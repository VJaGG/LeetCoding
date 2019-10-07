#include<vector>
#include<iostream>
using namespace std;
void constrcutEdge(vector<vector<int>> &matrix,int &num,int tR,int tC,int dR,int dC) {
	if (tR == dR && tC == dC) {
		matrix[tR][tC] = num;
		num++;
	}
	else {
		int curR = tR;
		int curC = tC;
		while (curC != dC) {
			matrix[tR][curC] = num;
			curC++;
			num++;
		}
		while (curR!=dR)
		{
			matrix[curR][dC] = num;
			curR++;
			num++;
		}
		while (curC != tC) {
			matrix[dR][curC] = num;
			curC--;
			num++;
		}
		while (curR != tR) {
			matrix[curR][tC] = num;
			curR--;
			num++;
		}
	}

}
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n,vector<int>(n)); //动态构建二维数组，初始值为0等价于vector<vector<int>> matrix(n, vector<int>(n, 0));
	int tR = 0, tC = 0;
	int dR = n - 1, dC = n - 1;
	int num = 1;
	while (tR <= dR && tC <=dC) {
		constrcutEdge(matrix, num, tR++, tC++, dR--, dC--);
	}
	return matrix;
}
void printMatrix(const vector<vector<int>> &matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col <cols; col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> matrix = generateMatrix(n);
	printMatrix(matrix);
	system("pause");
	return 0;
	
}