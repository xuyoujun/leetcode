// 10.10.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void sudokuSolver(vector <vector<char>> &result) {
		vector <vector<char>> path = result;
		dfs(0, 0,path,result);
		result = path;
	}
private:
	void dfs(int row, int col, vector <vector<char>> &path, vector<vector<char>> &result) {
		while (row < 9 && col < 9 &&result[row][col] != '.'  ) {
			if (col >= 8) {
				col = 0;
				row++;
			}
			else {
				col++;
			}
		}
		if (row == 9 && col == 0) {
			 path = result;
			 return;
		}
	   for (int i = 1; i <= 9; i++) {
			result[row][col] = '0' + i;
			if (isValid(row,col,result)) {
				dfs(row, col, path,result);
			}
			result[row][col] = '.';
		}
	}

	bool isValid(int x, int y, vector<vector<char>> & board) {
		int i, j;
		for (i = 0; i < 9; i++) // 检查 y 列
			if (i != x && board[i][y] == board[x][y])
				return false;
		for (j = 0; j < 9; j++) // 检查 x 行
			if (j != y && board[x][j] == board[x][y])
				return false;
		for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)   //小的正方形也要判断一下
			for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
				if ((i != x || j != y) && board[i][j] == board[x][y])
					return false;
		return true;
	}
};


class Solution2 {
public:
	bool solveSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					for (int k = 0; k < 9; ++k) {
						board[i][j] = '1' + k;
						if (isValid(board, i, j) && solveSudoku(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		return true;
	}
private:
	// 检查 (x, y) 是否合法
	bool isValid(const vector<vector<char> > &board, int x, int y) {
		int i, j;
		for (i = 0; i < 9; i++) // 检查 y 列
			if (i != x && board[i][y] == board[x][y])
				return false;
		for (j = 0; j < 9; j++) // 检查 x 行
			if (j != y && board[x][j] == board[x][y])
				return false;
		for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
			for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
				if ((i != x || j != y) && board[i][j] == board[x][y])
					return false;
		return true;
	}
};


int main()
{
	vector <vector <char>> result(9,vector<char>(9,0));
	for (int i = 0; i < 9;i++)
		for (int j = 0; j < 9; j++) {
			cin >> result[i][j];
		}
	
	Solution S;
	S.sudokuSolver(result);
	//Solution2 S;
	//S.solveSudoku(result);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

