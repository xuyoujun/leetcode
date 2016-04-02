// 8.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector <vector <int>> combinationUnique(int n, int k) {
		//sort(S.begin(), S.end());
		vector <int> path;
		vector <vector <int>> result;
		combinationUnique(1, n + 1, path, result, k,n);
	//	cout << "path's size is " << path.size();
		return result;
	}

private :
	void combinationUnique(int start, int end, vector <int> &path, vector <vector <int>> &result, int k, int n) {
		if (path.size() == k) {
			result.push_back(path);
			return;
		}
		int len = path.size();
		//for (int i = start; i < end - (k - len) + 1; i++) {
		for (int i = start; i < end ; i++) {
			path.push_back(i);
			combinationUnique(i + 1, end, path, result, k, n);
			path.pop_back();
		}
	
	}
};


int main()
{
	vector <int> S;
	for (int i = 0; i < 4; i++) {
		S.push_back(i + 1);
	}
	//S.push_back(2);
	vector < vector <int >> result;
	class Solution so;
	result = so.combinationUnique(4,2);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}