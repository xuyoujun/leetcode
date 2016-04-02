// 10.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
	vector <vector<string>> partition(string s) {
		if (s.empty()) return {};
		vector <vector<string>> result;
		vector <string> path;
		dfs(s, path, result,0);
		return result;
	}
private:
	void dfs(string &s, vector<string> &path, vector<vector<string>> &result, int start) {
		if (start == s.size()){
			result.push_back(path);
			return;
		}
		int size = s.size();
		for (auto i = start; i < size; i++) {
			if (isPalindrome(s, start, i)) {  //没找到一个回文就砍断，后面接着找
				path.push_back(s.substr(start, i-start + 1));
				dfs(s, path, result, i + 1);
				path.pop_back();
			}
		}
	}
	bool isPalindrome(string &s, int start, int end) {
		while (end > start && s[start] == s[end]) {
			end--;
			start++;
		}
		return start >= end;
	}
};

class Solution2 {

public :
	vector<vector<string>> partition(string &s) {
		vector <vector<string>> result;
		vector <string> path;
		dfs(s, result,path, 0, 1);
		return result;
	}
private:
	//start ,end 两种情况； 从 start 到end - 1 断开,递归一次； 不断开,递归一次
	void dfs(string &s, vector <vector<string>> &result, vector <string>&path, int start, int end) {
		if (end == s.size()) {
			if (isPalindrom(s, start, end - 1)) {
				path.push_back(s.substr(start, end - start));
				result.push_back(path);
				path.pop_back();
			}
			return;
		} 
		dfs(s, result, path, start, end + 1); // 不断开, 递归一次

		if (isPalindrom(s, start, end - 1)) { //从 start 到end - 1 断开, 递归一次； 也具有剪枝的功能
			path.push_back(s.substr(start, end - start));  //s[start] ~ s[end-1] 是回文，断开
			dfs(s, result, path, end, end + 1);
			path.pop_back();
		}
	}
	bool isPalindrom(string &s, int start, int end) {
		while (start < end && s[start] == s[end]) {
			start++;
			end--;
		}
		return start >= end;
	}
};

class Solution3 {
public:
	vector <vector <string>> partition(const string &s) {
		const int n = s.size();
		bool **P = new bool*[n];
		vector <vector<string>> *sub_part = new vector <vector<string>>[n];
		for (int i = 0; i < n; i++) {
			P[i] = new bool[n];
		}
		for (int i = n - 1; i >= 0; i--)
			for (int j = i; j < n; j++) {
				P[i][j] = (s[i] == s[j]) && (j - i < 2 || P[i + 1][j - 1]);
			}
		for (int i = n - 1; i >= 0; i--)
			for (int j = i; j < n; j++) {
				string temp;
				if (P[i][j]) {
					temp= s.substr(i, j - i + 1);
					if (j < n - 1) {
						for (auto k : sub_part[j + 1]) {
							k.insert(k.begin(), temp);
							sub_part[i].push_back(k);
						}
					}
					else {
						sub_part[i].push_back(vector <string> {temp});
					}
				}
			}
		return sub_part[0];
	}

};
int main()
{
	string s("aab");
	vector <vector<string>> result;
	Solution3 S;
	result = S.partition(s);
	for (auto i: result) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

