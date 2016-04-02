// 13.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace  std;

class Solution {
public:
	int distinctSubsequence(string S, string T) {
		
		int m = T.size();
		int n = S.size();
		vector <vector<int>> f(m + 1, vector<int>(n+1,0));
		for (int i = 0; i < n + 1; i++) {
			f[0][i] = 1;
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				f[i][j] = f[i][j - 1] + (T[i - 1] == S[j - 1] ? f[i - 1][j - 1] : 0);
			
			}
		return f[m][n];
	
	}
private:

};
int main()
{
	Solution S;
	cout << S.distinctSubsequence("rabbbit", "rabbit");
	system("pause");
    return 0;
}

