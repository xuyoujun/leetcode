// 10.8.cpp : Defines the entry point for the console application.
//
// 10.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector <vector<int>> combinationSum(vector <int> set, int target) {
		vector <int> path;
		vector <vector<int>> result;
		sort(set.begin(), set.end());
		dfs(0, set, path, result, target);
		return result;
	}
private:
	void dfs(int start, vector <int> &set, vector<int> &path, vector<vector <int>> &result, int gap) {
		if (gap == 0) {
			result.push_back(path);
			return;
		}


		int previous =  -1;
		for (int i = start; i < set.size(); i++) {
			if (set[i] == previous) continue; //防止重复的数。
			if (gap < set[i]) return;  //这里是剪枝，，不用continue的原因是，set是递减排列的，，set[i]后面的数 肯定会比gap 大，没有必要continue再比较
			path.push_back(set[i]);
			previous = set[i];
			dfs(i + 1, set, path, result, gap - set[i]);
			
			path.pop_back();
		}
	}
};


int main()
{
	vector <vector <int>> result;
	vector <int> set;
	set.push_back(10);
	set.push_back(1);
	set.push_back(2);
	set.push_back(7);
	set.push_back(6);
	set.push_back(1); 
	set.push_back(5);
	//10, 1, 2, 7, 6, 1, 5
	Solution S;

	result = S.combinationSum(set, 8);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

