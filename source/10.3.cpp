// 10.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include <vector>

using namespace std;

class Solution {

public:
	int uniquePath(vector <vector <int>> &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int ret = dfs(m, n, obstacleGrid);
		return ret;
	}
private:
	int dfs(int m, int n, vector <vector <int>> &obstacleGrid) {
		if (m < 1 || n < 1) return 0;
		if (m == 1 && n == 1)return 1;
		if (obstacleGrid[m - 1][n - 1]) return 0;
		return dfs(m - 1, n, obstacleGrid) + dfs(m, n - 1, obstacleGrid);
	}

};


class Solution2 {   //¶¯Ì¬¹æ»®

public:
	int uniquePath(vector <vector <int>> &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector <vector<int>> f(m,vector<int>(n));
		return dfs(obstacleGrid);
	}
private:
	int dfs(vector <vector <int>> &obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[m - 1][n - 1] || obstacleGrid[0][0]) return 0;
		vector <int> f(n, 0);
		f[0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				f[j] = obstacleGrid[i][j] ? 0 : ((j <= 0 ? 0 : f[j - 1]) + f[j]);
		return f[n - 1];
	}
};

int main()
{
	Solution2 S;
	vector<vector<int>> obstacleGrid;
	vector <int> temp;
	for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++)
	//	{
	//		temp[j] = 0;//obstacleGrid[i][j] = 0;
	//	}
		obstacleGrid.push_back({0,0,0});
	}
	obstacleGrid[1][1] = 1;
	//obstacleGrid[2][1] = 1;
	cout << S.uniquePath(obstacleGrid);
	system("pause");
	return 0;
}
