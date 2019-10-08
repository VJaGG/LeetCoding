#include<iostream>
#include<vector>
using namespace std;

void infect(vector<vector<char>> &grid, int row, int col) {
	int rows = grid.size();
	int cols = grid[0].size();
	if (row<0 || row>=rows || col<0 || col>=cols || grid[row][col]!='1')
		return;
	grid[row][col] = '2';
	infect(grid, row - 1, col);
	infect(grid, row, col - 1);
	infect(grid, row + 1, col);
	infect(grid, row, col + 1);
}

int numIslands(vector<vector<char>>& grid) {
	int rows = grid.size();
	int cols = grid[0].size();
	int count = 0;
	for (int i = 0; i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == '1') {
				infect(grid, i, j);
				count++;
			}
		}
	}

	return count;
}


int main() {
	vector<vector<char>> grid = { {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
 	int count = numIslands(grid);
	for (auto row : grid) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << count << endl;
	system("pause");
	return 0;
}