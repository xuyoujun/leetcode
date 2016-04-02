// 8.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end()); // ±ÿ–Î≈≈–Ú
		vector<vector<int> > result;
		vector<int> path;
		dfs(S, S.begin(), path, result);
			return result;
	}
private:
	static void dfs(const vector<int> &S, vector<int>::iterator start,
		vector<int> &path, vector<vector<int> > &result) {
		result.push_back(path);
		for (auto i = start; i < S.end(); i++) {
			if (i != start && *i == *(i - 1)) continue;
			path.push_back(*i);
			dfs(S, i + 1, path, result);
			path.pop_back();
		}
	}
};




int main()
{
	class Solution S;
	//int A[20] = { 1,2,3,4,5,6,7 };
	//S.subSet(A, 0, 6,7);
	vector <int > s;
	for (int i = 1; i < 4; i++) {
		s.push_back(i);
	}
	//s.push_back(2);
	vector <vector<int>> result = S.subsetsWithDup(s);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}