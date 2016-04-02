// 10.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector> 
#include <iostream>

using namespace std;

class Solution {
public:
	vector <vector <char>> generateParneses(int n) {
		vector<char> path;
		vector<vector <char>> result;
		dfs(n, 0, 0, path, result);
		return result;
	}
private:
	void dfs(int n, int l, int r, vector<char> &path, vector<vector<char>> &result) {
		if (l == n && r == n) {
			result.push_back(path);
			return;
		}
		if (l == n) {
			path.push_back(')');
			dfs(n, l, r + 1, path,result);
			path.pop_back();
		}
	    /*else if (l > r ) {
			path.push_back('(');
			dfs(n, l + 1, r, path, result);
			path.pop_back();
			path.push_back(')');
			dfs(n, l , r + 1, path, result);
			path.pop_back();
		}*/
		//else if (l == r){
			//path.push_back('(');
			//dfs(n, l + 1, r, path, result);
			//path.pop_back();
		//}
		else {
			path.push_back('(');
			dfs(n, l + 1, r, path, result);
			path.pop_back();
			if (l > r) {
				path.push_back(')');
				dfs(n, l, r + 1, path, result);
				path.pop_back();
			}
		}


	}
};

int main()
{
	vector<vector<char>> result;
	Solution S;
	result = S.generateParneses(5);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

