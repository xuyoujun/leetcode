// 13.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
		int minCut(string s) {
			const int n = s.size();
			vector <int> f(n  + 1, 0);
			vector <vector<bool>> p(n, vector<bool>(n, false));
			for (int i = 0; i <= n; i++)
				f[i] = n - 1 - i; // 最后一个 f[n]=-1
			for (int i = n - 1; i >= 0; i--)
				for (int j = i; j < n; j++) {
					if (s[i] == s[j] && (j - i < 2 || p[i][j])) {
						p[i][j] = true;
						f[i] = min(f[i], f[j + 1] + 1);
					}
				}
			return f[0];
		}
		int min(int a, int b) {
			return a > b ? b : a;
		}
};


class Solution2 {
public:
	int minCut(string s) {
		const int n = s.size();
		vector <vector<int>> f(n,vector<int>(n,0));
		vector <vector<bool>> p(n, vector<bool>(n, false));
		for (int l = 1; l <= n; l++)
			for (int i = 0; i < n - l + 1; i++) {
				int j = i + l - 1;
				f[i][j] = INT_MAX;
				p[i][j] = (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])); //s[i] ~ s[j]  是否是回文 动态规划
 				if (p[i][j]) {  //如果s[i]~s[j] 是回文，那么 f[i][j] = 0;
					f[i][j] = 0;
					continue;
				}
				for (int k = i; k < j; k++) {
					//f[i][j] = min(f[i][k],f[k+1][j])  ( i<= k < j )  动态规划
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + 1);
				}
			}
		return f[0][n - 1];
	}

	int min(int a, int b) {
		return a > b ? b : a;
	}

};



int main()
{
	Solution2 S;
	cout << S.minCut("aabbaadcaabbaadriglshklergjsgseoghhhhhhhhgggg");
	system("pause");
    return 0;
}

