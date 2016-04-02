// 13.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		bool ret = false;
		if (s1.size() + s2.size() != s3.size())
			return ret;
		dfs(s1, 0 ,s2,0, s3,0,ret);
		return ret;
	}

private:
	void dfs(string &s1, int i, string &s2, int j, string &s3,int curr, bool &ret) {
		if (i + j == s3.size()) {
			ret = true;
			return;
		}
		if (i < s1.size() && s1[i] == s3[curr]) {
			//cout << "i = " << i + 1 << endl;
			dfs(s1, i + 1, s2, j, s3, curr + 1, ret);
		}
		if(j < s2.size() && s2[j] == s3[curr]){
			//cout << "j = " << j + 1<< endl;
			dfs(s1, i , s2, j + 1, s3, curr + 1, ret);
		}
	}

};


class Solution2 {

public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size();
		int n = s2.size();

		vector <vector<bool>> f(m + 1, vector<bool>(n + 1, true));
		//for (int i = 0; i <= m; i++)
		//	for (int j = 0; j <= n; j++) {
		//		f[i][j] = (i == 0 || (f[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || j == 0 ||  (f[i][ j - 1] && s2[j - 1] == s3[i + j - 1]));
		//	}
		for (int i = 1; i <= m; i++) {
			f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
		}

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				f[i][j] = (f[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (f[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
		}
		return f[m][n];

	}
};

class T{
protected:
	int a;
};
class R :public T
{

private:
	int c;
};
int main()
{
	Solution2 S;
	R r;
	r.a = 2;
	string s1 = "aabcc",s2 = "dbbca", s3 = "aadbbbaccc";
	cout << S.isInterleave(s1,s2,s3);
	system("pause");
    return 0;
}

