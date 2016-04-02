// 13.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
	bool is_scramble(string s1,string s2) {
		string path;
		bool done = false;
		dfs(s1, s2,path,done);
		return done;
	}
private:

	void dfs(string s1,string &s2, string path,bool &done) {

		if (done)
			return;
	
		else {
			int len = s1.size();
			if (1 == len) {
				path += s1;
			}
			
			if (path == s2) {
				done = true;
				path.clear();
				return;
			}
		   
			//if (path.size() == s2.size()) {
			//	path.clear();
			//	return;
			//}


		//	cout << path << endl;
			for (int i = 1; i < len; i++) {
				string left  = s1.substr(0, i );
				string right = s1.substr(i , len - i);
				cout << left << endl;;
				cout << right << endl;
					//path = path + left;
				 dfs(left, s2,path,done);
					//path = path + right;
				dfs(right, s2, path, done);

				//path -= left;
				//path -= right;  
				dfs(right, s2, path, done);
				//path = path + left;
				dfs(left, s2, path, done);
				//path = path + right;
				
			}
		}
	}
};

class Solution2 {

public:
	bool is_scramble(string s1, string s2) {
		//string path;
		//bool done = false;
		return dfs(s1,0,s1.size(), s2,0,s2.size());
		//return done;
	}
private:
	bool dfs(string &s1, int start,int end, string &s2, int start2, int end2) {
		
		int len = end - start;
		if (len == 1) return s1[start] == s2[start2];

		for (int i = 1; i < len; i++) {
			if (dfs(s1, start, start + i, s2, start2, start2 + i) && dfs(s1, start + i, end, s2, start2 + i, end2)
				|| dfs(s1, start, start + i, s2, end2 - i, end2 ) && dfs(s1, start + i, end, s2, start2, end2 - i)
				)
				return true;
		}
		return false;
	}
};


int main()
{
	Solution2 S;
	cout << S.is_scramble("abcd", "dabc");
	system("pause");
    return 0; 
}

