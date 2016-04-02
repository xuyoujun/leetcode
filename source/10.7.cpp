// 10.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	vector <vector<int>> combinationSum(vector <int> set, int target) {
		vector <int> path;
		vector <vector<int>> result;
		dfs(0,set, path, result, target);
		return result;
	}
private:
	void dfs(int start, vector <int> &set,vector<int> &path, vector<vector <int>> &result, int gap) {
		if (gap == 0) {
			result.push_back(path);
			return;
		}
		for (int i = start; i < set.size(); i++) {
			if (gap < set[i]) return;
			path.push_back(set[i]);
			dfs(i, set, path, result, gap - set[i]);
			path.pop_back();
		}
	}
};


int main()
{
	vector <vector <int>> result;
	vector <int> set;
	set.push_back(2);
	set.push_back(3);
	set.push_back(6);
	set.push_back(7);
	Solution S;

	result = S.combinationSum(set, 7);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

