// 10.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public :
	int nQueen(int n) {
		//vector<int> path;
		int count = 0;
		int sum = 0;
		this->column = vector<int>(n, 0);
		this->diag_135 = vector<int>(2 * n, 0);
		this->diag_45 = vector<int>(2 * n, 0);
		dfs(n, 0, count,sum);
		return sum;
	}
private:
	vector <int> column;
	vector <int> diag_45;
	vector <int> diag_135;
	void dfs(int n, int row, int &path, int &sum) {
		if (path == n) {
			sum++;
			return;
		}

		for (int col = 0; col < n; col++) {
			if (column[col] || diag_135[col + row] || diag_45[n + row - col])
				continue;
			else {
				column[col] = 1;
				diag_135[col + row] = 1;
				diag_45[n + row - col] = 1;
				//path.push_back(col);
				path++;
				dfs(n, row + 1, path, sum);
				column[col] = 0;
				diag_135[row + col] = 0;
				diag_45[n + row - col] = 0;
				//path.pop_back();
				path--;
			}
		}
	}

};


int main()
{
	Solution S;
	cout << S.nQueen(15);
	system("pause");
    return 0;
}

