// 8.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector < vector <char >> LettersCombination(vector <int> number) {
		vector <char> path;
		vector<vector <char>> result;
		dfs(number, 0, path, result);
		return result;
	}
private:
	string str[10] = { " ", "\0", "abc", "def", // '0','1','2',...
		"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	void dfs(vector <int> &number,int level,vector<char> &path,vector<vector<char>> &result) {
		if (level == number.size() ){
			result.push_back(path);
			return;
		}
		int num = number[level];
		if(1 == num)dfs(number, level + 1, path, result);  //数字1对应的是空，需要专门处理一下
		else for(auto i:str[num]) {
			path.push_back(i);
			dfs(number, level + 1, path, result);
			path.pop_back();
		}
	
	}

};

int main()
{
	vector <int> S;
	for (int i = 0; i < 2; i++) {
		S.push_back(i + 2);
	}
	//S.push_back(2);
	vector < vector <char >> result;
	class Solution so;
	result = so.LettersCombination(S);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}