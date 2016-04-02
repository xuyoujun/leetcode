// 10.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {

public :
	vector <string> restoreIpAddress(string s) {
		vector <string> path ;
		vector <string> result;
		dfs(0,0,s,path,result);
		return result;
	}
private:
	void dfs(int steps,int start,string &s,vector <string> &path,vector <string> &result) {
		if (steps == 4 && start == s.size()) {
			string temp;
			for (auto i: path) {
				temp += i;
				temp += ".";	
			}
			temp.pop_back();  //删除最后一个多余的 '.'
			result.push_back(temp);
			return;
		}
		if (s.size() - start > 3 * (4 - steps)) return;   //剪枝 ， 剩的数字多于 3 * (4 - steps)，一步分3个还用不完
		if (s.size() - start < 4 - steps) return;         //剪枝， 剩的数字少于 (4 - steps),一步分一个都不够了
		//if (steps == 4 || start == s.size())return;
		int len = s.size();
		for (int i = start; i < len; i++) {
			if (isValid(s.substr(start,  i - start + 1))) {
				path.push_back(s.substr(start, i - start + 1));
				dfs(steps + 1, i + 1, s, path, result);
				path.pop_back();
				
			}
			if (s[i] == '0') break;  //不能有前缀0
		}
	}

private :
	bool isValid(string s) {
		if (s.size() > 0 && s.size() < 4 && atoi(s.c_str()) >= 0 && atoi(s.c_str()) <= 255)
			return true;
		return false;
	}
};


int main()
{
	Solution S;
	string temp;
	vector <string>result;
	string s = "255011135";
	result = S.restoreIpAddress(s);
	for (int i = 0; i < result.size(); i++) {
		temp = result[i];
		cout << temp << "  "; 
	}
	system("pause");
    return 0;
}

