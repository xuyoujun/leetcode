// 10.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public :
	int uniquePath(int m, int n) {
		int sum = 0;  
		dfs(m, n, 0, 0, sum);
		return sum;
	}
private:
	void dfs(int &m, int &n, int dsteps, int rsteps, int &sum) {
		if (dsteps == m - 1 && rsteps == n - 1) {
			sum++;
		}
		 if (dsteps < m - 1) {
			dfs(m, n, dsteps + 1, rsteps, sum);
		}
		if (rsteps < n -1){
			dfs(m, n, dsteps, rsteps + 1, sum);
		}
	}
};
class Solution2 {
public:
	int uniquePath(int m, int n) {
		memset(buffer, 0, 200 * 200 * 4);
		return dfs(m, n);
	}
private:
	int dfs(int m, int n) {
		if (m < 1 || n < 1) return 0;
		if (m == 1 && n == 1) return 1;
		return usingBuffer(m - 1, n) + usingBuffer(m, n - 1);
	}
	int usingBuffer(int m, int n) {
		if (buffer[m][n] > 0)return buffer[m][n];
		return buffer[m][n] = dfs(m, n);
	}
	int buffer[200][200] ;
};

class Solution3 {
public:
	int uniquePath(int m, int n) {
		memset(buffer, 0, 200 * 200 * 4);
		for (int i = 0; i < m ; i++)
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == 0)buffer[i][j] = 1;
				else buffer[i][j] = buffer[i - 1][j] + buffer[i][j - 1];
			}
		return buffer[m - 1][n - 1];
	}
private:
	int buffer[200][200];

};
int main()
{
	Solution3 S;
	cout << S.uniquePath(3, 4);
	system("pause");
    return 0;
}

