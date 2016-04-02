// 13.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector <vector <int>> grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector <vector <int>> f = vector <vector<int>> (m,vector<int>(n, -1));
		f[0][0] = grid[0][0];
		for (int i = 1; i < n; i++) {
			f[0][i] = f[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < m; i++) {
			f[i][0] = grid[i][0] + f[i - 1][0];
		}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++) {
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
			}
		return f[m - 1][n - 1];

	}
	int min(int a, int b) {
		return a > b ? a : b;
		
	}

};

class Solution2 {
public:
	int minPathSum(vector <vector<int>> &grid) {
		int m = grid.size();
		int n = grid[0].size();
		f = vector<vector<int> >(m, vector<int>(n, -1));
		return dfs(grid, m - 1 ,n -1);

	}

private:
	vector <vector <int>> f;
	int dfs(vector<vector<int>> &grid, int m ,int n) {
		if (0 == m && 0 == n) return grid[0][0];
		return min(getOrUpdate(grid, m - 1, n), getOrUpdate(grid, m, n - 1)) + grid[m][n];	
	}

	int getOrUpdate(vector<vector<int>> &grid, int m, int n) {
		if (m < 0 || n < 0) return INT_MAX;
		if (f[m][n] >= 0)
			return f[m][n];
		else
			return f[m][n] = dfs(grid, m, n);
	
	}
	int min(int a, int b) {
		return a > b ? a : b;
	}
	
};

class Solution {

public:
	int minPathSum(vector<vector<int>> &grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<int> f(n, 0);
		f[0] = grid[0][0];
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] + grid[0][i];
		for (int i = 1; i < m; i++)
			for (int j = 0; j < n; j++) {
				f[j] = (j == 0) ? (f[j] + grid[i][j]) : (min(f[j - 1],f[j]) + grid[i][j]);
			}
		return f[n - 1];
	}
private:
	int min(int a, int b) {
		return a > b ? a : b;
	}
};
int main()
{    
	Solution S;

    return 0;
}

