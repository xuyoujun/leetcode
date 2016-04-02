// 13.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;



class solution {

public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		return dfs(s,dict);
	}
private:
	bool dfs(string &s, unordered_set<string> &dict) {
		if (s.size() > 0) {
			if (dict.find(s) != dict.end())
				return true;
			//else return false;
		}
		if (s.size() <=0 ) return true;
		int len = s.size();
		for (int i = 1;  i < len; i++) {
			//cout << s.substr(0, i) << endl;
			//cout << s.substr(i, len) << endl;
			if (dfs(s.substr(0, i), dict) && dfs(s.substr(i, len), dict)) return true;
		
		}
		return false;
	}

};


class solution2 {
public:
	bool wordBreak(string s, unordered_set <string> &dict) {
		int m = s.size();
		vector <bool> f(m + 1, false);
		f[0] = true;

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= i; j++) {
				if (f[j - 1] && dict.find(s.substr(j - 1, i)) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		
		}
		return f[m];
	
	}

private:


};
//int i = 0;
int main()
{
	solution2 S;
	unordered_set <string> dict;
	dict.insert("leet");
	dict.insert("code");
	cout << S.wordBreak("leetcode", dict);
	system("pause");
    return 0;
}

