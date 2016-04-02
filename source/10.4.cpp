// 10.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
	vector <vector<int>> nQueens(int n) {
		vector <vector<int>> result;
		vector<int> path;
		dfs(n,0, path, result);
		return result;
	}
private:
	vector<int> row;
	vector<int> diag_45;
	vector<int> diag_135;
	void dfs(int &n, int curr,vector<int> &path, vector<vector<int>> &result) {
		if (curr == n ) {
			//cout << "kk";
			result.push_back(path);
			return;
		}

		for (int i = 0; i < n; i++) {
			if (find(row.begin(), row.end(), i) == row.end() && find(diag_135.begin(), diag_135.end(), curr + i) == diag_135.end() && find(diag_45.begin(), diag_45.end(), n + curr - i) == diag_45.end()) {
				row.push_back(i);
				diag_45.push_back(n + curr - i);
				diag_135.push_back(curr + i);
				path.push_back(i);
				dfs(n, curr + 1, path, result);
				row.pop_back();
				diag_45.pop_back();
				diag_135.pop_back();
				path.pop_back();
			}
			else
				continue;  //¼ôÖ¦
			
		}

	}
};

int main()
{
	vector <vector<int>> result;
	class Solution S;
	result = S.nQueens(6);
	for (auto i = 0; i < result.size(); i++) {
		for (auto j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

